/*
Homework H24.1
Implementare una classe Matrice3D. In particolare:
• il costruttore deve permettere allo usercode di specificare
le tre dimensioni della matrice, ed un ulteriore valore con
cui inizializzare tutti gli elementi della matrice; specificare
argomenti standard sia per le dimensioni, che per il valore
di inizializzazione;
• i metodi getDimX(), getDimY(), getDimZ();
• un metodo stampa(), che stampi tutti gli elementi della
matrice;
• un metodo sommaByPtr che prenda in input due
parametri formali di tipo puntatore a Matrice3D e
restituisca la somma delle due matrici come puntatore al
tipo Matrice3D;
• un metodo sommaByReference che prenda in input due
parametri formali reference al tipo Matrice3D e
restituisca la somma delle due matrici come reference al
tipo Matrice3D;
• un metodo getElement(int x, int y, int z) che
restituisca una reference all’elemento di indici x, y, e z.
• un metodo getValue(int x, int y, int z) che
restituisca il valore dello elemento di indici x, y, e z.
*/

#include <iostream>
using namespace std;

class Matrice3D{
	private:
		int ***arr;
		int x,y,z;
	public:
		Matrice3D(int x=5, int y=5, int z=5, int primo_valore=0){
			arr=new int arr **[x];
			for(int i=0; i<x; i++){
				arr[i]=new int arr*[x];
				for(int j=0; j<y; j++){
					arr[i][j]=new int arr[x];
					for(int h=0; h<z; h++){
						arr[i][j][h]=primo_valore;
					}
				}
			}
			
		this->x=x;
		this->y=y;
		this->z=z;
		}
		~Matrice3D(){
			for(int i=0; i<this->x; i++){
				for(int j=0; j<this->y; j++){
					delete[] arr[i][j];
					delete[] arr[i];
				}
			}
			delete[] arr;
		}
		int getDimX(){return x;}
		int getDimY(){return y;}
		int getDimZ(){return z;}
		void stampa(){
			for(int i=0; i<getDimX(); i++){
				for(int j=0; j<getDimY(); j++){
					for(int h=0; h<getDimZ(); h++){
						cout<<arr[i][j][h];
					}
				}
			}
		}
		Matrice3D* sommaByPtr(Matrice3D *ptr1,Matrice3D *ptr2){
			if(ptr1->getDimX() != ptr2->getDimY() || ptr1->getDimY() != ptr2->getDimY() || ptr1->getDimZ() != ptr2->getDimZ()){
				return nullptr;
			}
			Matrice3D* res=new Matrice3D(ptr1->getDimX(), ptr1->getDimY(), ptr1->getDimZ());
				for(int i=0; i<ptr1->getDimX(); i++){
				for(int j=0; j<ptr1->getDimY(); j++){
					for(int h=0; h<ptr1->getDimZ(); h++){
						res->arr[i][j][h]=ptr1->getElement(i,j,h) + ptr2->getElement(i,j,h);
					}
				}
			}
			return res;
		}
		Matrice3D& sommaByPtr(Matrice3D &ptr1,Matrice3D &ptr2){
		if(ptr1->getDimX() != ptr2->getDimY() || ptr1->getDimY() != ptr2->getDimY() || ptr1->getDimZ() != ptr2->getDimZ()){
			return nullptr;
		}
		Matrice3D& res=new Matrice3D(ptr1->getDimX(), ptr1->getDimY(), ptr1->getDimZ());
			for(int i=0; i<ptr1->getDimx(); i++){
				for(int j=0; j<ptr1->getDimY(); j++){
					for(int h=0; h<ptr1->getDimZ(); h++){
						res->arr[i][j][h]=ptr1->getElement(i,j,h) + ptr2->getElement(i,j,h);
					}
				}
			}
			return res;	
		}
		int &getElement(int x, int y, int z){
			return arr[x][y][z];
		}
		getValue(int x, int y, int z){
			
		}
};

int main(){
	return 0;
}
