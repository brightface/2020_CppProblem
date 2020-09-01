#include "MyPolynomial.h"
#include <cstdlib>
#include <cmath>

myPolynomial::myPolynomial(int c, unsigned e) : termNum(1), degree(e)
{
	Terms = new myTerm[termNum];
	Terms[0].setCoeff(c);
	Terms[0].setExp(e);

}
myPolynomial::myPolynomial(int nTerms, int mono[])
{
	termNum = nTerms;
	Terms = new myTerm[termNum];

	for (int i = 0; i < termNum; i++)
	{
		Terms[i].setCoeff(mono[i * 2]);
		Terms[i].setExp(mono[i * 2 + 1]);
	}
	///sort
	for (int i = 0; i < termNum - 1; i++)
	{
		if (Terms[i].getExp() < Terms[i + 1].getExp())
		{
			myTerm temp = Terms[i + 1];
			Terms[i + 1] = Terms[i];
			Terms[i] = temp;
			i = -1;
		}
	}
	degree = getDegree();
}
myPolynomial::myPolynomial(const myPolynomial &poly)
{
	termNum = poly.getNumTerms();

	Terms = new myTerm[termNum];
	for (int i = 0; i < termNum; i++)
	{
		Terms[i] = poly.Terms[i];
	}
	degree = poly.getDegree();
}
long myPolynomial::operator() (int x) const
{
	long ans = 0;
	for (int i = 0; i < termNum; i++)
	{
		ans += Terms[i].getCoeff()*pow(x, Terms[i].getExp());
	}
	return ans;
}
int myPolynomial::getDegree() const
{
	return Terms[0].getExp();
}
unsigned myPolynomial::getNumTerms() const
{
	return termNum;
}
myPolynomial myPolynomial::ddx() const
{
	myPolynomial ans = *this;

	for (int i = 0; i < termNum; i++)
	{
		ans.Terms[i] = ans.Terms[i].ddx();
		if (ans.Terms[i].getCoeff() == 0 && ans.termNum > 1)
			ans.termNum--;
	}

	return ans;
}




bool myPolynomial::operator == (const myPolynomial &poly) const
{
	if (termNum != poly.getNumTerms())
		return false;
	for (int i = 0; i < termNum; i++)
	{
		if (Terms[i] != poly.Terms[i])
			return false;
	}
	return true;
}
bool myPolynomial::operator != (const myPolynomial &poly) const
{
	return !(operator ==(poly));
}



myPolynomial myPolynomial::operator -() const
{
	myPolynomial ans = *this;
	for (int i = 0; i < termNum; i++)
	{
		ans.Terms[i] = -ans.Terms[i];
	}
	return ans;
}


myPolynomial myPolynomial::operator *(int k) const
{
	if (k == 0)
		return myPolynomial::ZERO;

	myPolynomial ans = *this;
	for (int i = 0; i < termNum; i++)
	{
		ans.Terms[i].setCoeff(ans.Terms[i].getCoeff()*k);
	}
	return ans;
}
myPolynomial myPolynomial::operator +(const myPolynomial &poly) const
{
	int data[500] = { 0, };
	int id = 0;
	int aPos = 0, bPos = 0;
	int realTermNum = 0;

	while (aPos < termNum && bPos < poly.termNum)
	{
		if (Terms[aPos].getExp() < poly.Terms[bPos].getExp())
		{
			data[id] = poly.Terms[bPos].getCoeff();
			data[id + 1] = poly.Terms[bPos].getExp();
			id += 2, bPos++;
		}
		else if (Terms[aPos].getExp() == poly.Terms[bPos].getExp())
		{
			data[id] = Terms[aPos].getCoeff() + poly.Terms[bPos].getCoeff();
			data[id + 1] = Terms[aPos].getExp();
			id += 2, aPos++, bPos++;
		}
		else
		{
			data[id] = Terms[aPos].getCoeff();
			data[id + 1] = Terms[aPos].getExp();
			id += 2, aPos++;
		}
		realTermNum++;
	}
	while (aPos < termNum)
	{
		data[id] = Terms[aPos].getCoeff();
		data[id + 1] = Terms[aPos].getExp();
		id += 2, aPos++;
	}
	while (bPos < poly.termNum)
	{
		data[id] = poly.Terms[bPos].getCoeff();
		data[id + 1] = poly.Terms[bPos].getExp();
		id += 2, bPos++;
	}

	myPolynomial ans(250, data);
	ans.termNum = realTermNum;

	return ans;
}
myPolynomial myPolynomial::operator -(const myPolynomial &poly) const
{
	int data[500] = { 0, };
	int id = 0;
	int aPos = 0, bPos = 0;
	int realTermNum = 0;

	while (aPos < termNum && bPos < poly.termNum)
	{
		if (Terms[aPos].getExp() < poly.Terms[bPos].getExp())
		{
			data[id] = -poly.Terms[bPos].getCoeff();
			data[id + 1] = poly.Terms[bPos].getExp();
			id += 2, bPos++;
		}
		else if (Terms[aPos].getExp() == poly.Terms[bPos].getExp())
		{
			data[id] = Terms[aPos].getCoeff() - poly.Terms[bPos].getCoeff();
			data[id + 1] = Terms[aPos].getExp();
			id += 2, aPos++, bPos++;
		}
		else
		{
			data[id] = Terms[aPos].getCoeff();
			data[id + 1] = Terms[aPos].getExp();
			id += 2, aPos++;
		}
		realTermNum++;
	}
	while (aPos < termNum)
	{
		data[id] = Terms[aPos].getCoeff();
		data[id + 1] = Terms[aPos].getExp();
		id += 2, aPos++, realTermNum++;
	}
	while (bPos < poly.termNum)
	{
		data[id] = -poly.Terms[bPos].getCoeff();
		data[id + 1] = poly.Terms[bPos].getExp();
		id += 2, bPos++, realTermNum++;
	}

	myPolynomial ans(250, data);
	ans.termNum = realTermNum;

	return ans;
}
myPolynomial myPolynomial::operator *(const myPolynomial &poly) const
{
	int exps[250];
	for (int i = 0; i < 250; i++)
	{
		exps[i] = -1;
	}

	int data[500];
	for (int i = 0; i < 500; i += 2)
	{
		data[i] = 0;
		data[i + 1] = 0;
	}

	int realTermNum = 0;

	for (int i = 0; i < termNum; i++)
	{
		for (int j = 0; j < poly.termNum; j++)
		{
			for (int k = 0; k < realTermNum; k++)
			{
				if (exps[k] == Terms[i].getExp() + poly.Terms[j].getExp() || Terms[i].getCoeff() * poly.Terms[j].getCoeff() == 0)
					goto skip;
			}
			exps[realTermNum] = Terms[i].getExp() + poly.Terms[j].getExp();
			realTermNum++;
		skip:
			continue;
		}
	}

	int id = 0;

	for (int i = 1; i <= realTermNum * 2; i += 2)
	{
		data[i] = exps[id];
		id++;
	}

	for (int i = 0; i < termNum; i++)
	{
		for (int j = 0; j < poly.termNum; j++)
		{
			for (int k = 1; k < realTermNum * 2; k += 2)
			{
				if (Terms[i].getExp() + poly.Terms[j].getExp() == data[k])
					data[k - 1] += Terms[i].getCoeff() * poly.Terms[j].getCoeff();
			}
		}
	}

	myPolynomial ans(250, data);
	ans.termNum = realTermNum;

	return ans;
}



myPolynomial& myPolynomial::operator += (const myPolynomial &poly)
{
	*this = *this + poly;
	return *this;
}
myPolynomial& myPolynomial::operator -= (const myPolynomial &poly)
{
	*this = *this - poly;
	return *this;
}
myPolynomial& myPolynomial::operator *= (const myPolynomial &poly)
{
	*this = *this * poly;
	return *this;
}
myPolynomial& myPolynomial::operator *= (int k)
{
	*this = *this * k;
	return *this;
}
myPolynomial operator *(int k, const myPolynomial &poly)
{
	return poly * k;
}


/********************* add your code here ********************************/




// output operator
ostream& operator <<(ostream &outStream, const myPolynomial& poly)
{
	bool finish = true;
	if (poly == myPolynomial::ZERO)
		return outStream << 0;

	outStream << poly.Terms[0];
	if (poly.Terms[0].getCoeff() != 0)
		finish = false;

	for (int i = 1; i < poly.termNum; i++)
	{

		if (poly.Terms[i].getCoeff() != 0)
			finish = false;

		if (poly.Terms[i].getCoeff() > 0)
			outStream << '+';

		outStream << poly.Terms[i];

	}
	if (finish)
		return outStream << '0';


	/********************* add your code here ********************************/
	return outStream;
}
const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x
