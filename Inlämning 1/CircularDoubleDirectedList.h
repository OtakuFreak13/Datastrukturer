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
	direction currentDirection;
public:
	CircularDoubleDirectedList();
	~CircularDoubleDirectedList();
	CircularDoubleDirectedList(const CircularDoubleDirectedList<T>& copy); //Vad är det som kopieras egentligen. Just det "CircularDoubleDirectedList"
	CircularDoubleDirectedList<T>& operator=(const CircularDoubleDirectedList<T>& copy);
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
	this->currentDirection = FORWARD;
}

template<typename T>
CircularDoubleDirectedList<T>::~CircularDoubleDirectedList()
{
	while (this->current != nullptr)
	{
		this->removeAtCurrent();
	}
}

template<typename T>
CircularDoubleDirectedList<T>::CircularDoubleDirectedList(const CircularDoubleDirectedList<T>& copy)
{
	this->nrOfElements = copy.nrOfElements;
	this->currentDirection = copy.currentDirection;

	if (this->nrOfElements > 0)
	{
		Node* walker = copy.current;
		T element = walker->element;
		this->current = new Node(nullptr, nullptr, element);
		this->current->prev = this->current;
		this->current->next = this->current;
		Node* walkerNew = this->current;
		Node* walkerOld;
		int i = 0;
		while (i < this->nrOfElements - 1)
		{
			walker = walker->next;
			walkerOld = walkerNew;
			element = walker->element;
			walkerNew = new Node(nullptr, nullptr, element);
			walkerNew->prev = walkerOld;
			walkerOld->next = walkerNew;

			i++;
		}
		walkerNew->next = this->current;
		this->current->prev = walkerNew;
	}
	else
	{
		this->current = nullptr;
	}

}

template<typename T>
inline CircularDoubleDirectedList<T>& CircularDoubleDirectedList<T>::operator=(const CircularDoubleDirectedList<T>& copy)
{
	if (this->current != copy.current)
	{
		while (this->current != nullptr)
		{
			this->removeAtCurrent();
		}
		this->nrOfElements = copy.nrOfElements;
		this->currentDirection = copy.currentDirection;

		if (this->nrOfElements > 0)
		{
			Node* walker = copy.current;
			T element = walker->element;
			this->current = new Node(nullptr, nullptr, element);
			this->current->prev = this->current;
			this->current->next = this->current;
			Node* walkerNew = this->current;
			Node* walkerOld;
			int i = 0;
			while (i < this->nrOfElements - 1)
			{
				walker = walker->next;
				walkerOld = walkerNew;
				element = walker->element;
				walkerNew = new Node(nullptr, nullptr, element);
				walkerNew->prev = walkerOld;
				walkerOld->next = walkerNew;

				i++;
			}
			walkerNew->next = this->current;
			this->current->prev = walkerNew;
		}
		else
		{
			this->current = nullptr;
		}
	}
	return *this;
}

template<typename T>
void CircularDoubleDirectedList<T>::addAtCurrent(const T & element)
{
	if (this->current == nullptr)
	{
		this->current = new Node(this->current, this->current, element);
		this->current->next = this->current;
		this->current->prev = this->current;
	}
	else if (this->currentDirection == FORWARD)
	{
		Node* walker = this->current;
		this->current = new Node(walker, walker->next, element);

		walker->next->prev = this->current;
		walker->next = this->current;

	}
	else if (this->currentDirection == BACKWARD)
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
	else if (this->nrOfElements == 1)
	{
		delete this->current;
		this->current = nullptr;
		this->nrOfElements--;
	}
	else
	{
		Node* walker = this->current;
		this->current->next->prev = this->current->prev;
		this->current->prev->next = this->current->next;
		if (this->currentDirection == FORWARD)
		{
			this->current = this->current->next;
		}
		if (this->currentDirection == BACKWARD)
		{
			this->current = this->current->prev;
		}
		this->nrOfElements--;
		delete walker;
		walker = nullptr;
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
	if (this->currentDirection == FORWARD)
	{
		this->currentDirection = BACKWARD;
	}
	else
	{
		this->currentDirection = FORWARD;
	}
}

template<typename T>
void CircularDoubleDirectedList<T>::moveCurrent() throw(...)
{
	if (this->current == nullptr)
	{
		throw "Exception: call of moveCurrent on empty list";
	}
	else if (this->currentDirection == FORWARD)
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
	return this->currentDirection;
}

