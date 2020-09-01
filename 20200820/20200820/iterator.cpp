#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	//iterator(반복자)
	//컨테이너의 한 지점을 가리키는 객체. 포인터가 아니다.
	//한 주소를 가리키는 객체
	//연산자 재정의를 통해 포인터처럼 동작을 할 뿐이다.

	/*
		[] next 똑같이 맞춘김에 반복자라는걸 쓴것이다.

	*/

	vector<int> vec;
	
	vec.push_back(1);
	vector<int>::iterator iter1 = vec.begin();
	//iter1++;
	//vec.push_back(2);//불가능. iter값 0으로 바꿔주었는데 다시 push_back이 iter 값에 영향을 줘서 에러,한번에 다 넣어줘야함
	//iter1++;
	cout << *iter1;
	
	
	/*
	
	list<int> l;
	vec.begin();
	l.begin(); 
	vec.end();
	l.end();

	//find(vec.begin());
	//알고리즘 헤더 iterator에 있는 이름
	//구성도 컨테이너마다 다르다.

	//범위기반 포문
	//cps stl이 아니다. map

	//이터레이터 타입으로 가정해서 만들었다. find(vec[0]); 이건 예외
	//알고리즘 헤더에서 만든것 왜 만드냐 반복자로 매개변수를
	//반복을 할 얘를 만들긴 해
	/*
		컨테이너에 접근 . 순회가 필요. 벡터같은거(순회가 필요없다)
		리스트 특정!
		컨테이너의 그 자체가 아니라 그 데이터에 대한것
		거기안에 있는것 어덯게 처리하느냐
		iterator를 통해서  해당 컨터네에 특정 위치에 접근하기 위해서 
		반복자하고 알고리즘하고 컨테이너 간에 연결고리

		물리적으로 나열되어있는 형태의 컨테이너
		cps container
		
*/
		
	//vector<int>::iterator iter;
	
	//리스트는 물리적으로 나열되어있는게 아니야. 논리적으로 연결이 되어있는거지
	list<int> l;
	
	l.push_back(7);
	list<int>::iterator iter2 = l.begin();
	cout << *iter2;
	l.push_back(8);//논리적으로 연결만 되어 있어서 push_back 값은 추가되도 iter2 가 증가하지 않는다. 하지만 벡터는 push_back하면 물리적으로 연결되어 있어서 iter값이 증가.
	iter2++;
	cout << *iter2;
	iter2++; //0x04 0x12 포인터 그 자체가 아니다.


	

	//vector<int>::iterator iter;
	//iter++;

	//리스트는 물리적으로 나열되어있는게 아니야.논리적으로 연결이 되어있는거지
	//list<int>::iterator it;
	//it++; //0x04 0x12 포인터 그 자체가 아니다.

	//map<int, int>::iterator iter;
	//iter++; //0x04 0x12 

	find(vec.begin(), vec.end(), 1);
	 //In It : 입력 전용 iterator / iterator의 종류

		/*
			InIt (입력전용) 오로지 입력만 가능 / 쓰기 불가능  (istream_iterator)
			OutIt (출력전용) 오로지 출력만 가능하며 읽기 불가능 (ostream_iterator)
			FwdIt(정방향)/ ++ 같은것 / 입출력은 모두 가능하며, 전진만 가능(++) : que
			BiIt(양방향) /앞뒤로 이동가능(정방향에서 -- 추가, ) : 연결리스트, 벡터도 지원하지만 잘 안쓴다.
			RanIt(random acess, 임의 접근) : vec[3] - 순회를 할 필요 없는애들 , 리스트는 이게 없다는 소리.
		*/
		//sort(a);//임의접근이 불가능한것은 여기 넣지말라
		//find();
		//sort(); // 람다

		//vector<int>::iterator iter = vec.begin();
		//for (; iter != vec.end(); ++iter)
		//{
		//	cout << *iter << endl;
		//	//당겨줘야한다.
		//	iter = vec.erase(iter); // 당겨줘야한다.  중간에 있는거 삭제 할때 많이 생김.
		//}
		//반복자 무효화 - 다음걸 지웠을떄. 내부구조가 어떻게 줘야한다.

	unordered_map<int, int> um;
	for (pair<int, int> p : um)
		cout << p.second << endl;

	unordered_map<int, int>::iterator iter5 = um.begin();
	//for(iter;iter!= um.end(); ++iter)

	//포인터같은놈 iter / 객체 : 클래스 
	
	/*vector<int> vec3{ 0 ,1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	list<int> l2(vec3.begin(), vec3.end());*/

	vector<int> vec3{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> l2(vec3.begin(), vec3.end());

	return 0;
}