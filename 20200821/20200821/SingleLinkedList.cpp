#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

int main()
{
	SingleLinkedList<int> l;
	l.Push_Back(10);
	l.Push_Back(20);
	l.Push_Front(0);
	l.Push_Back(50);
	l.Push_Front(-10);

		
		for (int i = 0; i < l.Size(); i++)
			cout << l[i]->data << " ";

	cout << endl;
	
	l.Insert(l[3], 1000);
	l.Remove(20);
	for (int i = 0; i < l.Size(); i++)
		cout << l[i]->data << " ";
	cout << endl;
	
	l.Pop_Back();
	for (int i = 0; i < l.Size(); i++)
		cout << l[i]->data << " ";
	cout << endl;
	l.Clear();
	for (int i = 0; i < l.Size(); i++)
		cout << l[i]->data << " ";
	return 0;
}