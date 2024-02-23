#include <iostream>

using namespace std;

class A{
    int data;

    public:
        //default constructor
        A(int datav=0):data(datav){
            cout << "A1 " << endl;
        }

        //copy constructor
        A(A& a){
            cout << "A2 " << endl;
            data=a.data;
        }

        //assign operator overload, υπερφόρτωση τελεστή ισότητας
        A& operator=(const A&){
            cout << "A3 " << endl;
            return *this;
        }

        //Destructor
        ~A(){
            cout << "A4 " << data << endl;
        }

        void put(int datav){
            data = datav;
        }
};

int main(void){

    A a1;
    A a2(a1);
    A a3=a2;

    a1.put(5);
    A& a4=a1;
    //a4=a2;

    //A1 
    //A2 
    //A2 
    //A4 0
    //A4 0
    //A4 5


    return  0;
}