/*Si costruisca una classe Rectangle che metta a disposizione metodi per calcolare perimetro e area.
 Si modifichi la classe Cicle (si veda l’esercizio precedente) inserendo un metodo encloses che prende 
in input un oggetto di classe Rectangle e restituisce true se il rettanglo è completamente contenuto all’interno del cerchio.*/

class Rettangolo{
	private:
		double altezza;
		double base;
	public:
		
		Rettangolo(double x, double y) : altezza(x), base(y){}
		void set_values(double x,double y){
			altezza=x;
			base=y;
		}
		double perimetro(){
			return (altezza*altezza)+(base*base);
		}
		double area(){
			return (altezza*base);
		}
};

