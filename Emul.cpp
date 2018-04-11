#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

using namespace std;
int R=10,Q=3,W=0,Z=50,N=0,res=0;
int K=3;

int main(){
    /*ifstream fin("input.txt");          //Определение условий игры
    fin >> K >> R >> Q >> Z;
    fin.close();*/
    int res1[K][Z];
    int res2[K][Z];
    int win1[Z];
    int win2[Z];
    for (N; N<Z;N++){
            cout<<N+1<<" ";
        system("prog1.exe"); //Запуск игрока 1
        ifstream fin1 ("output1.txt"); //Чтение результатов игрока 1
        for (int i=0;i<K;i++) {
            fin1 >>res1[i][N];
            //cout<<res1[i][N];
        }
        fin1.close();
        system("prog2.exe"); //Запуск игрока 2
        ifstream fin2 ("output2.txt"); //Чтение результатов игрока 2
        for (int i=0;i<K;i++) {
            fin2 >>res2[i][N];
            cout<<"\n";
            //cout<<res2[i][N];
        }
        fin2.close();
        win1[N]=0;
        win2[N]=0;
        for (int i = 0; i<K;i++){
            if (res1[i][N]==res2[i][N]){
                win1[N]++;
                win2[N]++;
            }
            else{
                if(res1[i][N]<res2[i][N]){
                    win2[N]=win2[N]+Q;
                }
                else{
                    win1[N]=win1[N]+Q;
                }
            }
        }
        ofstream result1("result1.txt");
        result1<<N+1<<" ";
        for (int r=0;r<K;r++){
            result1<<res1[r][N]<<" ";
        }
        result1.close();
        ofstream result2("result2.txt");
        result2<<N+1<<" ";
        for (int r=0;r<K;r++){
            result2<<res2[r][N]<<" ";
        }
        result2.close();
    }
    ofstream dataout("Protokol.txt");
    for (int dt=0; dt<Z;dt++){
        dataout <<dt+1<<" ";

        for(int i=0;i<K;i++){
            dataout<< res1[i][dt];
            //cout<< res1[i][dt];
        }
        dataout<<" "<<win1[dt]<<" ";
        for(int i=0;i<K;i++){
            dataout<<res2[i][dt];
            //cout<<res1[i][dt];
        }
        dataout<<" "<< win2[dt]<<"\n";
    }
    int allwin1=0;
    int allwin2=0;
    for(int i=0;i<Z;i++){
        allwin1 = allwin1+win1[i];
        allwin2 = allwin2+win2[i];
    }
    dataout<<allwin1<<" "<<allwin2;
    dataout.close();
}
