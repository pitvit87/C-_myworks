#include <iostream>
using namespace std;

//Функция которая миняет одно слово на второе
void ReplaceText(string& s, const char* oldText, const char* newText) //Функция которая миняет одно слово на второе
{
    string str1 = oldText; // старое слово записываем в строчную переменную
    string str2 = newText; // новое слово записываем в строчную переменную

    int len = str1.length(); // опредиляем длину старого слова
    int index = s.find(str1); // определяем номер символа с которого нужно начинать замену(место)

    s.replace(index, len, str2); // меняем в строке(место, длина, новый текст)
}

// Функция которая делает вставку строки в текст в заданных масивом позициях
void InsertTextInPositions(string& text, const char* str, int* arrayPositions, int size) 
{
    string tempstr = str; // вставляемая строка
    int len = tempstr.length(); // опредиляем ее длинну
    int temp = 0; //счетчик позиций, куда вставить вставляемую строку

    for (int i = 0; i < size; i++) // цикл
    {
        text.insert(arrayPositions[i] + temp, tempstr); //функция вставки строки(индекс куда, какую строку)
        temp += len; // счетчик позиций
    }
}

int main()
{
    string s = "English is a West Germanic language in the Indo-European language family."; //основной текс
    const char* oldText = "West"; // в нем находим слово
    const char* newText = "East"; // заминяемое слово

    cout << endl << "-=~ before change(ReplaceText) ~=-" << endl;
    cout << s << endl;
    cout << endl << "-=~ after change(ReplaceText) ~=-" << endl;
    ReplaceText(s, oldText, newText); // Функция которая миняет одно слово на второе
    cout << s << endl;
    cout << "=====================================================================================" << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    string text = "111111111111111111111111111111111"; // основной текст
    const char* str = "-2-"; // вставляемая строка

    int size = 5;
    int* arrayPosition = new int[size]; // динамичный массив с интовымы переменными
    arrayPosition[0] = 3;
    arrayPosition[1] = 6;
    arrayPosition[2] = 9;
    arrayPosition[3] = 12;
    arrayPosition[4] = 15;

    cout << endl << "-=~ before change(InsertTextInPositions) ~=-" << endl;
    cout << text << endl;
    InsertTextInPositions(text, str, arrayPosition, size); // Функция которая делает вставку строки в текст в заданных масивом позициях
    cout << endl << "-=~ after change(InsertTextInPositions) ~=-" << endl;
    cout << text << endl << endl;

    delete[] arrayPosition; // очистка динамического массива
}
