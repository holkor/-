


#include <iostream>
#include <string>
#include <vector>
using namespace std;



// Задача 1. Student, Aspirant
/*class Student {
public:
	string firstName, lastName, group;
	double averageMark;
	
	void infoStudent() {
		cout << "Студент:  " << firstName << " " << lastName << endl;
		cout << "Группа: " << group << endl;
	}
	void getScholarship() {
		if (averageMark == 5) { cout << "2000\n"; }
		else { cout << "1900\n"; }
	}
};
class Aspirant : public Student {
public:
	void getScholarship() {
		if (averageMark == 5) { cout << "2500\n"; }
		else { cout << "2200 \n"; }
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	Student one;
	one.firstName = "Дмитрий";
	one.lastName = "Карчев";
	one.group = "ПИэ";
	one.averageMark = (5 + 5 + 5)/3;

	one.infoStudent();
	one.getScholarship();

	Aspirant one1;
	one1.firstName = "Глеб";
	one1.lastName = "Ефимов";
	one1.group = "ФАИД";
	one1.averageMark = (4 + 5 + 5) / 3;

	one1.infoStudent();
	one1.getScholarship();
	return 0;
}*/



// Задача 2. User, Worker, Driver
/*
class User {
private:
	string name;
	int age;
public:
	void setName(string name) {
		this->name = name;
	}
	void getName() {
		cout << name;
	}
	void setAge(int age) {
		this->age = age;
	}
	void getAge() {
		cout << age;
	}
};
class Worker : public User {
private: 
	int salary;
public:
	void setSalaru(int salary) {
		this->salary = salary;
	}
	int getSalaru() {
		return salary;
	}
};
class Driver : public Worker {
private:
	int drivingexperience;
	char drivingcategory;
};
int main() {
	int b;
	setlocale(LC_ALL, "RUS");
	Worker one;
	one.setName("Иван");
	one.setAge(25);
	one.setSalaru(1000);
	Worker two;
	two.setName("Вася");
	two.setAge(26);
	two.setSalaru(2000);

	b = one.getSalaru() + two.getSalaru();
	cout << b / 2;

		return 0;
}
*/



// Задача 3. Animal
/*
class Animal {
protected:
	string name;
public:
	Animal(const string& _name) : name(_name) {}

	virtual void makeNoise() {
		cout << "Animal makes noise" << endl;
	}

	virtual void eat() {
		cout << "Animal eats food" << endl;
	}

	virtual string getDescription() {
		return "This is an animal";
	}
	string getName() const {
		return name;
	}
};

class Dog : public Animal {
public:
	Dog(const string& _name) : Animal(_name) {}
	void makeNoise() override {
		cout << "Собакак гавгает" << endl;
	}

	void eat() override  {
		cout << "Собака ест кости" << endl;
	}

	string getDescription() override {
		return "Это собака";
	}
};

class Cat : public Animal {
public:
	Cat(const string&_name) : Animal(_name) {}
	void makeNoise() override {
		cout << "Кот мяукает" << endl;
	}

	void eat() override {
		cout << "Кот ест рыбу" << endl;
	}

	string getDescription() override {
		return "Это кот";
	}
};
class Bear : public Animal {
public:
	Bear(const string& _name) : Animal(_name) {}
	void makeNoise() override {
		cout << "Медведь рычит" << endl;
	}

	void eat() override {
		cout << "Медведь ест мёд" << endl;
	}

	string getDescription() override {
		return "Это медведь";
	}
};

class Vet {
public:
	void treatAnimal(Animal& animal) {
		cout << "Имя: " << animal.getName() << endl;
		cout << "Описание: " << animal.getDescription() << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Dog dog("Герда");
	Cat cat("Яшка");
	Bear bear("Гриша");

	Vet veterinarian;

	veterinarian.treatAnimal(dog);
	veterinarian.treatAnimal(cat);
	veterinarian.treatAnimal(bear);

	return 0;
}
*/



// Задача 4. Фигуры
/*
class Shape {
protected:
	string color;
public:
	Shape(const string& c) : color(c) {}
	
	virtual void draw() {
		cout << "Рисуем фигуру цвета " << color << endl;
	}
};
class Circle : public Shape{
private:
	int radius;

public:
	Circle (const string& c, int r) : Shape(c), radius (r){}

	void draw() override{
		cout << "Рисуем круг радиусом " << radius << " и цвета " << color << endl; 
	}
};

class Rectangle : public Shape {
private:
	int width;
	int height;

public:
	Rectangle(const string& c, int w, int h) : Shape(c), width(w), height(h){}

	void draw() override {
		cout << "Рисуем прямоугольник шириной " << width << ", высотой " << height << "и цветом"<< color << endl;
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	Shape shape1("red");
	Circle circle1("white", 56);
	Rectangle rectangle1("black", 15, 10);
	shape1.draw();
	circle1.draw();
	rectangle1.draw();
}
*/



// Задача 5. Интернет магазин
/*
class Item {
public:
	string name;
	int price;
	double rating;
	Item(string n, int p, double r) {
		name = n;
		price = p;
		rating = r;
	}
};
class Category {
public:
	string name_category;
	vector <Item> products;

	Category(string n_c) {
		name_category = n_c;
	}

	void addProduct(Item p) {
		products.push_back(p);
	}
};
class Basket {
public:
	vector <Item> products;

	void addProduct(Item p) {
		products.push_back(p);
	}
};
class User {
public:
	string login;
	string password;
	Basket basket;

	User(string l, string p) {
		login = l;
		password = p;
	}

	void addProductInBasket(Item p) {
		basket.addProduct(p);
	}
};

int main() {
	int i;
	setlocale(LC_ALL, "ru");

	Category item1("Электроника");
	item1.addProduct(Item("Телефон", 6000, 4.5));
	item1.addProduct(Item("Телевизор", 10000, 4.1));

	Category item2("Одежда");
	item2.addProduct(Item("Футболка", 1500, 4.2));
	item2.addProduct(Item("Джинсы", 3800, 4.3));

	User user1("Дима", "qwe123hli");
	user1.addProductInBasket(Item("Телефон", 6000, 4.5));
	user1.addProductInBasket(Item("Джинсы", 3800, 4.3));

	User user2("Аня", "wrqg12fas");
	user2.addProductInBasket(Item("Телефон", 6000, 4.5));
	user2.addProductInBasket(Item("Футболка", 1500, 4.2));

	cout << "Каталог продуктов:" << endl;
	cout << "Категория: " << item1.name_category << endl;
	for (Item p : item1.products) {
		cout << p.name << "    " << p.price << "руб \t Рейтинг: " << p.rating << endl;	
	}
	cout << endl << "Категория: " << item2.name_category << endl;
	for (Item p : item2.products) {
		cout << p.name << "    " << p.price << "руб \t Рейтинг: " << p.rating << endl;
	}

	cout << endl <<"Покупки пользователь: " << endl;
	cout << "Пользователь: " << user1.login << endl;
	for (Item p : user1.basket.products) {
		cout << p.name << "    " << p.price << "руб \t Рейтинг: " << p.rating << endl;
	}

	cout << endl << "Пользователь: " << user2.login << endl;
	for (Item p : user2.basket.products) {
		cout << p.name << "    " << p.price << "руб \t Рейтинг: " << p.rating << endl;
	}
	return 0;
}
*/