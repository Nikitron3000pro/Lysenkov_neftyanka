// используемые библиотеки
#include <iostream>
#include <fstream>
#include <string>
// использование std
using namespace std;
// различные проверки на устойчивость программы
// проверка, если введено отрицательное число, то ошибка
int proverka_otric(int& chislo) 
{
	cin >> chislo;
	while (cin.fail() || cin.peek() != '\n' || chislo <= 0) //cin.fail()возвращает true, если последняя команда cin завершилась неудачно, и false в противном случае; cin.peek() != '\n') проверяет формат ввода по одному числу на строку
	{
		cin.clear(); // очищаем cin, приводим его в рабочее состояние
		cin.ignore(100, '\n'); // игнорирует 100 введенных символов, пока не встретит переход на новую строку
		cout << "\nВведено неверное значение, попробуйте еще раз:\n";
		cin >> chislo;
	}
	return chislo;
}
// если число меньше 0 или больше 7, то ошибка
int proverka_vvod(int& chislo) 
{
	cin >> chislo;
	while (cin.fail() || cin.peek() != '\n' || chislo < 0 || chislo > 7)
	{
		cin.clear(); // очищаем cin, приводим его в рабочее состояние
		cin.ignore(100, '\n'); // игнорирует 100 введенных символов, пока не встретит переход на новую строку
		cout << "\nВведено неверное значение, введите цифру от 0 до 7:\n";
		cin >> chislo;
	}
	return chislo;
}
// если введено значение вещественного тип с плавающей точкой двойной точности, то вывод ошибки
double proverka_double(double& chislo) 
{
	cin >> chislo;
	while (cin.fail() || cin.peek() != '\n' || chislo <= 0)
	{
		cin.clear(); // очищаем cin, приводим его в рабочее состояние
		cin.ignore(100, '\n'); // игнорирует 100 введенных символов, пока не встретит переход на новую строку
		cout << "\nВведено неверное значение, попробуйте еще раз\n";
		cin >> chislo;
	}
	return chislo;
}
// если введено значение эффективности меньше 0.0 или больше 1.0, то вывод ошибки
double chek_double(double& chislo) 
{
	cin >> chislo;
	while (cin.fail() || cin.peek() != '\n' || (chislo < 0.0) || (chislo > 1.0))
	{
		cin.clear(); // очищаем cin, приводим его в рабочее состояние
		cin.ignore(100, '\n'); // игнорирует 100 введенных символов, пока не встретит переход на новую строку
		cout << "\nВведите эффективность от 0.0 до 1.0 \n";
		cin >> chislo;
	}
	return chislo;
}
// проверка на булевой тип данных
bool chek_bool(bool& chislo) 
{
	cin >> chislo;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear(); // очищаем cin, приводим его в рабочее состояние
		cin.ignore(100, '\n'); // игнорирует 100 введенных символов, пока не встретит переход на новую строку
		cout << "\nВведено неверное значение, попробуйте еще раз:\n";
		cin >> chislo;
	}
	return chislo;
}
// структура для описания трубы, вводим переменные и первоначально обнуляем данные
struct Pipe
{
	string name = "None";
	double length = 0.0;
	int diameter = 0;
	bool repair = false;
};
// структура для описания компрессорной станции, вводим переменные и первоначально обнуляем данные
struct Station
{
	string Name = "None";
	int workshops = 0;
	int workshopsInOperation = 0;
	double efficiency = 0.0;
};
// функция для считывания данных трубы с консоли
Pipe AddPipe()
{
	Pipe pipe;
	cout << "Введите название трубы: ";
	cin.ignore(); // очищает кеш перед следующей строкой
	getline(cin, pipe.name); // извлечение одной строки и записывание ее в переменную
	cin.ignore(100, '\n');
	cout << "Введите длину трубы (в км): ";
	proverka_double(pipe.length);
	cin.ignore(100, '\n');
	cout << "Введите диаметр трубы (в м): ";
	proverka_otric(pipe.diameter);
	cin.ignore(100, '\n');
	cout << "Труба в ремонте? (1 - да, 0 - нет): ";
	chek_bool(pipe.repair);
	cin.ignore(100, '\n');
	return pipe;
}
// функция для просмотра введенных данных трубы на консоль
void PrintAddPipe(Pipe& pipe) // передаем в аргумент функции значения с помощью ссылок
{
	cout << endl << "Данные о трубе" << endl;
	if (pipe.name == "None")
	{
		cout << "Труб нет в наличии!\n";
	}
	else
	{
		cout << "Название трубы: " << pipe.name << "\tДлина трубы: " << pipe.length << "\t\tДиаметр трубы: " << pipe.diameter << "\tВ ремонте: " << (pipe.repair ? "Да" : "Нет") << endl;
	}
}
// функция для редактирования статуса ремонта трубы
void RepairPipe(Pipe& pipe) // передаем в аргумент функции значения с помощью ссылок
{
	if (pipe.name == "None")
	{
		cout << "Труб нет в наличии!\n";
	}
	else
	{
		pipe.repair = !pipe.repair;
		cout << endl << "Статус трубы успешно изменен!";
		PrintAddPipe(pipe);
	}
}
// функция для просмотра введенных данных компрессорной станции на консоль
Station AddStation()
{
	Station station;
	cout << "Введите название компрессорной станции: ";
	cin.ignore(); // очищает кеш перед следующей строкой
	getline(cin, station.Name); // извлечение одной строки и записывание ее в переменную
	cin.ignore(100, '\n');
	cout << "Введите количество цехов: ";
	proverka_otric(station.workshops);
	cin.ignore(100, '\n');
	cout << "Введите количество цехов в работе: ";
	proverka_otric(station.workshopsInOperation);
	//cin.ignore(100, '\n');
	while (station.workshopsInOperation > station.workshops) // проверка, чтобы число цехов в работе не превышало общее число цехов
	{
		cout << "Число рабочих цехов не может превышать общее число цехов!\n";
		cout << "Ведите количество цехов в работе: ";
		proverka_otric(station.workshopsInOperation);
	}
	//cout<< ;
	cout << "Эффективность вашей трубы (в процентах): "<<(int)((double)station.workshopsInOperation/ station.workshops*100);
	proverka_double(station.efficiency);
	return station;
}
// функция для просмотра введенных данных компрессорной станции на консоль
void PrintAddStation(Station& station) // передаем в аргумент функции значения с помощью ссылок
{
	cout << endl << "Данные о компрессорной станции" << endl;
	if (station.Name == "None")
	{
		cout << "Компрессорных станций нет в наличии!\n";
	}
	else
	{
		cout << "Название компрессорной станции: " << station.Name << "\tКоличество цехов: " << station.workshops
			<< "\tЦехов в работе: " << station.workshopsInOperation << "\tЭффективность: "
			<< station.efficiency << endl;
	}
}
// функция для изменения количества цехов в работе
void EditStation(Station& station) // передаем в аргумент функции значения с помощью ссылок
{
	if (station.Name == "None")
	{
		cout << "Компрессорных станций нет в наличии!\n";
	}
	else
	{
		cout << "Введите количество цехов в работе: ";
		proverka_otric(station.workshopsInOperation);
		while (station.workshopsInOperation > station.workshops)
		{
			cout << "Число рабочих цехов не может превышать общее число цехов!\n";
			cout << "Введите количество цехов в работе: ";
			proverka_otric(station.workshopsInOperation);
		}
	}
	PrintAddStation(station);
}
// функция для сохранения данных о трубе и о компрессорной станции в файл
void SaveToFile(Pipe& pipe, Station& station) // передаем в аргумент функции значения с помощью ссылок
{
	ofstream fout("neftyanka.txt"); // создаём объект класса ofstream и связываем его с файлом neftyanka.txt
	// сохранение данных о трубе
	setlocale(LC_ALL, "rus");
	if (pipe.name == "None")
	{
		setlocale(LC_ALL, "rus");
		cout << "Нет данных о трубе!\n";
	}
	else
	{
		setlocale(LC_ALL, "rus");
		cout << "Данные о трубе успешно загружены в файл!\n";
		if (fout)
		{
			setlocale(LC_ALL, "rus");
			fout << "Данные о трубе\n";
			fout << pipe.name << endl;
			fout << pipe.length << endl;
			fout << pipe.diameter << endl;
			fout << pipe.repair << endl;
		}
	}
	// сохранение данных о компрессорной станции
	if (station.Name == "None")
	{
		setlocale(LC_ALL, "rus");
		cout << "Нет данных о компрессорной станции!\n";
	}
	else
	{
		setlocale(LC_ALL, "rus");
		cout << "Данные о компрессорной станции успешно загружены в файл!\n";
		if (fout)
		{
			setlocale(LC_ALL, "rus");
			fout << "Данные о компрессорной станции\n";
			fout << station.Name << endl;
			fout << station.workshops << endl;
			fout << station.workshopsInOperation << endl;
			fout << station.efficiency << endl;
		}
	}
	fout.close();
}
// функция для загрузки данных о трубе и о компрессорной станции из файла
void LoadFromFile(Pipe& pipe, Station& station) // передаем в аргумент функции значения с помощью ссылок
{
	ifstream fin("neftyanka.txt"); // создаем объекта класса ifstream и связываем его с файлом neftyanka.txt
	setlocale(LC_ALL, "rus");
	if (fin)
	{
		string information;
		int statys = 0;
		int perfomance = 0;
		while (getline(fin, information))
		{
			// выводим данные о трубе 
			setlocale(LC_ALL, "rus");
			if (information == "Данные о трубе")
			{
				setlocale(LC_ALL, "rus");
				cout << "\nДанные о трубе успешно загружены из файла!" << endl;
				setlocale(LC_ALL, "rus");
				cout << "\nДанные о трубе" << endl;
				setlocale(LC_ALL, "rus");
				getline(fin, pipe.name);
				setlocale(LC_ALL, "rus");
				cout << "Название трубы: " << pipe.name << endl;
				fin >> pipe.length;
				setlocale(LC_ALL, "rus");
				cout << "Длина трубы: " << pipe.length << endl;
				fin >> pipe.diameter;
				setlocale(LC_ALL, "rus");
				cout << "Диаметр трубы: " << pipe.diameter << endl;
				fin >> pipe.repair;
				setlocale(LC_ALL, "rus");
				cout << "В ремонте: " << pipe.repair << endl;
				statys += 1;
			}
			// выводим данные о компрессорной станции 
			setlocale(LC_ALL, "rus");
			if (information == "Данные о компрессорной станции")
			{
				setlocale(LC_ALL, "rus");
				cout << "\nДанные о компрессорной станции успешно загружены из файла!" << endl;
				setlocale(LC_ALL, "rus");
				cout << "\nДанные о компрессорной станции" << endl;
				setlocale(LC_ALL, "rus");
				getline(fin, station.Name);
				setlocale(LC_ALL, "rus");
				cout << "Название компрессорной станции: " << station.Name << endl;
				fin >> station.workshops;
				setlocale(LC_ALL, "rus");
				cout << "Количество цехов: " << station.workshops << endl;
				fin >> station.workshopsInOperation;
				setlocale(LC_ALL, "rus");
				cout << "Цехов в работе: " << station.workshopsInOperation << endl;
				fin >> station.efficiency;
				setlocale(LC_ALL, "rus");
				cout << "Эффективность: " << station.efficiency << endl;
				perfomance += 1;
			}
		}
		if (statys == 0)
		{
			setlocale(LC_ALL, "rus");
			cout << "\nНет данных о трубе!" << endl;
		}
		if (perfomance == 0)
		{
			setlocale(LC_ALL, "rus");
			cout << "\nНет данных о компрессорной станции!" << endl;
		}
		fin.close();
	}
}
// функция создания меню и первоначальной картины программы
int main()
{
	Pipe pipe0;
	Station station0;
	int pynkt = 0;
	while (true) {
		setlocale(LC_ALL, "rus");
		cout << endl << "_____________________" << endl;
		cout << endl << "\tМеню:" << endl;
		cout << endl << "|____________________|" << endl;
		cout << "1. Добавить трубу" << endl;
		cout << "2. Добавить компрессорную станцию" << endl;
		cout << "3. Просмотр всех объектов" << endl;
		cout << "4. Редактировать трубу" << endl;
		cout << "5. Редактировать компрессорную станцию" << endl;
		cout << "6. Сохранить данные в файл" << endl;
		cout << "7. Загрузить данные из файла" << endl;
		cout << "0. Выход" << endl;
		cout << endl << "Введите цифру от 0 до 7: ";
		cin >> pynkt;
		if (cin.fail() || pynkt < 0 || pynkt > 7)
		{
			cout << "Введено неверное значение, введите цифру от 0 до 7:" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		//check_input(num);
		switch (pynkt)
		{
		case 1: // добавление трубы
		{
			pipe0 = AddPipe();
			PrintAddPipe(pipe0);
			break;
		}
		case 2: // добавление компрессорной станции
		{
			station0 = AddStation();
			PrintAddStation(station0);
			break;
		}
		case 3: // просмотр объектов
		{
			PrintAddPipe(pipe0);
			PrintAddStation(station0);
			break;
		}
		case 4: // редактирование трубы
		{
			RepairPipe(pipe0);
			break;
		}
		case 5: // редактирование компрессорной станции
		{
			EditStation(station0);
			break;
		}
		case 6: // сохранение данных о трубе и компрессорной станции в файл
		{
			SaveToFile(pipe0, station0);
			break;
		}
		case 7: // загрузка данных о трубе и компрессорной станции из файла
		{
			LoadFromFile(pipe0, station0);
			break;
		}
		case 0: // выход из программы
		{
			return false;
			break;
		}
		default:
		{
			cout << endl << "Введено неверное значение, введите цифру от 0 до 7:" << endl;
			break;
		}
		}
	}
	return 0;
}