#ifndef CIRCULAR_DOUBLE_DIRECTED_LIST_H
#define CIRCULAR_DOUBLE_DIRECTED_LIST_H
#include "ICircularDoubleDirectedList.h"

using namespace std;

template<typename T>
class CircularDoubleDirectedList :
	public ICircularDoubleDirectedList<T>
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
	direction dirrection;//TODO döp om till currentDirection
public:
	CircularDoubleDirectedList();
	~CircularDoubleDirectedList();
	void addAtCurrent(const T& element);
	T getElementAtCurrent() const throw(...);
	void removeAtCurrent()throw(...);
	int size() const;
	void changeDirection();
	void moveCurrent()throw(...);
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
	//else if (this->current->next == current)//Kanske behövs kanske inte
	//{
	//	Node* walker = this->current;
	//	this->current = new Node(walker, walker, element);
	//	walker->next = this->current;
	//	walker->prev = this->current;
	//}
	else if (this->dirrection == FORWARD)
	{
		Node* walker = this->current;
		this->current = new Node(walker, walker->next, element);
		walker->next->prev = this->current;
		walker->next = current;

	}
	else if (this->dirrection == BACKWARD)
	{
		Node* walker = this->current;
		this->current = new Node(walker->prev, walker, element);
		walker->prev->next = current;
		walker->prev = current;
	}
	this->nrOfElements++;
}

template<typename T>
T CircularDoubleDirectedList<T>::getElementAtCurrent() const throw(...)
{
	if (this->current == nullptr)
	{
		throw("Exception: call of getElementAtCurrent on empty list");
	}
	else
	{
		return this->current->element;
	}
}

template<typename T>
void CircularDoubleDirectedList<T>::removeAtCurrent()throw(...)
{
	if (this->current == nullptr)
	{
		throw("Exception: call of removeAtCurrent on empty list");
	}
	else 
	{
		this->current->next->prev = this->current->prev;
		this->current->prev->next = this->current->next;
		if (this->dirrection == FORWARD)
		{
			this->current = this->current->prev;
		}
		if (this->dirrection == BACKWARD)
		{
			this->current = this->current->next;
		}
		this->nrOfElements--;
	}
}

template<typename T>
int CircularDoubleDirectedList<T>::size() const
{
	return this->nrOfElements;
}

template<typename T>
void CircularDoubleDirectedList<T>::changeDirection()
{
	if (this->dirrection == FORWARD)
	{
		this->dirrection = BACKWARD;
	}
	else
	{
		this->dirrection = FORWARD;
	}
}

template<typename T>
void CircularDoubleDirectedList<T>::moveCurrent() throw(...)
{
	if (this->current == nullptr)
	{
		throw("Exception: call of moveCurrent on empty list");
	}
	else if (this->dirrection == FORWARD)
	{
		this->current = this->current->next;
	}
	else
	{
		this->current = this->current->prev;
	}
}

template<typename T>
inline direction CircularDoubleDirectedList<T>::getCurrentDirection() const
{
	return this->dirrection;
}

