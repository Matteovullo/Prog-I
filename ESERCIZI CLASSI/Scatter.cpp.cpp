/*
Definire una classe Punto2D che permetta di rappresentare punti bidimensionali con coordinate di tipo double. 
Si costruisca dunque una classe Scatter che abbia come variabile un array di puntatori a oggetti Punto2D.
La classe Scatter deve avere i seguenti metodi:
Un costruttore che prenda in input un intero N che rappresenta il numero di punti dell’array e inizializzi 
l’array inserendo floor(N/2) punti con coordinate casuali comprese tra −2.2 e 2.2;
Un metodo estrai che prenda in input un intero i e restituisca il puntatore al Punto2D di indice i nell’array.
Il metodo deve inoltre impostare a nullptr l’elemento nella posizionei dell’array;
Un metodo inserisci che prende in input un Punto2D e lo inserisce alla prima posizione libera dell’array se essa esiste;
Un metodo conta che restituisce il numero di puntatori che non sono nullptr nell’array;
Un metodo centroide che restituisce un puntatore a oggetto Punto2D che rappresenta il punto medio tra tutti i punti contenuti;
Si costruisca un programma che dichiari e inizializzi un oggetto di tipo Scatter con N=100 e poi effettui per 50 volte la seguente operazione.
 Calcolo del punto medio, e inserimento di questo punto nell’oggetto Scatter.
*/

#include <cmath>
#include <ctime>
#include <cstdlib>


class Punto2D{
	private:
		double x,y;
	public:
		Punto2D(double x_, double y_) : x(x_), y(y_){}
		double getX(){return x;}
		double getY(){return y;}
};

class Scatter{
	private:
		static const int n=15;
		Punto2D *arr[n];
	public:
		Scatter(int a){
			for(int i=0; i<floor(n/2); i++){
				double rx=-2.2 + (rand() * 2.2) / RAND_MAX;
				double ry=-2.2 + (rand() * 2.2) / RAND_MAX;
				arr[i]=new Punto2D(rx,ry);
			}
		}
		Punto2D* estrai(int x){
			Punto2D *ptr=arr[x];
			arr[x]=nullptr;
			return ptr;
		}
		void inserisci(Punto2D *d){
			for(int i=0; i<n; i++){
				if(arr[i]==nullptr){
					arr[i]=d;
				}
			}
		}
		int conta(){
			int count=0;
			for(int i=0; i<n; i++){
				if(arr[i]!=nullptr){
					count++;
				}
				return count;
		}
		Punto2D* centroide(){
			double max_x;
			double max_y;  
			double min_x;
			double min_y;

			for(int i=0; i<n; i++){
				if(arr[i]->getX()>max_x){
					max_x=arr[i]->getX(); 
				}

				if(arr[i]->getY()>max_y){
					max_y=arr[i]->getY(); 
				}

				if(arr[i]->getX()<min_x){
					min_x=arr[i]->getX(); 
				}

				if(arr[i]->getY()<min_y){
					min_y=arr[i]->getY(); 
				}
			}

			double PuntoMediox= (max_x+min_x)/2;
			double PuntoMedioy= (max_y+min_y)/2; 
			
			return new Punto2D(PuntoMediox, PuntoMedioy);
		}
};

int main(){
	Scatter s(100);
	for(int i=0; i<50; i++){
		*ptr=s.centroide();
		s.inserisci(ptr);
	}
}
