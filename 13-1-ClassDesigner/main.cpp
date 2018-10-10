#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

/*
1,拷贝构造函数，拷贝赋值运算符，移动构造函数，移动赋值运算符，析构函数
  拷贝和移动构造函数定义了当用同类型的另一个对象初始化本对象时做什么
  拷贝和移动赋值运算符定义了将一个对象赋予同类型的另一个对象时做什么
  析构函数定义了将一个对象销毁时做什么



*/
using namespace std;
class Sales_data
{
    public:
       ~Sales_data();                                                 //析构函数
    private:
};

Sales_data::~Sales_data()
{

}



class Test_Num1
{
    public:
        Test_Num1(void)                                                //构造函数
        {
            x = 0;
            y = 0;
            cout << "Tset_Num1 Constructor be called" <<endl;
        }

        ~Test_Num1()                                                  //析构函数
        {

        }

        Test_Num1(const Test_Num1 &tc)                                //拷贝构造函数，必须使用引用
        {
            x=tc.x;
            y=tc.y;
            cout << "Test_Num1 Copy Constructor Called" << endl;
        }

        const Test_Num1 &operator = (const Test_Num1 &right)          //赋值构造函数
        {
            x = right.x;
            y = right.y;
            cout << "Tset_Num1 Operator = be Called" << endl;
            return *this;
        }
    private:
        int x, y;
};

class Test_Num2
{
    public:
        Test_Num2()                                                      //构造函数
        {
            cout << "Test_Num2 Constructor be called" <<endl;
        }

        explicit Test_Num2(const Test_Num1 &tcc)                         //显示构造函数
        {
            tc = tcc;
        }

        ~Test_Num2()                                                    //析构函数
        {

        }

        Test_Num2(const Test_Num2 &test_num2): tc(test_num2.tc)        //拷贝构造函数
        {
            tc = test_num2.tc;
            cout << "Test_Num2 Copy Constructor be called" << endl;
        }

        const Test_Num2 &operator = (const Test_Num2 &right)           //赋值构造函数
        {
            tc = right.tc;
            cout << "Test_Num2 Operator = be Called" << endl;

            return *this;
        }
    private:
        Test_Num1 tc;
};






int main(void)
{
    string dots(10, '.');                                               //直接初始化
    string s(dots);                                                     //直接初始化
    string ss = dots;                                                   //拷贝初始化
    string null_book = "999999";                                        //拷贝初始化
    string nines = string(100, '9');                                    //拷贝初始化


    //退出局部作用域；对item p2 和vec调用析构函数
    //销毁p2会递减其引用计数；如果引用计数变为0，对象被释放
    //销毁vec会销毁它的元素
    {
        //p和p2指向动态分配的对象
        Sales_data *p = new Sales_data;                                 //p是一个内置指针
        auto p2 = make_shared<Sales_data>();                            //p2是一个shared_ptr
        Sales_data item(*p);                                            //拷贝构造函数将*p拷贝到item中
        vector<Sales_data>vec;                                          //局部对象
        vec.push_back(*p2);                                             //拷贝p2指向的对象
        delete p;
    }

    string s1("hello"), s2 = s1;                                        //拷贝构造函数
    string s3("hello"), s4;
    s3 = s4;                                                            //赋值运算重载

    //如果一个类，需要析构函数，我们几乎可以肯定它也需要一个拷贝构造函数和一个拷贝赋值运算符
    cout << "Test_Num1 test_num1" << endl;
    Test_Num1 test_num1;
    cout << endl;

    cout << "Test_Num1 test_num2 = test_num1" << endl;
    Test_Num1 test_num2 = test_num1;
    cout << endl;

    cout << "Test_Num1 test_num3(test_num2)" << endl;
    Test_Num1 test_num3(test_num2);
    cout << endl;

    cout << "test_num3 = test_num1" << endl;
    test_num3 = test_num1;
    cout << endl;

    cout << "Test_Num2 test1" << endl;
    Test_Num2 test1;
    cout << endl;

    cout << "Test_Num2 test2=test1" << endl;
    Test_Num2 test2=test1;
    cout << endl;

    cout << "Test_Num2 test3(test2)" << endl;
    Test_Num2 test3(test2);
    cout << endl;

    cout << "test3 = test1" << endl;
    test3 = test1;
    cout << endl;


    return 0;
}
