#include <iostream>
using namespace std;

int max(int a,int b){
	if(a>b){
		int max=a;
		return max;
	}else{
		int max=b;
		return max;
	}

int min(int a,int b){
	if(a>b){
		int mim=a;
		return min;
	}else{
		int mim=b;
		return mim;
	}
}

int main() {
	cout << max(5,6)<<endl;
	cout << min(5,6)<<endl;
}