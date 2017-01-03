/* Kaylan Mettus
 * CS302.1002
 * Assignment 4
 * 
 * The header file for the linkedQueue class */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
#include <cmath>

#define SIZE 100

template <class myType>
class linkedQueue 
{
public:
	linkedQueue();
	~linkedQueue();
	bool isEmpty() const;
	int getQueueCount();
	int getLinkCount();
	void add(const myType& newItem);
	myType front() const;
	myType back() const;
	void remove();
	void printQueue();
private:	
	struct queueNode{
		myType dataSet[SIZE];
		int front, back;
		queueNode *link;
	};
	queueNode *queueFront;
	queueNode *queueTail;
	int count;
	int linkCount;
};

//Constructor
template <class myType>
linkedQueue<myType>::linkedQueue()
{
	queueFront = NULL;
	queueTail = NULL;
	count = 0;
	linkCount = 0;
}

// Destructor
template <class myType>
linkedQueue<myType>::~linkedQueue()
{
	queueNode *next;
	
	while (queueFront != NULL)
	{
		next = queueFront->link;
		delete queueFront;
		queueFront = next;
	}
}

//Public functions
//Returns true is the queue is empty, false otherwise
template <class myType>
bool linkedQueue<myType>::isEmpty() const
{
	return queueFront == NULL ? true : false;
}

// Returns the number of elements in the queue
template <class myType>
int linkedQueue<myType>::getQueueCount()
{
	return count;
}

//Returns the number of nodes in the queue
template <class myType>
int linkedQueue<myType>::getLinkCount()
{
	return linkCount;
}

//Adds item to the front of the queue
template <class myType>
void linkedQueue<myType>::add(const myType& newItem)
{
	queueNode *newNode = NULL;
	newNode = new queueNode;
	
	if (!isEmpty() && queueTail->front == ((queueTail->back + 1) % SIZE))
	{
		queueTail->link = newNode;
		queueTail = newNode;
				
		newNode->link = NULL;
		newNode->dataSet[0] = newItem;
		newNode->front = 0;
		newNode->back = 0;
		
		linkCount++;
	}
	
	else if (queueFront == NULL)
		{
			queueFront = newNode;
			queueTail = newNode;
							
		newNode->link = NULL;
		newNode->dataSet[0] = newItem;
		newNode->front = 0;
		newNode->back = 0;
		
		linkCount++;
		}
	
	else
	{
		queueTail->back = (queueTail->back + 1) % SIZE;
		queueTail->dataSet[queueTail->back] = newItem;
	}
	
	count++;
}

//Returns the front of the queue
template <class myType>
myType linkedQueue<myType>::front() const
{
	return queueFront->dataSet[queueFront->front];
}

// Returns the back of the queue
template <class myType>
myType linkedQueue<myType>::back() const
{		
	return queueTail->dataSet[queueTail->back];
}

// Removes the current front of the queue
template <class myType>
void linkedQueue<myType>::remove()
{
	if (isEmpty())
		return;
		
	queueNode *curr = queueFront;
		
	if (curr->back != curr->front)
		curr->front = (curr->front + 1) % SIZE;
	else
	{
		queueFront = queueFront->link;
		delete curr;
		linkCount--;
	}	
	count--;
}

// Prints every element in the queue from the front
template <class myType>
void linkedQueue<myType>::printQueue()
{
	queueNode *curr = queueFront;
	
	while (curr != NULL)
	{
		int i = curr->front;
		while (i != curr->back)
		{
			std::cout << curr->dataSet[i] << " ";
			i = (i + 1) % SIZE;
		}	
		std::cout << curr->dataSet[i] << " ";
		curr = curr->link;
	}
}

#endif
