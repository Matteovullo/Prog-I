/*
Scrivere un metodo che prenda come parametro formale una matrice S di dimensione n×m di stringhe ed una stringa X,
 e restituisca una stringa di ‘*’ la cui lunghezza è pari al numero di stringhe in S contenenti la sottostringa X. 
 N.B.: Non è possibile usare substr*/

#include <iostream>
using namespace std;
#define N 2

string fun(string **S, int n, int m, string X){
    string s="";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(S[i][j].find(X) != string::npos)
                s+='*';
        }
    }
    return s;
}

/*int main(){
    string **s=new string*[N];
    for(int i=0; i<N; i++){
        s[i]=new string[N];
        for(int j=0; j<N; j++){
            s[i][j]="ciao";
        }
    }
    cout << fun(s, 2, 2, "p") << endl;
}*/

/*#include<iostream>
#include<string>

using namespace std;

string es3(string** S, int n, int m, string X) {
	int count = 0;
	for(int i=0; i<n; i++) { //scorro le righe dell'array
		for(int j=0; j<m; j++) { //scorro le colonne dell'array
			//adesso devo controllare se X è sottostringa di S[i][j]
			//questa variabile verifica se almeno un match è stato trovato
			bool match = false;
			for (int q=0; q<S[i][j].length(); q++) {
				int h = q, k = 0;
				while (S[i][j][h]==X[k] && h<S[i][j].length() && k<X.length()) {
					h++; k++;
				}
				if (k==X.length()) {
					match=true;
				}
			}
			//se abbiamo trovato la sottostringa, incrementiamo il contatore
			if(match) count++;
		}
	}

	char out[count];
	for (int i=0; i<count; i++)
		out[i]='*';

	return string(out);
}*/

int main() {

	int n = 3, m=4;

	string **s = new string*[n];
	for(int i=0;i<n;i++)
		s[i]=new string[m];

	s[0][0] = "ttabr"; s[0][1]="atratt"; s[0][2]="bbaap"; s[0][3]="ataratat";
	s[1][0] = "att"; s[1][1]="tr"; s[1][2]="spqr"; s[1][3]="atatar";
	s[2][0] = "ttr"; s[2][1]="rrt"; s[2][2]="aprt"; s[2][3]="rtatr";
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;


	cout << fun(s,n,m,"tr");

	cout << endl;

}