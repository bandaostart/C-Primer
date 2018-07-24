#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
#include <string>

/*
顺序容器操作：
除了Array外，所有标准库容器都提供灵活的内存管理，在运行时可以动态添加或删除元素改变容器大小
操作命令：
forward_list：有自己专用版本的insert和emplace;不支持push_back和emplace_back
vector和string：不支持push_front和emplace_front
c.push_back(t)
c.emplace_back(arg)
c.push_front(t)
c.emplace_front(arg)
c.insert(p, t)         //插入一个 t
c.emplace(p, arg)
c.insert(p, n, t)      //插入n个
*/



using namespace std;
int main()
{

    /*push_back除了array和forward_list每个容器都支持---------------------------------------------------------------*/
    list<int> list_num;

    for (int i=0; i<4; i++)
    {
        list_num.push_back(i);
    }
    //如果beg end放在for循环前则会beg == end,因为此时列表中还没有值
    auto list_num_beg = list_num.begin();
    auto list_num_end = list_num.end();
    while (list_num_beg != list_num_end)
    {
        cout << *list_num_beg++ << " ";
    }
    cout << endl;


    /*push_front除了vectro和string每个容器都支持-----------------------------------------------------------------*/
    deque<int> deque_num;

    for (int i=0; i<4; i++)
    {
        deque_num.push_front(i);
    }
   //如果beg end放在for循环前则会beg == end
    auto deque_num_beg = deque_num.begin();
    auto deque_num_end = deque_num.end();
    while (deque_num_beg != deque_num_end)
    {
        cout << *deque_num_beg++ << " ";
    }
    cout << endl;


    return 0;
}
