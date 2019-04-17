#include "XString.h"

#include <iostream>

int main()
{
	const char* test[20];
	const char* test3[20];
	*test = "Hello There.";
	*test3 = "Changing text.";
	std::string test2 = "What's up?";
	XString One(*test);
	XString Two;
	XString Three(One);
	XString Four(test2);
	XString Five(324);
	One.assign(*test3);
	One.display();
	Three.display();
	Four.display();
	system("pause");
	return 0;
}