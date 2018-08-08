#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <list>
#include <string>

/*
算法：算法不会执行容器操作，因此他们自身不能改变容器大小
1，读容器一些函数
    find：可以操作任何类型的容器和数组,如果找到值返回对应元素的迭代器
    accumulate:求和算法
    equal:查看两个序列是否有相等的值，相等返回true，不相等返回false
2，写容器一些函数
   fill:    可以对容器进行写操作
   fill_n:  对容器进行n个元素的写操作
3，back_inserter：插入迭代器

4，copy：拷贝函数，拷贝的目的序列至少要和输入序列一样多的元素
  replace：替换函数

5，重新排序算法
  sort： 排序
  unique：消除相同元素，仅能比较相邻元素
6，相排序算法，添加函数
  相算法添加的参数叫谓词
*/




using namespace std;
bool is_shorted(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}


int main(void)
{
    /*Find----------------------------------------------------------------------------------------------*/
    //如果找到返回给定值元素的迭代器
    vector<int> vector_num = {0,1,2,3,4,5,6,7,8,9,10};
    auto vector_result = find(vector_num.begin(), vector_num.end(), 8);
    cout << (vector_result == vector_num.end() ? "Data NO Find" : "Data Find") << endl;

    list<string> string_buf = {"xiaohua", "xiaotao", "xiaogou", "xiaojun"};
    string str= "xiaotao";
    auto list_rsult = find(string_buf.begin(), string_buf.end(), str);
    cout << (list_rsult == string_buf.end() ? "Data NO Find" : "Data Find") << endl;

    int arry[] = {0,1,2,3,4,5,6,7,8,9,10};
    int *arry_result = find(begin(arry), end(arry), 8);
    cout << *arry_result <<endl;



    /*accumulate--------------------------------------------------------------------------------------*/
    //前两个参数初始化求和范围，最后一个参数初始化sum值为0
    int sum = accumulate(vector_num.begin(), vector_num.end(), 0);
    cout << "sum = " << sum <<endl;

    //容器序列中的元素必须和第三个参数元素类型相同，或转换成第三个参数类型
    //如果第三个元素不进行类型转换会出现一个<const char *>编译错误; ""为const char *类型
    auto str_begin = string_buf.begin();
    while (str_begin != string_buf.end())
    {
        *str_begin += "; ";
        str_begin++;
    }
    string str_sum = accumulate(string_buf.begin(), string_buf.end(), string(""));
    cout << str_sum << endl;


    /*equal-----------------------------------------------------------------------------------------*/
    list<string> equal_str1 = {"tian", "di", "ren", "he"};
    list<string> equal_str2 = {"tian", "di", "ren", "he"};

    bool result_equal = equal(equal_str1.cbegin(), equal_str1.cend(), equal_str2.cbegin());
    cout << (result_equal ? "Equal" : "No Equal") << endl;


    /*fill-----------------------------------------------------------------------------------------*/
    //fill不进行容器操作，因此不会改变容器大小;fill_n算法不会检查写操作，所以在在指定操作长度时候一定要注意
    fill(vector_num.begin(), vector_num.end(), 0);
    cout << accumulate(vector_num.begin(), vector_num.end(), 0) << endl;
    fill(vector_num.begin(), vector_num.begin()+vector_num.size()/2, 10);
    cout << accumulate(vector_num.begin(), vector_num.end(), 0) << endl;
    //下面使用方式比较危险,操作n个元素
    fill_n(vector_num.begin(), 10, 10);
    cout << accumulate(vector_num.begin(), vector_num.end(), 0) << endl;



    /*back_inserter插入迭代器-----------------------------------------------------------------------*/
    vector<int> back_inserter_num;
    //创建一个插入迭代器，并添加10个元素
    fill_n(back_inserter(back_inserter_num), 10, 0);


    /*copy拷贝-------------------------------------------------------------------------------------*/
    int a1[] = {0,1,2,3,4,5,6,7,8,9,10};
    int a2[sizeof(a1)/sizeof(*a1)];

    //a2和a1有相同的元素
    copy(begin(a1), end(a1), a2);
    //用80替换8
    replace(begin(a1), end(a1), 8, 80);


    /*sort或unique排序---------------------------------------------------------------------------*/
    vector<string> string_words = {"My", "name", "is", "bandaostart", "My", "age", "is", "28"};

    //sort排序
    sort(string_words.begin(), string_words.end());
    auto string_words_beg = string_words.begin();
    while (string_words_beg != string_words.end())
    {
        cout << *string_words_beg++ << " ";
    }
    cout << endl;

    //unique去掉重复，因为算法函数不能执行容器操作，需要使用容器操作函数来执行真正的删除
    //返回重复元素迭代器地址,unique仅能比较相邻两个元素是否相同
    auto unique_beg = unique(string_words.begin(), string_words.end());
    string_words_beg = string_words.begin();
    while (string_words_beg != string_words.end())
    {
        cout << *string_words_beg++ << " ";
    }
    cout << endl;
    string_words.erase(unique_beg, string_words.end());
    string_words_beg = string_words.begin();
    while (string_words_beg != string_words.end())
    {
        cout << *string_words_beg++ << " ";
    }
    cout << endl;


    /*重载算法函数------------------------------------------------------------------------------*/
    //is_shorted为重载过的函数
    sort(string_words.begin(), string_words.end(), is_shorted);
    for(const auto &s : string_words)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
































