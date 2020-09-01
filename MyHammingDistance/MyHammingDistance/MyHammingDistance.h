#pragma once
#ifndef _MY_HAMMING_DISTANCE_H_
#define _MY_HAMMING_DISTANCE_H_
class MyBinaryNumber		
{
public:

	// constructors
	MyBinaryNumber();
	MyBinaryNumber(unsigned int val);
	// accessor/mutator functions
	unsigned int getValue() const;
	void setValue(unsigned int val);
	// utility function
	int getHammingWeight();
	int sum();
	void getPrint();
	int getHammingDistance(MyBinaryNumber& bn);
private:
	unsigned int value;
	int cnt = 0;
	int arr[100];

};
#endif // _MY_HAMMING_DISTANCE_H_