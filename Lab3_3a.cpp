/*Радкевич Ю.С. 91 группа. Задача 3a.
Реализовать шаблон класса стек (Stack<X>), хранящий элементы произвольного типа.Реализация стека с помощью массива
Класс должен в обязательном порядке содержать методы :
Вычисление длины стека;
Добавление нового элемента в голову стека;
Получение элемента из головы стека;
Поиск элемента в стеке;
Печать стека.
*/

#include <Windows.h>
#include <iostream>
#include <string>
#include <exception>
#define SIZE 100


using namespace std;

template <typename T>
class Stack {
private:
	T stack[SIZE];
	int Top = -1;
public:
	int GetTop() const{
		return Top;
	}

	int GetLength() const{
		return Top+1;
	}

	void Push(T newElem) {
		if (Top < SIZE - 1) {
			stack[Top + 1] = newElem;
			++Top;
		}
		else
			throw out_of_range("Стек полон!");
	}

	//просмотр верхнего элемента
	T GetTopElem() const{
		if (Top >= 0) {
			return stack[Top];
		}
		else
			throw out_of_range("Стек пуст!");
	}

	//получить верхний элемент
	T Pop() {
		if (Top >= 0) {
			T temp = stack[Top];
			stack[Top] = T();
			--Top;
			return temp;
		}
		else
			throw out_of_range("Стек пуст!");
	}

	int FindElement(T el) const{
		int i;
		for (i = 0; i <= Top && stack[i] != el; ++i);
		if (i <= Top) 
			return i;
		else
			throw out_of_range("Такого элемента нет в стеке!");
	}

	void PrintStack() const{
		if (Top == -1)
			cout << "Стек пуст" << endl;
		else
			for (int i = Top; i >=0; --i)
				cout << stack[i] << endl;
	}

	void AddElem() {
		T el;
		cout << "Введите элемент: ";
		cin >> el;
		Push(el);
	}

	int Find() const{
		T el;
		cout << "Введите элемент: ";
		cin >> el;
		return FindElement(el);
	}
};

struct Student {
	string surname;
	int Course;
	int Group;
};

ostream& operator <<(ostream& s, Student stud) {
	return s << stud.surname <<" Курс: " << stud.Course <<" Группа: "<< stud.Group<<endl;
}

bool operator !=(const Student& st1, const Student& st2) {
	return !(st1.surname == st2.surname && st1.Course == st2.Course && st1.Group == st2.Group);
}



istream& operator >>(istream& s, Student& stud) {
	cout <<endl<< "Введите фамилию студента: ";
	s >> stud.surname;
	do {
		cout << "Введите курс: ";
		s >> stud.Course;
	} while (stud.Course < 1 || stud.Course>4);

	cout << "Введите группу: ";
	s >> stud.Group;
	return s;
}

int menuType() {
	int item;
	do {
		cout << "Выберете тип данных, хранящихся в стеке" << endl;
		cout << "1 - цифры" << endl << "2 - строки" << endl << "3 - студенты" << endl<<"0 - выход" << endl;;
		cin >> item;
	} while (item < 0 || item>3);
	return item;
}

int menuAction() {
	int item;
	do {
		cout<< "1 - добавить элемент" << endl
			<< "2 - получить верхний элемент" << endl 
			<< "3 - поиск элемента" << endl
			<< "4 - печать стека" << endl 
			<< "5 - длина стека" << endl 
			<< "6 - просмотреть верхний элемент" << endl
			<< "0 - окончить работу с выбранным типом данных" << endl;
		cin >> item;
	} while (item < 0 || item>6);
	return item;
}

template <typename T>
void DoAction(Stack<T> s) {
	int item = menuAction();
	while (item != 0) {
		try {
			switch (item) {
			case 1:
				s.AddElem();
				break;
			case 2:
				cout <<"Верхний элемент стека: "<<endl<< s.Pop() << endl;
				break;
			case 3:
				cout <<"Номер элемента: "<< s.Find() << endl;
				break;
			case 4:
				cout << "Стек:" << endl;
				s.PrintStack();
				break;
			case 5:
				cout << "Длина стека:" << s.GetLength() << endl;
				break;
			case 6:
				cout << "Верхний элемент:" << s.GetTopElem() << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << e.what() <<endl;
		}
		item = menuAction();
	}
}

int main(){
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	Stack<int> sInt = Stack<int>();
	Stack<string> sStr = Stack<string>();
	Stack<Student> sStud = Stack<Student>();

	int item = menuType();
	while (item != 0) {
		switch (item) {
		case 1:
			DoAction(sInt);
			break;
		case 2:
			DoAction(sStr);
			break;
		case 3:
			DoAction(sStud);
		}
		item = menuType();
	}
	getchar();

}

