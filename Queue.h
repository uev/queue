#pragma once

template<class T>
class Queue
{
public:
	Queue();
	~Queue(void);
	void Pop();
	void Push(const T&);
	bool Empty();
	unsigned int Size();
	T& Front();
	T& Back();
	void Clear();

private:
	unsigned int count;
	struct Node{
            T date;
            Node *next;
        };
	Node *frontPtr;
    Node *backPtr;
};

template<class T>
Queue<T>::Queue(): frontPtr(NULL), backPtr(NULL), count(0)
{
}


template<class T>
bool Queue<T>::Empty()
{
   return(count == 0);
}

template<class T>
void Queue<T>::Push(const T &p)
{
	Node *newOne = new Node;
    newOne->date = p;
    newOne->next = NULL;
    if(Empty()){
        frontPtr = newOne;
    } else {
		backPtr->next = newOne;
    }
    backPtr = newOne;
    count++;
}

template<class T>
void Queue<T>::Pop()
{
	if(Empty()){
       puts("Nothing inside");
    } else {
		Node *temp = frontPtr;
		if(frontPtr == backPtr){
			frontPtr = NULL;
			backPtr = NULL;
			} else {
				frontPtr = frontPtr->next;
			}
			delete temp;
			count--;
		}
}

template<class T>
T& Queue<T>::Back(){
	return backPtr->date;
};


template<class T>
T& Queue<T>::Front(){
	return frontPtr->date;
};

template<class T>
unsigned int Queue<T>::Size()
{
	return count;
}

template<class T>
void Queue<T>::Clear()
{
	printf("\nTry clear queue");
	while (count > 0) {
		Pop();
	}
}

template<class T>
Queue<T>::~Queue(void)
{
	delete frontPtr;
	delete backPtr;
}