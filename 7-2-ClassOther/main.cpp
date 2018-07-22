#include <iostream>
#include <string>
using namespace std;


/*
1，定义类型成员：例：定义pos为size_type类型和 using pos = std::string::size_type相同
2，引用：格式：类型 &引用变量名 = 已定义变量名；特点：一个变量可以取多个别名、引用必须初始化、引用只能引用一次；常用作函数参数，函数返回值
3，引用作为函数返回值：1，不使用引用作为函数返回值：返回值是调用函数时创建的临时对象，函数调用完成后释放
                   2，使用引用作为函数返回值：返回的是对象本身，所以千万不能返回局部对象的引用
                   3，引用作为函数返回值，返回时不能做算术运算
                   3，const修饰引用作为函数返回值，防止被莫名其妙复制
4，类内联函数：定义在类内部的函数自动是inline的
5，类成员函数可以重载
6，类的声明
7，友元类
8，类的静态成员
*/


class Screen;                                             //类的声明


class Screen                                              //类的定义
{
    public:
        typedef std::string::size_type pos;
        Screen() = default;                               //使用default生成默认构造函数
        Screen(pos ht, pos wt, char c);                   //另外一个构造函数，可以让用户进行屏幕初始化

        pos  get_cursor()                                 //隐式内联函数，在类内定义函数
        {

            return cursor;
        }

        inline string  get_contens();                     //显示内联函数

        void set_ht_wt(pos ht);                           //类成员函数重载
        void set_ht_wt(pos ht, pos wt);

        Screen &get_this();                               //返回对象，通过引用返回的是对象本身不是对象副本

        friend class Max_Screen;                          //友元类，Max_Screen可以调用Screen的函数和变量

        static void Screen_Init(void);                    //类的静态成员函数

    private:
        pos cursor = 0;
        pos height = 0, weight = 0;
        std::string contens;
};


//重载构造函数
Screen::Screen(pos ht, pos wt, char c)
{
    cursor = c;
    height = ht;
    weight = wt;

    cout <<"Init ht wt:";
    cout << ht << " ";
    cout << wt <<endl;

}
//类函数定义
string Screen::get_contens()
{
    return contens;
}

//类成员函数重载
void Screen::set_ht_wt(pos ht)
{
    height = ht;
}
void Screen::set_ht_wt(pos ht, pos wt)
{
    height = ht;
    weight = wt;

    cout << "Set ht wt:";
    cout << ht << " "<< wt <<endl;
}



//返回对象this指针
Screen &Screen::get_this()
{
    return *this;
}


//友元类
class Max_Screen
{
    public:
    private:
};

//类静态成员函数
void Screen::Screen_Init()
{
//静态成员函数不能调用私有变量等
//    cursor = 0;
//    weight = 0;
//    height = 0;
    cout << "Screen Init" <<endl;
}






int main()
{
    //引用测试
    int a = 1, &a1 = a;
    a1++;
    cout << a <<endl;

    //静态成员函数测试
    Screen::Screen_Init();

    //类测试
    Screen screen(100, 20, 10);
    screen.set_ht_wt(200, 200);


    //静态成员测试,可以被类对象调用
    screen.Screen_Init();

    return 0;
}
