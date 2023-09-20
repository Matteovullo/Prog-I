#include <iostream>

using namespace std;
int main(){
	/*int var = 18;
int* const p = &var;
(*p)==var;

int x[] = {1,3,5,7};
int *y = &x[1];
cout << *y;

int arr[5] = {1,2,3,4,5};
int *ptr = arr;

cout << ptr<<endl;

cout << ptr+8<<endl;

cout << *(ptr+2)<<endl;

cout << ptr[2]<<endl;

cout << *(ptr++)<<endl;

cout << *(++ptr)<<endl;

char str[] = "hello";

cout << str[2]<<endl;

cout << *str<<endl;

cout << *(str+3)<<endl;

cout << (char)(*str+1)<<endl;*/

int arr[] {1,2,3,4,5};
int *ptr = &arr[2];
*ptr = -1;

for(int i=-2; i<3; i++) {
    cout << *(ptr+i) << endl;
}


}