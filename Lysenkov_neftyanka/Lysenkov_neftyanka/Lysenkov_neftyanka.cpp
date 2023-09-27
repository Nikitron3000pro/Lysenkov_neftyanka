#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
// Структура, описывающая трубу
struct Pipe {
    string name;
    double length;
    double diameter;
    bool inRepair;
    // Конструктор для инициализации трубы
    Pipe(const string& _name, double _length, double _diameter, bool _inRepair)
        : name(_name), length(_length), diameter(_diameter), inRepair(_inRepair) {}
};
// Структура, описывающая компрессорную станцию
struct CompressorStation {
    string name;
    int numWorkshops;
    int numWorkshopsInOperation;
    double efficiency;
    // Конструктор для инициализации компрессорной станции
    CompressorStation(const string& _name, int _numWorkshops, int _numWorkshopsInOperation, double _efficiency)
        : name(_name), numWorkshops(_numWorkshops), numWorkshopsInOperation(_numWorkshopsInOperation), efficiency(_efficiency) {}
};
// Список для хранения труб
list<Pipe> pipes;
// Список для хранения компрессорной станции
list<CompressorStation> stations;

// Функция для добавления новой новой трубы
void AddPipe() {
    string name;
    double length, diameter;
    bool inRepair;

    cout << "Введите название трубы: ";
    cin >> name;
    cout << "Введите длину трубы (в км): ";
    cin >> length;
    cout << "Введите диаметр трубы (в метрах): ";
    cin >> diameter;
    cout << "Труба находится в ремонте? (1 - да, 0 - нет): ";
    cin >> inRepair;
    

    Pipe pipe(name, length, diameter, inRepair);
    pipes.push_back(pipe);
    cout << "Труба успешно добавлена!" << endl;
}
// Функция для добавления новой компрессорной станции
void AddCompressorStation() {
    string name;
    int numWorkshops, numWorkshopsInOperation;
    double efficiency;

    cout << "Введите название компрессорной станции: ";
    cin >> name;
    cout << "Введите количество цехов: ";
    cin >> numWorkshops;
    cout << "Введите количество цехов в работе: ";
    cin >> numWorkshopsInOperation;
    cout << "Введите эффективность: ";
    cin >> efficiency;

    CompressorStation CompressorStation(name, numWorkshops, numWorkshopsInOperation, efficiency);
    stations.push_back(CompressorStation);
    cout << "Компрессорная станция успешно добавлена!" << endl;
}
// Функция для просмотра всех объектов
void ViewPipes() {
    if (pipes.empty()) {
        cout << "Список труб пуст." << endl;
    }
    else {
        cout << "Список труб:" << endl;
        for (const Pipe& pipe : pipes) {
            cout << "Название: " << pipe.name << endl;
            cout << "Длина: " << pipe.length << " км" << endl;
            cout << "Диаметр: " << pipe.diameter << " м" << endl;
            cout << "Находится в ремонте: " << (pipe.inRepair ? "Да" : "Нет") << endl;
            cout << "------------------------" << endl;
        }
    }
    if (stations.empty()) {
        cout << "Список компрессорных станций пуст." << endl;
    }
    else {
        cout << "Список компрессорных станций:" << endl;
        for (const CompressorStation& CompressorStation : stations) {
            cout << "Название: " << CompressorStation.name << endl;
            cout << "Количество цехов: " << CompressorStation.numWorkshops << " км" << endl;
            cout << "Количество цехов в работе: " << CompressorStation.numWorkshopsInOperation << " м" << endl;
            cout << "Эффективность: " << CompressorStation.efficiency << endl;
            cout << "------------------------" << endl;
        }
    }
}

// Функция для редактирования признака "в ремонте" для трубы
void EditPipe() {
    auto it = pipes.begin();
    it->inRepair = !it->inRepair;
    cout << "Статус ремонта для трубы  успешно изменен." << endl;
 }
// Функция для запуска и остановки цеха в компрессорной станции
void toggleWorkshopStatus() {
    if (stations.empty()) {
        cout << "Список компрессорных станций пуст. Нельзя выполнить это действие." << endl;
        return;
    }
    auto it = stations.begin();
    int newNumWorkshopsInOperation;
    cout << "Введите новое количество цехов в работе: ";
    cin >> newNumWorkshopsInOperation;
    it->numWorkshopsInOperation = newNumWorkshopsInOperation;
    cout << "Статус цеха в компрессорной станции изменен." << endl;
}
// Функция для сохранения данных в файл
void SaveToFile() {
    ofstream file("pipes.txt");
    if (file.is_open()) {
        for (const Pipe& pipe : pipes) {
            file << pipe.name << " " << pipe.length << " " << pipe.diameter << " " << pipe.inRepair << endl;
        }
        for (const CompressorStation& CompressorStation : stations) {
            file << CompressorStation.name << " " << CompressorStation.numWorkshops << " " << CompressorStation.numWorkshopsInOperation << " " << CompressorStation.efficiency << endl;
        }
        file.close();
        cout << "Данные успешно сохранены в файл pipes.txt." << endl;
    }
    else {
        cout << "Ошибка при открытии файла для сохранения данных." << endl;
    }
}
void LoadFromFile() {
    pipes.clear(); // Очищаем текущий список труб
    ifstream inputFile("pipes.txt"); 
    if (!inputFile.is_open()) {
        cerr << "Ошибка при открытии файла." << endl;
    }
    if (inputFile.is_open()) {
        string name;
        double length, diameter;
        bool inRepair;

        while (inputFile >> name >> length >> diameter >> inRepair) {
            Pipe pipe(name, length, diameter, inRepair);
            pipes.push_back(pipe);
        }
        inputFile.close();
        cout << "Данные успешно загружены из файла pipes.txt." << endl;
    }
    else {
        cout << "Ошибка при открытии файла для загрузки данных." << endl;
    }
    if (inputFile.is_open()) {
        string name;
        int numWorkshops, numWorkshopsInOperation;
        double efficiency;
        while (inputFile >> name >> numWorkshops >> numWorkshopsInOperation >> efficiency) {
            CompressorStation CompressorStation(name, numWorkshops, numWorkshopsInOperation, efficiency);
            stations.push_back(CompressorStation);
        }
        inputFile.close();
        cout << "Данные успешно загружены из файла pipes.txt." << endl;
    }
    if (pipes.empty()) {
        cout << "Список труб пуст." << endl;
    }
    else {
        cout << "Список труб:" << endl;
        for (const Pipe& pipe : pipes) {
            cout << "Название: " << pipe.name << endl;
            cout << "Длина: " << pipe.length << " км" << endl;
            cout << "Диаметр: " << pipe.diameter << " м" << endl;
            cout << "Находится в ремонте: " << (pipe.inRepair ? "Да" : "Нет") << endl;
            cout << "------------------------" << endl;
        }
    }
    if (stations.empty()) {
        cout << "Список компрессорных станций пуст." << endl;
    }
    else {
        cout << "Список компрессорных станций:" << endl;
        for (const CompressorStation& CompressorStation : stations) {
            cout << "Название: " << CompressorStation.name << endl;
            cout << "Количество цехов: " << CompressorStation.numWorkshops << " км" << endl;
            cout << "Количество цехов в работе: " << CompressorStation.numWorkshopsInOperation << " м" << endl;
            cout << "Эффективность: " << CompressorStation.efficiency << endl;
            cout << "------------------------" << endl;
        }
    }
}
int main() {
    int choice;
    setlocale(LC_ALL, "rus");
    while (true) {
        cout << "------------------------------" << endl;
        cout << "Меню:" << endl;
        cout << "------------------------------" << endl;
        cout << "1. Добавить трубу" << endl;
        cout << "2. Добавить компрессорную станцию" << endl;
        cout << "3. Просмотр всех объектов" << endl;
        cout << "4. Редактировать трубу" << endl;
        cout << "5. Редактировать компрессорную станцию" << endl;
        cout << "6. Сохранить в файл" << endl;
        cout << "7. Загрузить из файла" << endl;
        cout << "8. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1:
            AddPipe();
            break;
        case 2:
            AddCompressorStation();
            break;
        case 3:
            ViewPipes();
            break;
        case 4:
            EditPipe();
            break;
        case 5:
            toggleWorkshopStatus();
            break;
        case 6:
            SaveToFile();
            break;
        case 7:
            LoadFromFile();
            break;
        case 8:
            cout << "Программа завершена." << endl;
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    }
    return 0;
}
