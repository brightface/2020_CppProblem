#include<iostream>
#include <set>

using namespace std;
int main()
{
	 set<int> s1;
	 set<int> answer;
	 int check[100];
	 int n;
	 cin >> n;
	 for (int i = 0; i < n; i++)
	 {
		 int temp;
		 cin >> temp;
		 s1.insert(temp);
	 }

	 cin >> n;
	 for (int i = 0; i < n; i++)
	 {
		 int temp;
		 cin >> temp;
		 if (s1.find(temp)!=s1.end())
		 {
			 answer.insert(temp);
		 }
	 }
	
	 for (auto i = answer.begin(); i != answer.end(); i++)
		 cout << *i<<" ";

}