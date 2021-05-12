#include "pch.h"
#include <string>
#include <iostream>
#include <exception>
#include "math.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	double num1;
	double num2;
	int var = 1;

	while (var--)
	{
		cout << "Введите значение num1: ";
		cin >> num1;
		cout << "Введите значение num2: ";
		cin >> num2;

		cout << "num1 + num2 = " << num1 + num2 << endl;
		cout << "num1 / num2 = " << num1 / num2 << endl;

		/*если num2 у нас равно 0, то генерируется исключительная ситуация,
		какая-то часть кода БРОСИЛА (throw) исключение, тогда отрабатывает блок catch*/
		try
		{
			if (num2 == 0)
			{
				throw std::exception("Division by zero");
			}
		}

		/*catch поймал то, что случилось в try; то, что "ловит" блок catch, описывается в ()*/
		/*метод "what" как раз и показывает, что пошло не так, таким образом результат метода выводим на консоль*/
		catch (const std::exception& ex)
		{
			cout << " Ошибка " << ex.what() << " - на 0 делить нельзя!" << endl;
		}
		/*ключевой факт здесь в том, что использовать ключевое слово throw необходимо тогда,
		если в методе нашего класса или логике (как в нашем случае) состояние данных, которые мы получили, каким-то образом не соответствуют тому состоянию,
		которое мы задумывали для корректной работы этой программы (деление на 0)*/
	}
	cout << "Программа завершила работу!" << endl << endl;
	return 0;
}