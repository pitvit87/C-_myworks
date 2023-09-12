#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

class A
{

};

int main()
{
	string s1 = "abcd";
	
	string s2;
	s2 = s1;

	s1 = "0123456789";
	s2.assign(s1, 2, 4);
	cout << s2 << endl;

	s2.assign(s1, 8);
	cout << s2 << endl;

	s1 = "0123456789";
	s2 = "ABCD";
	s2.append(s1, 8, 15);
	cout << s2 << endl;
	cout << s2.length() << endl;
	cout << s2 << endl;

	s1 = "0123456789";
	s2 = "ABCDEF";
	/*s1.insert(3, s2);
	cout << s1 << endl;*/

	s1.insert(3,s2, 1, 3);
	cout << s1 << endl;


	s1 = "0123456789";
	s2 = "ABCDEF";

	s1.replace(2, 4, s2);
	cout << s1 << endl;

	s1 = "0123456789";
	s2 = "ABCDEF";

	s1.replace(2, 4, s2, 2, 3);
	cout << s1 << endl;

	s1 = "0123456789";
	s2 = "ABCDEF";

	s1.erase(3, 6);
	cout << s1 << endl;

	s1 = "0123456789";
	s2 = "ABCDEF";
	s1.erase(0,s1.length());
	cout << s1 << endl;

	s1 = "0123456789";
	s2 = "ABCDEF";
	int pos = s1.find("456");
	cout << "pos = " << pos << endl;

	pos = s1.find("ABC");
	cout << "pos = " << pos << endl;

	pos = s1.rfind("456");
	cout << "rfind.pos = " << pos << endl;

	s1 = "012345";
	s2 = "012345";
	int res;

	res = s1.compare(s2);
	cout << "res = " << res << endl;

	s1 = "0123456";
	res = s1.compare(s2);
	cout << "res = " << res << endl;

	s1 = "01234";
	res = s1.compare(s2);
	cout << "res = " << res << endl;

	cout << (int)'a' << endl;
	cout << (int)'0' << endl;

	string s1 = "abcd";
	const char* str = s1.c_str();

	cout << "str = " << str << endl;

	int len = s1.length();
	cout << "len = " << len << endl;


}
