#include<iostream>
using namespace std;

int main(){
    /*{
        int *x = new int(5);
        {
            int y = 3;
            x = &y;
        }    
        cout << *x;
    }*/

    /*int* array[3];
    for(int i=0; i<3; i++){
        array[i]=new int[3];
        for(int j=0; j<3; j++){
            array[i][j]=i;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }*/

    /*int array[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            array[i][j]=i;
            cout << (*(array+i)+j) << endl;
            cout << *(*(array+i)+j) << endl;
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << (array[i]+j) << endl;
            cout << *(array[i]+j) << endl;
        }
    }*/

    /*int** a=new int*[3];
    for(int i=0; i<3; i++){
        a[i]=new int[3];
        for(int j=0; j<3; j++){
            a[i][j]=i;
            cout << ((a+i))[j] << endl;
        }
    }*/

    /*int* b[3];
    int y=0;
    for(int i=0; i<3; i++) {
        b[i]=&y;
        y++;
    }
    for(int i=0; i<3; i++){
        cout << *b[i] << endl;
    }
    cout << **b << endl;
    for(int i=0; i<3; i++){}


    cout << endl << endl << endl;
    int* ptr_dinamico=new int(5);
    cout << ptr_dinamico << endl;
    cout << *ptr_dinamico << endl;*/

    char a[]="ciao";
    char y[100]="ciao";
    char b[]={'c', 'i', 'a', 'o', 0};
    char c[]={'c', 'i', 'a', 'o', '\0'};
    const char* v="ciao";
    cout << a << endl;
    cout << b << endl;
    cout << y << endl;
    cout << c << endl;
    cout << v << endl;

    
}