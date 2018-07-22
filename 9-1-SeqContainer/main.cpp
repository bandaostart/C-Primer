#include <iostream>
/*
顺序容器：
1，vector：可变大小数组，支持快速随机访问，在尾部之外的位置插入或删除元素很慢
2，deque： 双端列队，支持快速随机访问，在头尾位置插入和删除速度很快
3，list：双向链表，只支持双向顺序访问，在list中任何位置进行插入或删除操作速度都很快
4，forward_list: 单向链表，只支持单向顺序访问，在链表任何为hi在进行插入或删除操作速度都很快
5，array：固定大小数组，支持快速随机访问，不能添加或删除元素
6，string：与vector相似的容器，但专门用于保存字符，随机访问快，在尾部插入或删除快
类型别名：
iterator：此容器类型的迭代器类型
const_iterator：可以读取元素，但不能修改元素的迭代器类型
size_type：无符号整数类型，足够保存此中容器类型最大可能容器的大小
difference_type：带符号整数类型，足够保存两个迭代器之间的距离
value_type：元素类型
reference：元素的左值类型：与value_typed&含义相同
const_reference：元素的const左值类型


*/



using namespace std;
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
