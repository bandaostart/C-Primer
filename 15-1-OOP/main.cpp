#include <iostream>
#include <vector>
#include <memory>
/*
1，基类：  通常在层次关系的根部有一个基类
2，派生类：直接或间接从基类基础而来，这些继承得到的类称为派生类
3，虚函数：对于某些函数，基类希望它的派生类各自定义适合自身的版本，此时基类就将这些函数声明成虚函数，任何构造函数之外的非静态函数都可以是虚函数
4，protected：派生类可以有权访问该成员，同时禁止其他用户访问，可以用proteced说明这样的成员，派生类可以访问共有成员函数，禁止访问私有成员函数
5，override：如果派生类在虚函数声明时使用了override描述符，那么该函数必须重载其基类中的同名函数，如果我们使用override标记了某个函数，但该函
   数并没有覆盖已存在的虚函数，此时编译器将会报错
6，派生类对象含有从基类继承而来的成员，但是派生类并不能直接处时候这些成员，派生类也须使用基类的构造函数来初始化它的基类部分
7，动态绑定：只有我们通过指针或引用调用虚函数时候才会发生
8，多态性：在基类的函数前加上virtual关键字，在派生类中重写该函数，运行时将会根据对象的实际类型来调用相应的函数，如果对象类型是派生类
   就调用派生类的函数；如果对象类型是基类，就调用基类的函数
   <1>:用virtual关键字申明的函数叫做虚函数，虚函数可定时类的成员函数
   <2>:存在虚函数的类都有一个一维的虚函数表叫做虚表，类的兑现有一个指向虚表开始的虚指针，虚表和类对应的，虚表指针和对象对应的
   <3>:多态性是一个接口多种实现，是面向对象的核心，分为类的多态性和函数的多态性
   <4>:多态用虚函数来实现，结合动态绑定
   <5>:纯虚函数是虚函数再加上=0
   <6>:抽象类是指包括至少一个纯虚函数的类
   <7>:纯虚函数：virtual void fun() = 0;即抽象类必须在子类实现这个函数，即先有名称，没有内容，在派生类实现内容；含有纯虚函数的类是抽象基类
9，虚函数const修饰，虚函数的要求是：函数原型相同（函数返回值、函数名，参数列表、const修饰符），const修饰符包括函数返回值的修饰、函数形参
   的修饰、函数本身的修饰，只要有一处const没有对上、那么就不是虚函数的重载，而是发生了同名覆盖的现象
10,基类通常都应该定义一个虚析构函数，即使该函数不执行任何实际操作也是如此
11,继承与静态成员函数：如果基类定义了一个静态成员函数，则在整个继承体系中只存在该成员函数唯一定义
12,当且仅当通过指针或引用调用虚函数时，才会在运行时解析该调用，也只有在这种情况下对象的动态类型才有可能与静态类型不同
13,派生类构造函数只初始化的它的直接基类
14,当我们使用容器存放继承体系中的对象时，通常必须采用间接存储的方式，不能把具有继承关系的多种类型对象直接存放在容器当中；当我们希望在容器中存放
   具有继承关系的对象时，我们实际上存放的通常是基类的指针（更好的选择是智能指针）
*/


using namespace std;
//类的声明
class Quote;
class Bulk_quote;

//基类
class Quote
{
  public:
    Quote() = default;

    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price)
    {}

    std::string isbn() const {return bookNo;}

    virtual double net_price(std::size_t n) const {return n*price;}

    virtual ~Quote() = default;


  private:
    std::string bookNo;

  protected:
    double price = 0.0;


};


//派生类
class Bulk_quote : public Quote
{
 public:
    Bulk_quote() = default;

    //派生类通过基类的够着函数来初始化它的基类部分
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) : Quote(book,p),min_qty(qty),discount(disc)
    {

    }

    double net_price(std::size_t) const override;

 private:
    std::size_t min_qty = 0;

    double discount = 0.0;
};


double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
    {
        return cnt*(1-discount)*price;
    }
    else
    {
        return cnt*price;
    }
}



int main()
{
    //容器与类的使用
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("0-201-82470-1", 50));
    basket.push_back(make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
    cout <<basket.back()->net_price(15) <<endl;

    return 0;
}










