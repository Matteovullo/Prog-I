#include "CoppiaDiDadi.h"

using namespace std;
CoppiaDiDadi::CoppiaDiDadi(){
	srand(time(0));
	Dado d1;
	Dado d2;
}

void CoppiaDiDadi::lancia1(){
	d1.lancia();
}

void CoppiaDiDadi::lancia2(){
	d2.lancia();
}

void CoppiaDiDadi::lancia2D(){
	d1.lancia();
	d2.lancia();
}

CoppiaDiDadi::CoppiaDiDadi(time_t seed){
	srand(seed);
	Dado d1;
	Dado d2;
	d1.lancia();
	d2.lancia();
}

short CoppiaDiDadi::getValore1(){
	return d1.getValore();
}

short CoppiaDiDadi::getValore2(){
	return d2.getValore();
}