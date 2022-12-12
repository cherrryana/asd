#include <iostream>
#include <stack>
#include <string>
#include <locale.h> 

using namespace std;
    
    int main()
    {
        string str;
        setlocale(LC_ALL, "Rus");
        cout << "Введите строку :" << endl;
        cin >> str;
        stack <char> s;
        int f = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                s.push(str[i]);
            }

            else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
            {
                if (s.empty())
                    f = 1;
                else if (((str[i] == ')') && (s.top() == '(')) ||
                    ((str[i] == '}') && (s.top() == '{')) ||
                    ((str[i] == ']') && (s.top() == '[')))
                    s.pop();
            }
        }

        if (f == 1 || not s.empty()) printf("Строка составлена неверно");
        else printf("Строка составлена верно");
    }