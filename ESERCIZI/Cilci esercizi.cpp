#include <iostream>

using namespace std;
int main(){
	/*int x = 11;

while(x>0) {
    if (x%2!=0) {
        x--;
    }
    x/=2;
}

cout << x;*/

/*int x;
int sum = 0;

do {
    cin >> x;
    sum+=x;
} while (sum<100);*/

/*int x;
int sum=0;

cin>>x;
sum+=x;
while(sum<100){
	cin>>x;
	sum+=x;
}*/

/*int x;
int y;

cout << "Inserisci due numeri interi: ";
cin >> x;
cin >> y;

int res = 1;

for (int i =0; i<y; i++) {
    res*=x;
}

cout << "Il risultato e' " << res;*/



/*int x;
int y;

cout << "Inserisci due numeri interi: ";
cin >> x;
cin >> y;

int res = 1;
int i=0;

while(i<y){
	i++;
	res*=x;
}

cout << "Il risultato e' " << res;*/


/*string s = "Hello World";

for (int i=s.length(); i>0; i--) {
    cout << s[i];
}*/

/*tring s = "Hello World";

for (int i=s.length(); i>0; i--) {
    for (int j=0; j<s.length(); j++) {
        cout << "("<<s[i]<<","<<s[j]<<")";
    }
}   */

string s1 = "Hello Sunshine";
string s2 = "Goodbye Sunset";

for (char c1: s1) {
    for (char c2: s2) {
        if (c1==c2) {
            cout << c1;
        }
    }
}   



    


}