#pragma once
#define S	1024

template<class T>
class Queue
{
public:
	Queue(int = S);
	~Queue(void);
	void Pop();
	void Push(const T&);
	bool Empty();
	unsigned int Size();
	T& Front();
	T& Back();
	void Clear();
	T *qPtr; // указатель на очередь
	//штн ltQ; // последний элемент

private:
	unsigned int size;
	int cur; // текущий элемент
	int ltQ; // последний элемент
	int frQ; // первый элемент
};


template<class T>
Queue<T>::Queue(int s)
{
	size = s > 0 ? s : S;
	qPtr = new T[size];
	frQ = 0;
	ltQ = frQ;
}


template<class T>
bool Queue<T>::Empty()
{
	if (size == ltQ) {
		return true;
	} else {
		return false;
	}
}


template<class T>
void Queue<T>::Push(const T &p)
{
	if (size != ltQ) {
		qPtr[++ltQ] = p;
	}
}

template<class T>
T& Queue<T>::Back(){
	return qPtr[ltQ];
};



template<class T>
Queue<T>::~Queue(void)
{
}
