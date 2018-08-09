#include <iostream>
#include <memory>
#include <list>
#include <vector>

/*
1,智能指针
smart_point：智能指针的行为类似常规指针，重要的区别是它负责自动释放所指向的对象
shared_ptr：允许多个指针指向同一个对象
unique_ptr：独占所指向的对象
2,操作方式
shared_ptr unique_ptr: 共享函数
    p：          将p用作一个条件判断，若p指向一个对象，则为true
    *p：         解引用p，获得它指向的对象
    p->mem:      等价于(*p).mem
    p.get():     返回p中所保存的指针，要小心使用，若智能指针释放了其对象，返回的指针所指向的对象也就消失了
    swap(p, q); p.swap(q):  交换p和q中的指针
shared_ptr：独有的操作
    make_shared<T>(args): 返回一个shared_ptr，指向一个动态分配的类型为T的对象，使用args初始化此对象
    shared_ptr<T>p(q):    p是shared_ptr q的拷贝，此操作会递增q中的计数器，q中的指针必须能转换成T*
    p.unique():           若p。use_count()为1，返回true；否则返回false
    p.use_count():        返回与p共享对象的智能指针数量，可能很慢
3,动态内存使用原因
    程序不知道自己需要使用多少对象   容器类的使用时出于这个原因
    程序不知道所需对象的准确类型
    程序需要在多个对象间共享数据
*/

using namespace std;
int main()
{
    /*shared_ptr初始化定义-----------------------------------------------------------------*/
    shared_ptr<string>    p1;                       //shared_ptr，可以指向string
    shared_ptr<list<int>> p2;                       //shared_ptr，可以指向int的list

    if (p1 && p1->empty())
    {
        cout << "No Empty" << endl;
    }
    else
    {
        cout << "Empty" << endl;
    }

    //make_shared用其参数来构造给定类型的对象
    shared_ptr<int>p3    = make_shared<int>(4);          //指向一个值为4的int的shared_ptr指针
    shared_ptr<string>p4 = make_shared<string>(10, '9'); //指向10个9的string的shared_ptr指针
    shared_ptr<int>p5    = make_shared<int>();           //指向一个值为0的int的shared_ptr指针
    auto p6              = make_shared<vector<string>>();//动态分配一个空的string


    /*shared_ptr的拷贝和赋值---------------------------------------------------------------*/
    /*每个shared_ptr都有一个关联的计数器，通常称其为引用计数，无论何时我们拷贝一个shared_ptr计数器都会递增，
      当我们给shared_ptr赋予一个新值或是shared_ptr被销毁，计数器会递减,当计数器变为0，它就会自动释放自己所
      管理的对象
    */
    auto p7   = make_shared<int>(42);                //p7指向的对象只有p7一个引用者
    auto q(p7);                                      //p7和q指向相同对象，此对象有两个引用






























    return 0;
}
