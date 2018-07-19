#include <iostream>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    unsigned int num1 = 20;
    int num2 = -40;

    cout << "Char        = " << sizeof(char)      << " Byte\r\n";
    cout << "Short       = " << sizeof(short)     << " Byte\r\n";
    cout << "int         = " << sizeof(int)       << " Byte\r\n";
    cout << "long        = " << sizeof(long)      << " Byte\r\n";
    cout << "long long   = " << sizeof(long long) << " Byte\r\n";
    cout << "float       = " << sizeof(float)     << " Byte\r\n";
    cout << "double      = " << sizeof(double)    << " Byte\r\n";
    cout << "long double = " << sizeof(double)    << " Byte\r\n";

    cout << "num1=20;num2=-40: =>";
    cout << "num2+num1 = " << (num2+num1) <<endl;


    /*Output Result
    Char        = 1 Byte
    Short       = 2 Byte
    int         = 4 Byte
    long        = 4 Byte
    long long   = 8 Byte
    float       = 4 Byte
    double      = 8 Byte
    long double = 8 Byte
    num1=20;num2=-40: =>num2+num1 = 4294967276
    */
    return 0;
}
