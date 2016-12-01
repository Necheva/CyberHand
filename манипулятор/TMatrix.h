#pragma once
#include<math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

#include"TVector.h"

class TMatrix
{
	static const int N = 4;// у всех объектов данного класса он единственный
	double Matrix[N][N];
public:
	TMatrix(int E=0)//параметр, который мы будем задавать. Если Q==1, то марица единичная
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				Matrix[i][j] = 0;
			}
		}
		if (E == 1)
			for (int i = 0; i < N; i++)
			{
				Matrix[i][i] = 1;
			}
	};
	~TMatrix();

	void Set(int i, int j, double Value)// будем устанавливать значение при помощи value
	{
		Matrix[i][j] = Value;
	};

	void Print()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << Matrix[i][j]<<" ";
			}
			cout << endl;
		}
	};
	double GetMatrix(int i, int j)
	{
		return Matrix[i][j];
	}

	TMatrix operator *(TMatrix &T)
	{
		TMatrix Res;// модифицированный алгоритм умножения: умножаем матрицу по блокам

		// левый верхний блок
		for (int i = 0; i < N-1; i++)
		{
			for (int j = 0; j < N-1; j++)
			{
				for (int k = 0; k < N-1; k++)
				{
					Res.Matrix[i][j] += Matrix[i][k] * T.Matrix[k][j];
				}
			}
		}
		// правый верхний блок(столбец)
		
		for (int i = 0; i < N - 1; i++)
		{
			double sum = 0;
			for (int j = 0; j < N - 1; j++)
			{
				sum += Matrix[i][j] * T.Matrix[j][N-1];
			}
			Res.Matrix[i][N-1]= Matrix[i][N-1] + sum;
		}
		//нижняя строка
		for (int j = 0; j < N - 1; j++)
		{
			Res.Matrix[N - 1][j] = 0;
		}
		Res.Matrix[N - 1][N - 1] = 1;
		return Res;
	}

	/*TVector GetVector(int j)
	{
		TVector J;
		for (int i = 0; i < N - 1; i++)
		{
			J.Vector[i] = Matrix[i][j];
		}
		return J;
	}

	TVector operator *(TVector &V)
	{
		TVector Result;
		for (int i = 0; i < N - 1; i++)
		{
			double sum = 0;
			for (int j = 0; j < N - 1; j++)
			{
				sum += Matrix[i][j] * V.Vector[j];
			}
			Result.Vector[i] = sum;
		}
		return Result;
	}*/

	static TMatrix S(double q)// создаем матрицу S
	{
		TMatrix Res(1);
		Res.Set(0, 0, cos(q));
		Res.Set(0, 1, -sin(q));
		Res.Set(1, 0, sin(q));
		Res.Set(1, 1, cos(q));
		return Res;
	}
	void SaveToFile(FILE * out)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				fprintf(out,"%lf ", Matrix[i][j]);
			}
			fprintf(out, "\n");
		}
	}

	void ReadFromFile(FILE *in)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				fscanf(in, "%lf ", &Matrix[i][j]);
			}
			//fprintf(out, "\n");
		}
	}

};



