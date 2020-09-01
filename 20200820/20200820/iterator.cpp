#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	//iterator(�ݺ���)
	//�����̳��� �� ������ ����Ű�� ��ü. �����Ͱ� �ƴϴ�.
	//�� �ּҸ� ����Ű�� ��ü
	//������ �����Ǹ� ���� ������ó�� ������ �� ���̴�.

	/*
		[] next �Ȱ��� ����迡 �ݺ��ڶ�°� �����̴�.

	*/

	vector<int> vec;
	
	vec.push_back(1);
	vector<int>::iterator iter1 = vec.begin();
	//iter1++;
	//vec.push_back(2);//�Ұ���. iter�� 0���� �ٲ��־��µ� �ٽ� push_back�� iter ���� ������ �༭ ����,�ѹ��� �� �־������
	//iter1++;
	cout << *iter1;
	
	
	/*
	
	list<int> l;
	vec.begin();
	l.begin(); 
	vec.end();
	l.end();

	//find(vec.begin());
	//�˰��� ��� iterator�� �ִ� �̸�
	//������ �����̳ʸ��� �ٸ���.

	//������� ����
	//cps stl�� �ƴϴ�. map

	//���ͷ����� Ÿ������ �����ؼ� �������. find(vec[0]); �̰� ����
	//�˰��� ������� ����� �� ����� �ݺ��ڷ� �Ű�������
	//�ݺ��� �� �긦 ����� ��
	/*
		�����̳ʿ� ���� . ��ȸ�� �ʿ�. ���Ͱ�����(��ȸ�� �ʿ����)
		����Ʈ Ư��!
		�����̳��� �� ��ü�� �ƴ϶� �� �����Ϳ� ���Ѱ�
		�ű�ȿ� �ִ°� ��F�� ó���ϴ���
		iterator�� ���ؼ�  �ش� ���ͳ׿� Ư�� ��ġ�� �����ϱ� ���ؼ� 
		�ݺ����ϰ� �˰����ϰ� �����̳� ���� �����

		���������� �����Ǿ��ִ� ������ �����̳�
		cps container
		
*/
		
	//vector<int>::iterator iter;
	
	//����Ʈ�� ���������� �����Ǿ��ִ°� �ƴϾ�. �������� ������ �Ǿ��ִ°���
	list<int> l;
	
	l.push_back(7);
	list<int>::iterator iter2 = l.begin();
	cout << *iter2;
	l.push_back(8);//�������� ���Ḹ �Ǿ� �־ push_back ���� �߰��ǵ� iter2 �� �������� �ʴ´�. ������ ���ʹ� push_back�ϸ� ���������� ����Ǿ� �־ iter���� ����.
	iter2++;
	cout << *iter2;
	iter2++; //0x04 0x12 ������ �� ��ü�� �ƴϴ�.


	

	//vector<int>::iterator iter;
	//iter++;

	//����Ʈ�� ���������� �����Ǿ��ִ°� �ƴϾ�.�������� ������ �Ǿ��ִ°���
	//list<int>::iterator it;
	//it++; //0x04 0x12 ������ �� ��ü�� �ƴϴ�.

	//map<int, int>::iterator iter;
	//iter++; //0x04 0x12 

	find(vec.begin(), vec.end(), 1);
	 //In It : �Է� ���� iterator / iterator�� ����

		/*
			InIt (�Է�����) ������ �Է¸� ���� / ���� �Ұ���  (istream_iterator)
			OutIt (�������) ������ ��¸� �����ϸ� �б� �Ұ��� (ostream_iterator)
			FwdIt(������)/ ++ ������ / ������� ��� �����ϸ�, ������ ����(++) : que
			BiIt(�����) /�յڷ� �̵�����(�����⿡�� -- �߰�, ) : ���Ḯ��Ʈ, ���͵� ���������� �� �Ⱦ���.
			RanIt(random acess, ���� ����) : vec[3] - ��ȸ�� �� �ʿ� ���¾ֵ� , ����Ʈ�� �̰� ���ٴ� �Ҹ�.
		*/
		//sort(a);//���������� �Ұ����Ѱ��� ���� ��������
		//find();
		//sort(); // ����

		//vector<int>::iterator iter = vec.begin();
		//for (; iter != vec.end(); ++iter)
		//{
		//	cout << *iter << endl;
		//	//�������Ѵ�.
		//	iter = vec.erase(iter); // �������Ѵ�.  �߰��� �ִ°� ���� �Ҷ� ���� ����.
		//}
		//�ݺ��� ��ȿȭ - ������ ��������. ���α����� ��� ����Ѵ�.

	unordered_map<int, int> um;
	for (pair<int, int> p : um)
		cout << p.second << endl;

	unordered_map<int, int>::iterator iter5 = um.begin();
	//for(iter;iter!= um.end(); ++iter)

	//�����Ͱ����� iter / ��ü : Ŭ���� 
	
	/*vector<int> vec3{ 0 ,1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	list<int> l2(vec3.begin(), vec3.end());*/

	vector<int> vec3{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> l2(vec3.begin(), vec3.end());

	return 0;
}