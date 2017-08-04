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

    void add(LinkedList<T> * newObj)
	{
        if(nextObj == 0)
        {
            nextObj = newObj;
        }
        else
        {
            nextObj->add(newObj);
        }
	}


private:
	LinkedList<T> * nextObj;
};

#endif /* LINKEDLIST_H_ */
