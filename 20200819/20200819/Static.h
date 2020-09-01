#pragma once

class Static
{
public:
	Static();
	~Static();

	static void Function();
	void Function2();
private:
	static int value4;

	int value2;
	int value3;
};