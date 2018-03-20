#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
int R=0,Q=0,W=0,Z=0,N=1,res=0;
int K=0, win1=0, win2=0;
int mas[3];

int main(){
    ifstream fin("input.txt");          //Определение условий игры
    fin >> K >> R >> Q >> Z;
    fin.close();
    int res1[K], res2[K];
    for (N; N<=Z;N++){
        system("C:\\Users\\VISci-Portable\\Documents\\GitHub\\Confrontation\\prog1.exe"); //Запуск игрока 1
        ifstream fin1 ("output1.txt"); //Чтение результатов игрока 1
        for (int i=0;i<K;i++) {
            fin1 >>res1[i];
        }
        fin1.close();
        system("C:\\Users\\VISci-Portable\\Documents\\GitHub\\Confrontation\\prog2.exe"); //Запуск игрока 2
        ifstream fin2 ("output2.txt"); //Чтение результатов игрока 2
        for (int i=0;i<K;i++) {      //
            fin2 >>res2[i];        //
        }                        //
        fin2.close();
        int win1tmp = 0;
        int win2tmp = 0;
        for (int i = 0; i<K;i++){
            if (res1[i]==res2[i]){
                win1tmp++;
                win2tmp++;
                win1++;
                win2++;
            }
            else{
                if(res1[i]<res2[i]){
                    win2=win2+Q;
                    win2tmp=win2tmp+Q;
                }
                else{
                    win1=win1+Q;
                    win1tmp=win1tmp+Q;
                }
            }
        }
        ifstream fin("input.txt");
        fin >> K >> R >> Q >> Z;
        fin.close();
    }
    ofstream dataout("Protokol.txt");          //Определение условий игры
    for int (dt=1; dt<=Z;dt++){
        dataout >>dt>>" ">>res1>>" ">>win1>>" ">>res2>>" ">> win2;
    }
    dataout.close();
}
