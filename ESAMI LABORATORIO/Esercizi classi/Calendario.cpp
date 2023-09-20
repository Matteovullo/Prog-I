/*Con riferimento all’oggetto di tipo Data costruito in un 
esercizio precedente, si costruisca un oggetto Calendario che 
contenga un array di puntatori a oggetti di tipo Data. 
La classe possiede un costruttore che prende in input 
l’anno e il giorno di inizio (ad esempio “Lunedì” se 
il primo gennaio di quell’anno è un lunedì e 
inizializza opportunamento l’array inserendo tutte le 
date relative ai giorni di quell’anno.*/

#include <iostream>
using namespace std;

class Giorno{
    private:
        int giorno;
        string giorno_s;

    public:
        Giorno(int g, string giorno_s){
            if(g >= 1 && g <=31){
                this->giorno=g;
                this->giorno_s=giorno_s;
            }else{
                giorno=giorno%g;
                this->giorno_s=giorno_s;
            }
        }
        int getGiorno(){
            return giorno;
        }
        string getGiorno_s(){
            return giorno_s;
        }
};

class Mese{
    private:
        string mese;
        int m;

    public:
        Mese(string mese_m, int m){
            if(m >= 1 && m <= 12){
                this->mese=mese;
                this->m=m;
            }else{
                mese=m%12;
                this->mese=mese_m;
            }
        }
        string getMese(){
            return mese;
        }
        int getMesel(){
            return m;
        }
};

class Anno{
    private:
        int anno;

    public:
        Anno(int anno){
            this->anno=anno;
        }
        int getAnno(){
            return anno;
        }
};

class Data{
    private:
        Giorno g;
        Mese m;
        Anno a;

    public:
        Data(int i1, int i2, int i3, string s1, string s2) : g(i1, s1), m(s2, i2), a(i3){}
        void stampa(){
            cout << g.getGiorno_s() << " " << g.getGiorno() << " " << m.getMese() << " " << a.getAnno() << endl;
        }
        string getM(){
            return m.getMese();
        }
        int getm(){
            return m.getMesel();
        }
        int getA(){
            return a.getAnno();
        }
        int differenza(Data d){
            if(a.getAnno() == d.getA()){
                int a=abs(m.getMesel()-d.getm());
                return a*30;
            }else{
                int diff_anno=abs(a.getAnno()-d.getA());
                int diff_mesi=abs(m.getMesel()-d.getm());
                return diff_anno*360+diff_mesi*30;
            }
        }
};

class Calendario{
    private:
        Data **array;
        int anno;

    public:
        Calendario(int anno, string giorno){
            this->anno=anno;
            array=new Data*[360];
            for(int i=0; i<360; i++){
                array[i]=nullptr;
            }
        }
};

int main(){
    Calendario c(2022, " ");
}