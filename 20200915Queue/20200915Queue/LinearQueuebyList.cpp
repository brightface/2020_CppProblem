#include "LinearQueueByList.h"

int main()
{
	LinearQueueByList q;
	q.Push(70);
	q.Push(30);
	q.Push(40);
	q.Push(50);
	q.Push(60);

	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();

}