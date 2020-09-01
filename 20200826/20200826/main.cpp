#include "ListStack.h"

int main()
{
	ListStack<int> ls;
	ls.Push(10);
	ls.Push(20);
	ls.Push(20);
	ls.Push(20);

	while (ls.Empty() != true)
	{
		cout << ls.top() << endl;
		ls.Pop();
	}

	return 0;
}