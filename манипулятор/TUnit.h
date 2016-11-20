#pragma once
#include"TMatrix.h"
#include"TVector.h"

enum PairType {ROT,SHAR,MOVE,CATCH};
enum Orientation{X,MX,Y,MY,EE};

class TUnit
{
	double L;
	double *Ex, *Ey, *Ez;
	PairType Type;
	TMatrix B;
	char *TypeNames[4] = { "ROT","SHAR","MOVE","CATCH" };

public:
	TUnit(double *ex=0, double *ey=0, double *ez=0, PairType T=ROT, double L = 1)
	{
		this->L = L;//одинаковые имена L и L
		Ex = ex;
		Ey = ey;
		Ez = ez;
		Type = T;
		B = TMatrix(0);
		if (ex != 0)
		{
			for (int i = 0; i < 3; i++)
				B.Set(0, i, ex[i]);
			for (int i = 0; i < 3; i++)
				B.Set(1, i, ey[i]);
			for (int i = 0; i < 3; i++)
				B.Set(2, i, ez[i]);
		}
	}
	~TUnit();

	void Print()
	{
		cout <<"Type= "<< TypeNames[Type] << endl;
		cout << "L= " << L << endl;
		B.Print();
	}

	void SetB(int i, int j, double L)
	{
		B.Set(i, j, L);
	}
	TMatrix& GetB()
	{
 		return B;
	}

};

