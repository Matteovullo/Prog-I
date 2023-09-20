#include<iostream>
using namespace std;

class A{
    int x;

    public:
        A(){
            x=0;
        }
        friend int incremento(A& obj);
        friend class B;
};

int incremento(A& obj){
    obj.x++;
    return obj.x;
}

class B{
    int y;

    public:
        B(){
            y=0;
        }
        int modificaclasse(A& obj){
            obj.x++;
            return obj.x;
        }
};

int main(){
    A obj;
    A &ref_obj=obj;
    cout << incremento(ref_obj) << endl;

    B oggetto;
    cout << oggetto.modificaclasse(ref_obj) << endl;
    
}
