//Минимум для c++
#include <iostream> // стандартная библиотека с функциями
#include <iomanip> /*Манипуляция вводами данных, ввод консоли*/
#include <string> // объявлять переменную строкой
#include <stdlib.h> //содержаться классы (тренеры, векторы)
#include <cmath> //Возведение в степень
#include <windows.h> //доступ к API
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <vector>
#include <sstream>
#include "Bench.h"
using namespace std; // рабочее пространство, чтобы не писать каждый раз std

int main()
{
#pragma region Starterpuck
	SetConsoleOutputCP(1251); //изменение кодировки на другую
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian"); //добавление русской локализации в консоль
	srand(time(NULL)); //обнуление рандома
#pragma endregion
	//int a = -1;
	DataStructure::Double<int> test, test2;
	for (size_t i = 0; i < 1000; i++)
	{
		test.push_back(rand() % 1000);
		test2.push_back(rand() % 1000);
	}
	cout<<"Пузырь - "<<Benchmark::test_sortBub(test2) << endl;
	cout << "Select - " << Benchmark::test_sortSel(test) << endl;
	/*test.push_back(5);
	test.push_back(2);
	test.push_back(3);
	test.print();
	test.push_back(2); 
	test.push_back(6); 
	cout << endl;
	test.print();
	cout << "------------------------------------\n";
	for (size_t i = 0; i < test.get_size(); i++)
	{
	cout << test[i];

	}cout << "------------------------------------\n";
	cout << test[0];
	cout << "------------------------------------\n";
	for (int i = test.get_size()-1; i >= 0 ; i--)
	{
		cout << test[i] << " - "<<i<<"\n";
	}

	test.insert(235, 3);
	test.print();
	test.remove(3);
	cout << endl;
	test.print();*/
	
	

}