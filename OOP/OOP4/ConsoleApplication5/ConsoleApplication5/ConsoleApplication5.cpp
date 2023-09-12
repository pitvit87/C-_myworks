#include <iostream>
using namespace std;

class msg
{
	char* str;

public:

	msg()
	{
		str = nullptr;
	}

	msg(str)
	{
		str = new char str[strlen(str) + 1];
		strcpy_s(_str, (str)+1, str);
	}

	msg(str)
	{
		str = new char[(str)+1];
	};
	~msg();

private:

};

msg::msg()
{
}

msg::~msg()
{
}



int main()
{

}
