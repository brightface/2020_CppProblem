#include <queue>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

/*
1. �μ� ������� ���� �տ� �ִ� ����(J)�� ����Ͽ��� �����ϴ�.
2. ������ �μ� ����Ͽ��� J���� �߿䵵�� ���� ������ �� ���� �����ϸ� J�� ������� ���� �������� �ֽ��ϴ�.
3. �׷��� ������ J�� �μ��մϴ�.

���� �μ⸦ ��û�� ������ ���� ������� � ��ġ�� �ִ����� �˷��ִ� location�� �Ű������� �־��� ��, 
���� �μ⸦ ��û�� ������ �� ��°�� �μ�Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
*/
int solution(vector<int> priorities, int location)
{
	int answer = 0;
	queue<pair<int, int>> q;
	priority_queue<int> pq;

	int size = priorities.size();
	for (int i = 0; i < size; i++)
	{
		q.push(make_pair(i, priorities[i]));
		pq.push(priorities[i]);
	}

	while (q.empty() == false)
	{
		int i = q.front().first;
		int p = q.front().second;
		q.pop();

		if (p == pq.top())
		{
			pq.pop();
			answer++;

			if (i == location)
				break;
		}
		else
			q.push(make_pair(i, p));
	}

	return answer;
}

class Printer
{
public:
	Printer(string data, int priority) : data(data), priority(priority)
	{
		
	}

	bool operator <(const Printer& rhs) const
	{
		return priority < rhs.priority;
	}

	string data;
	int priority;

private:


};

struct Compare
{
	bool operator()(const Printer& lhs, const Printer& rhs) const
	{
		return lhs.priority < rhs.priority;
	}
};

template<typename T, typename U>
auto Function(T a, U b) -> decltype(a + b)
{
	return a + b;
}

int main()
{
	//priority_queue<Printer, vector<Printer>, Compare> pq;
	//priority_queue<Printer> pq;
	/*auto comp = [](const Printer& lhs, const Printer& rhs)
	{
		return lhs.priority < rhs.priority;
	};

	priority_queue<Printer, vector<Printer>, decltype(comp)> pq(comp);*/
	priority_queue<Printer, vector<Printer>, 
				   function<bool(const Printer& lhs, const Printer& rhs)>> 
		pq([](const Printer& lhs, const Printer& rhs)
	{
		return lhs.priority < rhs.priority;
	});


	// deque
	for (int i = 0; i < 10; i++)
	{
		string str = "Data" + i;
		pq.push(Printer(str, rand() % 10));
	}

	while (pq.empty() == false)
	{
		cout << pq.top().priority << endl;
		pq.pop();
	}

	vector<int> vec;
	sort(vec.begin(), vec.end(), [](const int& lhs, const int& rhs) {return lhs < rhs; });
	// sort �� ���ٽ� ��� ����
	// qsort();
	// qsort �� QuickSort �̴�.

	int  temp[100];
	//binary_search(vec.begin(), vec.end(), 55);
	binary_search(temp, temp + 100, 55);
	lower_bound(temp, temp + 100, 55);	// 55 �̻��� ���� �߿� ù ��° ��
	upper_bound(temp, temp + 100, 55);	// 55 �ʰ��� ���� �߿� ù ��° ��
	// ������ �Ǿ��־�� ������ �ȴ�. �׷��� sort �� ������ ����� �ȴ�.


	return 0;
}