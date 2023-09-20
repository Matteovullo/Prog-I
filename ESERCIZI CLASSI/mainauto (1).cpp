#include "automobile.h"
#include<iostream>
#include<string>
using namespace std;
int main(){
    persona p1("gabriele","riggi");
    persona p2("matteo","vullo");
    automobile auto1("ferrarigt",&p1);
    automobile auto2("lambo",&p1);
    automobile auto3("panda",&p2);
    auto1.getDati();
    auto2.getDati();
    auto3.getDati();

}