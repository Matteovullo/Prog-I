/*Si definisca un namespace double_point che 
includa le classi Point2D e Point3D che implementano
 punti negli spazi 2D e 3D con coordinate double.
  Si definisca un namespace int_point che includa 
  le classi Point2D e Point3D che implementano 
  punti negli spazi 2D e 3D con coordinate intere. 
  Si scriva un programma che usi questi quattro 
  oggetti.*/

#include <iostream>
using namespace std;

namespace double_point{
    class Point2D{
        private:
            double p1,p2;

        public:
            Point2D(double p1, double p2){
                this->p1=p1;
                this->p2=p2;
            }
            void stampa(){
                cout << "(" << p1 << ", " << p2 << ")" << endl;
            }
    };
    class Point3D{
        private:
            double p1, p2, p3;

        public:
            Point3D(double p1, double p2, double p3){
                this->p1=p1;
                this->p2=p2;
                this->p3=p3;
            }
            void stampa(){
                cout << "(" << p1 << ", " << p2 << ", " << p3 << ")" << endl;
            }
    };
}

namespace int_point{
    class Point2D{
        private:
            int p1,p2;

        public:
            Point2D(int p1, int p2){
                this->p1=p1;
                this->p2=p2;
            }
            void stampa(){
                cout << "(" << p1 << ", " << p2 << ")" << endl;
            }
    };
    class Point3D{
        private:
            int p1, p2, p3;

        public:
            Point3D(int p1, int p2, int p3){
                this->p1=p1;
                this->p2=p2;
                this->p3=p3;
            }
            void stampa(){
                cout << "(" << p1 << ", " << p2 << ", " << p3 << ")" << endl;
            }
    };
}

using namespace double_point;
using namespace int_point;

int main(){
    double_point::Point2D p1(2.5, 3.5);
    int_point::Point2D p2(2, 3);
    double_point::Point3D p3(2.5, 3.5, 4.5);
    int_point::Point3D p4(1, 2, 3);
    p1.stampa();
    p2.stampa();
    p3.stampa();
    p4.stampa();
}