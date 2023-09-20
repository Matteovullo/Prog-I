#include <iostream>

using namespace std;

class Scarpa{
    private:
        int taglia;
        char colore;

    public:
        Scarpa(int taglia, int colore){
            this->taglia=taglia;
            this->colore=colore;
        }
        int getTaglia(){
            return taglia;
        }
        char getColore(){
            return colore;
        }
};

class Scarpiera{
    private:
        Scarpa **s;
        int n;

    public:
        Scarpiera(int n){
            this->n=n;
            s=new Scarpa*[n];
            for(int i=0; i<n; i++){
                s[i]=nullptr;
            }
        }
        Scarpa estrarre(int i){
            return *s[i];
        }
        void contenuto(int t){
            for(int i=0; i<n; i++){
                if(s[i]){
                    if((*s[i]).getTaglia() == t){
                        cout << "Scarpa eistente alla posizone: " << i;
                    }
                }
            }
        }
        void stampa(){
            for(int i=0; i<n; i++){
                if(s[i])
                    cout << "Scarpa: " << i << ", taglia: " << (*s[i]).getTaglia() << ", colore: " << (*s[i]).getColore() << endl;
                else 
                    cout << "Spazio libero" << endl;
            }
        }
        void inserisci(int i1, char c){
            for(int i=0; i<n; i++){
                if(s[i] == nullptr)
                    s[i]=new Scarpa(i1, c);
            }
        }
};

int main(){
    Scarpiera s(10);
    Scarpa sa(45, 'r');
    for(int i=0; i<10; i++){
        s.inserisci(45, 'r');
    }
    s.stampa();
}