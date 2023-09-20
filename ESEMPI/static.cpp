#include <iostream>
using namespace std;

class A{
    static int x;

    public:
        A(){
            x++;
        }
        static int getCount(){return x;}
        static int incrementa(){
            x++;
            return x;
        }
};

int A::x=0;

int contatore(){
    static int c=0;
    return c++;
}

int main(){
    A obj;
    cout << obj.getCount() << endl;
    cout << A::getCount() << endl;

    cout << endl << endl << endl;

    for(int i=0; i<10; i++){
        cout << A::incrementa() << endl;
    }
    cout << endl << endl << endl;

    for(int i=0; i<10; i++) cout << contatore() << endl;
}