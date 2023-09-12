#include <iostream>
#pragma warning(disable: 4996)
#pragma warning(disable: 26495)
#pragma warning(disable: 6386)
#pragma warning(disable: 6385)
using namespace std;

struct grade
{
    int phis;
    int math;
    int chim;
};

struct Student
{
    char* name = nullptr;
    int id;
    int age;
    grade tabel;
    float avetabel;
};

struct Soldier
{
    char* name = nullptr;
    int id;
    int age;
    int sernum;
};

void AddStud(Student*& group, int& size1)
{
    char buff[30];
    Student* temp = new Student[size1 + 1];
    for (int i = 0; i < size1; i++)
        temp[i] = group[i];

    delete[] group;
    group = temp;

    cout << "Enter new student name:\n"; cin.getline(buff, 30);
    group[size1].name = new char[strlen(buff) + 1];
    strcpy(group[size1].name, buff);
    cout << "Enter Id:\n"; cin >> group[size1].id;
    cout << "Enter age:\n"; cin >> group[size1].age;
    cout << "Enter grade - phis:\n"; cin >> group[size1].tabel.phis;
    cout << "Enter grade - math:\n"; cin >> group[size1].tabel.math;
    cout << "Enter grade - chim:\n"; cin >> group[size1].tabel.chim;
    group[size1].avetabel = (float)((float)group[size1].tabel.phis + (float)group[size1].tabel.math + (float)group[size1].tabel.chim) / 3;
    cout << "average grade: " << group[size1].avetabel << endl;
    cin.ignore();
    size1++;
}

void ShowStud(Student* group, int size1)
{
    cout << "| # " << "\t" << "| Id " << "\t" << "| Name" << "\t" << "| Age" << "\t" << "| Phis" << "\t" << "| Math" << "\t" << 
        "| Chim" << "\t" << "| Average\t|" << "\n";
    for (int i = 0; i < size1; i++)
    {
        cout << i + 1 << "\t" << group[i].id << "\t" << group[i].name << "\t" << group[i].age << "\t" << group[i].tabel.phis <<
            "\t" << group[i].tabel.math << "\t" << group[i].tabel.chim << "\t" << group[i].avetabel << "\n";
    }
    cout << endl;
}

void ShowSold(Soldier* army, int size2)
{
    cout << "| # " << "\t" << "| Id " << "\t" << "| Name" << "\t" << "| Age" << "\t" << "| Serial number\t|" << "\n";
    for (int i = 0; i < size2; i++)
    {
        cout << i + 1 << "\t" << army[i].id << "\t" << army[i].name << "\t" << army[i].age << "\t" << army[i].sernum << "\n";
    }
    cout << endl;
}

void CheckStud(Student*& group, int& size1, Soldier*& army, int& size2)
{
    srand(time(NULL));
    Student* temp = nullptr;
    int size3 = 0;
    int count = 0;
    for (int i = 0; i < size1; i++)
    {
        if (group[i].avetabel < 3.5)
            count++;
    }
    size2 = count;
    size3 = size1 - count;
    army = new Soldier[size2];
    temp = new Student[size3];
    count = 0;
    size3 = 0;
    for (int i = 0; i < size1; i++)
    {
        if (group[i].avetabel < 3.5)
        {
            army[count].name = new char[strlen(group[i].name) + 1];
            strcpy(army[count].name, group[i].name);
            delete[] group[i].name;
            army[count].id = group[i].id;
            army[count].age = group[i].age;
            army[count].sernum = rand() % 100000;
            count++;
        }
        else if (group[i].avetabel >= 3.5)
        {
            temp[size3].name = new char[strlen(group[i].name) + 1];
            strcpy(temp[size3].name, group[i].name);
            delete[] group[i].name;
            temp[size3].id = group[i].id;
            temp[size3].age = group[i].age;
            temp[size3].tabel.phis = group[i].tabel.phis;
            temp[size3].tabel.math = group[i].tabel.math;
            temp[size3].tabel.chim = group[i].tabel.chim;
            temp[size3].avetabel = group[i].avetabel;
            size3++;
        }
    }
    delete[] group;
    group = temp;
    size1 = size3;
}

void Write(Student* group, Soldier* army, int size1, int size2, char* filename1, char* filename2)
{
    if (size1 > 0 && size2 == 0)
    {
        char buff[10];

        FILE* out = fopen(filename1, "w");
        for (int i = 0; i < size1; i++)
        {
            fputs(group[i].name, out);
            fputc(';', out);
            snprintf(buff, 10, "%d", group[i].id);
            fputs(buff, out);
            fputc(';', out);
            snprintf(buff, 10, "%d", group[i].age);
            fputs(buff, out);
            fputc(';', out);
            snprintf(buff, 10, "%d", group[i].tabel.phis);
            fputs(buff, out);
            fputc(';', out);
            snprintf(buff, 10, "%d", group[i].tabel.math);
            fputs(buff, out);
            fputc(';', out);
            snprintf(buff, 10, "%d", group[i].tabel.chim);
            fputs(buff, out);
            fputc(';', out);
            snprintf(buff, 10, "%f", group[i].avetabel);
            fputs(buff, out);
            fputc(';', out);
            fputc('\n', out);
        }
        fclose(out);
    }

    else if (size1 == 0 && size2 > 0)
    {
        char buff1[10];

        FILE* out1 = fopen(filename2, "w");

        for (int i = 0; i < size2; i++)
        {
            fputs(army[i].name, out1);
            fputc(';', out1);
            snprintf(buff1, 10, "%d", army[i].id);
            fputs(buff1, out1);
            fputc(';', out1);
            snprintf(buff1, 10, "%d", army[i].age);
            fputs(buff1, out1);
            fputc(';', out1);
            snprintf(buff1, 10, "%d", army[i].sernum);
            fputs(buff1, out1);
            fputc(';', out1);
            fputc('\n', out1);
        }
        fclose(out1);
    }
    
    else if (size1 > 0 && size2 > 0)
    {
        char buff[10];
        char buff1[10];

        FILE* out = fopen(filename1, "w");
        for (int i = 0; i < size1; i++)
        {
            fputs(group[i].name, out);
            fputc(';', out);
            snprintf(buff, 10, "%d", group[i].id);
            fputs(buff, out);
            fputc(';', out);
            snprintf(buff, 10, "%d", group[i].age);
            fputs(buff, out);
            fputc(';', out);
            snprintf(buff, 10, "%d", group[i].tabel.phis);
            fputs(buff, out);
            fputc(';', out);
            snprintf(buff, 10, "%d", group[i].tabel.math);
            fputs(buff, out);
            fputc(';', out);
            snprintf(buff, 10, "%d", group[i].tabel.chim);
            fputs(buff, out);
            fputc(';', out);
            snprintf(buff, 10, "%f", group[i].avetabel);
            fputs(buff, out);
            fputc(';', out);
            fputc('\n', out);
        }
        fclose(out);
    
        FILE* out1 = fopen(filename2, "w");

        for (int i = 0; i < size2; i++)
        {
            fputs(army[i].name, out1);
            fputc(';', out1);
            snprintf(buff1, 10, "%d", army[i].id);
            fputs(buff1, out1);
            fputc(';', out1);
            snprintf(buff1, 10, "%d", army[i].age);
            fputs(buff1, out1);
            fputc(';', out1);
            snprintf(buff1, 10, "%d", army[i].sernum);
            fputs(buff1, out1);
            fputc(';', out1);
            fputc('\n', out1);
        }
        fclose(out1);
    }
}

int main()
{
    Student* group = nullptr;
    Soldier* army = nullptr;
    int size1 = 0;
    int size2 = 0;
    int choice;
    bool job = 1;
    char filename1[260];
    char filename2[260];

    while (job)
    {
        if (size1 == 0 && size2 == 0)
        {
            cout << "Enter your choice:\n1 - Add student\n0 - Exit\n";
            cin >> choice;
            if (choice == 1)
            {
                cin.ignore();
                AddStud(group, size1);
                ShowStud(group, size1);
            }
            else if (choice == 0)
            {
                job = 0; cout << "Bye! Bye!\n";
            }
            else
                cout << "Wrong choice!\n";
        }


        else if (size1 == 0 && size2 > 0)
        {
            ShowSold(army, size2);
            cout << "Enter your choice\n1 - Add styudent\n2 - Show soldier(s)\n3 - Write file\n0 - Exit\n";
            cin >> choice;
            if (choice == 1)
            {
                cin.ignore();
                AddStud(group, size1);
                ShowStud(group, size1);
            }
            else if (choice == 2)
            {
                ShowSold(army, size2);
            }
            else if (choice == 3)
            {
                cin.ignore();
                cout << "Enter file name with soldiers:\n";
                cin.getline(filename2, 260);
                Write(group, army, size1, size2, filename1, filename2);
            }
            else if (choice == 0)
            {
                job = 0; cout << "Bye! Bye!\n";
            }
            else
                cout << "Wrong choice!\n";
        }


        else if (size1 > 0 && size2 == 0)
        {
            cout << "Enter your choice\n1 - Add student\n2 - Show student(s)\n3 - Check student(s)\n4 - Write file\n0 - Exit\n";
            cin >> choice;
            if (choice == 1)
            {
                cin.ignore();
                AddStud(group, size1); 
                ShowStud(group, size1);
            }
            else if (choice == 2)
            {
                ShowStud(group, size1);
            }
            else if (choice == 3)
            {
                CheckStud(group, size1, army, size2);
                ShowStud(group, size1);
                ShowSold(army, size2);
            }
            else if (choice == 4)
            {
                cin.ignore();
                cout << "Enter file name with students:\n";
                cin.getline(filename1, 260);
                Write(group, army, size1, size2, filename1, filename2);
            }
            else if (choice == 0)
            {
                job = 0; cout << "Bye! Bye!\n";
            }
            else
                cout << "Wrong choice!\n";
        }
        else
        {
            cout << "Enter your choice:\n1 - Add student\n2 - Show student(s)\n3 - Check student(s)\n4 - Show soldier(s)\n";
            cout << "5 - Write files\n0 - Exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1: cin.ignore(); AddStud(group, size1); ShowStud(group, size1); break;
            case 2: ShowStud(group, size1); break;
            case 3: CheckStud(group, size1,army,size2);  ShowStud(group, size1); ShowSold(army, size2); break;
            case 4: ShowSold(army, size2); break;
            case 5:  
                cin.ignore();
                cout << "Enter file name with students:\n";
                cin.getline(filename1, 260);
                cin.ignore();
                cout << "Enter file name with soldiers:\n";
                cin.getline(filename2, 260);
                Write(group, army, size1, size2, filename1, filename2); 
                break;
            case 0: job = 0; cout << "Bye! Bye!\n"; break;
            default: cout << "Wrong choice! Try agein!\n";
                break;
            }
        }
    }
    for (int i = 0; i < size1; i++)
        delete[] group[i].name;
    delete[] group;

    for (int i = 0; i < size2; i++)
        delete[] army[i].name;
    delete[] army;
}
   