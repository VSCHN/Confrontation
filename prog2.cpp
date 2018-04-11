#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
int R=0,Z=0,W=0,N=1,E=0,L=0;
float K=0.0, a=0.0;
int *mas;
int *prot;
int *mmas;

void Code1 () {
    for (int i=0;i<K;i++) {
        if(i==0) {
            mas[i]=R*a;
            //cout<<R<<"\n";
        }
        else {
            if (Z==1) {
                R=R-mas[i-1];
                //cout<<R<<"\n";
                mas[i]=R-mas[i-1];
            }
            else {
                //cout<<R<<"\n";
                mas[i]=R-mas[i-1];
                R=R-mas[i-1];
            }

        }
    }
}
                void Code2 () {

                }


        void Code3 () {

        }
int main () {
        ifstream fin("input.txt");
        fin >> L >> R >> K >> Z;
        fin.close();
W=K;
mmas=new int [W];
mas=new int [W];
prot=new int [W];
a=1/(K-1);
Code2();
if (N<=2) {
    Code1();
}
        ofstream fout;
        fout.open ("output2.txt");
        for (int i=0;i<K;i++) {
            fout <<mas[i]<<' ';
            //cout<<mas[i]<<' ';
        }
        fout.close();
}
