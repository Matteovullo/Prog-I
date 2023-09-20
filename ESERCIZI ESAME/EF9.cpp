/*Due stringhe si dicono simili se esse coincidono in almeno p posizioni, dove p è la metà 
(troncata) della lunghezza della stringa più corta. (Es.: Le stringhe “abcdefabcdef ” e 
“zbcaafacz” sono simili perché coincidono agli indici 1,2,5,6 ed è p=4). Scrivere un metodo 
che prenda in input una matrice A di puntatori a stringhe, e restituisca un boolean che indichi 
se esiste una colonna di A in cui sono presenti almeno due stringhe simili.
N.B.: Attenzione alle eventuali stringhe mancanti in A (con puntatore a null).*/

#include <iostream>
using namespace std;
#define n 3
#define m 3

bool fun(string ***a){
    int count, count_simile;
    string str2;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]){
            string str1=*a[i][j];
            int len=(*a[i][j]).length();
            for(int k=j+1; k<m; k++){
                count=0;
                for(int c=0; c<str1.length(); c++){
                    char l=str1[c];
                    str2=*a[i][k];
                    for(int y=0; y<str2.length(); l++){
                        char g=str2[y];
                        if(l==g && c==y){
                            count++;
                        }
                    }
                }
                if(str1.length() < str2.length()){
                    int len=str1.length() / 2;
                }else{
                    int len=str2.length() / 2;
                }
                if(count == len && count < str1.length()  && count < str2.length()){
                    count_simile++;
                }
            }
        }
        }
        if (count_simile >= 2) return true;
    }
    return false;

}

int main(){
    string ***s=new string **[n];

    for(int i=0; i<n; i++){
        s[i]=new string *[n];
        for(int j=0; j<m; j++){
        	s[i][j]=new string("ciao");
		}
    }
    
    /*s[0][0]= new string ("abcdefabcdef");
    s[0][1]= new string ("abbbbbbbb");
    s[1][0]= new string ("zbcaafacz");
    s[1][1]= new string ("fdtyjdtyj");*/

    cout<<fun(s);
    
}