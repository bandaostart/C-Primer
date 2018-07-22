#include <iostream>
#include <string>


/*
1，public:   类的所有对象都可以调用public内声明的函数和变量
2，private:  只能被类的成员函数调用，不能被类的对象调用
3，友元函数:   声明后在函数内允许类对象调用使用私有变量
4，类函数实现中::使用，作用域运算符来说明，我们定义了一个类函数，该函数在类内声明
5，构造函数: 构造函数和类的名字相同，没有返回类型；根据参数的不同类可以有多个构造函数(函数重载)，构造函数不接受任何实参
6，默认构造函数:如果程序没有显示的定义构造函数，编译器会为我们隐式定义一个默认构造函数
7，类的拷贝赋值：在使用类的拷贝和赋值过程中需要特别小心，有可能会出错
*/


using namespace std;
//类的定义
class Sales_Data
{
    public:
        Sales_Data();                                        //构造函数
        Sales_Data(string init_str);

        void Sales_Print(void);                              //公共函数
        friend void User_Print(Sales_Data sales_data);       //友元函数

    private:
        string str;                                          //私有变量
        void Salse_Input(void);                              //私有函数
};


//类成员函数实现
void Sales_Data::Sales_Print(void)
{
   cout << str <<endl;
}

void Sales_Data::Salse_Input()
{
    str = "hello world";
}

//类构造函数
Sales_Data::Sales_Data()
{
    str = "";
}

Sales_Data::Sales_Data(string init_str)
{
    str = init_str;
}


/*类的相关非成员函数，被声明友元函数可以调用类的私有变量*/
void User_Print(Sales_Data sales_data)
{
    sales_data.Salse_Input();
    cout << sales_data.str <<endl;
}




int main(void)
{

    Sales_Data sales_data;
    Sales_Data sales_data1("good day!");


    //sales_data.Salse_Input(); 错误使用，类对象不能调用类私有成员函数
    sales_data.Sales_Print();


    sales_data1.Sales_Print();


    User_Print(sales_data);

    return 0;
}
