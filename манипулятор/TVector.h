#pragma once

#include"TMatrix.h"

//class TMatrix;

class TVector
{
	static const int N = 4;// у всех объектов данного класса он единственный
	double Vector[N];
public:
	TVector()
	{
		for (int i = 0; i < N; i++)
			Vector[i] = 0;
	}
	~TVector();
	void Set(int j)
	{
		Vector[j] = 1;
	}

	double& operator[](int i)
	{
		return Vector[i];
	}

	/*TVector operator *(TMatrix& T)
	{
		TVector Res;
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N; i++)
			{
				Res.Vector[j] += Vector[j] * T.GetMatrix(i, j);
			}
		}
		return Res;
	}*/
	double operator *(TVector& V)
	{
		double Res = 0;
		for (int i = 0; i < N; i++)
		{
			Res += Vector[i] * V.Vector[i];
		}
		return Res;
	}
	friend class TMatrix;
};

