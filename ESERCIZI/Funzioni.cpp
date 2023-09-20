#include<iostream>
#include <cmath>
using namespace std;

int add1(int x) {
    return x+1;
}

float prodotto(float a,float b){
	return a*b;
}

double mypow(double a,double b){
	if(b==1){
		return pow(a,2);
	}else{
		return pow(a,b);
	}
}

int main() {
    int x = 0;
    for (int i=0; i<10; i++) {
        x = add1(x);
    }
    
    cout << add1(x)<<endl;
    
    float c=prodotto(2.3,5.6);
    cout<<c<<endl;
    
    cout<< pow(2,3)<<endl;
    
    cout<< pow(2,2)<<endl;
    
}
