#include <iostream>

using namespace std;
int main(){
	int x;
cin >> x;

switch(x) {
    case 12:
        cout << "twelve";
        break;
    case x%5==0:
        cout << "multiple of 5";
        break;
    default:
        cout << x;
}
//Riscrivere il codice sopra con  `if` e `else if`.

/*int x;
cin>>x;

if(x==12){
	cout<<"twelve";
}else if(x%5==0){
	cout<<"multiple of 5";
}else{
	cout<<x;
}*/


}