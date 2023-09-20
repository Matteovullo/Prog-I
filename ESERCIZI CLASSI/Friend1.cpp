/*
Si definisca una classe Set che rappresenti un insieme di massimo MAX_SIZE interi. 
La classe deve possedere come variabile un array di MAX_SIZE puntatori a interi 
(usare un define per assegnare un valore a MAX_SIZE). Gli interi contenuti nell’insieme sono rappresentati 
dai puntatori 
non nulli nell’array. Alla creazione, il set è vuoto, ma possiede un metodo add che permette di aggiungere 
un nuovo elemento all’insieme se c’è ancora spazio e un metodo remove che permette di rimuoverlo se presente. 
Ogni set ha un metodo stampa che stampa gli elementi presenti nel set. Definire una funzione friend intersect 
che prenda 
in input due set e restituisca un set che sia l’intersezione dei due insiemi. Costruire un programma che 
dimostri le capacità dei set.
*/

#include <iostream>
using namespace std;
#define MAX_SIZE 10

class Set{
	int* *arr[MAX_SIZE];
	public:
		Set(){
			arr=new int *[MAX_SIZE];
			for(int i=0; i<MAX_SIZE; i++){
				arr[i]=new int(0);
				arr[i]=nullptr;
			}
		}
		
		void add(int x){
			for(int i=0; i<MAX_SIZE; i++){
				if(arr[i]==nullptr){
					*arr[i]=x;
				}
			}
		}
		
		void remove(int y){
			for(int i=0; i<MAX_SIZE; i++){
				if(*arr[i]==y){
					arr[i]=nullptr;
				}
			}
		}
		
		void stampa(){
			for(int i=0; i<MAX_SIZE; i++){
				if(arr[i]){
					cout<<*arr[i]<<endl;
				}
			}
		}
		
		int prelevare(int y){
			int c;
			c=*arr[y];
			return c;
		}
		
		friend int** intersect(Set a, Set b){
			int count;
			for(int i=0; i<MAX_SIZE; i++){
				if(a.prelevare(i) == b.prelevare(i)){
					count++;
				}
			}
			int* *insieme[count]=new int *[count];
			for(int i=0; i<count; i++){
				insieme[i]=new int(a.prelevare(i));
			}

			return insieme;
		}
};

int main(){
	Set s;
	for(int i=0; i<MAX_SIZE; i++){
		s.add(1);
	}
	s.stampa();
}
