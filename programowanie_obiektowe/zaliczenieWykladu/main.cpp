#include <iostream>

using namespace std;

class A
{
protected:
    int a;
public:
    A(int o1) {a=o1;}
    virtual void mut1() {a += 1;}
    int mut2()
    {
        this->mut1();
        return a;
    }
    virtual int ob() {return a+1;}
};

class B : public A
{
public:
    //int b;
    B(int o1):A(o1) {a+=2;}
    void mut1(){a+=3;}
    int ob() {return a+2;}
};

class D : protected A
{
public:
    D(int o1):A(o1){}
    int ob2(){return 0;}
};

int main()
{
    A a1(2);
    B b1(3);
    D d1(4);
    A* ap1 = &b1;
    A a2(100);
    a2 = *ap1;
    A* ap2 = &b1;
    B* bp1 = dynamic_cast<B*>(ap1);
    A* ap3 = reinterpret_cast<A*>(&d1);
    D* dp1 = dynamic_cast<D*>(&a1);
    cout<<a1.ob()<<endl;
    cout<<b1.mut2()<<endl;
    cout<<ap1->ob()<<endl;
    cout<<ap1->mut2()<<endl;
    cout<<a2.mut2()<<endl;
    if(sizeof(*ap1)==sizeof(b1))cout<<"1"<<endl;
    //cout << sizeof(a1);
    cout<<bp1->mut2()<<endl;
    //cout<<ap3->ob2()<<endl; nie dziala, klasa A nie ma metody ob2
}
