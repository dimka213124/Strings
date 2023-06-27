#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int Task1() {
    /*
        Дана строка из символов, требуется выяснить сколько раз встречается 
        заданный пользователем символ. 
    */

    string str;
    char symb;

    cout << "Введите строку:\t";
    getline(cin, str);

    cout << "Введите символ для поиска:\t";
    cin >> symb;

    int k = 0;

    string::size_type pos = 0;
    string::size_type n = str.find(symb, pos);

    while (n != string::npos) {
        k++;
        pos = n+1;      
        n = str.find(symb, pos);
    }

    cout << "Кол-во найденных символов:\t" << k << endl;

    return 0;
}

int Task2() {
    /*
        Заменить все вхождения символа на другой.
    */

    string str;
    string symb;
    string symbReplace;

    cout << "Введите строку:\t";
    getline(cin, str);

    cout << "Введите символ для поиска:\t";
    cin >> symb;

    cout << "Введите символ для замены:\t";
    cin >> symbReplace;

    cout << str << endl;

    size_t pos = 0;

    while ((pos = str.find(symb)) != string::npos) {
        str.replace(pos, 1, symbReplace);
    }

    cout << str << endl;

    return 0;
}

int Task3() {
    /*
        Заменить каждую точку – многоточием.
    */

    string str;
    char symb = '.';

    cout << "Введите строку:\t";
    cin.get();
    getline(cin, str);

    cout << str << endl;

    string::size_type pos = 0;
    string::size_type n = str.find(symb, pos);

    while (n != string::npos) {
        str.insert(n, 2, symb);
        pos = n + 3;
        n = str.find(symb, pos);
    }

    cout << str << endl;

    return 0;
}

int Task4() {
    /*
        Удалить из заданной строки все цифры.
    */

    string str;

    cout << "Введите строку:\t";
    cin.get();
    getline(cin, str);

    cout << str << endl;

    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            str.erase(i, 1);
            i--;
        }
    }

    cout << str << endl;

    return 0;
}

int Task5() {
    /*
        Строка состоит из слов, разделённых пробелами. На экран вывести количество слов в строке, у которых начало и конец на одну и туже букву. 
    */

    string str;
    char symb = ' ';

    cout << "Введите строку:\t";
    getline(cin, str);

    cout << str << "\t" << str.length() << endl;

    int k = 0;

    string::size_type pos = 0;
    string::size_type n = str.find(symb, pos);

    while (n != string::npos) {
        if (str[pos] == str[n - 1]) k++;
        pos = n + 1;
        n = str.find(symb, pos);
    }

    if (str[pos] == str[str.length() - 1]) k++;

    cout << "Количество слов:\t" << k;

    return 0;
}

int Task6() {
    /*
        Строка представляет собой слова которые могут быть разделены знаками препинания (, ; пробел)
        посчитать слова начало и конец – на одну и туже букву. 
    */

    return 0;
}

int Task7() {
    /*
        Известно имя, фамилия, отчество, вывести на экран код личности. 
        Код личности: буквы превращаем в порядковый номер алфавита, потом получаем их сумму. 
        Складываем до тех пор, пока не получится цифра. (пока однозначным не станет). 
    */

    string alpht = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    string name,
        surname,
        fname;

    cout << "Введите имя:\t";
    getline(cin, name);

    cout << "Введите фамилию:\t";
    getline(cin, surname);

    cout << "Введите отчество:\t";
    getline(cin, fname);

    int sum1 = 0,
        sum2 = 0,
        sum3 = 0;
    char symb;
    string::size_type n;

    for (int i = 0; i < name.length(); i++) {
        symb = tolower(name[i]);
        n = alpht.find(symb, 0);
        sum1 += (int)n+1;
        
    }

    for (int i = 0; i < surname.length(); i++) {
        symb = tolower(surname[i]);
        n = alpht.find(symb, 0);
        sum2 += (int)n + 1;

    }

    for (int i = 0; i < fname.length(); i++) {
        symb = tolower(fname[i]);
        n = alpht.find(symb, 0);
        sum3 += (int)n + 1;
    }

    int sum = sum1 + sum2 + sum3;

    string sumS = to_string(sum);

    while (sumS.length() != 1) {
        int sumF = 0;

        for (int i = 0; i < sumS.length(); i++) {
            sumF += (int)sumS[i] - 48;
        }

        sumS = to_string(sumF);
    }

    cout << "Код личности:\t" << sumS << endl;

    return 0;
}

int Task8() {
    /*
        В шифре цезаря алфавит размещён на круге по часовой стрелке (за последней буквой идёт первая).
        При шифровании текста буквы заменяются другими буквами, отстоящими по кругу на заданное количество позиций (сдвиг) дальше по часовой стрелке.
    */

    string alpht = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    string text;
    int k;

    cout << "Введите текст:\t";
    //cin.get();
    getline(cin, text);

    cout << "Введите шаг:\t";
    cin >> k;

    //cout << text << "\t" << text.length() << endl;

    string::size_type n;
    char symb;
    char symbr;
    string hash;
    int alphtSz = (int) alpht.length();
    int kn;
    string::size_type i;

    for (i = 0; i < text.length(); i++) {
        if (text[i] != ' ' && text[i] != '.' && text[i] != ',' && text[i] != ':' && text[i] != ';') {
            symb = tolower(text[i]);
            n = alpht.find(symb, 0);

            kn = (int)n + k;

            if (kn <= alpht.length()) {
                if (isupper((unsigned char)text[i])) {
                    symbr = toupper(alpht[kn]);
                    hash.insert(i, 1, symbr);
                }
                else {
                    symbr = alpht[kn];
                    hash.insert(i, 1, symbr);
                }
            }
            else {
                while(kn > alphtSz) kn -= alphtSz;

                if (isupper((unsigned char)text[i])) {
                    symbr = toupper(alpht[kn]);
                    hash.insert(i, 1, symbr);
                }
                else {
                    symbr = alpht[kn];
                    hash.insert(i, 1, symbr);
                }
            }
        }
        else {
            hash.insert(i, 1, text[i]);
        }
    }

    cout << "Шифр:\t" << hash << endl;

    return 0;
}

int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    //Task1();
    //Task2();
    //Task3();
    //Task4();
    //Task5();
    //Task7();
    Task8();

    return 0;
}