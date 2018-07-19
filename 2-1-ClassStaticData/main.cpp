#include<iostream>
#include<string>
/*
C++中的::的作用
(1)作用域限定符，当在类体中直接定义函数时，不需要在函数名字的前面加上类名，
   但是在类体外实现函数定义的时候，必须加上类名并且加上作用域限定符.
(2)静态数据成员既可以通过对象名引用，也可以通过类名加::来引用.
*/

/*
C++中的静态数据成员用关键字static表示，首先我们应该从两个维度上来考虑，
（1）是生存周期的角度问题，就是它和Ｃ语言中的static一样，也是在程序开始的时候，分配存储空间，在程序结束的时候才释放存储空间。
（2）能够实现同类的多个对象之间的数据共享。类似于C语言中的全局变量，能够被多个函数所使用。

静态数据成员在使用过程中注意的问题：
（1）静态数据中员不属于对象，普通的数据成员，在声明类的时候是不占有存储空间的，而静态数据成员是不属于类的，所以在声明的时候就占有存储空间。
（2）即使不定义类对象，静态数据成员也可以在类外被引用，即使不定义类对象，也就是说这个和普通成员变量是不同的，普通的成员变量属于类对象，不定义类对象是不可以引用的。
（3）静态成员可以初始化，但是只能在类体外进行初始化，int Box::height=10;
（4）public和private对静态数据成员的影响

在类外初始化的时候是不分public和private的。但是引用的时候就不行了。

但是对于类对象来说，就和原来普通成员变量是相同的了
*/


class static_test
{
    public:
        static int Get_RadomNum(void);
        int Get_SumNum(int num1, int num2);

    private:
        static int num1;
        int num2;

};

int static_test::Get_RadomNum(void)
{
    return 100;
}


int static_test::Get_SumNum(int num1, int num2)
{
    return (num1+num2);
}

int static_test::num1 = 0;




using namespace std;
int main(int argc, char *argv[])
{
    string str = "";

    cout << static_test::Get_RadomNum()<<endl;
    str = "hello world";
    cout << str <<endl;


    return 0;
}











