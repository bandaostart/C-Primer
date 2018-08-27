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
4，unique_ptr操作函数：
    unique_ptr<T> u1:      空unique_ptr可以指向类型为T的对象，u1会使用delete
    u = nullptr     :      释放u指向的对象，将u置为空
    u.release()     ：      u放弃对指针的控制权，返回指针，并将u置为空; 并不会释放指针
    u.reset()       ：      释放u指向的对象
    u.reset(q)      :      如果提供了内置指针q，令u指向这个对象；否则将u置为空
    u.reset(nullptr)：
5，new T[]          :      动态分配数组

6,allocator类：
    allocator<T> a         :      定义一个名为a的allocator对象，它可以为类型为T的对象分配内存
    a.allocate(n)          :      分配一段原始的，未构造的内存，保存n个类型为T的对象
    a.deallocate(p,n)      :      释放从T*指针p中地址开始的内存
    a.construct(p, args)   :      p必须是一个类型为T*的指针，指向一块原始内存，arg被传递给类型weiT的构造函数
    a.destroy(p)           :      p为T*类型的指针，此算法对p指向的对象执行西沟函数

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


    /*unique_ptr指向它所指的对象，当它被销毁时它所指的对象也被销毁----------------------------------*/
    //当我们定义unique_ptr时，需要将其绑定到new返回的指针上，unique_ptr不支持普通的拷贝和赋值操作
    unique_ptr<int> p8(new int(42));                 //p8指向一个值为42的int
    p8 = nullptr;                                    //释放指针，将p8置为空

    unique_ptr<string> p9(new string("hello point"));
    unique_ptr<string> p10(p9.release());            //将p9的所有权转移给p10
    unique_ptr<string> p11(new string("Text"));
    p10.reset(p11.release());                        //将所有权从p11转到p10；reset释放了p10原来指向的内存

    /*new T[]动态数组----------------------------------------------------------------------*/
    int *pa      = new int;
    int *pia     = new int[10];                          //10个未初始化的int
    int *pia2    = new int[10]();                        //10个值初始化为0的int
    string *psa  = new string[10];                       //10个空string
    string *psa2 = new string[10]();                     //10个空string

    int    *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};     //10个int分别进行初始化
    string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')}; //前4个进行初始化

    delete pa;                                          //释放指针动态分配的对象

    delete [] pia;                                       //释放动态分配的数组
    delete [] pia2;
    delete [] pia3;

    delete [] psa;
    delete [] psa2;
    delete [] psa3;

    /*unique_ptr分配数组------------------------------------------------------------------*/
    unique_ptr<int[]> up(new int[10]);                      //up指向一个包含10未初始化int的数组
    for (size_t i=0; i<10; i++)
    {
        up[i] = i;
    }
    up.release();                                           //自动用delete[]销毁其指针


    /*shared_ptr管理动态数组，shared_ptr不直接支持管理动态数组，如果希望使用shared_ptr管理，必须提供自
     * 己定义的删除器----------------------------------------------------------------------*/
    shared_ptr<int> sp(new int[10], [] (int *p) {delete[] p;});
    sp.reset();                                             //使用我们提供的lambda释放数组，他是用detete[]


    /*allocatro使用---------------------------------------------------------------------*/
    allocator<string> alloc;                                //可以分配string的allocator对象
    auto const p = alloc.allocate(10);                      //分配n个未初始化的string

    auto m = p;                                             //q指向最后构造的元素之后的位置
    alloc.construct(m++);                                   //*q为空字符串
    alloc.construct(m++, 10, 'c');                          //*q为cccccccc
    alloc.construct(m++, "hi");                             //*q为hi

    while (m != p)
    {
        cout << *(--m) << endl;
        alloc.destroy(m);                                  //释放真正构造的string
    }


    return 0;
}
