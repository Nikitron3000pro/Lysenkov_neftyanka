#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Pipe
{
	string pipe_name = "None";
	double pipe_length = 0.0;
	int pipe_diameter = 0;
	bool pipe_repair = false;
};
struct Station
{
	string station_name = "None";
	int station_workshops = 0;
	int station_workshopsInOperation = 0;
	double station_efficiency = 0.0;
};
int check_int(int& int_data)
{
	cin >> int_data;
	while (cin.fail() || cin.peek() != '\n' || int_data <= 0)
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nВведено неверное значение, введите цифру от 0 до 7:\n";
		cin >> int_data;
	}
	return int_data;
}

int check_input(int& input_data)
{
	cin >> input_data;
	while (cin.fail() || cin.peek() != '\n' || input_data < 0 || input_data > 7)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "\nВведено неверное значение, введите цифру от 0 до 7:\n";
		cin >> input_data;
	}
	return input_data;
}

double check_double(double& double_data)
{
	cin >> double_data;
	while (cin.fail() || cin.peek() != '\n' || double_data <= 0)
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nВведено неверное значение, введите цифру от 0 до 7:\n";
		cin >> double_data;
	}
	return double_data;
}
double check2_double(double& efficiency_data)
{
	cin >> efficiency_data;
	while (cin.fail() || cin.peek() != '\n' || (efficiency_data < 0.0) || (efficiency_data > 1.0))
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nВведите эффективность от 0.0 до 1.0 \n";
		cin >> efficiency_data;
	}
	return efficiency_data;
}
bool check_bool(bool& bool_data)
{
	cin >> bool_data;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "\nВведено неверное значение, введите цифру от 0 до 7:\n";
		cin >> bool_data;
	}
	return bool_data;
}
Pipe AddPipe()
{
	Pipe new_pipe;
	cout << endl << "Добавление новой трубы..." << endl;
	cout << "Введите название трубы: ";
	cin.ignore();
	getline(cin, new_pipe.pipe_name);
	cout << "Введите длину трубы (в км): ";
	check_double(new_pipe.pipe_length);
	cout << "Введите диаметр трубы (в м): ";
	check_int(new_pipe.pipe_diameter);
	cout << "Введите статус трубы: ";
	check_bool(new_pipe.pipe_repair);
	return new_pipe;
}


void PrintAddPipe(Pipe& new_pipe)
{
	cout << endl << "Информация о трубе..." << endl;
	if (new_pipe.pipe_name == "None")
	{
		cout << "Труб нет в наличии!\n";
	}
	else
	{
		cout << "Название трубы: " << new_pipe.pipe_name << "\tДлина трубы: " << new_pipe.pipe_length
			<< "\tДиаметр трубы: " << new_pipe.pipe_diameter << "\tВ ремонте: " << new_pipe.pipe_repair << endl;
	}
}
void RepairPipe(Pipe& new_pipe)
{
	if (new_pipe.pipe_name == "None")
	{
		cout << "Труб нет в наличии!\n";
	}
	else
	{
		new_pipe.pipe_repair = !new_pipe.pipe_repair;
		cout << endl << "Статус трубы успешно изменен!";
		PrintAddPipe(new_pipe);
	}
}
Station AddStation()
{
	Station new_station;
	cout << endl << "Добавление новой компрессорной станции..." << endl;
	cout << "Введите название компрессорной станции: ";
	cin.ignore();
	getline(cin, new_station.station_name);
	cout << "Введите количество цехов: ";
	check_int(new_station.station_workshops);
	cout << "Введите количество цехов в работе: ";
	check_int(new_station.station_workshopsInOperation);
	while (new_station.station_workshopsInOperation > new_station.station_workshops)
	{
		cout << "Число рабочих цехов не может превышать общее число цехов!\n";
		cout << "Ведите количество цехов в работе: ";
		check_int(new_station.station_workshopsInOperation);
	}
	cout << "Введите эффективность (некий показатель от 0 до 1): ";
	check2_double(new_station.station_efficiency);
	return new_station;
}

void PrintAddStation(Station& new_station)
{
	cout << endl << "Информаций о компрессорной станции..." << endl;
	if (new_station.station_name == "None")
	{
		cout << "Компрессорных станций нет в наличии!\n";
	}
	else
	{
		cout << "Название компрессорной станции: " << new_station.station_name << "\t:Количество цехов: " << new_station.station_workshops
			<< "\tЦехов в работе: " << new_station.station_workshopsInOperation << "\tЭффективность: "
			<< new_station.station_efficiency << endl;
	}
}
void EditStation(Station& new_station)
{
	if (new_station.station_name == "None")
	{
		cout << "Компрессорных станций нет в наличии!\n";
	}
	else
	{
		cout << "Введите количество цехов в работе: ";
		check_int(new_station.station_workshopsInOperation);
		while (new_station.station_workshopsInOperation > new_station.station_workshops)
		{
			cout << "Число рабочих цехов не может превышать общее число цехов!\n";
			cout << "Введите количество цехов в работе: ";
			check_int(new_station.station_workshopsInOperation);
		}
	}
	PrintAddStation(new_station);
}

void FileRecord(Pipe& pipe_data, Station& station_data)
{
	ofstream fout("info");
	if (pipe_data.pipe_name == "None")
	{
		cout << "Нет информации о трубе!\n";
	}
	else
	{
		cout << "Данные о трубе успешно загружены в файл!\n";
		if (fout)
		{
			fout << "Информация о трубе...\n";
			fout << pipe_data.pipe_name << endl;
			fout << pipe_data.pipe_length << endl;
			fout << pipe_data.pipe_diameter << endl;
			fout << pipe_data.pipe_repair << endl;
		}
	}
	if (station_data.station_name == "None")
	{
		cout << "Нет информации о компрессорной станции!\n";
	}
	else
	{
		cout << "Данные о компрессорной станции успешно загружены в файл!\n";
		if (fout)
		{
			fout << "Информация о компрессорной станции...\n";
			fout << station_data.station_name << endl;
			fout << station_data.station_workshops << endl;
			fout << station_data.station_workshopsInOperation << endl;
			fout << station_data.station_efficiency << endl;
		}
	}
	fout.close();
}
void FileOutput(Pipe& pipe_data, Station& station_data)
{
	ifstream fin("info");
	if (fin)
	{
		string zero_mean;
		int pipe_flag = 0;
		int station_flag = 0;
		while (getline(fin, zero_mean))
		{
			if (zero_mean == "Информация о трубе...")
			{
				cout << "\nИнформация о трубе успешно загружена из файла!" << endl;
				cout << "\nИнформация о трубе..." << endl;
				getline(fin, pipe_data.pipe_name);
				cout << "Название трубы: " << pipe_data.pipe_name << endl;
				fin >> pipe_data.pipe_length;
				cout << "Длина трубы: " << pipe_data.pipe_length << endl;
				fin >> pipe_data.pipe_diameter;
				cout << "Диаметр трубы: " << pipe_data.pipe_diameter << endl;
				fin >> pipe_data.pipe_repair;
				cout << "Статус трубы: " << pipe_data.pipe_repair << endl;
				pipe_flag += 1;
			}
			if (zero_mean == "Информация о компрессорной станции...")
			{
				cout << "\nИнформация о компрессорной станции успешно загружена из файла!" << endl;
				cout << "\nИнформация о компрессорной станции..." << endl;
				getline(fin, station_data.station_name);
				cout << "Название компрессорной станции: " << station_data.station_name << endl;
				fin >> station_data.station_workshops;
				cout << "Число цехов:: " << station_data.station_workshops << endl;
				fin >> station_data.station_workshopsInOperation;
				cout << "Число цехов в работе: " << station_data.station_workshopsInOperation << endl;
				fin >> station_data.station_efficiency;
				cout << "Эффективность: " << station_data.station_efficiency << endl;
				station_flag += 1;
			}
		}
		if (pipe_flag == 0)
		{
			cout << "\nНет информации о трубе!" << endl;
		}
		if (station_flag == 0)
		{
			cout << "\nНет информации о компрессорной станции!" << endl;
		}
		fin.close();
	}
}
int main()
{
	Pipe pipe0;
	Station station0;
	int num = 0;
	while (true) {
		setlocale(LC_ALL, "rus");
		cout << endl << "Меню:" << endl;
		cout << "1. Добавить трубу" << endl;
		cout << "2. Добавить компрессорную станцию" << endl;
		cout << "3. Просмотр всех объектов" << endl;
		cout << "4. Редактировать трубу" << endl;
		cout << "5. Редактировать компрессорную станцию" << endl;
		cout << "6. Сохранить данные в файл" << endl;
		cout << "7. Загрузить данные из файла" << endl;
		cout << "0. Выход" << endl;
		cout << endl << "Please, enter the command number: ";
		cin >> num;
		if (cin.fail() || num < 0 || num > 7)
		{
			cout << "Введено неверное значение, введите цифру от 0 до 7:" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		check_input(num);
		switch (num)
		{
		case 1:
		{
			pipe0 = AddPipe();
			PrintAddPipe(pipe0);
			break;
		}
		case 2:
		{
			station0 = AddStation();
			PrintAddStation(station0);
			break;
		}
		case 3:
		{
			PrintAddPipe(pipe0);
			PrintAddStation(station0);
			break;
		}
		case 4:
		{
			RepairPipe(pipe0);
			break;
		}
		case 5:
		{
			EditStation(station0);
			break;
		}
		case 6:
		{
			FileRecord(pipe0, station0);
			break;
		}
		case 7:
		{
			FileOutput(pipe0, station0);
			break;
		}
		case 0:
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
