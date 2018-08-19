#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
    char nb1[101],nb2[101];
    string sum="",ARm;
    cin >> nb1 >> nb2;
    int len1,len2,rest=0,add=0,ARmod,res[102];
    memset(res,0,102);
    stringstream ss;
    len1=strlen(nb1);
    len2=strlen(nb2);

    for(int i=0;i<max(len1,len2);i++){
        if(len1-1-i>=0 && len2-1-i>=0){
            add=nb1[strlen(nb1)-1-i]-48+nb2[strlen(nb2)-1-i]-48;
            ARmod=(add+rest)%10;
            res[i]=ARmod;
            //sum=""+ARmod+sum;
            rest=(add+rest)/10;
        }
        else if(len1-1-i>=0){
            add=nb1[strlen(nb1)-1-i]-48;
            ARmod=(add+rest)%10;
            res[i]=ARmod;
            //sum=""+ARmod+sum;
            rest=(add+rest)/10;
        }
        else if(len2-1-i>=0){
            add=nb2[strlen(nb2)-1-i]-48;
            ARmod=(add+rest)%10;
            //sum=""+ARmod+sum;
            res[i]=ARmod;
            rest=(add+rest)/10;
        }
    }
    int taille=max(len1,len2);
    if(rest!=0){
        res[max(len1,len2)]=rest;
        taille++;
    }
    for(int i=taille-1;i>=0;i--)
        cout << res[i];
    cout << endl;
    return 0;
}
