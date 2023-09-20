#include <iostream>
using namespace std;

class Collar{
    private:
        char color;

    public:
        Collar(char c){
            color=c;
        }
        char getColor(){
            return color;
        }
};

class RedCollar : public Collar{
    public:
        RedCollar() : Collar('r'){}
};

class BlueCollar : public Collar{
    public:
        BlueCollar() : Collar('b'){}
};

class Animal{
    private:
        int legs;
        int life_expectancy;
        double meters;
        Collar* collar;

    protected:
        double base_speed;
        int age;

    public:
        Animal(int legs, int life_expectancy, double base_speed){
            this->legs=legs;
            this->life_expectancy=life_expectancy;
            age=0;
            meters=0;
            int r=rand()%(1-0+1)+1;
            if(r==0){
                collar=new BlueCollar;
            }else{
                collar=new RedCollar;
            }
        }
        void happyBirthday(){
            age++;
        }
        int getAge(){
            return age;
        }
        int getMeters(){
            return meters;
        }
        void run(double time){
            double percorso=base_speed*time;
            if(age > life_expectancy/2){
                percorso-=(percorso*100)/20.0;
            }
            if(legs >= 4){
                percorso+=(percorso*100.00)/10.0;
            }
            if(typeid(*collar) == typeid(BlueCollar)){
                percorso-=(percorso*100.0)/5.0;
            }else{
                percorso-=(percorso*100.0)/5.0;
            }
        }
        virtual void special()=0;
        virtual ostream& put(ostream& os){
            os << "Class=" << typeid(*this).name() << " legs=" << legs << ", life_expextancy=" << life_expectancy << ", base_speed=" << base_speed << ", meters=" << meters << ", type of collar=" << collar->getColor(); 
            return os;
        }
};

ostream& operator<<(ostream& os, Animal& obj){
    return obj.put(os);
}

class Zerusa : public Animal{
    public:
        Zerusa() : Animal(3, 15, 12){}
        void special(){
            age--;
        }
        ostream &put(ostream &os){
            Animal::put(os);
            return os;
        }
};

class Dakure : public Animal{
    public:
        Dakure() : Animal(5, 10, 15){}
        void special(){
            base_speed+=rand()%(3-(-3)+1)-3;
        }
        ostream &put(ostream &os){
            Animal::put(os);
            return os;
        }
};

int main(){

    srand(424242);

    const int DIM = 10;
    Animal* vec[DIM];
 
    for(int i=0; i<DIM; i++) {
        if(rand()%2){
            vec[i] = new Zerusa();
        } else {
            vec[i] = new Dakure();
        }
    }
 
    for(int i=0; i<DIM*5; i++) {
        int x = rand() % DIM;
        vec[x]->happyBirthday();
 
        double meters = double(rand())/RAND_MAX*10;
 
        vec[x]->run(meters);
        if(rand()%5==0)
            vec[x]->special();

    }

    //Punto 1:
    for(int i=0; i<DIM; i++){
        cout << i << *vec[i] << endl;
    }

    //Punto 2:
    int min = 0;
    for(int i=0; i<DIM; i++){
        if(vec[i]->getAge() < vec[min]->getAge())
            min = i;
    }
    cout << "\nAnimale piu' giovane: " << *vec[min] << endl;

    //Punto 3:
    int max = 0;
    for(int i=0; i<DIM; i++){
        if(vec[i]->getMeters() > vec[max]->getMeters())
            max = i;
    }
    cout << "\nAnimale piu' lontano: " << *vec[max] << endl;
}
