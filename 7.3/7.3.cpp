// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(0, "");

    string st = "my.txt";
    string s = "m.txt";
    ifstream fin;
    fstream fin2;
    fin2.open(s, fstream::out);
    fin.open(st);

    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл";
    }
    if (!fin2.is_open())
    {
        cout << "Не удалось открыть файл";
    }
    else
    {
        string msg;

        int c;
        cout << "Чтобы включить программу напишите 1\n";
        cin >> c;

        if (c == 1)
        {
            //SetConsoleCP(1251);
            int count = 0;
            char a;
            cout << "Введите букву\t:";
            cin >> a;

            cout << "\nВсе слова из файла на букву: ";  cout << a; cout << "\n";
            while (!fin.eof())
            {
                msg = "";
                fin >> msg;

                if (msg[0] == a)
                {
                    fin2 << msg << endl;
                    count++; cout << msg << ' ';

                }


            }
            cout << endl;

            fin2.close();
            fin2.open(s, fstream::in);
            unsigned int i = 0;



            string* arr = new string[count+1];

            int** arr1 = new int* [count];

            for (int i = 0; i < count; i++)
            {
                arr1[i] = new int[2];
            }

            int p = 0;
            string str;
            while (!fin2.eof())
            {
                str = "";
                fin2 >> str;

                arr[p] = str;

                p++;
            }
            for (int i = 0; i < count; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    arr1[i][j] = -1;
                }
            }

            for (int i = 0; i < count; i++)
            {

                bool f = true;

                for (int j = 0; j < i; j++)
                {


                    if (arr[i] == arr[arr1[j][0]])
                    {

                        arr1[j][1]++;
                        f = false;
                        break;

                    }


                }

                if (f)
                {
                    arr1[i][0] = i;
                    arr1[i][1] = 1;
                }
            }
                int tmp;

             for (int i = 0; i <  count; ++i) // i - номер прохода
             {
                for (int j = 0; j < count - 1-i; ++j) // внутренний цикл прохода
                {
                    if (arr1[j][1] < arr1[j + 1][1])
                    {
                        tmp = arr1[j + 1][0];
                        arr1[j + 1][0] = arr1[j][0];
                        arr1[j][0] = tmp;
                        tmp = arr1[j + 1][1];
                        arr1[j + 1][1] = arr1[j][1];
                        arr1[j][1] = tmp;
                    }
                }
             }
             
             cout << endl;

             cout << endl;
             for (int i = 0; i < count; i++)
             {
                 if (arr1[i][0] != -1)
                     cout << arr[arr1[i][0]] << endl;

             }

             cout << endl;

        }

    }

    fin.close();
    fin2.close();
    return 0;
}

