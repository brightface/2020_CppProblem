#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> vec;
	for (int i = 0; i < 7; i++) {
		vec.push_back(i);
		cout<<vec.capacity()<<endl; //크기자체는 아니고 몇개를 할당. 인트가 들어갈 자리를 몇개를 받았는나.
		//6개까지는 됐다하다가 그이상은 9로 뛴다. 공간을 크게 잡는다. 이렇게 해야 많이 재할당하는것 피할수 있다. //정점이 몇개인지는 알수있잖아.
		//미리 벡터에 공간을 잡아놓으면 되겠지.
	}

	/*vec.resize(10000); 
	vec.assign(10000,VertexColor()); 10000개만큼 자리를 잡아가지고 채우는거야. */

	//벡터와 리스트의 차이점.
	/*
		1. 벡터는 연속적으로 나열되어있기 때문에, 벡터의 요소들에 임의접근(RanIt)이 가능하지만, 리스트는 노드들이 흩어져 있기 때문에 
		그냥 양방향으로 이동만 가능하다. 그래서 반복자가 순서값으로 접근하는 []연산자를 지원하지 않고, 당연히 at()도 지원하지 않는다.<특정 위치에 접근하는 함수>
		cf) stl::list : 양방향 리스트

		임의 위치를 상수시간에 엑세스 할수 없으면 (리스트이야기 하는거야.) 반드시 순회를 해야만 원하는 데이터를 찾을수 있다.
		그래서 임의 접근 반복자(RanIt)를 요구하는 Sort / binary_search 같은 알고리즘은 사용할수 없다.

		2. 각 요소들이 노드로 할당되어 링크에 의해 논리적으로 연결되어 있으므로 삽입 삭제를 수행할수 있다. 요소들이 인접하지 않아도 상관없기 때문에 삽입, 삭제시에
		메모리 이동을 할 필요가 없고, 위치에 상관없이 상수시간내에 삽입삭제를 할 수 있다.
		제일앞에 요소를 삽이박제하는 push_front, pop_front함수가 제공된다. 
		이에비해 벡터는 중간에서 삽입삭제를 할때 요소를 밀거다 당겨야되서 상대적으로 느리다.
		한편 리스트는 속도 희생없이 크기를 늘리던지 줄일수 있기 때문에 미리 크기를 결정할 필요가 없다. 그래서 capacity라든지 reserve함수를 쓸 필요도 없다.

		3. 링그 구조로 인해 메모리 소모량은 벡터보다 훨씬 더 많다. 요소를 저장하는 노드는 "무조건"동적할당 해야하며, 요소간의 순서를 기억하기 위한 링크도 별도의 메모리를 소모한다. 또한 삽입 삭제시마다
		노드를 할당 해제 하는 과정을 계쏙 반복하기 때문에 메모리 단편화 현상도 심하다.
		//노드들은 무조건 동적할당이야. 정적할당은 스텍날아가버리면 문제가 생겨 연결이 끊겨, 
		//stl list : 메모리 단편화 현상 

		//메모리 단편화 현상 : OS 에 관련된 현상
	*/

	//vector<int> vec;
	list<int> l;
	//vec.push_front();//불가

	l.push_back(10);
	l.push_back(20);
	l.push_front(0);
	l.push_front(0);
	l.push_front(-10);
	list<int>::iterator iter;
	for (iter=l.begin(); iter != l.end(); ++iter)
		cout << *iter << endl;

	iter = l.begin();
	iter ++; iter++;
	//-10 0 10 20
	l.insert(iter, 100);

	for (iter = l.begin(); iter != l.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	//////////////////////////////////////

	iter = l.end();
	iter--; iter--;
	l.erase(iter);
	

	for (iter = l.begin(); iter != l.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	///////////////////////////////////////
	l.remove(0); //0이 지워져 있는거 다지워져
	for (iter = l.begin(); iter != l.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	l.clear();// 다 지운다.

};