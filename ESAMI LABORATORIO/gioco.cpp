#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>


using namespace std;

template<class T>
class Character{
    private:
        T*** power;

    protected:
        int rows;
        int columns;
        T** getColumn(int index){
            T** vettore=new T*[rows];
            for(int i=0; i<rows; i++){
                vettore[i]=power[i][index];
            }
            return vettore;
        }

    public:
        Character(int rows, int columns){
            this->rows=rows;
            this->columns=columns;
            power=new T**[rows];
            for(int i=0; i<rows; i++){
                power[i]=new T*[columns];
                for(int j=0; j<columns; j++){
                    power[i][j]=new T((T)(rand()) / RAND_MAX);
                }
            }
        }
        void traspose(){
            T*** matrice=new T**[columns];
            for(int i=0; i<columns; i++){
                matrice[i]=new T*[rows];
                for(int j=0; j<rows; j++){
                    matrice[i][j]=new T(*power[j][i]);
                }
            }
            int aux=rows;
            this->rows=columns;
            this->columns=aux;
            for (int i = 0; i < columns; i++){
                for (int j = 0; j < rows; j++){
                    delete[] power[i][j];
                }
                delete[] power[i];
            }
            delete[] power;
            power=new T**[rows];
            for(int i=0; i<rows; i++){
                power[i]=new T*[columns];
                for(int j=0; j<columns; j++){
                    power[i][j]=new T(*matrice[i][j]);
                }
            }
        }
        virtual double attack() = 0;
        virtual ostream &put(ostream &os){
            os << typeid(*this).name() << " ";
            os << "power= ";
            for(int i=0; i<rows; i++){
                for(int j=0; j<columns; j++){
                    os << *power[i][j] << " ";
                }
                os << endl;
            }
            return os;
        }
};

template<class T>
ostream &operator<<(ostream &os, Character<T> &obj){
    return obj.put(os);
}

template<class T>
class Wizard : public Character<T>{
    public:
        Wizard(int rows, int columns) : Character<T>::Character(rows, columns){
            Character<T>::traspose();
        }
        T attack(){
            int dado=rand()%12+1;
            if(dado%2 == 0){
                Character<T>::traspose();
                return 0;
            }else{
                int r=0;
                T somma=0;
                do{
                    r=rand()%(Character<T>::columns-0+1)+0;
                }while(r%2 == 0);
                T** vettore=Character<T>::getColumn(r);
                for(int i=0; i<Character<T>::rows; i++){
                    somma+=*vettore[i];
                }
                delete[] vettore;
                return somma+(dado%6);
            }
        }
        ostream &put(ostream &os){
            Character<T>::put(os);
            os << "attack()= " << attack();
            return os;
        }
};

template<class T>
class Cleric : public Character<T>{
    public:
        Cleric(int rows, int columns) : Character<T>::Character(rows, columns){}
        T attack(){
            int dado=rand()%(6-1+1)+1;
            if(dado == 1 || dado == 5){
                return 0;
            }else if(dado%2 == 0){
                T somma=0;
                int r=rand()%Character<T>::columns;
                T** vettore=Character<T>::getColumn(r);
                for(int i=0; i<Character<T>::rows; i++){
                    somma+=*vettore[i];
                }
                delete[] vettore;
                return somma+dado;
            }else{
                return dado/(double)2;
            }
        }
        ostream &put(ostream &os){
            Character<T>::put(os);
            os << "attack()= " << attack();
            return os;
        }
};

int main() {
  srand(11223344);
  
  const int DIM = 10;

  Character<double>* vett[DIM];

  for(int i = 0; i < DIM; i++) {
    int r = rand() % 2;
    if(r == 0) {
      vett[i] = new Wizard<double>(rand()%5 + 2, rand()%5 + 2);
    }
    else {
      vett[i] = new Cleric<double>(rand()%5 + 2, rand()%5 + 2);
    }
  }

  for(int i = 0; i < DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
  }
}