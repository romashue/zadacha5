#include <iostream>
using namespace std;

class List
{
public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(int data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	int& operator[](const int index);

	//добавление элемента в начало списка
	void push_front(int data);

	//добавление элемента в список по указанному индексу
	void insert(int data, int index);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	//удаление последнего элемента в списке
	void pop_back();

	//изменение элемента по индексу
	void change(int data, int index);

private:


	class Node
	{
	public:
		Node* pNext;
		int data;

		Node(int data = 0, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node* head;
};


List::List()
{
	Size = 0;
	head = nullptr;
}


List::~List()
{
	clear();
}


void List::pop_front()
{
	Node* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}


void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);

	}

	Size++;
}


void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}


int& List::operator[](const int index)
{
	int counter = 0;

	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


void List::push_front(int data)
{
	head = new Node(data, head);
	Size++;
}


void List::insert(int data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node* newNode = new Node(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}
}


void List::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}


void List::pop_back()
{
	removeAt(Size - 1);
}


void List::change(int data, int index)
{
	removeAt(index);
	insert(data, index);
}



int main()
{

	setlocale(LC_ALL, "ru");


	List lst;
	lst.push_back(5);
	lst.push_back(7);
	lst.push_back(101);

	cout << "Всего элементов = " << lst.GetSize() << endl;

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "изменяем элемент по индексу 1 на '555'" << endl;

	lst.change(555, 1);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "удаляем элемент по индексу 2"<< endl;

	lst.removeAt(2);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "добавляем элемент '698' по индексу 1" << endl;

	lst.insert(698,1);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}
