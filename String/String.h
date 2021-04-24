#pragma once
#pragma warning(disable:4326)
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

////////// CLASS DECLARATION /////////////////////////////

class String
{
	int size;
	char* str;
public:
	int get_size() const;
	const char* get_str() const;
	char* get_str();
	/*_________________*/
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other)noexcept;
	~String();
	String& operator=(const String& other);
	String& operator+=(const String& other);
	void Print() const;
};


///////// CLASS DECLARATION END ////////////
