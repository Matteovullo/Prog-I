/*Letta una stringa di caratteri verificare se à costituita da sequenze alternate di lunghezza pari di “a” e di
“b”. Ad esempio la stringa “aaaabbaaaaaabbbbaa” rispetta la regola descritta nel testo dell’esercizio;
viceversa le stringhe “aabaabbb” e “aaaabbccaabbbb” non la rispettano.*/

#include <iostream>

using namespace std;

bool fun(string s){
    bool found = false;
    int a=0; 
    int b=0;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='a'){
            a++;
            if(a%2 == 0)
                found = true;
            else{
                found = false;
                break;
            }
        }else{
            a=0;
        }
        if(s[i]=='b'){
            b++;
            if(b%2 == 0)
                found = true;
            else{
                found = false;
                break;
            }
        }else{
            b=0;
        }
    }

    return found;
}

int main(){
    string s="aab";
    cout << fun(s);
}