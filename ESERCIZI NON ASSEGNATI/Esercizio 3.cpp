#include <iostream>
using namespace std;
int main(){
	int x,y;
	cout << "ins. x:"; cin>>x;
	cout << "ins. y:"; cin>>y;
	if ((x%2==0)||(y%2==0)) cout<<x+y;
	else if ((x%2==0)&&(y%2==0)) cout<<x*y;
	else cout << (float)x/y;
}