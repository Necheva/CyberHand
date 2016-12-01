#include<iostream>
#include"TModel.h"
using namespace std;

int main()
{
	TModel Model;
	Model.ReadFromFile("Manipul.txt");
	Model.Calculate();
	TMatrix T = Model.GetT();
	cout << "Result" << endl;
	T.Print();
	return 0;

	//вызвать калькулятор печать результата и проверка
}