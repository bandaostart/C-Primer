#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <utility>


/*
关联容器：
1，关联容器是按关键词来保存和访问的，关联容器支持高效的关键字查找和访问；顺序容器是按元素顺序来保存和访问的


2，按关键字有序保存元素,容器添加元素后按顺序排列
map：        关联数组；保存关键字-值对
set：        关键字即值，即只保存关键字的容器
multimap：   关键字可重复出现的map
multiset：   关键字可重复出现的set


3，无序集合
unordered_map：     用哈希函数组织的map
unordered_set：     用哈希函数组织的set
unordered_multimpa: 哈希组织的map；关键字可以重复出现
unordered_multiset：哈希组织的set；关键字可以重复出现


4, pair标准库类型模板


5，类型别名和typdef具有相同的功能，关联容器的类型别名
key_type       此容器类型的关键字类型别名
mapped_type    每个关键字关联的类型别名；只适用于map
value_type     对于set，与key_type相同
               对于map，与pair<const key_type, mapped_type>相同
set<string>::value_type        v1      //v1是一个string类型
set<string>::key_type          V2      //v2是一个string类型
map<string, int>::value_type   v3      //v3是一个pair<const string, int>类型
map<string, int>:key_type      v4      //v4是一个string类型
map<string, int>::mapped_type  v5      //v5是一个int类型

6，添加元素
c.insert(v)               ：v是value_type类型的对象
c.emplace(args)           ：对于map和set,只有当元素的关键字不在c中时才插入元素
c.insert(b,e)             ：b和e是迭代器
c.insert(il)              ：花括号列表

7，删除元素
c.erase(k)                ：从c中删除每个关键字为k的元素
c.erase(p)                ：从c中删除迭代器p指定的元素
c.erase(b, e)             ：删除迭代器对b和e所表示的范围中的元素

8，小标操作
c[k]
c.at[k]

9，访问元素
c.find(v)                 ：返回一个迭代器
c.count(v)                ：返回元素的数量，对multimap，multiset有用

10，不同访问元素的方法
lower_bound               ：返回的迭代器将指向第一个具有给定关键字的元素
upper_bound               ：返回的迭代器则指向最后一个匹配给定的关键字的元素之后的位置

11，不同查找元素的方式
equal_range：查找元素       ：返回一个迭代器pair

12，无序元素的使用


13，管理桶

*/



using namespace std;
int main()
{
    /*map关联容器--------------------------------------------------------------------*/
    //给定的关键字只能有一个元素等于它，取第一次对应关键字的值
    map<string ,size_t> name_age = {{"xiaotao", 18},
                                    {"xiaojun", 22},
                                    {"xiaomei", 24},
                                    {"xiaotao", 20}};

    //temp_check指向name_age的某个元素，name_age的元素是pair
    for (const auto &temp_check : name_age)
    {
        cout << "Name Is " << temp_check.first << " Age is " << temp_check.second;
        cout << endl;
    }



    /*set关联容器-------------------------------------------------------------------*/
    set<string> name = {"xiaotao", "xiaojun", "xiaomei", "xiaotao"};

    for (const auto &temp_name : name)
    {
        cout << temp_name << endl;
    }



    /*multiset, multimap关联容器--------------------------------------------------*/
    multimap<string ,size_t> name_age2 = {{"xiaotao", 18},
                                    {"xiaojun", 22},
                                    {"xiaomei", 24},
                                    {"xiaotao", 20}};

    for (const auto &temp_check : name_age2)
    {
        cout << "Name Is " << temp_check.first << " Age is " << temp_check.second;
        cout << endl;
    }



    /*关联容器的迭代器------------------------------------------------------------*/
    map<string, size_t> name_age3 = {
                                     {"xiaotao", 18},
                                     {"xiaojun", 20}
                                    };
    auto temp_name_age = name_age3.begin();
    //pair->first为const类型不能进行赋值操作,pair->second可以进行赋值操作
    cout << temp_name_age->first << endl;
    cout << (temp_name_age->second = 22) << endl;

    set<int> num = {1,2,3,4,5,6,7,8,9,10};
    set<int>::iterator temp_num = num.begin();
    //set为const类型不能对元素进行修改
    while (temp_num != num.end())
    {
        cout << *temp_num++ << " ";
    }
    cout << endl;


    /*添加元素----------------------------------------------------------------*/
    vector<int> seq = {3,2,1,0};
    set<int>    seq1;

    //插入元素后按顺序排列
    seq1.insert(seq.begin(), seq.end());
    seq1.insert({4,5,6,7,8,8});
    for (const auto &temp_seq : seq1)
    {
        cout << temp_seq << " ";
    }
    cout << endl;

    map<string, int> Grap;
    Grap.insert({"zhang", 99});
    Grap.insert(make_pair("wang", 98));
    Grap.insert(pair<string, int>("li", 97));
    Grap.insert(map<string, int>::value_type("zhao", 96));
    for (const auto &temp_grap : Grap)
    {
        cout << temp_grap.first << " " << temp_grap.second << endl;
    }


    /*删除元素---------------------------------------------------------------*/
    Grap.erase("zhao");
    for (const auto &temp_grap : Grap)
    {
        cout << temp_grap.first << " " << temp_grap.second << endl;
    }


    /*map的下表操作----------------------------------------------------------*/
    Grap["zhang"] = 100;
    cout << Grap["zhang"] << endl;
    cout << Grap.at("li") << endl;


   /*find, cout查找指定元素--------------------------------------------------*/
   //返回迭代器
   auto temp_grap1 = Grap.find("zhang");
   //返回元素的个数
   auto temp_grap2 = Grap.count("li");
   cout << temp_grap1->second << endl;
   cout << temp_grap2 << endl;


   /*multimap find count使用-----------------------------------------------*/
   multimap<string, string>  Author_Book {{"bandao", "Happy"},
                                          {"start",  "Sad"},
                                          {"three",  "good"},
                                          {"bandao", "egg"},
                                         };
   auto temp_author_place = Author_Book.find("bandao");
   auto temp_author_num   = Author_Book.count("bandao");
   //因为是有序关联容器所以可以用此方法查找
   while (temp_author_num)
   {
       cout << temp_author_place->first << "  " << temp_author_place->second << endl;
       temp_author_place++;
       temp_author_num--;
   }


   /*lower_bound upper_bound方式查找元素---------------------------------------*/
   auto temp_author_author = Author_Book.lower_bound("bandao");
   while (temp_author_author != Author_Book.upper_bound("bandao"))
   {
       cout << temp_author_author->first << "  " << temp_author_author->second << endl;
       temp_author_author++;
   }

   /*equal_range 不同查找元素的方式---------------------------------------------*/
   for (auto pos = Author_Book.equal_range("bandao"); pos.first != pos.second; ++pos.first)
   {
        cout << pos.first->first << "  " << pos.first->second << endl;
   }


   /*无序元素的使用-----------------------------------------------------------*/
   unordered_map<string, string>  Unorder_Author_Book;
   Unorder_Author_Book.insert(Author_Book.begin(), Author_Book.end());
   Unorder_Author_Book.insert({"anyboy", "anything"});
   for (auto temp_unorder = Unorder_Author_Book.begin(); temp_unorder != Unorder_Author_Book.end(); temp_unorder++)
   {
      cout << temp_unorder->first << "  " << temp_unorder->second << endl;
   }




   return 0;
}
