#include "String.h"

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