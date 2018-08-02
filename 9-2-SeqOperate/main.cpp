#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
#include <string>

/*
顺序容器操作：
1，除了Array外，所有标准库容器都提供灵活的内存管理，在运行时可以动态添加或删除元素改变容器大小
2，操作命令：
    forward_list：有自己专用版本的insert和emplace;不支持push_back和emplace_back
    vector和string：不支持push_front和emplace_front
    c.push_back(t)
    c.emplace_back(arg)
    c.push_front(t)
    c.emplace_front(arg)
    c.insert(p, t)         //插入一个 t
    c.emplace(p, arg)
    c.insert(p, n, t)      //插入n个
3，push与emplace区别：
    push：   当调用push时，我们将元素类型的对象传递给他们，这些对象被拷贝到容器中
    emplace：当调用emplace时，则是将参数传递给元素类型的构造函数，emplace成员使用这些参数在容器管理的内存空间中直接
             构造元素
    区别：push和emplace都会创建新的对象，emplace会在容器管理的内存空间中直接创建对象，push则会创建一个局部临时对象，
         并将其压入容器中，emplace效率更高
4，元素访问：
   c.front(); c.back(); c.front(); c[n], c.at(n)
5，元素删除：
   forward_list有特殊版本的erase
   forward_list不支持pop_back;
   vector string不支持pop_front
   c.pop_back()：删除c中尾元素
   c.pop_front()：删除c中首元素
   c.erase(p)：删除迭代器p所指定的元素，返回一个指向被删元素之后元素的迭代器
   c.erase(b,3)：删除迭代器b和e所指定环卫内的元素返回一个指向最后一个删除元素之后元素的迭代器
   c.clear()：删除c中的所有元素，返回void
6，重新定义容器大小：
   c.resize()
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


    /*insert在特定的位置添加元素-------------------------------------------------------------------------------*/
    list<string> list_str;

    list_str.push_front("xiaohua");
    list_str.push_back("xiaotao");
    list_str.insert(list_str.begin(), "xiaogou");

    auto list_str_beg = list_str.begin();
    auto list_str_end = list_str.end();
    while (list_str_beg != list_str_end)
    {
        cout << *list_str_beg++ << " ";
    }
    cout << endl;



    /*insert插入范围内元素----------------------------------------------------------------------------------*/
    vector<string> list_name;
    vector<string> list_name_bak = {"xiao tao", "xiao mei", "xiao jun"};

    list_name.insert(list_name.begin(), 2, "xiao hua");
    list_name.insert(list_name.end(), ++list_name_bak.begin(), list_name_bak.end());
    list_name.insert(list_name.end(), {"xiao li", "xiao mei"});
    list_name.insert(list_name.begin(), list_name.begin(), list_name.end());

    auto list_name_beg = list_name.begin();
    auto list_name_end = list_name.end();
    while (list_name_beg != list_name_end)
    {

        cout << *list_name_beg++ << "; ";
    }
    cout << endl;



    /*emplace_back, emplace, emplace_front----------------------------------------------------------*/
    vector<string> vector_age;
    vector_age.emplace_back("18");



    /*访问元素----------------------------------------------------------------------------------------*/
    vector<string> vector_lev;

    vector_lev.emplace_back("P6");
    vector_lev.emplace_back("P7");
    vector_lev.emplace_back("P8");
    vector_lev.emplace_back("P9");

    cout << vector_lev.front() << endl;
    cout << vector_lev.back() << endl;
    cout << vector_lev[1] << endl;
    cout << vector_lev.at(2) << endl;

    /*删除元素---------------------------------------------------------------------------------------*/
    list<int> list_num2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    list_num2.pop_back();
    list_num2.pop_front();
    
    auto list_it  = list_num2.begin();
    while(list_it != list_num2.end())
    {
    	if (*list_it % 2)
      {
      	//删除单个元素
        list_it = list_num2.erase(list_it);
      }
      else
      {
      	++list_it;
      }	
    }
    //删除指定个数元素
    list_num2.erase(list_num2.begin(), ++list_num2.begin());
    //清空元素
    list_num2.clear();
    
    
    /*改变容器大小------------------------------------------------------------------------------------*/
    list<int> list_resize = {0,1,2,3,4,5,6,7,8,9};
    list_resize.resize(15);                         //将5个值为0的元素添加到list_resize的末尾
    list_resize.resize(25,-1);											//将10个值为-1的元素添加到list_resize的末尾
    list_resize.resize(5);                          //从list_resize末尾删除20个元素
    
    
    
    /*容器操作可能使迭代器功能失效--------------------------------------------------------------------*/
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    

    //在erase后不必递增迭代器，因为erase返回的迭代器已经指向序列中下一个元素
    //在insert后，需要递增迭代器两次，insert在给定位置之前插入新元素，然后返回指向新插入元素的迭代器
    //不要保存end返回的迭代器，在添加或删除后，原来返回的迭代器总会失效
    while (iter != vi.end())
    {
    	if (*iter % 2)
    	{
            iter = vi.insert(iter, *iter);           //复制当前元素
            iter += 2;                               //向前移动迭代器，跳过当前元素及插入之前的元素
    	}
    	else
        {
            iter = vi.erase(iter);                  //删除偶数元素，iter指向删除之后的元素
        }
    }
    
    
    

    return 0;
}
