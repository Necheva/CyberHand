#pragma once
#include"..\манипулятор\TMatrix.h"
class TModel
{
	double L[4] = { 1,1,1,1 };
	double q[3] = { 0,0,0 };
	TMatrix B0;
	TMatrix B1;
	TMatrix B2;
	TMatrix B3;

public:
	TModel();
};

