#include <iostream>
#include "ListStack.h"

int main()
{
	ListStack<int> ls;
	ls.Push(10);
	ls.Push(20);
	ls.Push(35);
	ls.Push(40);
	ls.Push(50);
	

	for (int i = 0; i < 5; i++)
	{
		//cout << ls.Size() << " ";
		cout << ls.printTop().data << endl;
		ls.Pop();
	}
	cout << "end" << endl;
	//return 0;
}