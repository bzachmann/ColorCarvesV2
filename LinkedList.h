#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template <class T> class LinkedList
{
public:

    LinkedList<T>() : nextObj(0) {}

    T * next()
    {
        return nextObj;
    }

    void add(T * newObj)
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
    T * nextObj;
};

#endif /* LINKEDLIST_H_ */
