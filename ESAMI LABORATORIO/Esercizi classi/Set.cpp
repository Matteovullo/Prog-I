/*Si definisca una classe Set che rappresenti un insieme 
di massimo MAX_SIZE interi. La classe deve possedere come 
variabile un array di MAX_SIZE puntatori a interi 
(usare un define per assegnare un valore a MAX_SIZE). 
Gli interi contenuti nell’insieme sono rappresentati 
dai puntatori non nulli nell’array. Alla creazione, 
il set è vuoto, ma possiede un metodo add che permette 
di aggiungere un nuovo elemento all’insieme se c’è ancora 
spazio e un metodo remove che permette di rimuoverlo se 
presente. Ogni set ha un metodo stampa che stampa gli 
elementi presenti nel set. Definire una funzione friend 
intersect che prenda in input due set e restituisca un 
set che sia l’intersezione dei due insiemi. 
Costruire un programma che dimostri le capacità dei set.*/

#include <iostream>
using namespace std;

class Set{
    private:
        int** array;
        int max_size;

    public:
        Set(int max_size){
            this->max_size=max_size;
            array=new int*[max_size];
            for(int i=0; i<max_size; i++){
                array[i]=nullptr;
            }
        }
        void add(int j){
            for(int i=0; i<max_size; i++){
                if(array[i]==nullptr){
                    array[i]=new int(j);
                    break;
                }
            }
        }
        void remove(int i){
            for(int i=0; i<max_size; i++){
                if(array[i] && *array[i]==i)
                    array[i]=nullptr;
            }
        }
        int* get(int i){
            if(array[i])
                return array[i];
            else
                return nullptr;
        }
        int getMax_size(){
            return max_size;
        }
        void stampa(){
            for(int i=0; i<max_size; i++){
                if(array[i])
                    cout << *array[i] << " ";
                else
                    cout << "*" << " ";
            }
            cout << endl;
        }
        friend Set intersect(Set s1, Set s2);
};

Set intersect(Set s1, Set s2){
    Set s3(s1.getMax_size()+s2.getMax_size());
    for(int i=0; i<s1.getMax_size(); i++){
        if(s1.get(i))
            s3.add(*s1.get(i));
    }
    for(int i=0; i<s2.getMax_size(); i++){
        if(s2.get(i))
            s3.add(*s2.get(i));
    }
    return s3;
}

int main(){
    Set s1(10);
    Set s2(5);
    s1.add(1);
    s1.add(2);
    s1.add(3);
    s1.add(4);
    s1.add(5);
    s2.add(6);
    s2.add(7);
    s2.add(8);
    s2.add(9);
    s2.add(10);
    Set s3=intersect(s1, s2);
    s3.stampa();
}
