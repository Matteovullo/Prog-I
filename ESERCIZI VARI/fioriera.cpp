#include <iostream>

using namespace std;

class Pianta{
    private:
        int petali;
        char nome;
        int altezza;
    
    public:
        Pianta(int petali, char nome, int altezza){
            this->petali=petali;
            this->nome=nome;
            this->altezza=altezza;
        }
        int getPetali(){
            return petali;
        }
        char getNome(){
            return nome;
        }
        int getAltezza(){
            return altezza;
        }
};

class Fioriera{
    private:
        Pianta** p;

    public:
        Fioriera(){
            p=new Pianta*[3];
            for(int i=0; i<3; i++){
                p[i]=nullptr;
            }
        }
        void inserimento(Pianta pianta){
            for(int i=0; i<3; i++){
                if(p[i] == nullptr){
                    *p[i]=pianta;
                    break;
                }
            }
        }
        void stampa(){
            for(int i=0; i<3; i++){
                if(p[i])
                    cout << "Pianta di petali: " << (*p[i]).getPetali() << ", nome:" << (*p[i]).getNome() << ", altezza:" << (*p[i]).getAltezza() << endl;
            }
        }
};

int main(){
    Pianta p1(5, 'A', 10);
    Pianta p2(5, 'A', 10);
    Pianta p3(5, 'A', 10);

    Fioriera f;
    f.inserimento(p1);
    f.inserimento(p2);
    f.inserimento(p3);
    f.stampa();
}