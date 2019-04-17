#include <string>
#pragma once


class XString {
protected:
	char* raw_string;
	size_t capacity;

public:
	XString();
	XString(const char*);
	XString(const XString&);
	XString(const std::string&);
	XString(size_t);
	~XString();

	int len(const char*); //returns string length.
	void clear();
	int capmod(); //returns the capacity of the string.
	std::string str(std::string&);
	void display();

	void assign(const char*);
	void assign(XString&);
	void assign(const std::string&);

	void append(const char*);
	void append(XString&);
	void append(const std::string&);

};