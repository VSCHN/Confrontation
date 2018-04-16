#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

using namespace std;
int S=0,R=0,Z=0,W=0,T=0,e=0,m=0,xy=0,z=0;
float formula=0.0,K=0.0;
int *mas;
int *resultat;

void Ras() {
    for (int i=0;i<Z;i++) {
        if(i==0) {
            mas[i]=R*formula;
        }
        else {
            mas[i]=R-mas[i-1];
        }
        R=R-mas[i];
    }
    if (S==1) {
        for(int i=0;i<Z-1;i++) {
            for(int j=i+1;j<Z;j++)  {
                if (mas[i]<mas[j])  {
                    e=mas[i];
                    mas[i]=mas[j];
                    mas[j]=e;
                }
            }
        }
    }
}

int main(int argc, char* argv[]){
    string input_file = "input.txt";
    string output_file = "output1.txt";
    if (argc == 3)
    {
        input_file = argv[1];
        output_file = argv[2];
    }
    ifstream inputfile (input_file.c_str());
    inputfile >> S >> R >> K >> W >> T;
    formula=1/(K-1);
    Z=K;
    int resenemy[T][Z];
    int resmy[T][Z];
    resultat=new int[T];
    if (T!=0) {
        for(int i=0;i<T;i++){
            for(int j=0;j<Z;j++){
                inputfile >> resenemy[i][j];
            }
            for(int j=0;j<K;j++){
                inputfile >> resmy[i][j];
            }
            inputfile >> resultat[i];
        }
    }
    inputfile.close();
mas=new int [Z];
if (T==0){
    Ras();
}
else {
    if (resultat[T-1]==W) {
        for (int i=0;i<Z;i++) {
            mas[i]=resmy[T-1][i];
        }
    }
    else if (resultat[T-1]==1) {
        for (int i=0;i<Z;i++) {
            mas[i]=resmy[T-1][i];
        }
        for (int i=0;i<Z-1;i++) {
            for (int j=0;j<Z-1;j++) {
                if (mas[j]<mas[j+1]) {
                    z=mas[j];
                    mas[j]=mas[j+1];
                    mas[j+1]=e;
                }
            }
        }
    }
    else {
        m=resenemy[T-1][0];
        for (int i=0;i<Z-1;i++) {
            for (int j=0;j<Z-1;j++) {
                if (resenemy[T-1][j]>m) {
                    m=resenemy[T-1][j];
                    xy=j;
                    if (m<R*formula)
                }
            }
        }
        mas[xy]=R-m;
        R=R-mas[xy];
        for (int i=0;i<Z;i++) {
            if (i!=xy) {
                if (i==0) {
                    mas[i]=R*formula;
                }
                else {
                    mas[i]=R-mas[i-1];
                }
                R=R-mas[i];
            }
        }
    }
}
ofstream outputfile (output_file.c_str());
    for (int i=0; i<K; i++){
        outputfile <<mas[i]<<" ";
        cout<<mas[i]<<" ";
    }
    outputfile<<"\n";
    outputfile.close();
}

