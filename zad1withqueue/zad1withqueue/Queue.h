#pragma once
template<typename T>
struct node {

	T info;

	struct node<T> *next;

};
template<typename T>
class Queue {

private:

	node<T> *rear;
	node<T> *front;

public:

	Queue()
	{

		rear = NULL;
		front = NULL;

	}

	void enqueue(const T& data)
	{


		node<T> *temp = new node<T>;
		temp->info = data;
		temp->next = NULL;

		if (front == NULL)
		{
			front = temp;
		}
		else 
		{
			rear->next = temp;
		}

		rear = temp;

	}


	T dequeue()
	{

		node<T> *temp = new node<T>;

		if (front == NULL)
		{
			cout << "\nQueue is Emtpty\n";

		}
		else {

			temp = front;
			front = front->next;
			return temp->info;
			delete temp;

		}

	}
};