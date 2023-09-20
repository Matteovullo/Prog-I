/*Si definisca una classe Persona che abbia come variabili le stringhe nome e cognome. 
Si definisca una classe Automobile che abbia come variabili la stringa modello e un riferimento proprietario a un oggetto di tipo Persona. 
Definire metodi e costruttori in maniera opportuna. Costruire un programma che permetta di creare due persone e tre automobili.
 Dopo aver costruito le automobili, è possibile cambiarne i proprietari? Perché?*/

 #include<iostream>
 #include<string>
 using namespace std; 
 class persona{
     public:
     string nome,cognome;
     persona(string ,string);
 string getAnagrafica();
 };
 