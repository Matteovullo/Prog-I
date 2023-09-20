#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>

using namespace std;

template <class T>
class Player{
    private:
        char name;
        char lname;
        int age;

    public:
        Player(char n, char in, int a){
            name=n;
            lname=in;
            age=a;
        }
        char getName(){
            return name;
        }
        char getLastname(){
            retunr lname;
        }
        char getEtà(){
            return età;
        }
        void setName(char ng){
            name=rg;
        }
        void setLastNane(char cg){
            lname=cg;
        }
        void setAge(int a){
            age=a;
        }
        virtual int GetAction()=0;
        virtual void StampaGiocatore=0;
        virtual ostream& put(ostream& os) {
            os << typeid(*this).name() << ", name: " << name << ", lastname: " << lname << ", age: " << age << "], ";
            return os;
        }
};

ostream& operator<<(ostream& os, Player& obj) {
    return obj.put(os);
}

template <class T>
class Def: class Player{
    private:
        int defend;

    public:
        Def(char n, char ln, int a): Player::Player(n, ln, a){
            defend=rand();
        }
        int getAction(){
            return defend;
        }
        void StampaGiocator(){
            cout << defend;
        }
        virtual ostream& put(ostream& os) {
            A::put(os);
            os << ", defend=" << defend; 
            return os;
        }
};

template <class T>
class Atk: class Player{
    private:
        int attack;

    public:
        Atk(char n, char ln, int a): Player::Player(n, ln, a){
            attack=rand();
        }
        int getAction(){
            return defend;
        }
        void StampaGiocator(){
            cout << attack;
        }
        virtual ostream& put(ostream& os) {
            A::put(os);
            os << ", attack=" << attack; 
            return os;
        }
};

int main(){
    srand(111222333);
    const int DIM = 50;
    Player* vett[DIM];

    for (int i = 0; i < DIM; i++) {
        short n = 5 + rand() % 5;
        switch (rand() % 3) {
        case 0:
            vett[i] = new Atk();
            break;
        case 1:
            vett[i] = new Def<double>(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 2:
            vett[i] = new Def<short>(n, rand() % 5 + 1, rand() % 10 + 5);
        }
    }

    
}