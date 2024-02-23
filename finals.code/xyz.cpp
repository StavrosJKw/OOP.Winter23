#include <iostream>

using namespace std;

class P{
    private:
        void priv(){}

    protected:
        void prot(){};

    public:
        void pub(){};
};

class C : public P{
    P p;
    C* pc;

    public:
        void mem(){
            XX(); //pub() and prot()
            p.YY(); //pub() not private and protected
            pc-> ZZ(); //pub() and prot()
        }
};

int main(void){
    
    C c;
    c.WW(); // only public, object of derived class

    return 0;
}

//protected inheritance makes the public and protected 
//members of the base class protected in the derived class.

//public inheritance makes public members of 
//the base class public in the derived class, 
//and the protected members 
//of the base class remain protected in the derived class.

//private inheritance makes the public and protected 
//members of the base class private in the derived class.