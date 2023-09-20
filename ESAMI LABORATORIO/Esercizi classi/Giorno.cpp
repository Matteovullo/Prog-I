/*Si implementino delle classi:
Giorno: rappresenta un giorno del mese espresso sia come 
numero che come giorno della settimana;
Mese: rappresenta un mese;
Anno: rappresenta un anno;
Le classi sopra definite dovranno avere gli opportuni 
costruttori e dovranno assicurarsi di ricevere input 
corretti (ad esempio Giorno dovrà rappresentare giorni 
compresi tra 1 e 31);
Definire dunque una classe Data che abbia come variabili 
membro tre oggetti di tipo Giorno, Mese e Anno. 
La classe dovrà avere un costruttore opportuno che controlli
che la data inserita sia valida, un metodo stampa che mostri
la data nel formato “Mercoledì 22 dicembre 2021”,
e un metodo differenza che prenda in input un altro
oggetto di tipo Data e calcoli il numero di giorni 
che intercorrono tra le due date.
Nota: un anno è bisestile se è divisibile per 4 ma non 
per 100.*/

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
            this->mese=mese;
            this->m=m;
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
        Data(int i1, int i2, int i3, int i4, string s1, string s2) : g(i1, s1), m(s2, i4), a(i3){}
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

int main(){
    return 0;
}
