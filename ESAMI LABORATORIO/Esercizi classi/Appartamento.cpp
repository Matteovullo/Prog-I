/*Si implementi una classe Stanza che rappresenti una stanza 
di una casa. La classe dovrà contenere informazioni sul nome 
(es. stanza da pranzo) e sulle dimensioni 
(si assuma che la stanza è rettangolare) e prmettere di 
calcolare la superficie della stanza. Si implementi una 
classe Bagno contenenti le dimensioni 
(si assumano bagni rettangolari) e che permetta di calcolare 
la superficie del bagno. Si costruiscano dunque le seguenti 
classi:
Bivani: contiene una stanza da letto, una cucina e un bagno;
Trivani: contiene due stanze da letto, una cucina e un bagno;
Quadrivani: contiene una cucina, un soggiorno, due stanze da 
letto e due bagni.
Ciascuna delle classi implementate sopra dovrà permettere di 
calcolare la superficie dell’appartamento e dovrà avere un 
riferimento al proprietario dell’appartamento, 
un oggetto di tipo Persona. Ciascuna delle 
classi implementate dovrà anche possedere 
un metodo sommario() che stampi un sommario delle 
caratteristiche della casa.
Si costruisca un programma che costruisca diversi 
appartamenti appartenenti a diverse persone e visualizzi 
informazioni su di essi.*/

#include <iostream>

using namespace std;

class Persona {
    string nome;
    string cognome;
    int eta;
    public:
        Persona(string n, string c, int e) : nome(n), cognome(c), eta(e) {}
};

class Stanza{
    private:
        string nome;
        int base;
        int altezza;

    public:
        Stanza(string nome, int base, int altezza){
            this->nome=nome;
            this->base=base;
            this->altezza=altezza;
        }
        int area(){
            return base*altezza;
        }
};

class Bagno{
    private:
        Stanza s;

    public:
        Bagno(int base, int altezza) : s("", base, altezza) {}
        int area(){
            return s.area();
        }
};

class Bivani{
    private:
        Stanza stanza_da_letto;
        Stanza cucina;
        Bagno bagno;
        Persona *propietario;

    public:
        Bivani(string n1, string n2, string n3, int b1, int b2, int b3, int a1, int a2, int a3, Persona *p) :  stanza_da_letto(n1, b1, a1), cucina(n2, b2, a2), bagno(b3, a3), propietario(p){}
        int area(){
            return stanza_da_letto.area()+cucina.area()+bagno.area();
        }
        void sommario(){
            cout << "L' appartamento è un bivano composto da 3 stanza: " << endl;
            cout << "Stana da letto di " << stanza_da_letto.area() << endl;
            cout << "Cucina di " << cucina.area() << endl;
            cout << "Bagno di " << bagno.area() << endl;
        }
};

class Trivani{
    private:
        Stanza stanza_da_letto1;
        Stanza stanza_da_letto2;
        Stanza cucina;
        Bagno bagno;
        Persona *propietario;

    public:
        Trivani(string n1, string n2, string n3, int b1, int b2, int b3, int b4, int a1, int a2, int a3, int a4, Persona *p) :  stanza_da_letto1(n1, b1, a1), stanza_da_letto2(n2, b2, a2), cucina(n3, b3, a3), bagno(b4, a4), propietario(p){}
        int area(){
            return stanza_da_letto1.area()+stanza_da_letto2.area()+cucina.area()+bagno.area();
        }
        void sommario(){
            cout << "L' appartamento è un bivano composto da 3 stanza: " << endl;
            cout << "Stana da letto 1 di " << stanza_da_letto1.area() << endl;
            cout << "Stana da letto 2 di " << stanza_da_letto2.area() << endl;
            cout << "Cucina di " << cucina.area() << endl;
            cout << "Bagno di " << bagno.area() << endl;
        }
};

class Quadrivani{
    private:
        Stanza stanza_da_letto1;
        Stanza stanza_da_letto2;
        Stanza cucina;
        Stanza soggiorno;
        Bagno bagno1;
        Bagno bagno2;
        Persona *propietario;

    public:
        Quadrivani(string n1, string n2, string n3,string n4, int b1, int b2, int b3, int b4, int b5, int b6, int a1, int a2, int a3, int a4, int a5, int a6, Persona *p) :  stanza_da_letto1(n1, b1, a1), stanza_da_letto2(n2, b2, a2), soggiorno(n3, b3, a3), cucina(n4, b4, a4), bagno1(b5, a5), bagno2(b6, a6), propietario(p) {}
        int area(){
            return stanza_da_letto1.area()+stanza_da_letto2.area()+soggiorno.area()+cucina.area()+bagno1.area()+bagno2.area();
        }
        void sommario(){
            cout << "L' appartamento è un bivano composto da 3 stanza: " << endl;
            cout << "Stana da letto 1 di " << stanza_da_letto1.area() << endl;
            cout << "Stana da letto 2 di " << stanza_da_letto2.area() << endl;
            cout << "Soggiorno di " << soggiorno.area() << endl;
            cout << "Cucina di " << cucina.area() << endl;
            cout << "Bagno di " << bagno1.area() << endl;
            cout << "Bagno di " << bagno2.area() << endl;
        }
};

int main(){
    Persona p("Matteo", "Vullo", 19);
    Persona *ptr=&p;
    Quadrivani q("", "", "", "", 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, ptr);
    q.sommario();
}