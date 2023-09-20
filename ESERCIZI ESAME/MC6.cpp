/*6.Scrivere un metodo che prenda come parametro
formale un cubo (array tridimensionale) C di stringhe,
e restituisca in output una stringa contenente tutte le
desinenze di due caratteri delle stringhe sulla faccia
superiore del cubo C.*/
#include<string>

#define DIM 2

//"abcd" -> "cd" -> substr(2,2); 4-2
//"abcdefg" -> "fg" -> substr(5,2); 7-2
//"ef" -> "ef" -> substr(0,2); 2-2
//"e" -> ?
//""-> ?

string es6(string C[DIM][DIM][DIM]) {

    //matrice M
    //for(int j=0; j<DIM; j++) {
    //    M[0][j]; //tutti gli elementi della prima riga
    //}

    string out;

    for(int i=0; i<DIM; i++) {
        for(int j=0; j<DIM; j++) {
            string s = C[0][i][j];
            if(s.length()>=2) {
                out += s.substr(s.length()-2, 2);
            }
        }
    }

    return out;
}