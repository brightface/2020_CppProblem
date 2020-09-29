#pragma once
/*
이진트리 자식노드가 아예없거나 한개거나. 두개거나
2개이하.

포화이진트리 : 같은레벨의 자식 2개가 있어야 한다.
시간 복잡도 : 검색과 삭제를 빼면 일반적으로 상수시간에 해결이 가능하다.
일반적으로 삽입

검색과 삭제는 어떻게 되나
검색과 삭제는 
O(N)이 나오게 된다.
전위순회 L Root R
노드수 만큼 탐색 을 해야한다. O(N)
지우기 O(N) 모든 하위노드를 날려야한다.


일반적으로 이진트리를 만들때 왼쪽에서부터 채워나간다.
제일 마지막에 있는게 레벨이 제일 높고 제일 오른쪽에 있겠지

삽입  :상수시간안에 된다. O(1) - 맨 마지막에 넣어진다. 

연결리스트.로
-----------------------------------------
배열로 구현하는 이진트리

n링크 방식
문제점 : 데이터 몇개 있을지 모른다. 자식노드 몇개있을지 모른다.
이진트리 : 자식노드 많아봤자 2개다.

--------------------------------------------
배열 0 1 2  3 4 5 6
왼쪽에서 부터 채운다. 
배열로 만든 이진트리의 장점.
연결리스트 문제: 탐색오래걸린다. 배열보다 O(n)
이진 트리에서 탐색 : 효율적이다 - 현재 노드가 1이다. 부모노드 규칙이 어떻게 되느냐. 규칙은?
arr이라 치면
arr[(n+1)/2 -1] 

자식노드
arr[n*2 +1] : 왼쪽일때
arr[n*2 +2] : 오른쪽일때

루트에서 찾아가기
(N*2 +1)*2 +2 //왼쪽이라면 거기에서 또 오른쪽이면

null 값 배열의 크기와 이진트리의 크기는 다를수 있다.
//숫자일때는 상관없는데
구조체 타입이면 어떻게 표현하냐

힙트리 같은곳에 쓴다. 이진탐색에 쓸수 있다. 연결리스트 - 임의접근이 안되잖아. 
나름 쓸데가 있다.

//형제노드
왼쪽노드 : 홀수면 - 왼쪽노드라면 arr[n+1]
오른쪽노드 : 짝수면 - arr[n-1]


*/

//배열로 구현한 이진트리
/*
현재 노드가 arr[n]일때
현재 노드의 부모 -> arr[(n + 1) / 2 - 1]
현재 노드의 왼쪽 자식 -> arr[n * 2 + 1]
현재 노드의 오른쪽 자식 -> arr[n * 2 + 2]
형제노드(내가 왼쪽) -> arr[n + 1]
형제노드(내가 오른쪽) -> arr[n - 1]
*/

//단방향 연결리스트 // 양방향으로 만들어도 되잖아 그럼 부모로 바로 올라갈수 있잖아.
//근데 별로 좋은 생각이 아니다. 이유는
/*
다음 노드의 포인터 :4 바이트
또 노드의 포인터 : 8 바이트
만개의 데이터면 이진트리는 방대한 데이터 다루기 때문에 배열로 했던것보다 추가적으로 8만 바이트 더 들어간다.

연결리스트로 만들었을때 장점: left right 직관적이다. 노드 . 간단하고. 배열로 할려면 수식이 계속 길어진다. 
데이터가 구조체가 널체크를 어떻게 하냐. 배열은
연결리스트는 그냥 nullptr로 하면 된다. 

컴퓨터가 찾아갈때는 배열이 빠르다.


*/

#include <iostream>
using namespace std;

class BinaryTree
{
	public:
		struct Node
		{
			//노드의 포인터 이걸로 핡어ㅑ.
			char* data;
			//char data;
			//Node* Parent;//이건 양방향. 배열에 비해서 12바이트가 잡히네;;
			Node* left = nullptr;
			Node* right = nullptr;
		
			~Node()
			{
				delete[] data;
			}
		};
		//메모리 누수 되겠지. 잡아주자
		
		
		static Node* CreateNode(char* data)
		{
			Node* node = new Node();
			node->data = data;
			return node;
		}
		static void DeleteNode(Node** node)
		{
			delete(*node);
			*node = nullptr;
		}

		//삽입삭제 마지막노드 찾기 해줘야해.만들어야해.
		//순회방법 3가지. 스택가지고 계산했잖아. 수식트리 만들어서 해볼거야.

public:
	static void PreOrder(Node* node)
	{
		if (node == nullptr) return;
		cout << " " << node->data;

		PreOrder(node->left);
		PreOrder(node->right);
	}

	static void InOrder(Node* node)
	{
		if (node == nullptr)return;
		InOrder(node->left);
		cout << " " << node->data;
		InOrder(node->right);

	}

	static void PostOrder(Node* node)
	{
		if (node == nullptr)return;
		PostOrder(node->left);
		PostOrder(node->right);
		cout << " " << node->data;
	}


private:
	
};