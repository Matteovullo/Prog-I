#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

#define DIM 10

using namespace std;

template<class T>
class Player{
    private:
        string name;
        string lname;
        int age;

    public:
        Player(string n, string ln, int a){
            this->name=n;
            this->lname=ln;
            this->age=a;
        }
        string getName(){
            return name;
        }
        string getLastName(){
            return lname;
        }
        int getAge(){
            return age;
        }
        void setName(string ng){
            this->name=ng;
        }
        void setLastName(string cg){
            this->lname=cg;
        }
        void setEta(int a){
            this->age=a;
        }
        virtual int GetAction()=0;
        virtual void StampaGiocatore()=0;
        virtual ostream &put(ostream &os){
        os << typeid(*this).name();
        return os;
        }
};

template<class T>
ostream &operator<<(ostream &os, Player<T> &obj){
    return obj.put(os);
}

template<class T>
class Def : public Player<T>{
    private:
        int defend;

    public:
        Def(string n, string ln, int a, int defend) : Player<T>::Player(n, ln, a){
            this->defend=defend;
        }
        int GetAction(){
            return defend;
        }
        void StampaGiocatore(){
            cout << "Defend player: " << Player<T>::getName() << " " << Player<T>::getLastName() << " " << Player<T>::getAge() << endl;
        }
        ostream &put(ostream &os){
        Player<T>::put(os);
        os << "Nome=" << Player<T>::getName() << ", Cognome=" << Player<T>::getLastName() << ", Eta=" << Player<T>::getAge() << ", Defend=" << defend << endl ;
        return os;
        }
};

template<class T>
class Atk : public Player<T>{
    private:
        int attack;

    public:
        Atk(string c, string ln, int a, int attack) : Player<T>::Player(c, ln, a){
            this->attack=attack;
        }
        int GetAction(){
            return attack;
        }
        void StampaGiocatore(){
            cout << "Defend player: " << Player<T>::getName() << " " << Player<T>::getLastName() << " " << Player<T>::getAge() << endl;
        }
        ostream &put(ostream &os){
        Player<T>::put(os);
        os << "Nome=" << Player<T>::getName() << ", Cognome=" << Player<T>::getLastName() << ", Eta=" << Player<T>::getAge() << ", Atk=" << attack << endl;
        return os;
        }
};

int main(){
    Player<int>* vec[DIM];
    for(int i=0; i<DIM; i++){
        string giocatore="";
        cout << "Inserire giocatore: ";
        cin >> giocatore;
        if(giocatore == "def"){
            vec[i]=new Def<int>("Matteo", "Vullo", 19, 50);
        }else if(giocatore == "atk"){
            vec[i]=new Atk<int>("Matteo", "Vullo", 19, 100);
        }
    }

    int score1=0;
    int score2=0;
    int media_attack=0;
    int media_defend=0;
    int c1=0;
    int c2=0;
    int attacco[5];
    int difesa[5];
    bool win=false;
    do{
        int r1=0;
        int r2=0;
        do{
            r1=rand()%(10-0+1)+1;
            r2=rand()%(10-0+1)+1;
        }while(typeid(vec[r1])==typeid(Def<int>)  && typeid(vec[r1])==typeid(Def<int>) || typeid(vec[r1])==typeid(Atk<int>)  && typeid(vec[r1])==typeid(Atk<int>));
        int val1=0;
        int val2=0;
        if(typeid(*vec[r1])==typeid(Def<int>)){
            media_defend+=vec[r1]->GetAction();
            c1++;
            val1=vec[r1]->GetAction();
            val2=vec[r2]->GetAction();
        }else{
            media_attack+=vec[r1]->GetAction();
            c2++;
            val2=vec[r2]->GetAction();
            val1=vec[r1]->GetAction();
        }
        if(val1 > val2){
            score1++;
        }else{
            score2++;
        }
    }while(score1 <= 3 || score2 <= 3);

    if(score1 > score2){
        cout << "Ha vinto la squadra 1";
    }else{
        cout << "Ha vinto la squadra 2";
    }


    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vec[i] << endl;
    }

}