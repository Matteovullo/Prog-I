#include<iostream>
#include<cmath>
using namespace std;

int main(){
	//Si crei un file chiamato `ciao_mondo.cpp` e si scriva al suo interno un programma che stampi a schermo la scritta "Ciao mondo!" 
	//indentando correttamente il codice. Si compili il sorgente in modo da creare un eseguibile `ciao_mondo.exe` 
	//(o semplicemente `ciao_mondo` su sistemi unix. Si esegua il programma e se ne verifichi il corretto funzionamento.
	cout << "Ciao mondo!"<< endl;
	
	//Si scriva un programma che stampi a schermo i primi 4 versi della divina commedia. 
	//Si scrivano, compilino ed eseguano due versioni del programma: 
	//una che utilizza l'istruzione `using namespace std;` e una che non la utilizza.
	cout <<"Nel mezzo del cammin di nostra vita" << endl;
	cout<<"mi ritrovai per una selva oscura,"<< endl;
	cout <<"ché la diritta via era smarrita." << endl;
	cout <<"Ahi quanto a dir qual era è cosa dura" << endl;
	
	std::cout <<"Nel mezzo del cammin di nostra vita" << std::endl;
	std::cout<<"mi ritrovai per una selva oscura,"<< std::endl;
	std::cout<<"ché la diritta via era smarrita." << std::endl;
	std::cout<<"Ahi quanto a dir qual era è cosa dura" << endl;
	
	//Si scriva, compili ed esegua un programma che stampi a schermo la scritta "Hello World!" 
	//(tutto su una riga) utilizzando esattamente **due** istruzioni del tipo `cout << ...`.
	cout<<"Hello ";
	cout<<"word!";
	
	//Si scriva un programma che verifichi i limiti numerici del tipo long double.???
	
	

    //Si dichiari una variabile con un tipo opportuno per contenere il numero 1234566712345667.
    long long int a;
    a=1234566712345667;
    cout<<a<<endl;
    
    //Si utilizzino le sequenze di escape per stampare il messaggio:
   //H
   //e
   //l
   //l
   //o

   //G
   //o
   //o
   //d
   //b
   //y
   //e
   
   cout<< "H\ne\nl\nl\no"<<endl;
   cout<<""<<endl;
   cout<<"g\no\no\nd\nb\ny\ne\n"<< endl;
   
   //Si utilizzino le sequenze di escape per stampare una tabella come segue:
	//x1    x2    x3    x4
   //12    15    21    38
   //11    16    911   12
   
   cout<<"x1\tx2\tx3\tx4\n"<<endl;
   cout<<"12\t15\t21\t38\n"<<endl;
   cout<<"11\t16\t911\t12\n"<<endl;
   
   //Si definisca una costante g e si ponga il suo valore pari a 9.8. Si usi un tipo opportuno e si motivi la scelta. 
   //Si stampi il valore di g. Si producano diverse versioni che definiscono la costante in diversi modi.??
   
    //const float g=9.8;
    cout<<g<<endl;
    const double g=9.8;
    
    //Si scriva un programma che:
   //Dichiara le variabili float a e b;
  //Assegna ad a il valore 10E30 e a b il valore -10E40;
  //Dichiara la variabile float c e le assegna il risultato dell’espressione a*b;
  //Stampa a schermo il valore di c. Qual è il valore di c? Perché? ????
  
  float e,b,c;
  e=10E30;
  b=-10E30;
  c=e*b;
  cout<< c<<endl;

  
  //Si scriva un programma che:
  //Definisce la variabile float r che rappresenta il raggio di un cerchio;
  //Assegna a r il valore 3.8;
  //Calcola e stampa a schermo l’area e la circonferenza del cerchio.
  
  float r,circonferenza,area;
  r=3.8;
  circonferenza=r*2*3.14;
  area=pow(2,r)*3.14;
  cout<<"circonferenza: "<<circonferenza<<endl<<"area: "<<area<<endl;
  
  //Si scriva un programma che:
  //Definisce la variabile float x e la pone uguale a 9.2;
  //Calcola e stampa schermo il seno e il coseno di x;
  //Assumendo che x sia il valore di un angolo in radianti, lo converta in gradi.
  
  float seno,coseno,x=9.2;
  x=9.8*(180/3.14);
  seno=sin(x);
  coseno=cos(x);
  cout<<"seno: "<<seno<<endl<<"coseno: "<<coseno<<endl;
  
	
}