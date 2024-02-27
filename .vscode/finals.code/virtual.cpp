#include <iostream>

using namespace std;

class one{
    public:
        virtual void foo(){
            cout << "A";bar();
        }
        void bar(){
            cout << "B";
        }
};

//protected inheritance makes the public and protected 
//members of the base class protected in the derived class.

//public inheritance makes public members of 
//the base class public in the derived class, 
//and the protected members 
//of the base class remain protected in the derived class.

//private inheritance makes the public and protected 
//members of the base class private in the derived class.

class two:public one{
    public:
        void foo(){
            cout << "C";bar();
        }
};

class three:public one{
    public:
        void bar(){
            cout << "D";
        }
};

int main(void){

    one *p;
    p=new one;
    p->foo();
    cout << endl;

    p=new two;
    p->foo();
    cout <<endl;

    p=new three;
    p->foo();
    cout << endl;

    return 0;
}