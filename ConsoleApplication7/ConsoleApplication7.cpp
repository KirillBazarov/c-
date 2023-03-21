#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // для функции isvowel()

using namespace std;

bool isvowel(char c) {
    // Возвращает true, если символ является гласной буквой
    switch (tolower(c)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        cout << "фамилия начинается с гласной" << endl;
        return true;
    default:
        cout << "фамилия не начинается с гласной" << endl;
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    string surname, name;

    // Запрашиваем фамилию и имя пользователя
    cout << "Введите фамилию: ";
    cin >> surname;
    cout << "Введите имя: ";
    cin >> name;

    // Открываем файл для записи
    ofstream outfile("names.txt");

    // Записываем фамилию и имя в файл
    outfile << surname << " " << name << endl;

    // Закрываем файл
    outfile.close();

    // Открываем файл для чтения
    ifstream infile("names.txt");

    // Открываем файл для записи имен, начинающихся на гласные буквы
    ofstream outfile2("vowel_names.txt");

    // Читаем строки из файла и проверяем, начинается ли имя на гласную букву
    while (infile >> surname >> name) {
        if (isvowel(surname[0])) {
            outfile2 << surname <<  endl;
        }
    }

    // Закрываем файлы
    infile.close();
    outfile2.close();

    cout << "Готово!" << endl;

    return 0;
}
