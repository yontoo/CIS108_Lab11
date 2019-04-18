#include "XString.h"
#include <string>
#include <iostream>


XString::XString(){
	capacity = 256;
	raw_string = new char[capacity];
	raw_string[0] = '\0';
}

XString::XString(const char* ArrayInput) {
	capacity = len(ArrayInput) + 1;
	raw_string = new char[capacity];
	for (int x = 0; x < (capacity - 1); x++)
	{
		raw_string[x] = ArrayInput[x];
	}
	raw_string[(capacity - 1)] = '\0';
}

XString::XString(const XString& SomeXString)
{
	capacity = SomeXString.capacity;
	raw_string = new char[capacity];
	for (int x = 0; x < (capacity - 1); x++)
	{
		raw_string[x] = SomeXString.raw_string[x];
	}
	raw_string[(capacity - 1)] = '\0';
}

XString::XString(const std::string & SomeString)		//https://stackoverflow.com/questions/4207737/how-to-convert-stdstring-to-const-char helped with this one.
{
	const char* StringPoint = SomeString.c_str();
	capacity = len(StringPoint) + 1;
	raw_string = new char[capacity];
	for (int x = 0; x < (capacity - 1); x++)
	{
		raw_string[x] = StringPoint[x];
	}
	raw_string[(capacity - 1)] = '\0';
}

XString::XString(size_t SomeCapacity)
{
	capacity = SomeCapacity;
	raw_string = new char[capacity];
	raw_string[0] = '\0';
}

void XString::assign(const char* ArrayInput)
{
	capacity = len(ArrayInput) + 1;
	raw_string = new char[capacity];
	for (int x = 0; x < (capacity - 1); x++)
	{
		raw_string[x] = ArrayInput[x];
	}
	raw_string[(capacity - 1)] = '\0';
}

void XString::assign(XString & SomeXString)
{
	capacity = SomeXString.capacity;
	raw_string = new char[capacity];
	for (int x = 0; x < (capacity - 1); x++)
	{
		raw_string[x] = SomeXString.raw_string[x];
	}
	raw_string[(capacity - 1)] = '\0';
}

void XString::assign(const std::string & SomeString)
{
	const char* StringPoint = SomeString.c_str();
	raw_string = new char[capacity];
	capacity = len(StringPoint) + 1;
	for (int x = 0; x < (capacity - 1); x++)
	{
		raw_string[x] = StringPoint[x];
	}
	raw_string[(capacity - 1)] = '\0';
}

void XString::append(const char * ArrayInput)
{
	capacity = len(raw_string) + len(ArrayInput);
	for (int x = len(raw_string), y = 0; x < (capacity); x++, y++)
	{
		raw_string[x] = ArrayInput[y];
	}
	raw_string[capacity] = '\0';
}

void XString::append(XString & SomeXString)
{
	capacity = len(raw_string) + SomeXString.capacity;
	for (int x = len(raw_string), y = 0; x < (capacity); x++, y++)
	{
		raw_string[x] = SomeXString.raw_string[y];
	}
	raw_string[capacity] = '\0';
}

void XString::append(const std::string & SomeString)
{
	const char* StringPoint = SomeString.c_str();
	capacity = len(StringPoint) + len(raw_string);
	for (int x = len(raw_string), y = 0; x < (capacity); x++, y++)
	{
		raw_string[x] = StringPoint[y];
	}
	raw_string[(capacity - 1)] = '\0';
}

XString::~XString() {
	delete[] raw_string;
	raw_string = nullptr;
}

size_t XString::len(const char* ArrayLen)
{
	const char* ArrayPoint = ArrayLen;
	while (*ArrayPoint)		//While loop walks through pointer until '\0'. Used https://stackoverflow.com/questions/26923117/rewriting-strlen-in-c for help with this one.
	{
		++ArrayPoint;
	}
	return ArrayPoint - ArrayLen;
}

void XString::display() {
	std::cout << raw_string << std::endl;
}

int XString::capmod()
{
	return capacity - 1;
}