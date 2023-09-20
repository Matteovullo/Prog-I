#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>

using namespace std;

template <class T>
class Character{
    private:
        T ***power;

    protected:
        int rows;
        int columns;
        T** getColumns(int index){
            T **vec= new T*[columns];
            for(int i=0; i<rows; i++){
                vec[i]=new T(power[i][index]);
            }
            return vec;
        }

    public:
        Character(int rows, int columns){
            this->rows=rows;
            this->columns=columns;
            power=new T*[rows];
            for(int i=0; i<rows; i++){
                power[i]=new T[colomns];
                for(int i=0; i<columns; i++){
                    power[i][j]=new T(rand()%(1-0+1)+0));
                }
            }
        T** traspose(){
        T **B;
        if(rows == columns){
            T **B=new T *[rows];
            for(int i=0; i<n; i++){
                B[i]=new T [columns];
            }
            for(int i=0; i<rows; i++){
                for(int j=0; j<columns; j++){
                    
                    *B[j][i]=*power[i][j];
                }
            }
        }else{
            T **B=new T *[columns];
            for(int i=0; i<rows; i++){
                B[i]=new T [n];
            }
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    *B[i][j]=*power[j][i];
            }
        }
        return B;
        }
        virtual double attack()=0;
};

template <class T>
class Wizard: public Character{
    public:
        Wizard(int rows, int colomns): Character::Character(rows, colomns){
            power.Character::traspose();
        }
        T attack(){
            int dado=rand()%(12-1+1)+1;
            if(dado%2 == 0){
                power.Character::traspose();
                dado=0;
                return dado;
            }else{
                dado=dado%6;
                int somma=0;
                T* vec=Character::getColumns();
                for(int i=0; i<rows; i++){
                    somma+=vec[i];
                }
                return dado+=somma;
            }
        }
};

template <class T>
class Cleric: public Character{
    public:
        Cleric(int rows, int colomns): Character::Character(rows, columns){}
        T attack(){
            int dado=rand()%(5-1+1)+1;
            if(dado==1 || dado==5){
                return 0;
            }else if(dado%2==0){
                int somma=0;
                T* vec=Character::getColumns(rand()%(columns-0+1)+1);
                for(int i=0; i<rows; i++){
                    somma+=vec[i];
                }
                return dado+=somma;
            }else{
                return dado/(double)2;
            }
        }
};

int main(){

}