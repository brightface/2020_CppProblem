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
	//위에 2개가 이미 있으니 외부함수로 뻈다. complex+complex , norm +norm , 위에 있으니 여기서 norm+complex 는 외부함수로
	//이렇게 오버로딩 해야한다. 멤버함수는 암시적인 첫번째 매개변수를 사용한다.
	// 따라서 3개의 매개변수를 사용한다. 2개이상의 매개변수를 사용할때는 비 멤버함수로 고쳐서 사용할수있다.
	//complex+ num 은 앞에 있으니 순서 바꾸면 안돼, 이건 num+ complex
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
		 //전위연산자
	myComplex operator ++();
	myComplex operator --();
	//후위연산
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