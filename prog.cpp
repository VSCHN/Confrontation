#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

using namespace std;
int S=0,R=0,Z=0,W=0,T=0,R0=0,e=0;
float formula=0.0,K=0.0;
int *mas;

void Ras1() {
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

                    void Ras2() {
                        for (int i=0;i<Z;i++) {
                            srand(time(NULL)+T);
                            if (i!=K-1) {
                                mas[i]=rand() % (R+1);
                            }
                            else {
                                mas[i]=R;
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
    cout << input_file << " " << output_file<< " "<<"\n";
    ifstream inputfile (input_file.c_str());
    inputfile >> S >> R >> K >> W >> T;
    formula=1/(K-1);
    Z=K;
    if (T!=0) {
        int resenemy[T][Z];
        int resmy[T][Z];
        int resultat[T];
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
if (S==1){
    Ras1();
}
else {
    Ras2();
}
ofstream outputfile (output_file.c_str());
    for (int i=0; i<K; i++){
        outputfile <<mas[i]<<" ";
        cout<<mas[i]<<" ";
    }
    outputfile<<"\n";
    outputfile.close();
}

