#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)

using namespace std;

int main()
{
    int N,nb;
    int qS1,qS2,qS3;
    int r1,r2,r3,l1,l2,l3,cc1,cc2,cc3;
    bool s1,s2,s3;
    int p1,p2,p3;
    int nPr1,nPr2,nPr3,nPl1,nPl2,nPl3,c01,c02,c03;
    int T[100000];
    bool T1[100000];
    bool T2[100000];
    bool T3[100000];
    vector<int> TnPr3;
    vector<int> TnPl3;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> nb;
        for(int j=0;j<nb;j++)
            cin >> T[j];
        memset(T1,true,sizeof(bool)*nb);
        memset(T2,true,sizeof(bool)*nb);
        memset(T3,true,sizeof(bool)*nb);
        //memset(TnPr3,0,sizeof(int)*nb);
        //memset(TnPl3,0,sizeof(int)*nb);
        cc1=0;p1=-1;r1=0;l1=0;s1=false;qS1=0;
        cc2=0;p2=-1;r2=0;l2=0;s2=false;qS2=0;
        cc3=0;p3=-1;r3=0;l3=0;s3=false;qS3=0;TnPr3.clear();TnPl3.clear();
        while(!s1 || !s2 || !s3){
            if(!s1){
                if(p1==-1){
                    p1=0;
                    T1[0]=false;
                }
                if(cc1<nb){
                    if(cc1==0)
                        c01=0;
                    if(T1[cc1]){
                        //cout << T[cc1] << " " << T[p1] << endl;
                        qS1++;
                        if(T[cc1]<T[p1]){
                            r1++;
                            if(r1==1)
                                nPr1=cc1;
                        }
                        else{
                            l1++;
                            if(l1==1)
                                nPl1=cc1;
                        }
                    }
                    else
                        c01++;
                    cc1++;
                    if(cc1==nb && c01==nb)
                        s1=true;
                    else if(cc1==nb){
                        if(r1>1 && l1>1)
                            p1=(r1<l1?nPr1:nPl1);
                        else if(r1<=1 && l1>1){
                            p1=nPl1;
                            if(r1==1)
                                T1[nPr1]=false;
                        }
                        else if(l1<=1 && r1>1){
                            p1=nPr1;
                            if(l1==1)
                                T1[nPl1]=false;
                        }
                        else{
                            if(r1==1)
                                T1[nPr1]=false;
                            if(l1==1)
                                T1[nPl1]=false;
                            s1=true;
                        }
                        T1[p1]=false;
                        cc1=0;
                        r1=0;
                        l1=0;
                    }
                }
            }
            if(!s2){

                if(p2==-1){
                    p2=nb-1;
                    T2[nb-1]=false;
                }
                if(cc2<nb){
                    if(cc2==0)
                        c02=0;
                    if(T2[cc2]){
                        //cout << T[cc1] << " " << T[p1] << endl;
                        qS2++;
                        if(T[cc2]<T[p2]){
                            r2++;
                            nPr2=cc2;
                        }
                        else{
                            l2++;
                            nPl2=cc2;
                        }
                    }
                    else
                        c02++;
                    cc2++;

                    if(cc2==nb && c02==nb)
                        s2=true;
                    else if(cc2==nb){
                        //cout << "test debut" << endl;
                        if(r2>1 && l2>1)
                            p2=(r2<l2?nPr2:nPl2);
                        else if(r2<=1 && l2>1){
                            p2=nPl2;
                            if(r2==1)
                                T2[nPr2]=false;
                        }
                        else if(l2<=1 && r2>1){
                            p2=nPr2;
                            if(l2==1)
                                T2[nPl2]=false;
                        }
                        else{
                            if(r2==1)
                                T2[nPr2]=false;
                            if(l2==1)
                                T2[nPl2]=false;
                            s2=true;
                        }
                        //cout << "test fin" << endl;
                        //cout << "p2: " << p2 << endl;
                        T2[p2]=false;
                        cc2=0;
                        r2=0;
                        l2=0;

                    }

                }

            }
            if(!s3){
                //cout << "test boucle" << endl;
                if(p3==-1){
                    p3=nb/2;
                    T3[nb/2]=false;
                }
                if(cc3<nb){
                    if(cc3==0)
                        c03=0;
                    if(T3[cc3]){
                        //cout << T[cc3] << " " << T[p3] << endl;
                        qS3++;
                        if(T[cc3]<T[p3]){
                            r3++;
                            TnPr3.push_back(cc3);
                            //nPr3=cc3;
                        }
                        else{
                            l3++;
                            TnPl3.push_back(cc3);
                            //nPl3=cc3;
                        }
                    }
                    else
                        c03++;
                    cc3++;
                    if(cc3==nb && c03==nb)
                        s3=true;
                    else if(cc3==nb){
                        if(r3>1 && l3>1)
                            p3=(r3<l3?TnPr3[r3/2]:TnPl3[l3/2]);
                        else if(r3<=1 && l3>1){
                            p3=TnPl3[l3/2];
                            if(r3==1)
                                T3[TnPr3[0] ]=false;
                        }
                        else if(l3<=1 && r3>1){
                            p3=TnPr3[r3/2];
                            if(l3==1)
                                T3[TnPl3[0] ]=false;
                        }
                        else{
                            if(r3==1)
                                T3[TnPr3[0] ]=false;
                            if(l3==1)
                                T3[TnPl3[0] ]=false;
                            s3=true;
                        }
                        T3[p3]=false;
                        cc3=0;
                        r3=0;
                        l3=0;
                        TnPr3.clear();
                        TnPl3.clear();
                    }
                }
            //cout << "test fin boucle" << endl;
            }
        }
        cout << qS1 << " " << qS2 << " " << qS3 << endl;

    }
    return 0;
}
