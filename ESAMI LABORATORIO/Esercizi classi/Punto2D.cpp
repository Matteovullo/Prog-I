/*Definire una classe Punto2D che permetta di rappresentare 
punti bidimensionali con coordinate di tipo double. 
Si costruisca dunque una classe Scatter che abbia 
come variabile un array di puntatori a oggetti Punto2D. 
La classe Scatter deve avere i seguenti metodi:
Un costruttore che prenda in input un intero N che 
rappresenta il numero di punti dell’array e inizializzi 
l’array inserendo floor(N/2) punti con coordinate casuali 
comprese tra −2.2 e 2.2;
Un metodo estrai che prenda in input un intero i e 
restituisca il puntatore al Punto2D di indice i nell’array. 
Il metodo deve inoltre impostare a nullptr l’elemento nella 
posizionei dell’array;
Un metodo inserisci che prende in input un Punto2D e 
lo inserisce alla prima posizione libera dell’array 
se essa esiste;
Un metodo conta che restituisce il numero di puntatori 
che non sono nullptr nell’array;
Un metodo centroide che restituisce un puntatore a oggetto 
Punto2D che rappresenta il punto medio tra tutti i punti 
contenuti;
Si costruisca un programma che dichiari e inizializzi un 
oggetto di tipo Scatter con N=100 e poi effettui per 50 volte 
la seguente operazione. Calcolo del punto medio, 
e inserimento di questo punto nell’oggetto Scatter.*/

#include <iostream>
#include <cmath>
using namespace std;

class Punto2D{
    private:
        double x, y;

    public:
        Punto2D(double x, double y) {
            this->x=x;
            this->y=y;
        }
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
};

class Scatter{
    private:
        Punto2D **array;
        int dim;

    public:
        Scatter(int n){
            dim=n;
            array=new Punto2D*[dim];
            for(int i=0; i<floor(n/2); i++){
                if(i < floor(n/2))
                    array[i]=new Punto2D((2.2-(-2.2))*(1.0*rand()/RAND_MAX)+(-2.2), (2.2-(-2.2))*(1.0*rand()/RAND_MAX)+(-2.2));
                else
                    array[i]=nullptr;
            }
        }
        Punto2D* estrai(int i){
            Punto2D* aux=array[i];
            array[i]=nullptr;
            return aux;
        }
        void inserisci(Punto2D p){
            for(int i=0; i<dim; i++){
                if(array[i] == nullptr){
                    array[i]=new Punto2D(p);
                    break;
                }
            }
        }
        int conta(){
            int c=0;
            for(int i=0; i<dim; i++){
                if(array[i])
                    c++;
            }
            return c;
        }
        Punto2D* centroide(){
            double media_x=0.0;
            double media_y=0.0;
            int n=0;
            for(int i=0; i<dim; i++){
                if(array[i]){
                    media_x+=array[i]->getX();
                    media_y+=array[i]->getY();
                    n++;
                }
            }
            Punto2D p(media_x/n, media_y/n);
            Punto2D* ptr;
            *ptr=p;
            return ptr;
        }

};

int main(){
    Scatter s(100);
    for(int i=0; i<50; i++){
        s.inserisci(*(s.centroide()));
    }
}
