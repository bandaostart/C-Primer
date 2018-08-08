#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

/*
1，插入迭代器
当我们通过一个插入迭代器进行赋值时，该迭代器调用容器操作来向给定容器的指定位置插入一个元素
back_inserter:创建一个push_back的迭代器
front_inserter:创建一个push_front的迭代器
inserter：创建一个insert的迭代器

2,iosteam迭代器

3，反向迭代器

4，迭代器类别
输入迭代器；输出迭代器；前向迭代器；双向迭代器；随机访问迭代器

5，算法一般明明规则
alg(beg, end, args)
alg(beg, end, dest, args)
alg(beg, end, beg2, args)
alg(beg, end, beg2, end2, args)

6,谓词
一元函数对象：函数参数1个
二元函数对象：函数参数2个
一元谓词 函数参数1个，函数返回值是bool类型，可以作为一个判断式
谓词可以是一个仿函数，也可以是一个回调函数
二元谓词 函数参数2个，函数返回值是bool类型





*/
using namespace std;
int main()
{
    /*插入迭代器---------------------------------------------------------------------------*/
    list<int> num1 = {0,1,2,3,4,5};
    list<int> num2, num3;

    copy(num1.begin(), num1.end(), front_inserter(num2));
    for (const auto &temp_num : num2)
    {
        cout << temp_num << " ";
    }
    cout << endl;
    copy(num1.begin(), num1.end(), inserter(num3, num3.begin()));
    for (const auto &temp_num : num3)
    {
        cout << temp_num << " ";
    }
    cout << endl;


    /*反向迭代器-------------------------------------------------------------------------*/
    vector<int> num4 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<string> buf = {"a", "and", "name", "egg"};

    for (const auto &temp_num : num4)
    {
        cout << temp_num << " ";
    }
    cout << endl;

    for (auto temp_num=num4.crbegin(); temp_num != num4.crend(); ++temp_num)
    {
        cout << *temp_num << " ";
    }
    cout << endl;
    //sort用 "<" 运算符来排序
    sort(buf.rbegin(), buf.rend());
    for (const auto &temp_buf : buf)
    {
        cout << temp_buf << " ";
    }
    cout << endl;


    /*字符比较----------------------------------------------------------------------------*/
    string str1 = "and", str2 = "egg";
    cout << (str1 > str2 ? str1 : str2) << endl;





    return 0;
}
