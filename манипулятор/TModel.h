#pragma once
#include"TUnit.h"
#include"TMatrix.h"
#include"BMatrix.h"
//#include<fstream>

#include<stdio.h>

class TModel
{
	int N;
	TUnit* MUnit;
	int UCount;
	TMatrix T;
	double *q;//углы поворота
	//TMatrix* B;
public:
	TModel()
	{
		N = 0;
		MUnit = 0;
		UCount = 0;
		q = 0;
	}

	TModel(int n)
	{
		N = n;
		MUnit = new TUnit[N];
		UCount = 0;
		q = new double[N];
		for (int i = 0; i < N; i++)
		{
			q[i] = 0;
		}
		/*B = new TMatrix[N];
		for (int i = 0; i < N; i++)
		{
			B[i] = TMatrix(0);
		}*/
	}

	void SetB(int N, int i, int j, double L)//запись эл-та с заданными индексами в матрицу ¬ с заданным номером
	{
		MUnit[N].SetB(i, j, L);
	}

	void SetQ(double Q[])
	{
		for (int i = 0; i < UCount; i++)
		{
			/*MUnit[i].SetQ(q[i]);*/
			q[i] = Q[i];
		}
	}

	void Calculate(void)
	{
		T=TMatrix(1);
		for (int i = 0; i < UCount-1; i++)
		{
			T = T*MUnit[i].GetB() * TMatrix::S(q[i]);
		}
		T = T*MUnit[UCount - 1].GetB();

		/*TMatrix T = B0 * TMatrix::S(q[0])*
			B1 * TMatrix::S(q[1])*
			B2 * TMatrix::S(q[2])* B3;*/
	}

	TMatrix GetT()
	{
		return T;
	}

	void Print(void)
	{
		for (int i = 0; i < UCount; i++)
		{
			MUnit[i].Print();
			cout<<"q= "<< q[i] << endl;
			cout << "S= "<<endl;
			TMatrix::S(q[i]).Print();
		}
	}

	void AddUnit(PairType PT, double L,Orientation OR)
	{
		double*Ex, *Ey, *Ez;
		switch (OR)
		{
		case Orientation::MY:
			Ex = Ez2MY[0];
			Ey = Ez2MY[1];
			Ez = Ez2MY[2];
			break;
		case Orientation::MX:
			Ex = Ez2MX[0];
			Ey = Ez2MX[1];
			Ez = Ez2MX[2];
			break;
		case Orientation::X:
			Ex = Ez2X[0];
			Ey = Ez2X[1];
			Ez = Ez2X[2];
			break;
		case Orientation::Y:
			Ex = Ez2Y[0];
			Ey = Ez2Y[1];
			Ez = Ez2Y[2];
			break;
		case Orientation::EE:
			Ex = Ee[0];
			Ey = Ee[1];
			Ez = Ee[2];
			break;
		default:
			Ex = Ey = Ez = 0;
			break;
		}
		MUnit[UCount] = TUnit(Ex, Ey, Ez, PT, L);
		UCount++;
	}
	~TModel();

	void SaveToFile(char *FileName)
	{
		//ofstream out(FileName);
		//out << "manipulate data file" << endl;

		FILE * out = fopen(FileName, "wt");
		fprintf (out, "manipulate data file \n" );
		fprintf(out, "UCount= %d \n", UCount);
		for (int i = 0; i < UCount; i++)
		{
			MUnit[i].SaveToFile(out);
			fprintf(out, "q= %lf \n", q[i]);
		}
		
		fclose(out);
	}
	void ReadFromFile(char *FileName)
	{
		FILE * in = fopen(FileName, "rt");
		if (in == 0)
		{
			cout << "file not found";
			exit(0);
		}
		char Buff[256];
		fgets(Buff, 256, in);
		fscanf(in, "UCount= %d \n", &UCount);
		N = UCount;
		MUnit = new TUnit[N];
		q = new double[N];
		for (int i = 0; i < N; i ++)
		{
			MUnit[i].ReadFromFile(in);
			fscanf(in, "q= %lf \n", &q[i]);
		}
		fclose(in);
	}
};

