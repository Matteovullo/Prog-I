#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <climits>
#include <typeinfo>

using namespace std;

class A{
    private:
        string w;

    public:
        A(string s){
            w=s;
        }
        int getSum(){
            int l=0;
            char arr[w.length()];
            for(int i=0; i<w.length(); i++){
                arr[i]=w[i];
            }
            for(int j=0; j<w.length(); j++){
                for(int h=j+1; h<w.length(); h++){
                    if(arr[j]==arr[h]){
                        l+=(int)(arr[j]);
                        break;
                    }
                }
            }
            return l+1;
        }

        virtual int *values()=0;

        
        virtual ostream &put(ostream &os) const{
            return os << "Class " << typeid(*this).name() << ": w=" << w;
        }
};

    ostream &operator << (ostream &left, const A &obj){
      return obj.put(left);
    }

class B : public A{
    private:
        string s;
        int l;

    public:
        B(string s1, string s2, short n) : A(s){}
        int *values(){
            int *arr=new int [this->l];
            for(int i=0; i<this->l; i++){
                arr[i]=((int)(s[i]) % 10);
            }
            return arr;
        }
        float res(){
            int *v=values();
            int somma=0;
            for(int i=0; i<this->l; i++){
                somma+=v[i];
            }
            return (float)somma/getSum();
        }
        ostream &put(ostream &os) const{
            return A::put(os) << "{ s=" << s << ", l=" << l << "}"; 
        }
};

class C: public A{
    private:
        string t;
        int n;

    public:
        C(string s) : A(s){
        t="";
        for(unsigned int i=0; i<s.length(); i++){
	    if(tolower(s[i])==s[i])
	    t+=toupper(s[i]);
	    else
	        t+=tolower(s[i]);
        this->n = (this->t).length();     
        }
        }
        int *values(){
            int *arr=new int [t.length()];
            for(int i=0; i<t.length(); i++){
                if(isdigit(t[i])) arr[i]=0;
                else arr[i]=1;
            }
            return arr;
        }
        short zeros(){
            int *vet=values();
            short c=0;
            for(int i=0; i<t.length(); i++){
                if(vet[i]=0) c++;
            }
            return c;
        }
        ostream &put(ostream &os) const{
        return A::put(os) << "{ t=" << t << ", n=" << n << "}";
        }         
};

int main(){
    const int DIM = 30;
    srand(111222333);
    A *vett[DIM];
    
    for(int i=0; i<DIM; i++){
        string str1 = ""; string str2 = "";
        if(rand()%2==0){
            short l1 = rand()%5+3; short l2 = rand()%5+6;
        for(int j=0; j<l1; j++)
	    str1+=((char) ('a' + rand()%25));
        for(int j=0; j<l2; j++)
	    str2+=((char) ('a' + rand()%25));
        short n = rand()%3+1;
        //cout << "i=" << i << ", Str1: " << str1 << ", Str2: " << str2 <<  ", n=" << n <<", new B()"<< endl << flush;
        vett[i] = new B(str1, str2, n);
    }
    else{      
      for(int j=0; j<10; j++){
	  int r = rand(); 
	  if(r%2==0)
	      str1+=((char) ('0' + rand()%9));
	  else if(r%3==0)
	      str1+=((char) ('a' + rand()%25));
	  else
	      str1+=((char) ('A' + rand()%25));
      }
      vett[i] = new C(str1);
    }
  }

}