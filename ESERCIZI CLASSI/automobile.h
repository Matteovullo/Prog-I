
#include<iostream>
#include<string>
#include "definizionepersona.h"

using namespace std;
class automobile{
    public:
    string modello;
    persona *proprietario;

    automobile(string modello,persona *proprietario);
    void getDati();
};
