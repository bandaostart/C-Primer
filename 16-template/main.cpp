#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
/*
1,类型参数前必须使用关键字class或typename修饰，两者没有区别
  template<typename T, class U> calc(const T&, const U&);


*/




using namespace std;
using std::string;

//函数模板 类型模板参数列表 我们的compare函数声明一个名为T的类型参数，我们用名字T表示一个类型
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

//非类型模板参数 非类型参数，一个非类型参数表示一个值而非一个类型我们通过一个特定的类型名而非关键字class或typename来指定非类型参数
template <unsigned N, unsigned M>
int compare_str(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}






int main(int argc, char *argv[])
{
    //编译器实例化出 int compare(const int&, const int&)
    cout << compare(1, 0) << endl;

    //编译器实例化出 int compare(const vector<int>&, const vector<int>&)
    vector<int> vec1{1,2,3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl;

    //编译器会使用字面常量的大小来替代N和M，从而实例化模板，编译器会在一个字符串字面常量的末尾插入一个空字符作为终结符
    //编译器实例化出 int compare(const char(&p1)[3], const char (&p2)[4])
    cout << compare_str("hi", "mom") << endl;

    return 0;
}
