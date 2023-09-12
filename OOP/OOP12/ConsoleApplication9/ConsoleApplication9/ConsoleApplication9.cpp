#include <iostream>
#include <list>
#include <vector>
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
    void SetCourse(int _course) { course = _course; }
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
    void Print()
    {
        cout << " Name - " << name << endl;
        cout << " Course - " << course << endl;
        cout << " Rating - " << rating << endl;
    }
};

class ListStudents
{
private:
    list<Student> AS;

public:
    ListStudents() {  }

    void Add(const Student& obj)
    {
        AS.push_back(obj);
    }

    void Add(string name, int course, double rating)
    {
        Student obj(name, course, rating);
        AS.push_back(obj);
    }

    void Print(string msg)
    {
        cout << msg << ":\n";
        list<Student>::iterator iter = AS.begin();
        for (iter; iter != AS.end(); iter++)
        {
            iter->Print();
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Student firstS("Иванов И.", 1, 4);
    Student secondS("Петров П.", 2, 5);
    ListStudents firstL;
    firstL.Add(firstS);
    firstL.Add(secondS);
    firstL.Add("Сидоров С.", 3, 4.3);
    firstL.Print("Группа студентов");
}