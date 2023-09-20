#include <iostream>

using namespace std;

class Settore{
    private:
        string codSettore;
        int NRep;

    public:
        Settore(string s,int i){
            this->codSettore=s;
            this->NRep=i;
        }
        string getcodSettore(){
            return codSettore;
        }
        int getNRep(){
            return NRep;
        }
};

class Ufficio : public Settore{
    private:
        string codUfficio;
        int num_imp;
        int num_pratiche;

    public:
        Ufficio(string s, int i1, int i2, string s2, int i3) : Settore(s2, i3){
            this->codUfficio=s;
            this->num_imp=i1;
            this->num_pratiche=i2;
        }
        string getcodUfficio(){
            return codUfficio;
        }
        int getNum_imp(){
            return num_imp;
        }
        int getNum_pratiche(){
            return num_pratiche;
        }
};

int main(){
    
}
