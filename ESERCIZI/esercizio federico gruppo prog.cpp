/*

*/

#include<iostream>
#include<string>
#define N 2
#define M 3
using namespace std;

bool func(string** A, string s){
	int counter=0; 
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(A[i][j].find(s)){
			counter++;
			cout<<counter<<endl;
		    }
	    }   
	}	
		return true;
}

int main(){
	string c="pippo";
	string **b=new string *[N];
	
	for(int i=0; i<N; i++){
		b[i]=new string [N];
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout<<"inserire una stringa: "<<endl;
			cin>>b[i][j];
		}
	}
	
	cout<<func(b,c);
	
	/*string B[N][M]={"federico", "alessandro","rapo","ninuzzo","innominabile"};
    string a="ico";
    func(B,a);*/
}
