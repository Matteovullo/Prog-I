#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

#define DIM 25

using namespace std;

class AbstractRandomMat{
    protected:
        int** mat;
        int rows;
        int cols;

    public:
        AbstractRandomMat(int n, int m ,int min, int max){
            rows=n;
            cols=m;
            mat=new int*[n];
            for(int i=0; i<rows; i++){
                mat[i]=new int[m];
                for(int j=0; j<cols; j++){
                    mat[i][j]=rand()%(max-min+1)+min;
                }
            }
        }
        virtual int count()=0;
        int* get(int i, int j){
            int* ptr;
            if(i <= rows-1 && j <=cols-1){
                *ptr=mat[i][j];
                return ptr;
            }else{
                return nullptr;
            }
        }
        int numel(){
            int count = 0;
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    if(mat[i][j])
                        count++;
                }
            }
            return count;
        }
        float mean(){
            int media=0;
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                	if(mat[i][j])
                    	media+=mat[i][j];
                }
            }
            return media/(float)numel();
        }
        virtual ostream &put(ostream &os){
            os << typeid(*this).name() << ", rows=" << rows << ", cols=" << cols << ", mat=[";
            for(int i=0; i<rows; i++){
                os << "[";
                for(int j=0; j<cols; j++){
                    os << mat[i][j] << " ";
                }
                os << "][";
            }
            os << "]";
            return os;
        }
};

ostream &operator<<(ostream &os, AbstractRandomMat &obj){
    return obj.put(os);
}

class BinaryMat : public AbstractRandomMat{
    public:
        BinaryMat(int n, int m) : AbstractRandomMat(n, m, 0, 1){}
        int count(){
            return numel();
        }
        ostream &put(ostream &os){
            AbstractRandomMat::put(os);
        return os;
        }
};

class EvenMat : public AbstractRandomMat{
    private:
        double midpoint;

    public:
        EvenMat(int n, int m, int min, int max) : AbstractRandomMat(n, m, min, max){
            midpoint=(double)(min+max)/2;
        }
        int count(){
            int count = 0;
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    if(mat[i][j]){
                        if(mat[i][j] > midpoint)
                            count++;
                    }
                }
            }
            return count;
        }
        int countMul(int num){
            int c=0;
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    if(mat[i][j]%num == 0){
                        c++;
                    }
                }
            }
            return c;
        }
        ostream &put(ostream &os){
            AbstractRandomMat::put(os);
            os << ", midpoint=" << midpoint;
        return os;
        }
};

int main(){
    srand(424242);
    AbstractRandomMat* vett[DIM];

    for (int i = 0; i < DIM; i++){
        int n = 5 + rand() % 5;
        int m = 5 + rand() % 5;
        int min = rand() % 10 + 5;
        int max = min + rand() % 20;

        switch (rand() % 2)
        {
        case 0:
            vett[i] = new BinaryMat(n, m);
            break;
        case 1:
            vett[i] = new EvenMat(n, m, min, max);
        }
    }

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vett[i]<< endl;
    }

    int max=INT_MIN;
    int c=0;
    int media=0;
    for(int i=0; i<DIM; i++){
        if(vett[i]->count() > max){
            max = vett[i]->count();
        }
        if(typeid(*vett[i]) == typeid(EvenMat)){
            media+=dynamic_cast<EvenMat*>(vett[i])->countMul(4);
            c++;
        } 
    }


    cout << "max count(): " << max << endl;
    cout << "mean countMul(): " << media/(double)(c) << endl;

    return 0;
}