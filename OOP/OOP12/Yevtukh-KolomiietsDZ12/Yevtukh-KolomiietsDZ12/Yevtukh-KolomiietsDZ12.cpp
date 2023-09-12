#include <iostream>
#include <list>
using namespace std;

class Student
{
private:
	string name;
	int course;
	double rating;

public:
	Student(string _name, int _course, double _rating)
	{
		name = _name;
		course = _course;
		if (_rating < 1)
		{
			rating = 1;
		}
		else if (_rating > 5)
		{
			rating = 5;
		}
		else
		{
			rating = _rating;
		}
	}

	Student() : Student(" ", 0, 0.0) { }

	string GetName() const { return name; }
	int GetCourse() const { return course; }
	double GetRating() const { return rating; }
	void SetName(string _name) { name = _name; }
	void SetCours(int _course) { course = _course; }
	void SetRating(double _rating)
	{
		if (_rating < 1)
		{
			rating = 1;
		}
		else if (_rating > 5)
		{
			rating = 5;
		}
		else
		{
			rating = _rating;
		}
	}
};

class ListStudents : public Student
{
private:
	list<Student> AS;

public:
	ListStudents() : Student() {}

	void Add(const Student& _AS)
	{
		AS.insert(AS);
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
}
