#include <iostream>

using namespace std;

int main(){
	/*int x = 12;
double y = 52;

int *ptr1 = &x;
double *ptr2 = &y;
*/

/*int x = 18;
int *h = &x;
x++;

int y = *h;
y++;

cout << y << endl;
cout << x << endl;*/

double d = 3.14;
double *ptrd = &d;

double c;
double *ptrc = &c;

*ptrc = d;
c-=0.14;

cout << d << endl;
cout << c << endl;

*ptrd = *ptrc/2;

ptrd = ptrc;

*ptrd/=2;

cout << d;

}