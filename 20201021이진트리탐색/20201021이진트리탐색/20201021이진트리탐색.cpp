#include<iostream>
using namespace std;

void DfsTreePreOrder(int n)
{
	if (n > 7) return;
	else {
		cout << n <<" ";
		DfsTreePreOrder(2 * n);
		DfsTreePreOrder((2 * n) + 1);
	}
}
void DfsTreeInOrder(int n)
{
	if (n > 7) return;
	else {
		DfsTreeInOrder(2 * n);
		cout << n << " ";
		DfsTreeInOrder((2 * n) + 1);
	}
}
void DfsTreePostOrder(int n)
{
	if (n > 7) return;
	else {
		DfsTreePostOrder(2 * n);
		DfsTreePostOrder((2 * n) + 1);
		cout << n << " ";
	}
}

int main()
{
	//DfsTreePreOrder(1);
	//DfsTreeInOrder(1);
	DfsTreePostOrder(1);
}