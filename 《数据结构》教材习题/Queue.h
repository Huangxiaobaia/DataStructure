#pragma once
template<class Type>class Queue
{
public:
	Queue(int = 10);
	~Queue(){delete[] Q;}

	void EnQueue(Type& item);
	Type DeQueue();
	Type GetFront();
	void MakeEmpty() { front = rear = tag = 0; }
	int isEmpty()const { return front == rear && tag == 0; }
	int IsFull()const { return front == rear && tag == 1; }
private:
	int rear, front, tag;
	Type* Q;
	int m;
};