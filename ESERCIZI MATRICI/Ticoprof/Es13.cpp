/*Verificare se in una matrice 5×5 ogni cella è uguale alla somma delle celle che la precedono sulla stessa riga.*/


int main(){
    int a[5][5];
    a[0][0]=1;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int somma=0;
            if(j>1){
            for(int o=0; o<=j; o++){
                somma+=a[i][o];
                }
            }
            a[i][j]=somma;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0; i<5; i++){
        int somma=a[i][0];
        int c=0;
        for(int j=0; j<5; j++){
            if(a[i][j] == somma)
                c++;
            somma+=a[i][j];
        }
        if(c == 5) 
            cout << "Ogni cella della riga " << i << " è uguale alla somma delle celle che la precedono sulla stessa riga" << endl;
        else
            cout << "Ogni cella della riga " << i << " non è uguale alla somma delle celle che la precedono sulla stessa riga" << endl;
    }
}
