#include "CircleQueue.h"

int main()
{
	CircularQueue<int> cq(5);
	cq.Enqueue(10);
	cq.Enqueue(20);
	cq.Enqueue(30);
	cq.Dequeue();
	cq.Dequeue();
	cq.Enqueue(40);
	cq.Enqueue(50);
	cq.Enqueue(60);
	cq.Dequeue();
}