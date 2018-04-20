#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

using namespace std;
int S=0,R=0,Z=0,W=0,T=0,e=0,z=0,m=0,xy=0;
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
    string input_file = "input1.txt";
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

if (T<2){
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
        /*for(int d=0;d<Z;d++){
            if (mas[d]<mas[d+1]){
                int ff=mas[d+1];
                mas[d+1]=mas[d];
                mas[d]=ff;
            }
        }*/
        for (int i=0;i<Z-1;i++) {
            for (int j=0;j<Z-1-i;j++) {
                if (mas[j]<mas[j+1]) {
                    z=mas[j];
                    mas[j]=mas[j+1];
                    mas[j+1]=z;
                }
            }
        }
    }
    else if (resultat[T-1]==0) {
        int flag=0; //Наличие больше формулы
        int nomer=0;
        int check=0; //
        for (int gg=0;gg<Z;gg++){
            if (resenemy[T-1][gg]>check){
                nomer=gg;
                check=resenemy[T-1][gg];
                if(resenemy[T-1][gg]>R*formula){
                    flag=1;
                }else{
                    if(resenemy[T-1][gg]<R*formula){
                        flag=-1;
                    }
                }
            }
        }
        if (flag==0){
            for(int kk=0;kk<Z;kk++){
                mas[kk]=resenemy[T-1][kk];
            }
        }else{
            if(flag==1){                                        //!
                for(int kk=0;kk<Z;kk++){
                    if(nomer==kk){
                        mas[kk]=1;
                    }else{
                        int suma=0;
                        for(int k=0;k<Z;k++){
                            suma+=mas[k];
                        }
                        if(suma<=R-R*formula){
                            mas[kk]=R*formula;
                        }else{
                            mas[kk]=R*formula-1;
                        }
                    }
                }
            }else{
                for (int i=0;i<Z;i++) {
                    if(i==0) {
                        mas[i]=R*formula;
                    }else {
                        mas[i]=R-mas[i-1];
                    }
                    R=R-mas[i];
                }
            }
        }
        /*m=resenemy[T-1][0];
        for (int i=0;i<Z;i++) {
            if (resenemy[T-1][i]>m) {
                m=resenemy[T-1][i];
                xy=i;
            }
        }
        if (m>R*formula) {
            mas[xy]=1;
            R=R-mas[xy];
            if (xy==0) {
                e=1;
                cout<<xy<<"\n";
            }
            for (int i=0+e;i<Z;i++) {
                if (i!=xy) {
                    if (i==0+e) {
                        mas[i]=R*formula;
                    }
                    else if (i==1+e) {
                        mas[i]=R-mas[i];
                    }
                    else {
                        mas[i]=R;
                    }
                    R=R-mas[i];
                }
            }
        }
        else if (m==R*formula) {
            for (int i=0;i<Z;i++) {
                mas[i]=resenemy[T-1][i];
            }
        }
        else {
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
        }*/
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

