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
       
        cout << "\t\t\t����:" << endl << endl;
        cout << "\t 1. �������� ���������" << endl;
        cout << "\t 2. ������� ���������" << endl;
        cout << "\t 3. ������� ����������" << endl;
        cout << "\t 4. ����� ��������� �� ����� � �������" << endl;
        cout << "\t 5. ����� ��� ����������" << endl;
        cout << "\t 6. ����� c �����������" << endl << endl;
        cout << "\t \t�������� �������: ";
        cin >> number;

        switch (number)
        {
      
        case 1:
        {
            setlocale(LC_ALL, "Rus");
            Worker newWorker;
            cout <<  "\n������� ���: ";
            cin >> newWorker.firstname;
            cout << "������� �������: ";
            cin >> newWorker.surname;
            cout << "�������� � 1 ���: ";
            cin >> newWorker.rate;
            cout << "������������ ����: ";
            cin >> newWorker.hour;
            add_worker(newWorker);
            break;
        }
        case 2:
        {
            string name, surname;
            cout << "\n������� ���: ";
            cin >> name;
            cout << "������� �������: ";
            cin >> surname;
            delete_worker(name, surname);
            break;
        }
        case 3:
        {
            cout << "\n--------���-----�������-------������---����-----��������-------\n\n";
            print();
            cout << "\n---------------------------------------------------------------\n\n";
            break;
        }
        case 4:
        {
            string name, surname;
            cout << "\n������� ���: ";
            cin >> name;
            cout << "������� �������: ";
            cin >> surname;
            cout << "\n--------���-----�������-------������---����-----��������-------\n\n";
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
        cout << "\n�������� �������� � ���� ������\n" << endl;
    }
    else
        cout << "���� �� ������" << endl;
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
                cout << "\n�������� ������ �� ���� ������\n" << endl;
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
        cout << "���� �� ������" << endl;
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
        cout << "���� �� ������" << endl;
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
        cout << "�������� �� ������ � ���� ������" << endl;
        file.close();
    }
    else
        cout << "���� �� ������" << endl;
}