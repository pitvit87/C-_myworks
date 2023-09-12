#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

struct Worker
{
    char* name = nullptr;
    int ID;
    int pay;
    float bonus;
    float all;
};

void Add(Worker*& group, int& size)
{
    char buff[100];
    Worker* temp = new Worker[size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = group[i];
    delete[] group;
    group = temp;
    cout << "Enter new worker name\n"; cin.getline(buff, 100);
    group[size].name = new char[strlen(buff) + 1];
    strcpy(group[size].name, buff);
    cout << "Enter ID\n"; cin >> group[size].ID;
    cout << "Enter payment\n"; cin >> group[size].pay;
    group[size].bonus = (float)group[size].pay / 10;
    group[size].all = group[size].pay + group[size].bonus;
    size++;
}       

void Delete(Worker*& group, int& size, int index)
{
    Worker* temp = new Worker[size - 1];
    for (int i = 0; i < size; i++ )
    {
        if (i < index) temp[i] = group[i];
        else if (i > index) temp[i-1] = group[i];
    }
    delete[] group[index].name;
    delete[] group;
    group = temp;
    size--;
}

void Show(Worker* group, int size)
{
    cout << "#\tName\t\tID\tPay\tBonus\tAll\n";
    for (int i = 0; i < size; i++)
    {
        cout << i+1 << "\t"  << group[i].name << "\t" << group[i].ID << "\t" << group[i].pay << "\t" << group[i].bonus << "\t" << group[i].all << "\n";
    }
}

void Devision(Worker* group, int size, Worker*& big, int& b_size, Worker*& small, int& s_size)
{
    for (int i = 0; i < size; i++)
        if (group[i].all >= 13000)
            b_size++;
        
    big = new Worker[b_size];
    s_size = size - b_size;
    small = new Worker[s_size];
    int b = 0, s = 0;
    for (int i = 0; i < size; i++)
    {
        if (group[i].all >= 13000)
        {
            big[b] = group[i];
            b++;
        }
        else
        {
            small[s] = group[i];
            s++;
        }
    }
}

void Del_big(Worker*& group, int& size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
        if (group[i].all < 15000)
            counter++;
    Worker* temp = new Worker[counter];
    int k = 0;
    for(int i = 0; i < size; i++)
    {
        if (group[i].all < 15000)
        {
            temp[k] = group[i];
            k++;
        }
        else
        {
            delete[] group[i].name;
        }
    }
    delete[] group;
    group = temp;
    size = counter;
}

void Sort(Worker*& group, int size, int direct)
{
    if (direct == 1)
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size-i-1; j++)
                if (strcmp(group[j].name, group[j + 1].name) > 0)
                    swap(group[j], group[j + 1]);
    }
    else
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size-i- 1; j++)
                if (strcmp(group[j].name, group[j + 1].name) < 0)
                    swap(group[j], group[j + 1]);
    }
}

void Write(Worker*& group, int size, char* filename)
{
    char buff[10];
    FILE* out = fopen(filename, "w");
    for (int i = 0; i < size; i++)
    {
        fputs(group[i].name, out);
        fputc(';', out);
        snprintf(buff, 10, "%d", group[i].ID);
        fputs(buff, out);
        fputc(';', out);
        snprintf(buff, 10, "%d", group[i].pay);
        fputs(buff, out);
        fputc(';', out);
        snprintf(buff, 10, "%f", group[i].bonus);
        fputs(buff, out);
        fputc(';', out);
        snprintf(buff, 10, "%f", group[i].all);
        fputs(buff, out);
        fputc('\n', out);
    }
    fclose(out);
}

void Read(Worker*& group, int& size, char* filename)
{
    char buff[100];
    FILE* in = fopen(filename, "r");
    if (!in) cout << "Wrong file!\n";
    else
    {
        while (fgets(buff, 100, in))
            size++;
        group = new Worker[size];
        rewind(in);
        for (int i = 0; i<size;i++)
        {
            fgets(buff, 100, in);
            char* token = strtok(buff, ";");
            group[i].name = new char[strlen(token) + 1];
            strcpy(group[i].name, token);
            token = strtok(NULL, ";");
            group[i].ID = atoi(token);
            token = strtok(NULL, ";");
            group[i].pay = atoi(token);
            token = strtok(NULL, ";");
            group[i].bonus = atoi(token);
            token = strtok(NULL, ";");
            group[i].all = atoi(token);
            token = strtok(NULL, "\n");
        }
        fclose(in);
    }
}


int main()
{
    Worker* group = nullptr;
    int size = 0;
    int choice;
    bool job = 1;
    int index;
    int direct;
    char filename[260];
    Worker* big = nullptr;
    Worker* small = nullptr;
    int b_size = 0;
    int s_size = 0;
    while (job)
    {
        if (size == 0)
        {

            cout << "Enter your choice\n1-Add\n2-Read\n0-Exit\n";
            cin >> choice;
            if (choice == 1)
            {
                cin.ignore();
                Add(group, size);
            }
            else if (choice == 2)
            {
                cin.ignore();
                cout << "Enter filename\n"; cin.getline(filename, 260);
                Read(group, size, filename);
            }
            else if (choice == 0) job = 0;
            else cout << "Wrong choice!\n";
        }
        else
        {
            cout << "Enter your choice\n1-Add\n2-Show\n3-Delete\n4-Division\n5-Sort\n6-Del_big\n7-Write\n0-exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cin.ignore();
                Add(group, size);
                break;
            case 2: Show(group, size); break;
            case 3:
                cout << "Enter index for delete\n";
                cin >> index;
                index--;
                if (index < 0 || index > size - 1)
                    cout << "Wrong index\n";
                else
                    Delete(group, size, index);
                break;
            case 4:
                Devision(group, size, big, b_size, small, s_size);
                Show(big, b_size);
                Show(small, s_size);
                break;
            case 5:
                cout << "Enter direct\n1 - A->Z\n2 - Z->A\n";
                cin >> direct;
                if (direct < 1 || direct > 2)
                    cout << "Wrong direct!\n";
                else
                    Sort(group, size, direct);
                break;
                cout << "Enter index for delete\n";
                cin >> index;
                break;
            case 6:
                Del_big(group, size); break;
            case 7:
                cin.ignore();
                cout << "Enter filename\n"; cin.getline(filename, 260);
                Write(group, size, filename); break;
            case 0: job = 0; break;
            default: cout << "Wrong choice!\n"; break;
            }
        }
    }
    for (int i = 0; i < size; i++)
        delete[] group[i].name;
    delete[] group;
    if (big != nullptr)
        delete[] big;
    if (small != nullptr)
        delete[] small;
}
  