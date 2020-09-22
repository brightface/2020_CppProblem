#include "LinearQueue.h"

using namespace std;

int main()
{
	LinearQueue lq(5);
	lq.Enqueue(10);
	lq.Enqueue(20);
	lq.Enqueue(30);
	lq.Enqueue(40);
	lq.Enqueue(50);
	lq.Enqueue(50);

	while (lq.Empty() == false)
	{
		cout << lq.Front() << endl;
		cout << lq.Back() << endl;
		lq.Dequeue();
	}
	lq.Dequeue();
	//일로 하는건 생산성이라는걸 생각해야돼. 굳이 이렇게 까지 해야하나? 
	//취미가 아니라.  한달만 지나봐라
	//시키는대로 할 기계일뿐이야.
	//그속에서 재미를 찾아가야돼
	//서버전검이 있으면 서버전검 직전에 운영자 코드 직전에 아이템들이 만들고 지우고 그래서 지우고 해서 개발자로 해서 심심함녀 할수 잇다. 우리가 만들어서 코드 만들어서 함녀돼 안걸린다.
	//테스트 서버 gm만하는게 아니고 우리들도 한다.
	//오픈하기 패치하기 전에 다시 오픈전 테스트 한다. 최대한 버글르 잡아낸다. 테스트 서버가지고 아이템 풀로 맞추서 난리치다가.
	/*운영자 
		레이드 ㄱㄱ 
	*/

	return 0;

}