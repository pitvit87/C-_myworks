#include <iostream>
using namespace std;


int main()
{
	char chr = 't';
	char str1[] = "This is string!";
	cout << "str1=" << str1 << "\n";

	char str2[] = { 'T','h','i','s',' ','i','s',' ','s','t','r','i','n','g','2','!','\0' };
	cout << "str2=" << str2 << "\n";

	char str3[100];
	cout << "Enter string:\n";
	cin.getline(str3, 100);
	cout << "str3=" << str3 << "\n";
	
	const char* str4 = "This is string4!";
	cout << "str4=" << str4 << "\n";

	string str5 = "This is string5!";
	cout << "str5=" << str5 << "\n";
}
