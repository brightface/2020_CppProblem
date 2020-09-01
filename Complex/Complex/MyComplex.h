#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_

#include <iostream>
using namespace std;

class myComplex {

	friend ostream &operator << (ostream &outStream, const myComplex& number);
	friend istream &operator >> (istream & inStream, myComplex& number);

public:

	//Constructor
	myComplex(int real = 0, int imag = 0);
	//Copy constructor
	myComplex(const myComplex& number);

	//Accessor functions
	int getRealPart() const;
	int getImaginaryPart() const;

	//Mutator functions
	void setRealPart(int real);
	void setImaginaryPart(int imag);
	void set(int real, int imag);

	//Overloaded binary operators
	myComplex operator +(const myComplex& number) const;
	myComplex operator +(int value) const;
	myComplex operator *(const myComplex& number) const;
	//    myComplex operator *(int value) const;
	myComplex operator -(const myComplex& number) const;
	myComplex operator -(int value) const;

	//difficult
	//���� 2���� �̹� ������ �ܺ��Լ��� �Q��. complex+complex , norm +norm , ���� ������ ���⼭ norm+complex �� �ܺ��Լ���
	//�̷��� �����ε� �ؾ��Ѵ�. ����Լ��� �Ͻ����� ù��° �Ű������� ����Ѵ�.
	// ���� 3���� �Ű������� ����Ѵ�. 2���̻��� �Ű������� ����Ҷ��� �� ����Լ��� ���ļ� ����Ҽ��ִ�.
	//complex+ num �� �տ� ������ ���� �ٲٸ� �ȵ�, �̰� num+ complex
	friend myComplex operator +(int norm, const myComplex& number);
	friend myComplex operator -(int val, const myComplex& number);
	friend myComplex operator *(int val, const myComplex& number);
	//
		//Overloaded assignment operators
	myComplex& operator =(const myComplex& number);
	myComplex& operator =(int value);
	myComplex& operator -=(const myComplex& number);
	//    myComplex& operator -=(int value);


	myComplex& operator +=(const myComplex& number);
	//    myComplex& operator +=(int value);
	myComplex& operator *=(const myComplex& number);
	//    myComplex& operator *=(int value);

	//    operator const +(myComplex& umber);
		 //����������
	myComplex operator ++();
	myComplex operator --();
	//��������
	myComplex operator ++(int);
	myComplex operator --(int);


	//Overloading relational operators
	bool operator == (const myComplex& number) const;
	bool operator > (const myComplex& number) const;
	bool operator < (const myComplex& number) const;
	bool operator != (const myComplex& number) const;
	bool operator >= (const myComplex& number) const;
	bool operator <= (const myComplex& number) const;

	//Overloaded unary operators
	myComplex operator -(); //unary minus
	myComplex operator ~();
private:
	int realPart;
	int imaginaryPart;
	int norm() const;

};

#endif //COMPLEXNUM_MYCOMPLEX_H