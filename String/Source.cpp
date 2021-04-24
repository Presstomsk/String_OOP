﻿#pragma warning(disable:4326)
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);

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

///////// CLASS DEFINITION ////////////////////

int String::get_size() const
{
	return size;
}
const char* String::get_str() const
{
	return str;
}
char* String::get_str()
{
	return str;
}
/*_________________*/
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];*/
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other)noexcept :size(other.size), str(other.str)
{
	/*this->size = other.size;
	this->str = other.str;*/
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;

}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return (*this = *this + other);
}
void String::Print() const
{
	cout << "Size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i+left.get_size()-1] = right.get_str()[i];
	return result;

}

/////////// CLASS DEFINITION END /////////////////////////////////

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK

	String str;
	str.Print();
	String str1 = "Hello";
	str1.Print();
	cout << str1 << endl;
	String str2 = str1;
	cout << str2 << endl;
	str = str2;
	cout << str << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
#endif // ASSIGNMENT_CHECK
#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;
	/*str1 += str2;
	cout << str1 << endl;*/
#endif // OPERATOR_PLUS_CHECK

	
}