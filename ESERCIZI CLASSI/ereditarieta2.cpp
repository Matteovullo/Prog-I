/*Dichiarare la classe astratta Figura con le funzioni virtuali area e perimetro che 
abbia come classi derivate le figure geometriche cerchio, quadrato e rettangolo.*/

class Figura{
    public:
        virtual area()
        virtual perimetro()
};

class Cerchio: public Figura{
    const double p=3.14;
    double raggio;
    public:
        Cerchio(double raggio){
            this->raggio=raggio;
        }
        double areac(){
            area=p*r*r;
            return area;
        }
        double perimetroc(){
            perimetro=p*r*2;
            return perimetro
        }
};

class Quadrato: public Figura{
    int n;
    public:
        Cerchio(double lato, int n){
            this->lato=lato;
            this->n=n
        }
        double areac(){
            area=l*l;
            return area;
        }
        double perimetroc(){
            perimetro=l*n;
            return perimetro
        }
};

class Rettangolo: public Figura{
    double base;
    double altezza;
    public:
        Rettangolo(double base, double altezza){
            this->base=base;
            this->altezza=altezza;
        }
        double areac(){
            area=base*altezza;
            return area;
        }
        double perimetroc(){
            perimetro=2*(base*altezza);
            return perimetro
        }
};