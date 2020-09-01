#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

bool check(int n) {
	n &= (n - 1);
	if (n == 0)
		return true;
	else
		return false;
}

unsigned int hammingEncode(unsigned int n) {
	bitset<32> bit;
	int i = 0, parCnt = 0;
	int p[] = { 0, 0, 0, 0, 0 };
	while (n != 0) {
		if (check(i + 1)) {
			++parCnt;
		}
		else {
			if (!(i % 2)) {
				p[0] += n % 2;
			}
			if ((i % 4) >= 1 && (i % 4) <= 2) {
				p[1] += n % 2;
			}
			if ((i % 8) >= 3 && (i % 8) <= 6) {
				p[2] += n % 2;
			}
			if ((i % 16) >= 7 && (i % 16) <= 14) {
				p[3] += n % 2;
			}
			if ((i % 32) >= 15 && (i % 32) <= 30) {
				p[4] += n % 2;
			}
			bit.set(i, n % 2);
			n /= 2;
		}
		++i;
	}
	for (size_t j = 0; j < parCnt; ++j) {
		int powData = int(pow(2, j));
		bit.set(powData - 1, p[j] % 2);
	}
	return bit.to_ulong();
}

unsigned int hammingDecode(unsigned int n) {
	bitset<32> bit;
	int i = 0, j = 0, parCnt = 0;
	int p[] = { 0, 0, 0, 0, 0 };
	while (n != 0) {
		if (!(i % 2)) {
			p[0] += n % 2;
		}
		if ((i % 4) >= 1 && (i % 4) <= 2) {
			p[1] += n % 2;
		}
		if ((i % 8) >= 3 && (i % 8) <= 6) {
			p[2] += n % 2;
		}
		if ((i % 16) >= 7 && (i % 16) <= 14) {
			p[3] += n % 2;
		}
		if ((i % 32) >= 15 && (i % 32) <= 30) {
			p[4] += n % 2;
		}
		if (check(i + 1)) {
			++parCnt;
		}
		else {
			bit.set(j, n % 2);
			++j;
		}
		n /= 2;
		++i;
	}
	int errorPoint = 0;
	for (size_t k = 0; k < parCnt; ++k) {
		if (p[k] % 2) {
			errorPoint += int(pow(2, k));
		}
	}
	if (errorPoint != 0 && parCnt > 1) {
		int errorCount = 0;
		for (size_t k = 1; k < errorPoint; ++k) {
			if (check(k)) {
				++errorCount;
			}
		}
		errorPoint -= errorCount;
		bit.flip(errorPoint - 1);
	}
	return bit.to_ulong();
}

int main() {

	int testCases;

	cin >> testCases;

	for (int i = 0; i < testCases; ++i) {
		unsigned int a, b;
		cin >> a >> b;
		cout << (a ? hammingDecode(b) : hammingEncode(b)) << endl;
	}

}