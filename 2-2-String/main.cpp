#include<string>
#include<iostream>

using namespace std;
int main(int argc, char *argv[])
{
    string str = "";
    string str1(10 , 'H');
    string str2 = "some, string!";

    str = "hello world";
    cout << str  << endl;
    cout << str1 << endl;

    str += str1;
    cout << str <<endl;

    /*
    //C++11
    int count = 0;
    for (auto c : str2)
    {
        if (ispunct(c))
        {
            ++count;
            cout << c <<endl;
        }
    }

    for (auto &c : str2)
    {
        c = toupper(c);
    }
    */
    for (int i=0; i<str2.size(); i++)
    {
        cout << str2[i] <<endl;
    }


    return 0;
}
