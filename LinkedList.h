/*
 * LinkedList.h
 *
 *  Created on: Aug 3, 2017
 *      Author: Boston
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template <class T> class LinkedList : public T
{
public:

	LinkedList<T>(): T(), nextObj(0) {}

	LinkedList<T> * getNext()
	{
		return nextObj;
	}

	void add(T * newObj)
	{
		LinkedList<T> * lastObjPtr = nextObj;

		while(lastObjPtr != 0)
		{
			lastObjPtr = lastObjPtr->getNext();
		}

		lastObjPtr->setNext(newObj);
	}

	void setNext(LinkedList<T> * obj)
	{
		nextObj = obj;
	}


private:
	LinkedList<T> * nextObj;
};

#endif /* LINKEDLIST_H_ */
