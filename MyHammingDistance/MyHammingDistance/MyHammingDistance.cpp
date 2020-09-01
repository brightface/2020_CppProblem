#pragma once
#include "MyHammingDistance.h"
#include <iostream>
using namespace std;


#define XOR(a,b) (!(a)^!(b))
// constructors
MyBinaryNumber::MyBinaryNumber()
	:value(0)
{
}
MyBinaryNumber::MyBinaryNumber(unsigned int val)
	: value(val)
{
}
// accessor functions
unsigned int MyBinaryNumber::getValue() const
{
	return value;
}
// mutator functions
void MyBinaryNumber::setValue(unsigned int val)
{
	value = val;
}
// 어떤 정수의 해밍 무게를 계산하는 함수
int MyBinaryNumber::getHammingWeight()
{
	if (value >= 2) {
		if (value % 2 == 0) arr[32 - (cnt++)] = 0;
		else arr[32 - (cnt++)] = 1;
		value = value / 2;
		getHammingWeight();
	}
	else {
		arr[32 - (cnt)] = value;
		return 0;
	}
}
void MyBinaryNumber::getPrint() {
	for (int i = 0; i < 100; i++) {
		cout << arr[i];
	}cout << endl;
}
int MyBinaryNumber::sum() {
	for (int i = 0; i < 100; i++) {
		arr[i] = 0;
	}
	//getPrint();
	getHammingWeight();
	//getPrint();
	int result = 0;
	for (int i = 0; i < 100; i++) {
		result += arr[i];
	}
	return result;
}

// comptue Hamming Distance
int MyBinaryNumber::getHammingDistance(MyBinaryNumber& bn) 
{
	//bn.getPrint();
	int result = 0;
	getHammingWeight();
	bn.getHammingWeight();
	//getPrint();
	//cout << endl;
	//an.getPrint();
	for (int i = 0; i < 100; i++) {
		if (arr[i] != bn.arr[i]) result++;
	}
	return result;
}