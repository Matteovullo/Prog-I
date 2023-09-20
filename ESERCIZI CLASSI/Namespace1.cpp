/*
Si definisca un namespace double_point che includa le classi Point2D e Point3D 
che implementano punti negli spazi 2D e 3D con coordinate double. 
Si definisca un namespace int_point che includa le classi Point2D e Point3D 
che implementano punti negli spazi 2D e 3D con coordinate intere. 
Si scriva un programma che usi questi quattro oggetti.
*/

#include <iostream>
using namespace std;

namespace Double_point{
	class Point2D{
		double x;
		double y;
		public:
			Point2D(double x, double y){
				this->x=x;
				this->y=y;
			}
	};
	class Point3D{
		double x;
		double y;
		double z;
		public:
			Point3D(double x, double y, double z){
				this->x=x;
				this->y=y;
				this->z=z;
			}
	};
}

namespace Int_point{
	class Point2D{
		int x;
		int y;
		public:
			Point2D(int x, int y){
				this->x=x;
				this->y=y;
			}
	};
	class Point3D{
		int x;
		int y;
		int z;
		public:
			Point3D(int x, int y, int z){
				this->x=x;
				this->y=y;
				this->z=z;
			}
	};
}

using namespace Double_point;
using namespace Int_point;

int main(){
	Double_point::Point2D p1(2.5,2.6);
	Int_point::Point2D p2(1,2);
}
