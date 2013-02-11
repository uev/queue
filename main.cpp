// Queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string.h"
#include "Queue.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Queue<int> q;
	int g;
	int i = 0;
	g=50;
	q.Push(g);
	if (q.Size() > 0){
		printf("\nFront: %d",q.Front());
		printf("\nBack: %d",q.Back());
		printf("\nSize: %d", q.Size());
		q.Clear();
		if (q.Size()>0) {
			printf("\nFront: %d",q.Front());
			printf("\nBack: %d",q.Back());
			printf("\nSize: %d", q.Size());
		} else {
			puts("Queue is empty");
		}
	}
	g=30;
	printf("\nPush %d elements",g);
	for (i = 1 ; i < g; i++) {
		q.Push(i);
	}
	printf("\nFront: %d",q.Front());
	printf("\nBack: %d",q.Back());
	printf("\nSize: %d", q.Size());
	g=100;
	printf("\nTry remove %d element...",g);
	for (i=0; i < g; i++)
		q.Pop();
	!q.Empty() ? printf("\nFront: %d",q.Front()) : printf("\nFirst element epsent");
	!q.Empty() ? printf("\nBack: %d",q.Back()) : printf("\nBack element epsent");
	printf("\nSize: %d", q.Size());
	return 0;
}