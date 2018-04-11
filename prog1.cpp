#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int S=0,T=0,R=0,W=0,Q=0,x=0,v=0,xy=0;
float K=0.0, y=0.0, Z=0.0;
int *mas;
int *savetmp;

void Code1 () {
    if (S==1) {
    for (int i=0;i<W;i++) {
        if(i==0) {
            mas[i]=R*y;
        }
        else {
                mas[i]=R-mas[i-1];
            }
            R=R-mas[i];
    }
        if (Z==0) {
            for (int i=1;i<W;++i) {
                for (int j=0;j<W-1;j++) {
                    if (mas[j]>mas[j+1]) {
                        x=mas[j];
                        mas[j]=mas[j+1];
                        mas[j+1]=x;
                    }
                }
            }
        }
        if (Z==2) {
            for (int i=1;i<W;++i) {
                for (int j=0;j<W-1;j++) {
                    if (mas[j]<mas[j+1]) {
                        x=mas[j];
                        mas[j]=mas[j+1];
                        mas[j+1]=x;
                    }
                }
            }
        }
    }

    else {
        for (int i=0;i<W;i++) {
            if (i!=K-1) {
                srand(time(NULL));
                mas[i]=rand() % (R+1);
            }
            else {
                mas[i]=R;
            }
            R=R-mas[i];

        }
    }
}

                void Code2 () {
                    ifstream fin ("result2.txt");
                    int savetmp [W-1];
                    for (int i=0;i<W;i++) {
                        fin>>savetmp[i];
                    }
                    fin.close();
                    ofstream fout ("savetmp.txt", ios_base::app);
                    for (int i=0;i<W;i++) {
                        fout<<savetmp[i]<<" ";
                        if (i==W-1) {
                            fout<<"\n";
                        }
                    }
                    fout.close();
                }


                           void Code3 () {
                                int savetmp[W-1][T-1];
                                ifstream fin ("savetmp.txt");
                                for (int i=0;i<W;i++) {
                                    for (int j=0;j<T-1;j++) {
                                        fin>>savetmp[i][j];
                                    }
                                }
                                fin.close();
                                v=savetmp[0][T-1];
                                for (int i=0;i<W;i++) {
                                    for (int j=0;j<T-1;j++) {
                                        if (savetmp[i][j]!=savetmp[i][j+1]) {
                                            for (int c=0;c<W;c++) {
                                                if (savetmp[c][T-1]<v) {
                                                    v=savetmp[c][T-1];
                                                    xy=c;
                                                }
                                            }
                                        }
                                    }
                                }
                                mas[xy]=R-v;
                                R=R-mas[xy];
                                for (int i=0;i<W;i++) {
                                    if (S==1) {
                                        if (i!=xy && xy!=0) {
                                            mas[i]=R*y;
                                        }
                                        else if (xy==0) {
                                            mas[i+1]=R*y;
                                        }
                                        else {
                                            mas[i]=R-mas[i-1];
                                        }
                                        R=R-mas[i];
                                    }
                                }
                                if (Z==0) {
                                    for (int i=1;i<W;++i) {
                                        for (int j=0;j<W-1;j++) {
                                            if (mas[j]>mas[j+1]) {
                                                x=mas[j];
                                                mas[j]=mas[j+1];
                                                mas[j+1]=x;
                                            }
                                        }
                                    }
                                }
                                if (Z==2) {
                                    for (int i=1;i<W;++i) {
                                        for (int j=0;j<W-1;j++) {
                                            if (mas[j]<mas[j+1]) {
                                                x=mas[j];
                                                mas[j]=mas[j+1];
                                                mas[j+1]=x;
                                            }
                                        }
                                    }
                                }
                            }

int main () {
        ifstream fin ("input.txt");
        fin >> S >> R >> K >> W;
        fin.close();
W=K;
mas=new int [W-1];
y=1/(K-1);
srand(time(NULL));
Z=rand() % 3;
        ifstream f4 ("result2.txt");
        f4>>T;
        f4.close ();
if(T>1) {
    Code2();
}
if (T<=2) {
    Code1();
}
        ofstream fout;
        fout.open ("output1.txt");
        for (int i=0;i<K;i++) {
            fout <<mas[i]<<' ';
            cout<<mas[i]<<' ';
        }
        fout.close();
}
