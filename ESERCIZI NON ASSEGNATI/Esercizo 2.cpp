#include<iostream>
using namespace std;
main(){
int a,b,c,max,min,med;
cout<<"ins.num:";cin>>a;//input
cout<<"ins.num:";cin>>b;
cout<<"ins.num:";cin>>c;
//algoritmo
if(a>b){max=a;min=b;}
else {max=b;min=a;}

if(c>max){med=max;max=c;}
else if(c<min){med=min;min=c;}
else {med=c;}
//output
cout<<max<<" "<<med<<" "<<min<<"\n";

}//fine main