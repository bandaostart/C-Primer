#include <iostream>
#include <string>
/*
1，输入输出模式分类
头文件：iostream 标准输入输出
包含：istream、wistream 从流读取数据；ostream、wostream 向流写入数据；iostream、wiostream 读写数据
头文件：fstream 文件输入输出
ifstream、wifstream 从文件读取数据；ofstream、wofstream 向文件写入数据；fstream、wfstream 读写文件
头文件：sstream 内存string输入输出
istringstream、wistringstream 从string读取数据；ostringstream、wostringstream 向string写入数据；
stringstream、wstringstream读写string

ifstream istringstream都继承之istream
2，输出缓冲区刷新
unitbuf;nounitbuf;
3，对文件操作

*/


using namespace std;
int main()
{
    //每个输出流都管理一个缓冲区，用来保存程序读写的数据
    cout << "HI!" <<endl;                       //输出hi和一个换行，然后刷新缓冲区
    cout << "HI!" <<flush;                      //输出hi，然后刷新缓冲区，不附加任何额外字符
    cout << "HI!" <<ends;                       //输出hi和一个空字符，然后刷新缓冲区

    cout << unitbuf;                            //所有输出操作后都会立即刷新缓冲区
    cout << nounitbuf;                          //回到正常的缓冲模式

    return 0;
}



