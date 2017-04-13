#ifndef QUEUE_H
#define QUEUE_H

#include "IQueue.h"

using namespace std;

template <typename T>
class Queue :
	public IQueue<T>
{
private:

public:
	Queue();
	~Queue();
	void enqueue(const T& element);
	void dequeue();
	T front() const;
	bool isEmpty() const;
};

#endif // !QUEUE_H

template<typename T>
Queue<T>::Queue()
{

}

template<typename T>
Queue<T>::~Queue()
{

}

template<typename T>
void Queue<T>::enqueue(const T & element)
{

}

template<typename T>
void Queue<T>::dequeue()
{

}

template<typename T>
T Queue<T>::front() const
{
	return T();
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	return false;
}
