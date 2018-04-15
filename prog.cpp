#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

using namespace std;
int S=0,R=0,K=0,W=0,T=0;
//float formula=1/K-1;
void Ras1(){

 //for (int i=0;i<K;i++){}
}
void Ras2(){

}
int main(int argc, char* argv[]){
    string input_file = "input.txt";
    string output_file = "output1.txt";
    if (argc == 1){return 0;}
    else if (argc == 3)
    {
        input_file = argv[1];
        output_file = argv[2];
    }
    cout << input_file << " " << output_file;
    ifstream inputfile (input_file.c_str());
    inputfile >> S >> R >> K >> W >> T;
    for(int i=0;i<T;i++){
            for(int j=0;i<K;j++){
                inputfile >> resenemy[j][i];
            }
            for(int j=0;i<K;j++){
                inputfile >> resmy[j][i];
            }
            inputfile >> resultat[i];

        }
    inputfile.close();
    int enemy[K];


    if (S==0){
        Ras1(); //Без сортировки
    }else{
        Ras2(); //С сортировкой
    }
    ofstream outputfile (output_file.c_str());
    outputfile << T;
    for (int i=0; i<K; i++){
        outputfile << enemy[i];
    }
    outputfile.close();
}

