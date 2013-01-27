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
	if (frQ == ltQ) {
		if (ltQ < (int)size) {
			return true;
		}else { 
			return false;
		};
	} else {
		return false;
	}
}


template<class T>
void Queue<T>::Push(const T &p)
{
	if (size != ltQ )  {
		qPtr[++ltQ] = p;
	} else {
		if ((ltQ+frQ) > (int)size) {
			//sheeft
			int sheeft=frQ,i=0,ltQ=0;
			for(frQ=1;frQ<(int)size;frQ++){
				if (frQ < ((int)size - sheeft)) {
					qPtr[frQ]=qPtr[frQ+sheeft];
					ltQ+=1;
				}else {
					qPtr[frQ]=0;
				}
			}
		} else {
			printf("Sorry. Buffer is full");
		}
	}
}

template<class T>
void Queue<T>::Pop()
{
	if (frQ == ltQ) { 
		printf("\nQueue is empty\n");
		qPtr[frQ] = 0;
		qPtr[ltQ] = 0;
	} else {
		qPtr[frQ] = 0;
		frQ+=1;
	}
}


template<class T>
T& Queue<T>::Back(){
	return qPtr[ltQ];
};


template<class T>
T& Queue<T>::Front(){
	return qPtr[frQ+1];
};




template<class T>
unsigned int Queue<T>::Size()
{
	return ltQ-frQ;
}


template<class T>
void Queue<T>::Clear()
{
	int i;
	for (i=0; i < int(size);i++){
		qPtr[i]=0;
	}
	printf("\nTry clear queue");
}



template<class T>
Queue<T>::~Queue(void)
{
}
