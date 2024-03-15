#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Worker 
{
    string firstname;
    string surname;
    double rate;
    int hour;

};

void add_worker(const Worker& newWorker);
void print();  
void delete_worker(const string& firstname, const string& surname);
void searchname(const string& firstname, const string& surname);


int main()
{
    int number;
    setlocale(LC_ALL, "Rus");

    while (true)
    {
       
        cout << "\t\t\tМеню:" << endl << endl;
        cout << "\t 1. Добавить работника" << endl;
        cout << "\t 2. Удалить работника" << endl;
        cout << "\t 3. Вывести работников" << endl;
        cout << "\t 4. Найти работника по имени и фамилии" << endl;
        cout << "\t 5. Выйти без сохранения" << endl;
        cout << "\t 6. Выйти c сохранением" << endl << endl;
        cout << "\t \tВыберите команду: ";
        cin >> number;

        switch (number)
        {
      
        case 1:
        {
            setlocale(LC_ALL, "Rus");
            Worker newWorker;
            cout <<  "\nВведите имя: ";
            cin >> newWorker.firstname;
            cout << "Введите фамилию: ";
            cin >> newWorker.surname;
            cout << "Зарплата в 1 час: ";
            cin >> newWorker.rate;
            cout << "Отработанные часы: ";
            cin >> newWorker.hour;
            add_worker(newWorker);
            break;
        }
        case 2:
        {
            string name, surname;
            cout << "\nВведите имя: ";
            cin >> name;
            cout << "Введите фамилию: ";
            cin >> surname;
            delete_worker(name, surname);
            break;
        }
        case 3:
        {
            cout << "\n--------Имя-----Фамилия-------Ставка---Часы-----Зарплата-------\n\n";
            print();
            cout << "\n---------------------------------------------------------------\n\n";
            break;
        }
        case 4:
        {
            string name, surname;
            cout << "\nВведите имя: ";
            cin >> name;
            cout << "Введите фамилию: ";
            cin >> surname;
            cout << "\n--------Имя-----Фамилия-------Ставка---Часы-----Зарплата-------\n\n";
            searchname(name, surname);
            cout << "\n---------------------------------------------------------------\n\n";
            break;
        }
        case 5:
        {
            remove("workers.txt");
        }

        case 6:
            return 0;
        default:
            cout << "None" << endl;
        }
    }
}




void add_worker(const Worker& newWorker) 
{
    ofstream file("workers.txt", ios::app);
    if (file.is_open())
    {
        file << newWorker.firstname << "\t" << newWorker.surname << "  \t" << newWorker.rate << "\t" 
            << newWorker.hour << "\t" << newWorker.rate * newWorker.hour << endl;
        file.close();
        cout << "\nРаботник добавлен в базу данных\n" << endl;
    }
    else
        cout << "Файл не открыт" << endl;
}

void delete_worker(const string& name, const string& surname)
{
    ifstream file("workers.txt");
    ofstream file1("workers1.txt");
    if (file.is_open() && file1.is_open())
    {
        string line;
        while (getline(file, line))
        {
            size_t found = line.find(name + "\t" + surname);
            if (found != string::npos) {
                cout << "\nРаботник удален из базы данных\n" << endl;
            }


            if (found == string::npos)
            {
                file1 << line << endl;
            }
        }
        file.close();
        file1.close();
        remove("workers.txt");
        rename("workers1.txt", "workers.txt");
    }
    else
        cout << "Файл не открыт" << endl;
}

void print()  
{
    ifstream file("workers.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        { 
            cout << "\t" << line << endl;
        }
        file.close();
    }
    else
        cout << "Файл не открыт" << endl;
}

void searchname(const string& name, const string& surname)
{
    ifstream file("workers.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            size_t found = line.find(name + "\t" + surname);
            if (found != string::npos)
            {
                cout <<"\t" << line << endl;
                return;
            }
        }
        cout << "Работник не найден в базе данных" << endl;
        file.close();
    }
    else
        cout << "Файл не открыт" << endl;
}