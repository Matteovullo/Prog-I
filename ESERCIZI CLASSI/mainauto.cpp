#include "automobile.h"
#include<iostream>
#include<string>
using namespace std;
int main(){
    persona p1("gabriele","riggi");
    persona p2("matteo","vullo");
    automobile auto1("ferrarigt",&p1);
    automobile &ref_alias1=auto1;
    automobile auto2("lambo",&p1);
    automobile &ref_alias2=auto2;
    automobile auto3("panda",&p2);
    automobile &ref_alias3=auto3;
    ref_alias1.getDati();
    ref_alias2.getDati();
    ref_alias3.getDati();


}