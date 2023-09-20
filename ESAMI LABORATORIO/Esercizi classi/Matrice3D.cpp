/*Implementare una classe Matrice3D. In particolare:
• il costruttore deve permettere allo usercode di specificare
le tre dimensioni della matrice, ed un ulteriore valore con
cui inizializzare tutti gli elementi della matrice; 
specificare
argomenti standard sia per le dimensioni, che per il valore
di inizializzazione;
• i metodi getDimX(), getDimY(), getDimZ();
• un metodo stampa(), che stampi tutti gli elementi della
matrice;
Prof. Giovanni Maria Farinella DMI UNICT [PDF generato il 
13 dicembre 2021 alle ore 10:16] 27
Homework H24.1
• un metodo sommaByPtr che prenda in input due
parametri formali di tipo puntatore a Matrice3D e
restituisca la somma delle due matrici come puntatore al
tipo Matrice3D;
• un metodo sommaByReference che prenda in input due
parametri formali reference al tipo Matrice3D e
restituisca la somma delle due matrici come reference al
tipo Matrice3D;
• un metodo getElement(int x, int y, int z) che
restituisca un reference all’elemento di indici x, y, e z.
• un metodo getValue(int x, int y, int z) che
restituisca il valore dello elemento di indici x, y, e z.
*/

/*Con riferimento alla classe Matrice3D (homework 24.1),
implementare le seguenti ulteriori funzionalit`a:
• Costruttore di copia;
• Overloading operatore di assegnamento “=”, per gestire
correttamente la copia degli elementi della matrice
sorgente (operando destro) nella matrice destinazione
(operando sinistro);
• Overloading operatore di uguaglianza “==”, che
restituisca true solo se le due matrici hanno identiche
dimensioni e identici valori;
Prof. Giovanni Maria Farinella DMI UNICT [PDF generato il 10 gennaio 2022 alle ore 08:48] 59
Homework H28.1
• Overloading operatore di disuguaglianza “!=”, duale
rispetto all’operatore “==”;
• Overloading operatore “()”, che permetta di indicizzare i
singoli valori della matrice mediante tre indici; inoltre, tipo
di ritorno deve essere reference all’elemento estratto, in
modo che valore di ritorno si possa usare nella parte
sinistra di una espressione di assegnamento;
• Overloading operatore “+”, che permetta di sommare due
matrici con la stessa dimensione;
• Overloading operatore “∗”, che permetta di eseguire il
prodotto “riga per colonna” di due matrici;
Prof. Giovanni Maria Farinella DMI UNICT [PDF generato il 10 gennaio 2022 alle ore 08:48] 60
Homework H28.1
• Overloading operatore “<<”, che permetta di “stampare”
gli elementi della matrice (suo operando destro) su uno
stream di output (suo operando sinistro);
Note.
• Usare il passaggio per riferimento dei parametri formali,
quando possibile e/o opportuno;
• Usare il modificatore const per i parametri formali,
quando opportuno (quando gli operandi non andrebbero
modificati dalla funzione di overloading);
Prof. Giovanni Maria Farinella DMI UNICT [PDF generato il 10 gennaio 2022 alle ore 08:48] 61
Homework H28.1
• Implementare ogni eventuale metodo che si renda
necessario per la corretta realizzazione delle funzionalit`a
e/o per garantire la necessaria modularit`a (ES: metodo
relativo alla gestione della memoria dinamica che possa
essere invocato sia da costruttore che da costruttore di
copia);*/

#include <iostream>
using namespace std;

template<class T>
class Matrice3D{
    private:
        int x, y, z;
        T val;
        T ***matrice;

    public:
        Matrice3D(T n, int x=3, int y=3, int z=3){
            this->x=x;
            this->y=y;
            this->z=z;
            matrice=new T**[x];
            for(int i=0; i<x; i++){
                matrice[i]=new T*[y];
                for(int j=0; j<y; j++){
                    matrice[i][j]=new T[z];
                    for(int h=0; h<z; h++){
                        matrice[i][j][h]=n;
                    }
                }
            }
            val=n;
        }
        /*Matrice3D(Matrice3D<T>& m) : x(m.x), y(m.y), z(m.z){
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    for(int h=0; h<z; h++){
                        change(i, j, h, m.getValue(i, j, h));                  
                    }
                }
            }
        }*/
        /*Matrice3D(const Matrice3D& other){
		    this->memoryManagement(other);
	    }

	    void memoryManagement(Matrice3D& source){

		this->x = source.x;
		this->y = source.y;
		this->z = source.z;
		this->val = source.val;

		this->mat = new T**[source.x];
		for(int i=0; i<x; i++){
			this->mat[i] = new T*[source.y];
			for(int j=0; j<y; j++)
			{
				this->mat[i][j] = new T[source.z];
				for(int k=0; k<z; k++)
					this->mat[i][j][k] = source.mat[i][j][k];
			}
		    }
	    }*/
        ~Matrice3D(){
        for (int i = 0; i < this->x; i++) {
			for (int j = 0; j < this->y; j++) {
				delete[] matrice[i][j];
			}
				delete[] matrice[i];
			}
			delete[] matrice;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        int getZ(){
            return z;
        }
        void stampa(){
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    for(int h=0; h<z; h++){
                        cout << matrice[i][j][h] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;
        }
        /*T& getElement(int a, int b, int c){
            if(a < x-1 && b < y-1 && c < z-1){ 
            T* ptr;
            *ptr=matrice[a][b][c];
            return *ptr;
            }else{
                return *(new int(-1));
            }
        }*/
        T& getElement(int i, int j, int k) {
				return matrice[i][j][k];
		}
        T getValue(int a, int b, int c){
            return matrice[a][b][c]; 
        }
        void change(int a, int b, int c, T d){
            matrice[a][b][c]=d;
        }
        Matrice3D* sommaByptr(Matrice3D *m1, Matrice3D *m2, T n){
            if(m1->getX() == m2->getX() &&
            m1->getY() == m2->getY() &&
            m1->getZ() == m2->getZ()){
                Matrice3D<T>* m3 = new Matrice3D(n, m1->getX(), m2->getY(), m1->getZ());
                for(int i=0; i<m1->getX(); i++){
                    for(int j=0; j<m1->getY(); j++){
                        for(int h=0; h<m1->getZ(); h++){
                            m3->change(i, j, h, m1->getElement(i, j, h)+m2->getElement(i, j, h));
                        }
                    }
                }
                return m3;
            }else{
                return nullptr;
            }
        }
        Matrice3D& sommaByreference(Matrice3D &m1, Matrice3D &m2, T n){
            if(m1.getX() == m2.getX() &&
            m1.getY() == m2.getY() &&
            m1.getZ() == m2.getZ()){
                Matrice3D<T>* m3 = new Matrice3D<T>(n, m1.getX(), m2.getY(), m1.getZ());
                for(int i=0; i<m1.getX(); i++){
                    for(int j=0; j<m1.getY(); j++){
                        for(int h=0; h<m1.getZ(); h++){
                            m3->change(i, j, h, m1.getValue(i, j, h)+m2.getValue(i, j, h));
                        }
                    }
                }
                return *m3;
            }else{
                return m1;
            }
        }
        bool operator==(Matrice3D<T>& m){
            if(m.getX() == x && m.getY() == y && m.getZ() == z){
                for(int i=0; i<x; i++){
                    for(int j=0; j<y; j++){
                        for(int h=0; h<z; h++){
                        if(m.getValue(i, j, z) != matrice[i][j][h]){
                            return false;
                        }
                    }
                }
            }
            }else{
                return false;
            }
            return true;
        }
        bool operator!=(Matrice3D<T>& m){
            if(m.getX() != getX() && m.getY() != getY() && m.getZ() != getZ()){
                for(int i=0; i<x; i++){
                    for(int j=0; j<y; j++){
                    for(int h=0; h<z; h++){
                        if(m.getValue(i, j, z) == getValue(i, j, z)){
                            return false;
                        }
                    }
                }
            }
            }else{
                return false;
            }
            return true;
        }
        /*Matrice3D<T> &operator=(Matrice3D<T>& p) {
            x=p.x;
            y=p.y;
            z=p.z;
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    for(int h=0; h<z; h++){
                        matrice[i][j][h] = p.getValue(i, j, h);                  
                    }
                }
            }
            return *this;
        }*/
        /*Matrice3D<T>& operator= (Matrice3D<T>& source){
		    this->memoryManagement(source);
	    }*/
        T& operator()(int i1, int i2, int i3){
			return matrice[i1][i2][i3];
		}
        ostream& put(ostream& os){
        for(int i=0; i<getX(); i++){
            for(int j=0; j<getY(); j++){
                for(int h=0; h<getZ(); h++){
                    os << getElement(i, j, h) << " ";
                }
                os << endl;
            }
            os << endl;
        }
        os << endl;
        return os;            
        }
};

template<class T>
ostream &operator<<(ostream& os, Matrice3D<T>& obj){;
    return obj.put(os);
}

template<class T>
Matrice3D<T> operator+(Matrice3D<T> m1, Matrice3D<T> m2){
    Matrice3D<T> m3(m1.getValue(0, 0, 0), m1.getX(), m2.getY(), m3.getZ);
        for(int i=0; i<m1.getX(); i++){
            for(int j=0; j<m1.getY(); j++){
                for(int h=0; h<m1.getZ(); h++){
                    m3.change(i, j, h, m1.getValue(i, j, h)+m2.getValue(i, j, h));
                }
            }
        }
    return m3;
}

template<class T>
Matrice3D<T> operator*(Matrice3D<T> m1, Matrice3D<T> m2){
    Matrice3D<T> m3(0, m1.getX(), m2.getY(), m1.getZ());
    int k=0;
    for(int h=0; h<m3.getZ(); h++){
        for(int i=0; i<m1.getX(); i++){
            T somma=0;
            for(int j=0; j<m2.getY(); j++){
                somma+=m1.getElement(i, j, h) * m2.getElement(j, i, h);
            }
            m3.change(i, k, h, somma);
            k++;
        }
    }
    return m3;
}


int main(){
    Matrice3D<int> *p1 = new Matrice3D<int>(5, 5, 3, 4);
	Matrice3D<int> *p2 = new Matrice3D<int>(5, 5, 3, 4);
    Matrice3D<int> m(2, 2, 2, 2);
	p1->stampa();
	cout << "Dimensione x della Matrice3D: " << (*p1).getX() << endl;
	cout << "Dimensione y della Matrice3D: " << (*p1).getY() << endl;
	cout << "Dimensione z della Matrice3D: " << (*p1).getZ() << endl;
	//Somma passando alla funzione i puntatori
	p1 = p1->sommaByptr(p1, p2, 0);
	//Somma passando alla funzioni le reference
	*p2 = p1->sommaByreference(*p1, *p2, 0);
	cout << endl << "Somma della matrice p1 + p2 e salvata su p1" << endl; 
	p1->stampa();
	p2->getElement(0, 0, 0) = 0;
	cout << endl << "Somma della matrice p1 + p2 e salvata su p2" << endl; 
	p2->stampa();
    //Matrice3D<int> p3(*p1);
    Matrice3D<int> *p4 = new Matrice3D<int>(2, 2, 2, 2);
    delete p4;
    cout << p1->getValue(0, 0, 0) << endl;
    cout << m.operator==(*p1) << endl;
    cout << m.operator!=(*p1) << endl;
    //Matrice3D<int> p5=m;
    cout << *p1 << endl;
    //*p1+*p2;
    cout << (*p1)(0, 0, 0) << endl;
	return 0;
}