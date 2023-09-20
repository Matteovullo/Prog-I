#include <iostream>
using namespace std;

class A{
        int x;

    public:
        A(){
            x=0;
        }
        int getX() const{
            x++;
            return x;
        }
        int g(){
            x=100;
            return x;
        }
        friend ostream& operator<<(ostream& os, A &obj) {
            os << "x=" << obj.x << endl;
            return os;
        }
};

int main(){
    A obj;
    A &ref_obj=obj;
    A obj2;
    const A &ref_obj2=obj2;

    cout << ref_obj.getX() << endl;
    cout << ref_obj2.getX() << endl;
    cout << ref_obj.g() << endl;
    //cout << ref_obj2.g() << endl;
    cout << ref_obj;
    //cout << ref_obj2;

    int x=5;
    const int &ref_x=x;
    cout << ref_x << endl;
}
