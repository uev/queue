// Queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string.h"

#include "Queue.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Queue<int> q(100);
	int m = 2;
	q.Push(m);
	int g = q.Back();
	q.Push(m+1);
	q.Push(3232);
	printf("%d",&g);
	return 0;


}

