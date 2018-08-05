#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <string>
#include <functional>

/*
1，调用lambda表达式
  [](const string &s1, const string &s2){ return s1.size()>s2.size();}         //默认返回类型，不能包含return意外的语句
  [](const string &s1, const string &s2) ->int { return s1.size()>s2.size();}  //指定返回类型，可以包含return以外的语句

2，lambda参数传递

3，参数绑定
   auto newcallable = bind(callable, arg_list);




*/




using namespace std;
using namespace std::placeholders;

bool check_sized(const string &s1, size_t sz)
{
    return s1.size() > sz;
}


void sort_num(int num1, int num2, int num3, int num4, int num5)
{
    cout << num1 << " ";
    cout << num2 << " ";
    cout << num3 << " ";
    cout << num4 << " ";
    cout << num5 << " ";
    cout << endl;
}






int main(void)
{
    vector<string> string_words = {"My", "name", "is", "bandaostart", "My", "age", "is", "28"};


    /*lambad表达式的使用-----------------------------------------------------------------------*/
    //unique仅能比较相邻元素
    sort(string_words.begin(), string_words.end());
    string_words.erase(unique(string_words.begin(), string_words.end()), string_words.end());
    sort(string_words.begin(), string_words.end(), [](const string &s1, const string &s2){return s1.size()>s2.size();});
    for (const auto &s : string_words)
    {
        cout << s << " ";
    }
    cout << endl;


    /*lambda参数传输-------------------------------------------------------------------------*/
    unsigned int sz = 3;
    auto wc = find_if(string_words.begin(), string_words.end(), [sz](const string &s1){return s1.size()< sz ;});
    cout << "num = " << wc-string_words.begin() << endl;
    auto string_words_beg = string_words.begin();

    while(string_words_beg != wc)
    {
        cout << *string_words_beg++ << " ";
    }
    cout << endl;


    /*lambda值的捕获------------------------------------------------------------------------*/
    //值在创建时拷贝，不是在使用时拷贝
    {
        size_t vt = 100;

        auto f = [vt] ()  {return vt ;};  //创建时将vt拷贝到名为f的可调用对象

        vt = 0;

        cout << f() << endl;
    }

    //引用捕获
    {
        size_t vt = 100;

        auto f = [&vt](){return vt ;};

        vt = 0;

        cout << f() <<endl;
    }


    /*可变lamdba-------------------------------------------------------------------------*/
    //对于一个值被拷贝量，lamdba不能改变其变量；如果想要改变加上mutable
    {
        size_t vt  = 100;

        //auto f = [vt] () {return ++vt; }; 不加mutable会提示编译错误
        auto f = [vt] () mutable {return ++vt; };

        cout << f() <<endl;
    }

    //如果是引用变量值则可以修改
    {
        size_t vt = 100;

        auto f = [&vt] () {return ++vt ;};

        cout << f() << endl;
    }


    /*指定lamdba返回类型----------------------------------------------------------------*/
    //如果lamdba包含任何return之外的语句，则编译器默认返回void
    {
        vector<int> num = {1, -2, 3, -4, 5, -6, 7, -8, 9};

        //负值取绝对值
        transform(num.begin(), num.end(), num.begin(), [](const &temp_num){return temp_num > 0 ? temp_num : -temp_num; });
        for (const auto &temp_num : num)
        {
            cout << temp_num << " ";
        }
        cout << endl;

        //指定返回类型，  使用 ->int, 或者包含非return语句编译器报错
        transform(num.begin(), num.end(), num.begin(),
                  [](const &temp_num) ->int
                  {  if (temp_num % 2 == 0) return temp_num; else return -temp_num  ;});
        for (const auto &temp_num : num)
        {
            cout << temp_num << " ";
        }
        cout << endl;

    }


    /*bind函数使用---------------------------------------------------------------------------------*/
    //check_sized函数第二个参数指定为6，在调用CheckSized时，传入第一个参数即可
    auto CheckSized = bind(check_sized, std::placeholders::_1, 6);
    string words = "hello";
    cout << CheckSized(words) << endl;

    auto SortNum = bind(sort_num, 1, 2, 3, std::placeholders::_2, std::placeholders::_1);
    SortNum(5, 4);

}
