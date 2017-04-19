#ifndef QUEUE_H
#define QUEUE_H

#include "IQueue.h"

using namespace std;//WHY GITTHUB NOT WORK!?!?

template <typename T>
class Queue :
	public IQueue<T>
{
private:
	class Node
	{
	public:
		Node* next;
		T element;
		Node(Node* next, T element)
		{
			this->next = next;
			this->element = element;
		}
		Node(const Node& copy)
		{
			this = new Node(copy.next, copy.element);
		}
	};
	Node* first;
	Node* last;
public:
	Queue();
	~Queue();
	Queue(const Queue<T>& copy);
	Queue<T>& operator=(const Queue<T>& copy);
	void enqueue(const T& element);
	void dequeue() throw(...);
	T front() const throw(...);
	bool isEmpty() const;
};

#endif // !QUEUE_H

template<typename T>
Queue<T>::Queue()
{
	this->first = nullptr;
	this->last = this->first;
}

template<typename T>
Queue<T>::~Queue()
{
	while (this->first != nullptr)
	{
		this->dequeue();
	}
}

template<typename T>
Queue<T>::Queue(const Queue<T>& copy)
{
	if (copy.first == nullptr)
	{
		this->first = nullptr;
		this->last = nullptr;
	}
	else
	{
		Node* walker = copy.first;
		T element = walker->element;
		this->first = new Node(nullptr, element);
		Node* walker2 = this->first;
		Node* walker3;

		while (walker != nullptr && walker->next != nullptr)
		{
			walker = walker->next;
			walker3 = walker2;
			element = walker->element;
			walker2 = new Node(nullptr, element);
			walker3->next = walker2;
		}
	}
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& copy)
{
	if (this->first != copy.first)
	{
		while (this->first != nullptr)
		{
			this->dequeue();
		}

		Node* walker = copy.first;
		T element = walker->element;
		this->first = new Node(nullptr, element);
		Node* walker2 = this->first;
		Node* walker3;

		while (walker != nullptr && walker->next != nullptr)
		{
			walker = walker->next;
			walker3 = walker2;
			element = walker->element;
			walker2 = new Node(nullptr, element);

			walker3->next = walker2;
		}
	}
	return *this;
}

template<typename T>
void Queue<T>::enqueue(const T & element)
{
	if (this->first == nullptr)
	{
		this->first = new Node(nullptr, element);
		this->last = this->first;
	}
	else
	{
		Node* walker = this->last;
		this->last = new Node(nullptr, element);
		walker->next = this->last;
	}
}

template<typename T>
void Queue<T>::dequeue() throw(...)
{
	if (this->isEmpty())
	{
		throw "Exception: empty queue";
	}
	else
	{
		Node* walker = this->first;
		this->first = this->first->next;
		delete walker;
		walker = nullptr;
	}
}

template<typename T>
T Queue<T>::front() const throw(...)
{
	if (this->isEmpty())
	{
		throw "Exception: empty queue";
	}

	T returnVal = this->first->element;

	return returnVal;
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	bool empty = false;
	if (first == nullptr)
	{
		empty = true;
	}
	return empty;
}
