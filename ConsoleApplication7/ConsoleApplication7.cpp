#include <iostream>		// для консольного ввода-вывода
#include <string>		// для переменных типа данных string
#include <Windows.h>	// для кодировок (поддержка кирилицы)
#include <iomanip>		// для форматированного вывода

// подключаем стандартное пространство имен
using namespace std;

// определяем структуру "Ребенок"
typedef struct TChild
{
	string name; // имя ребенка
	char sex; // пол ребенка (М - мужской; Ж - женский)
	int height; // рост ребенка
} Child;

// вывод информации обо всех детях на экран в табличном формате
void Print_children(Child* children, const int children_count)
{
	int average = 0;
	cout << endl << "Информация о детях(" << children_count << " чел.) имеет вид:" << endl;
	SetConsoleCP(866);

	cout << "" << endl;
	cout << "     №             Имя            Пол         Рост, см" << endl;
	cout << "" << endl;
	for (int i = 0; i < children_count; i++)
	{
		cout << setw(6) << (i + 1) << "\t";
		cout << setw(17) << children[i].name << "\t";
		cout << setw(4) << children[i].sex << "\t";
		cout << setw(12) << children[i].height << endl;
	}
	cout << "" << endl;
}

void Print_children_lower_than_average(Child* children, const int children_count, int average)
{
	cout << endl << "Информация о детях ниже ср. роста имеет вид:" << endl;
	SetConsoleCP(866);
	cout << "" << endl;
	cout << "     №             Имя            " << endl;
	cout << "" << endl;
	for (int i = 0; i < children_count; i++)
	{
		if (children[i].height < average)
		{
			cout << setw(6) << (i + 1) << "\t";
			cout << setw(17) << children[i].name << "\t" << endl;
		}

	}
	cout << "" << endl;
}

void Print_child_max(Child* children, const int children_count)
{
	int max = children[0].height;
	int i_max = 0;
	for (int i = 1; i <= children_count; i++)
		if (children[i].height > max)
		{
			max = children[0].height;
			i_max = i;
		}
	cout << "								Самый высокий ребенок" << endl;
	cout << "" << endl;
	cout << children[i_max].name << endl;
	cout << "" << endl;

}
// получение среднего роста всех детей
double Get_average_height(Child* children, const int children_count)
{
	// отвечает за среднее значение возраста всех детей
	double average = 0;

	// перебираем всех детей
	for (int i = 0; i < children_count; i++)
		average += children[i].height; // добавляем возраст текущего ребенка к результату

	// чтобы получить среднее значение, надо сумму разделить на количество
	return (average / (children_count * 1.0));
}

// главная функция программы (точка входа)
int main(void)
{
	// русификация всех диалогов программы
	setlocale(LC_ALL, "Russian");

	// отвечает за количество детей
	const size_t CHILDREN_COUNT = 3;

	// хранит информацию о 20 детях
	Child children[CHILDREN_COUNT];

	// запрашиваем от пользователя ввод информации о 20 детях
	cout << "Введите информацию о " << CHILDREN_COUNT << " детях." << endl;
	for (int i = 0; i < CHILDREN_COUNT; i++)
	{
		fflush(stdin);
		cout << "\t Ребенок № " << (i + 1) << endl;

		cout << "\t\t -  имя: ";
		SetConsoleCP(1251);
		cin >> children[i].name;
		SetConsoleCP(866);

		cout << "\t\t -  пол (М/Ж): ";
		SetConsoleCP(1251);
		cin >> children[i].sex;
		SetConsoleCP(866);

		cout << "\t\t - рост, см: ";
		cin >> children[i].height;
		cout << endl;
	}

	// выводим информацию о детях на экран в красивом табличном формате
	Print_children(children, CHILDREN_COUNT);
	int average = Get_average_height(children, CHILDREN_COUNT);
	// выводим средний рост всех детей
	cout << "Средний возраст всех детей: " << setprecision(3) << fixed << average << endl << endl;


	Print_children_lower_than_average(children, CHILDREN_COUNT, average);
	// задержка работы программы, чтобы у пользователя была возможность просмотреть результат

	Print_child_max(children, CHILDREN_COUNT);
	fflush(stdin);
	system("pause");

	// завершение выполнение программы и передача управления в ОС (код 0 - все прошло успешно!)
	return 0;
}
