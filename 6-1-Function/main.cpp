#include <iostream>
#include <vector>


/*
1，函数重载：如果作用域内几个函数的名字相同但是形参列表不同，我们称之为函数重载
2，默认实参：我们可以为函数的多个形参定义默认值
*/





using namespace std;
//函数重载
void User_Print(const string name)
{
    cout << name <<endl;
}

void User_Print(const string name ,const string age)
{

    cout << name << " ";
    cout << age  <<endl;
}

void User_Print(const string name, const string age, const string lev)
{

    cout << name << " ";
    cout << age  << " ";
    cout << lev  <<endl;
}

//默认实参,某一形参定义了默认值其前面的所有形参都要定义默认值
void User_Screen(int x=20, int y=30, string name = "Screen");//声明
void User_Screen(int x, int y, string name)
{
    cout << "Name is " << name << endl;
    cout << "X= " << x << " Y=" << y <<endl;
}



int main()
{
    /*函数重载测试-----------------------------------------------------------*/
    vector<string> name_age_lev;
    name_age_lev.push_back("xiaozhang");
    name_age_lev.push_back("18");
    name_age_lev.push_back("P6");

    User_Print(name_age_lev.at(0));
    User_Print(name_age_lev.at(0), name_age_lev.at(1));
    User_Print(name_age_lev.at(0), name_age_lev.at(1), name_age_lev.at(2));


    /*默认实参-------------------------------------------------------------*/
    User_Screen();
    User_Screen(100);
    User_Screen(100,200);
    User_Screen(100,200,"HOME");



    return 0;
}
