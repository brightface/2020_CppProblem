#include "cstring"
#include "MyISBN.h"
// constructors
MyISBN::MyISBN()
{
	isbn[0] = '\0';
}
MyISBN::MyISBN(char isbn_number[])
{
	strcpy(isbn, isbn_number);
}
// utility functions
bool MyISBN::isCorrectNumber() 
{
	if (isSyntaxValid() && isCheckSumValid())
		return true;
	else
		return false;
}
// private functions
bool MyISBN::isSyntaxValid() 
{
	_count = 0;
	int tmpCnt = 0;
	int tCnt = 0;
	for (int i = 0; i < strlen(isbn); i++) {
		
		tmpCnt++;

		if (isbn[i] == '-' || isbn[i] == '\0') {
			_count++;
			for (int j = i; j < i + tmpCnt; j++) {
				isbn[j] 
			}
			tmpCnt = 0;
		}
		
	}
}
bool MyISBN::isCheckSumValid() const
{

}

char* MyISBN::getIsbn()
{	
	return isbn;
}
