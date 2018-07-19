#include <iostream>

//namespace : 给类或者函数做一个区间定义
//using     : 指定特定使用namespace
using namespace std;
namespace first_namespace
{
    void Test_Fun()
    {
        std::cout << "First namespace\r\n";
    }
}

namespace second_namesapce
{
    void Test_Fun()
    {
        std::cout << "Second namespace\r\n";
    }
}

namespace first_using
{
    void Using_Fun()
    {
        std::cout << "First Using\r\n";
    }
}

namespace second_using
{
    void Using_Fun()
    {
        std::cout << "Second Using\r\n";
    }
}


using namespace second_using;
int main()
{

    //namespace test
    first_namespace::Test_Fun();
    second_namesapce::Test_Fun();

    //using test
    Using_Fun();


    return 0;
}






















