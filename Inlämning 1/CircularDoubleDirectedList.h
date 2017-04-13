#ifndef CIRCULAR_DOUBLE_DIRECTED_LIST_H
#define CIRCULAR_DOUBLE_DIRECTED_LIST_H
#include "ICircularDoubleDirectedList.h"

using namespace std;

template<typename T>
class CircularDoubleDirectedList :
	public ICircularDoubleDirectedList
{
private:
	class Node
	{
	public:
		Node* prev;
		Node* next;
		T element;
		Node(Node* prev, Node* next, T element)
		{
			this->prev = prev;
			this->next = next;
			this->element = element;
		}
	};
	Node* current;
	int nrOfElements;
	direction dirrection;
public:
	CircularDoubleDirectedList();
	~CircularDoubleDirectedList();
	void addAtCurrent(const T& element);
	T getElementAtCurrent() const;
	void removeAtCurrent();
	int size() const;
	void changeDirection();
	void moveCurrent();
	direction getCurrentDirection() const;
};

#endif



template<typename T>
CircularDoubleDirectedList<T>::CircularDoubleDirectedList()
{
	this->current = nullptr;
	this->nrOfElements = 0;
	this->dirrection = FORWARD;
}

template<typename T>
CircularDoubleDirectedList<T>::~CircularDoubleDirectedList()
{

}

template<typename T>
void CircularDoubleDirectedList<T>::addAtCurrent(const T & element)
{
	if (this->current == nullptr)//TODO gör så att den pekar på sig själv om den är det enda objektet
	{
		this->current = new Node(this->current, this->current, element);
	}
	else if(this->dirrection==FORWARD)
	{
		Node* walker = this->current;
		if (this->current->next == this->current)
		{

		}
		this->current = new Node(this->walker, this->first, element);
		this->first->prev = this->current;
	}
	else if (this->dirrection == BACKWARD)
	{
		Node* walker = this->current;
		
	}
	this->nrOfElements++;
}

template<typename T>
T CircularDoubleDirectedList<T>::getElementAtCurrent() const
{
	return this->current->e;
}

template<typename T>
void CircularDoubleDirectedList<T>::removeAtCurrent()
{

}

template<typename T>
int CircularDoubleDirectedList<T>::size() const
{
	return 0;
}

template<typename T>
void CircularDoubleDirectedList<T>::changeDirection()
{

}

template<typename T>
void CircularDoubleDirectedList<T>::moveCurrent()
{

}

template<typename T>
inline direction CircularDoubleDirectedList<T>::getCurrentDirection() const
{
	return direction();
}

