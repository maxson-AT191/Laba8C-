#include <iostream>
#include <forward_list>
#include <list>
#include <iterator>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	void push_back(T data);
	int GetSize() { return Size; }
	T& operator[](const int index);
	void pop_front();

private:
	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(),Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;

		}
	};
	Node<T>* head;
	int Size;

};
template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
}
template<typename T>

void List<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext !=nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}
template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current!=nullptr)
	{
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

void task1()
{
    //Cоздать однонаправленный список удалить из списка первый элемент.
	setlocale(LC_ALL, "Russian");
	List<int> lst;
	lst.push_back(10);
	lst.push_back(5);
	lst.push_back(22);
	cout << " До удаления элемента " << endl;
	for (int i = 0; i < lst.GetSize(); i++) {
		cout << lst[i] << " ";
	}
	lst.pop_front();
	cout << endl;
	cout << " После удаления элемента " << endl;
	for (int i = 0; i < lst.GetSize(); i++) {
		cout << lst[i] << " ";
	}
    cout << endl;
}




bool number_less_than_five(const int& number)
{
    return number < 5;
}

void task2()
{
    //Создать однонаправленный список из целых чисел. Найти сумму элементов, которые >= 15 и удалить элементы, которые < 5;

    forward_list <int> Numbers = { 5, -2, 15, 16, 20, -1, 6, -4 };

    forward_list <int> ::iterator Place;

    int sum = 0;

    cout << "Изначальные элементы списка: ";

    //находим сумму элементов больших либо равных 15;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
        if (*Place >= 15)
        {
            sum += *Place;
        }
    }

    cout << endl << endl << "Сумма элементов больших либо равных 15: " << sum << endl << endl;

    //удаляем элементы меньшие чем 5;
    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        Numbers.remove_if(number_less_than_five);
    }

    cout << "Список после удаления элементов меньших чем 5: ";

    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }

    cout << endl << endl;
}

void task3()
{
    //Создать два двунаправленных списка, вывести указатели на первый и последний элементы первого списка, и на один из элементов второго.
    //После указанного элемента второго списка поместить все элементы первого списка во второй, тем самым объединив два списка. 
    //Вывести новые указатели на первый и последний элементы.

    list <int> Numbers = { 7, 5, 4, -2, 2, 1, 55, 76 };
    list <int> Numbers_1 = { 55, 3, 2, 3, 66, 7, 88, 41 };
    list <int> ::iterator Place, Place_1;
    int* P1, * P2, * P3;

    cout << "Первый список: ";

    for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
    {
        cout << *Place << " ";
    }
    cout << endl << "Второй  список: ";

    for (Place_1 = Numbers_1.begin(); Place_1 != Numbers_1.end(); Place_1++)
    {
        cout << *Place_1 << " ";
    }
    cout << endl;

    //Указываем на первый и последний элементы 1-го, и на последний 2-го списков;
    P1 = &Numbers.front();
    P2 = &Numbers.back();
    P3 = &Numbers_1.back();

    cout << "Первый и последний элементы первого списка: " << *P1 << ", " << *P2 << endl;
    cout << "Последний элемент второго списка: " << *P3 << endl;

    //Переносим элементы из первого списка во второй, пока первый не будет пустым;
    do
    {
        Numbers_1.push_back(Numbers.front());
        Numbers.pop_front();
    } while (!Numbers.empty());

    cout << "Объединенные списки: ";

    //Выводим новый список и указатели;
    for (Place_1 = Numbers_1.begin(); Place_1 != Numbers_1.end(); Place_1++)
    {
        cout << *Place_1 << " ";
    }

    P1 = &Numbers_1.front();
    P2 = &Numbers_1.back();

    cout << endl << "Первый и последний элементы  списка после изменений: " << *P1 << ", " << *P2 << endl << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
	task1();
    task2();
    task3();
}