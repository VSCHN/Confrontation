#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>


using namespace std;
int S=0,R=10,W=3,Z=50,T=1,res=0;
int K=3;
int main(int argc, char* argv[]){
    /*cout << "Starting...\n";
    for (int i = 0; i < argc; i++)
    {
        cout << "param[" << i << "] = \'" << argv[i] << "\'" << endl;
    }

    if (argc == 1)
    {
        cout << "Starting child!\n";
        system("emul.exe input.txt out-data.txt");
    }
    else if (argc == 3)
    {
        cout << "We are called with 2 params!\n";
        string command = argv[0];
        command += ' ';
        command += argv[2];
        command += ' ';
        command += argv[1];
        command += " stop";
        cout << "Call: \'" << command << "\'\n";
        system(command.c_str());
    }
    cout << "Finished...\n";
    return 0;*/

    /*ifstream fin("input.txt");          //Определение условий игры
    fin >> S >> R >> K >> W >> Z;
    fin.close();*/
    int res1[K][Z];
    int res2[K][Z];
    int win1[Z];
    int win2[Z];
    for (T; T<=Z;T++){
        ofstream input1("input1.txt");
        input1 <<S<<" "<<R<<" "<<K<<" "<<W<<"\n"<<T-1<<"\n";
        if (T!=0){
            for(int i=0;i<T-1;i++){
            for(int j=0;j<K;j++){
                input1 << res2[j][i]<<" ";
            }
            for(int j=0;j<K;j++){
                input1 << res1[j][i]<<" ";
            }
            input1 << win1[i]<<"\n";
        }
        }
        input1.close();
        ofstream input2("input2.txt");
        input2 <<S<<" "<<R<<" "<<K<<" "<<W<<"\n"<<T-1<<"\n";
        if(T!=0){
            for(int i=0;i<T-1;i++){
            for(int j=0;j<K;j++){
                input2 << res1[j][i]<<" ";
            }
            for(int j=0;j<K;j++){
                input2 << res2[j][i]<<" ";
            }
            input2 << win2[i]<<"\n";
        }
        }
        input2.close();
        cout<<T<<" "<<"Gamer1 ";
        system("prog1.exe input1.txt output1.txt"); //Запуск игрока 1
        ifstream fin1 ("output1.txt"); //Чтение результатов игрока 1
        for (int i=0;i<K;i++) {
            fin1 >>res1[i][T-1];
            //cout<<res1[i][T];
        }
        fin1.close();
        cout<<"Gamer2 ";
        system("prog2.exe input2.txt output2.txt"); //Запуск игрока 2
        ifstream fin2 ("output2.txt"); //Чтение результатов игрока 2
        for (int i=0;i<K;i++) {
            fin2 >>res2[i][T-1];
            cout<<"\n";
            //cout<<res2[i][T];
        }
        fin2.close();
        win1[T-1]=0;
        win2[T-1]=0;
        int tmpwin1=0;
        int tmpwin2=0;
        for (int i = 0; i<K;i++){
            if (res1[i][T-1]==res2[i][T-1]){

            }
            else{
                if(res1[i][T-1]<res2[i][T-1]){
                    tmpwin2++;
                }
                else{
                    tmpwin1++;
                }
            }
        }
        if(tmpwin1==tmpwin2){
                win1[T-1]=1;
                win2[T-1]=1;
            }else{
                if(tmpwin1>tmpwin2){
                    win1[T-1]=W;
                }else{
                    win2[T-1]=W;
                }
            }
        ofstream result1("result1.txt");
        result1<<T<<" ";
        for (int r=0;r<K;r++){
            result1<<res1[r][T-1]<<" ";
        }
        result1.close();
        ofstream result2("result2.txt");
        result2<<T<<" ";
        for (int r=0;r<K;r++){
            result2<<res2[r][T-1]<<" ";
        }
        result2.close();
    }
    ofstream dataout("Protokol.txt");
    for (int dt=0; dt<Z;dt++){
        dataout <<dt+1<<"  ";
        for(int i=0;i<K;i++){
            dataout<< res1[i][dt]<<" ";
            //cout<< res1[i][dt];
        }
        dataout<<" "<<win1[dt]<<"  ";
        for(int i=0;i<K;i++){
            dataout<<res2[i][dt]<<" ";
            //cout<<res1[i][dt];
        }
        dataout<<"  "<< win2[dt]<<"\n";
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
