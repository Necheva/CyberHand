//#include<TMatrix.h>
#include"TMatrix.h"
#include"TVector.h"
#include"TUnit.h"
#include<iostream>
using namespace std;

int main()
{
	cout << "прямоугольные матрицы" << endl;
	double L[4] = { 1,1,1,1 };
	double q[3] = { 0,0,0 };
	TMatrix B0(1);
	int N = 4;
	TVector Vx, Vy, Vz, Vt;

	double Ex1[] = { 1,0,0 }, Ey1[]= { 0,1,0 }, Ez1[]= { 0,0,1 };
	TUnit U1(Ex1,Ey1,Ez1, ROT, 1.0);

	double Ex2[] = { 1,0,0 }, Ey2[] = { 0,1,0 }, Ez2[] = { 0,0,1 };
	TUnit U2(Ex2, Ey2, Ez2, ROT, 1.0);

	double Ex3[] = { 1,0,0 }, Ey3[] = { 0,0,1 }, Ez3[] = { 0,-1,0 };
	TUnit U3(Ex3, Ey3, Ez3, SHAR, 1.0);

//	TMatrix B0 = U1.CteateMatrixB(U2);//написать метод создания путем сравнивания


	Vx.Set(0);
	Vy.Set(1);
	Vz.Set(2);
	Vt.Set(3);

	B0.Set(2, 3, L[0]);
	cout << "B0: " << endl;
	B0.Print();
	cout << endl;

	TMatrix B1;//не единичная матрица, поэтому без скобок и без параметров
	B1.Set(0, 2, 1);
	B1.Set(1, 0, sqrt(3)/2);
	B1.Set(1, 1, -1.0 / 2);
	B1.Set(1, 3, L[1]*sqrt(2) / 2);
	B1.Set(2, 1, sqrt(3) / 2);
	B1.Set(2, 0, 1.0 / 2);
	B1.Set(2, 3, L[1]*sqrt(2) / 2);
	B1.Set(3, 3, 1);
	cout << "B1: " << endl;
	B1.Print();
	cout << endl;

	/*TMatrix C = B0*B1;
	cout << "C: " << endl;
	C.Print();
	cout << endl;*/

	TMatrix B2;
	B2.Set(0, 2, 1);
	B2.Set(0, 3, L[2]);
	B2.Set(1, 0, 1);
	B2.Set(2, 1, 1);
	B2.Set(3, 3, 1);

	cout << "B2: " << endl;
	B2.Print();
	cout << endl;

	TMatrix B3(1);
	B3.Set(2, 3, L[3]);

	cout << "B3: " << endl;
	B3.Print();
	cout << endl;

	cout << "S(q[0]): " << endl;
	TMatrix::S(q[0]).Print();
	cout << endl;

	cout << "S(q[1]): " << endl;
	TMatrix::S(q[1]).Print();
	cout << endl;

	cout << "S(q[2]): " << endl;
	TMatrix::S(q[2]).Print();
	cout << endl;


	TMatrix T = B0 * TMatrix::S(q[0])* 
		        B1 * TMatrix::S(q[1])* 
		        B2 * TMatrix::S(q[2])* B3;

	cout << "T: " << endl;
	T.Print();
	cout << endl;
	
	double Fx = T.GetMatrix(0, 3);
	double Fy = T.GetMatrix(1, 3);
	double Fz = T.GetMatrix(2, 3);

	cout << "Fx= " << Fx << "; " << "Fy= " << Fy << "; " << "Fz =" << Fz << endl;

	/*cout << "Vector: " << endl;
	double Fx = Vx*T*Vt;
	cout << "Fx= " << Fx;
	cout << endl;
	double Fy = Vy*T*Vt;
	cout << "Fy= "<<Fy ;
	cout << endl;
	double Fz = Vz*T*Vt;
	cout << "Fz= "<<Fz ;
	cout << endl;*/
	

}