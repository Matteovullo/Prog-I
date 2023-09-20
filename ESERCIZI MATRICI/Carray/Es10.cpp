/*Assegnata una matrice A di interi e di riempimenti RIEMP1 e RIEMP2 si generino
da essa due vettori VMAX e VMIN contenenti rispettivamente i valori massimi di
ogni riga e i minimi di ogni colonna*/

int* fun(int **a, int n, int m,int **riempi1, int **riempi2){
    int *vmax=new int[n];
    int *vmin=new int[m];

    for(int i=0; i<n; i++){
        int max=a[i][0];
        for(int j=0; j<m; j++){
            if(a[i][j] > max){
                max=a[i][j];
            }
        }
        vmax[i]=max;
    }

    for(int j=0; j<m; j++){
        int min=a[j][0];
        for(int i=0; i<n; i++){
            if(a[i][j] < min){
                min=a[i][j];
            }
        }
        vmin[j]=min;
    }

    return vmax,vmin;
}
