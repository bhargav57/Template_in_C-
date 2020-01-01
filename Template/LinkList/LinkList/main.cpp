#include<iostream>
using namespace std;

template<typename T>
class node
{
public:
	T data;
	node* next;
};

template<typename T>
class ll
{
	node<T>* start;
public:
	ll()
	{
		start = nullptr;
	}
	node<T>* createNode(T i);
	void insertNode(T i);
	void show();
};
template<typename T>
node<T>* ll<T>::createNode(T i)
	{
		node<T>* temp = new node<T>();
		if( temp != nullptr)
		{
			temp->data = i;
			temp->next = nullptr;
			return temp;
		}
		else
		{
			//error
			return temp;
		}
	}

template<typename T>
void ll<T>::insertNode(T i)
	{
		if(start == nullptr)
		{
			start = createNode(i);
		}
		else
		{
			node<T>* temp;
			temp = start;

			while( temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp ->next = createNode(i);
		}
	}

template<typename T>
void ll<T>::show()
{
	node<T>* temp = start;
	while( temp != nullptr)
	{
		std::cout<< temp->data <<"\n";
		temp = temp->next;
	}
}
int main()
{
	ll<int> a;
	a.insertNode(5);
	a.insertNode(15);
	a.insertNode(25);

	a.show();
}