#include <iostream>

using namespace std;

/*void fun(int x) {
    int *ptr = &x;
    int y = 5;
    *ptr = y;
}

int main(){
int val=10;
fun(val);
cout << val;
}*/

/*void transform(int &x, int &y) {
    x = y*y;
    y = 5;
}

int main(){
int arr[2] = {1,2};
int *pp1 = arr;
int *pp2 = &arr[1];

transform(*pp1,*pp2);
cout<<transform;
}*/

void transform_array1(int *a) {
    *a = -1;
}

void transform_array2(int *a) {
    a[0]=a[1];
    a[1]=-1;
}

int main(){
	int arr[2] = {1,2};
	transform_array1(arr);
	cout<<arr[0];
	
}