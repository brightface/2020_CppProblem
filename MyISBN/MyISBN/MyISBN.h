#ifndef _MY_ISBN_H_
#define _MY_ISBN_H_
const int max_length = 256;
class MyISBN
{
public:
	// constructors
	MyISBN();
	MyISBN(char isbn_number[]);
	// utility functions
	bool isCorrectNumber();
private:
	char isbn[max_length + 11];
	//isbn 문자열 가지고 있다.
	bool isSyntaxValid();
	bool isCheckSumValid() const;
public:	
	int _count;
	char* getIsbn();
};
#endif // _MY_ISBN_H_