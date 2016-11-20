//#include<TMatrix.h>
#include<iostream>
#include"TModel.h"
using namespace std;

int main()
{
	int NUnit = 4;
	TModel model(NUnit);//создаем модель с числом пар кинематики
	model.AddUnit(PairType::ROT, 1.0, Orientation::EE);// создали первый узел
	model.SetB(0,2,3,1.0);

	model.AddUnit(PairType::ROT, 1.0, Orientation::MY);
	/*model.SetB(1,0, 2, 1);
	model.SetB(1,1, 0, sqrt(3) / 2);
	model.SetB(1,1, 1, -1.0 / 2);
	model.SetB(1,1, 3,1.0* sqrt(2) / 2);
	model.SetB(1,2, 1, sqrt(3) / 2);
	model.SetB(1,2, 0, 1.0 / 2);
	model.SetB(1,2, 3, 1.0 * sqrt(2) / 2);
	model.SetB(1,3, 3, 1);*/
	model.SetB(1, 2, 3, 1.0);

	model.AddUnit(PairType::SHAR, 1.0, Orientation::X);
	model.SetB(2, 2, 3, 1.0);

	model.AddUnit(PairType::CATCH, 0, Orientation::X);
	model.SetB(3, 2, 3, 1);
	model.Print();

	model.Calculate();
	TMatrix T = model.GetT();
	cout << "Result" << endl;
	T.Print();
	return 0;
}