#include<iostream>
#include <vector>

/*
在c++中，vector是一个十分有用的容器
1，它能够像容器一样存放各种类型的对象，简单地说，vector是一个能够存放任意类型的动态数组，能够增加和压缩数据
2，vector在C++标准模板库中的部分内容，它是一个多功能的，能够操作多种数据结构和算法的模板类和函数库

*/




using namespace std;
int main(void)
{
    //定义一个int型vector
    vector<int> Int_Test;

    //把值 1，2压入vector
    Int_Test.push_back(1);
    Int_Test.push_back(2);

    cout << Int_Test[0] << endl;
    cout << Int_Test[1] << endl;

    return 0;
}
