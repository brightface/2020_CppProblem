//Queue
/*
	LIFO stack
	FIFO queue : 대기열 큐돌린다. 게임할때 큐돌린다. 롤 큐돌린다. 대기줄 . api 할때 메세지 큐라는게 있었다.
	메시지가 자료구조에 들어가서 차곡차곡 쌓인다. 마우스 왼쪽클릭한게 처리가 되야한다.
	배열처럼 되가지고 마우스 클릭한 메세지가 들어오고 앞에서 부터 처리하고 나가는것.
	메시지 큐하나로만 돌리는게 아니고 입력 메시지 큐
	랜더링 따로 주고 
	 쓰레드로 관리를 하는거지
	 그거를 비교를 하는거야.
	 특정한 스킬이 나오고 일반 적인 : 입력같은거 마우스 누르는거 키보드 누르는거
	 순차적으로 되야할거아니야.
	 랜더링 큐. 랜더링 되는 순서가 중요하다.
	 배경맵같은것 제일 먼저그리고
	 제일 마지막에 플레이어 그리고

	 랜더링될 애들 순차적으로 그리고 
	 그렇게 까지는 하지 않는다.
	 쓰레드를 써야한다.
	 쓰레드 완벽하게 잡고 있어야돼
	 
	 서버에서 쓰레드를 쓴다.

	 스택: 벡터나 리스트로 구현가능
	 근데 큐같은경우 벡터로 못써
	 pop_front 지원하지 않는다.
	 list , 배열 , 선형구조 문제점이 있다.
	 배열 : 크기 잡혀져 있어야겠지. 동적이든 정적이든
	 앞에것까지 왔으면 남은 공간이 얼마 안남았잖아. 앞으로 당기겨야 돼 비용이 많이 들어
	 선형배열로는 큐를 잘 만들지 않는거지.

	  |빼 |빼 |뺴 |이제 당겨야돼 | | |
	  복사를 하고
	  그래서 환형큐를 사용하면 돼.
	  클래스로 만들면 인덱스를 가지고 있거든

	  인덱스
	  front 
	  rear

	  처음
	  front =0;
	  rear =0;
	  입력시 
	  rear+=1;

	  가득차있는것.
	  어떻게 판단?
	  배열의 끝 제일 마지막 자리를 비워놓게 돼
	  rear+1 % size == front
	  면 가득 차있다.
	  ---------------------------------
	  리스트로 구현하면 훨 간단하다.
	  리스트는 환형으로 굳이 만들 필요도 없고. 그냥 이어가면 되잖아.
	  잠재적인 위험이 있는건 계속 이어갈수 잇잖아. 무한루프에 걸릴수 있다. 메모리가 터져벼려
	  이론상으로는 무한대로 생성이 가능하지만 길이 제한같은걸 둬서 메모리 터지는걸 막아줘야한다.
	  	  
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	//큐에 밀어넣는걸 Enqueue : push
	//빼는걸 Dequeue 라 한다. : pop 컴공아저씨들이
	//Empty : 기본적으로 있어야 한다. 

	queue<int> q; // 
	
	//순회가 할 필요가 없다. 중간에 있는값들을 쓸수가 없다.
	//q[10] 이 안된다.
	//큐쓰면 안된다.
	
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	
	while (q.empty() == false)
	{	//레퍼런스로 반환해주는거야 스택의 top도 래퍼런스로 반환하는거야.
		cout << q.front() << endl;
		cout << q.back() << endl;

		q.pop();
	}//std queue는 기본적으로 원형큐다.

	return 0;
}
