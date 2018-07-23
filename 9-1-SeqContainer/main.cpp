#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <forward_list>
#include <deque>
#include <array>

/*
顺序容器：
1，vector：可变大小数组，支持快速随机访问，在尾部之外的位置插入或删除元素很慢
2，deque： 双端列队，支持快速随机访问，在头尾位置插入和删除速度很快
3，list：双向链表，只支持双向顺序访问，在list中任何位置进行插入或删除操作速度都很快
4，forward_list: 单向链表，只支持单向顺序访问，在链表任何为hi在进行插入或删除操作速度都很快
5，array：固定大小数组，支持快速随机访问，不能添加或删除元素
6，string：与vector相似的容器，但专门用于保存字符，随机访问快，在尾部插入或删除快
类型别名，迭代器类型：
iterator：此容器类型的迭代器类型
const_iterator：可以读取元素，但不能修改元素的迭代器类型
size_type：无符号整数类型，足够保存此中容器类型最大可能容器的大小
difference_type：带符号整数类型，足够保存两个迭代器之间的距离
value_type：元素类型
reference：元素的左值类型：与value_typed&含义相同
const_reference：元素的const左值类型
迭代器
迭代器是使用容器的基础，除了下标运算迭代器是一种更加通用的机制

*/



using namespace std;
int main()
{
    /*容器大小-----------------------------------------------------------------------------------------*/
    //只用顺序容器的的构造函数才能接受参数大小
    const vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto num_beg = num.cbegin();
    auto num_end = num.cend();

    cout << "num.size() = " << num.size() << endl;              //元素个数
    cout << "num.max_size() = " << num.max_size() << endl;      //最大个数
    cout << "num.empty() = " << num.empty() << endl;            //判断是否为空
    while (num_beg != num_end)
    {
       cout << *num_beg <<" ";
       num_beg++;
    }
    cout << endl;



    /*迭代器类型获得-------------------------------------------------------------------------------------*/
    list<string>      str = {"a", "an", "and"};                 //定义一个容器

    //atuo与begin end结合使用时，获得的迭代器类型依赖于容器类型，与我们想如何使用迭代器无关
    auto it1 = str.begin();                                //list<string>::iterator                迭代器
    auto it2 = str.rbegin();                               //list<string>::reverse_iterator        反向迭代器
    auto it3 = str.cbegin();                               //list<string>::const_iterator          const迭代器
    auto it4 = str.crbegin();                              //list<string>::const_reverse_iterator  反向 const迭代器



    /*容器类型拷贝-----------------------------------------------------------------------------------------*/
    list<string>         name = {"xiaohua", "xiaotao", "xiaojun"};   //定义 name 列表
    list<string>         name_bak(name);                             //把 name 的内容拷贝给 namebak

    vector<const char *> age = {"25", "26", "27"};

    auto age_beg = age.begin();
    age_beg++;
    deque<string>        age_haf(age.begin(), age_beg);
    auto age_haf_beg = age_haf.begin();
    auto age_haf_end = age_haf.end();
    while (age_haf_beg != age_haf_end)
    {
        cout << *age_haf_beg++ <<endl;
    }

    forward_list<string> age_bak(age.begin(), age.end());            //可以把const char *转换成string
    auto age_bak_beg = age_bak.begin();
    auto age_bak_end = age_bak.end();
    while (age_bak_beg != age_bak_end)
    {
       cout << *age_bak_beg++ << " ";
    }
    cout << endl;



    /*顺序容器默认大小定义----------------------------------------------------------------------------------*/
    vector<int>       invec(10, 1);                                       //初始化10个int元素每个初始化为1
    list<string>      slist(10, "HI");                                    //初始化10个string元素每个初始化为“HI”
    forward_list<int> flist(10, 2);                                       //初始化10个int元素每个初始化为1
    deque<string>     dstr(10, "a");                                      //初始化10个string元素每个初始化为“a”

    array<int, 10>::size_type    iarray;                                  //数组在使用的时候必须指定类型和大小



    /*赋值和swap-----------------------------------------------------------------------------------------*/
    array<int, 10>  array_1 = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
    array<int, 10>  array_2 = {0};
    auto array_1_beg = array_1.begin();
    auto array_1_end = array_1.end();
    auto array_2_beg = array_2.begin();
    auto array_2_end = array_2.end();

    //array_1 和 array_2交换数据
    array_2.swap(array_1);
    while (array_1_beg != array_1_end)
    {
        cout << *array_1_beg++ << " ";
    }
    cout << endl;
    while (array_2_beg != array_2_end)
    {
        cout << *array_2_beg++ << " ";
    }
    cout << endl;


    vector<int>  vector_1 = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
    vector<int>  vector_2(10, 0);
    auto vector_2_beg = vector_2.begin();
    auto vector_2_end = vector_2.end();

    //拷贝数据 数组没有assign函数
    vector_2.assign(vector_1.begin(), vector_1.end());
    while (vector_2_beg != vector_2_end)
    {
        cout << *vector_2_beg++ << " ";
    }
    cout << endl;


    /*关系运算符-----------------------------------------------------------------------------------------*/

    vector<int>     vectro_cmp1 = {0,1,2,3,4,5,6};
    vector<int>     vectro_cmp2 = {0,1,2,5};
    vector<int>     vectro_cmp3 = {0,1,2,3,4};
    vector<int>     vectro_cmp4 = {0,1,2,3,4,5,6};

    //cmp2与cmp1不同之处在于cmp2[3] > cmp1[3]
    cout << (vectro_cmp2 > vectro_cmp1) << endl;               //true
    cout << (vectro_cmp1 < vectro_cmp3) << endl;               //false
    cout << (vectro_cmp1 == vectro_cmp4) <<endl;               //true



    return 0;
}
