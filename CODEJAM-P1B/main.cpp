#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
    ifstream input("A-large (3).in");
    ofstream output("A-large (3).out");
    //number of Z = number of ZERO
    //number of W is number of TWO
    //number of U is number of FOUR
    //number of F = number of FIVE(after verif FOUR)
    //number of X = number of SIX
    //number of V = number of SEVEN(after FIVE)
    //number of O = number of ONE(after ZERO / TWO / FOUR)
    //number of N /2 = number of NINE (after ONE/SEVEN)
    //number of R = number of THREE (after ZERO/FOUR)
    //number of H = number of EIGHT (after THREE)
    int NUMBER[10];
    int LETTERS[26];
    int N;
    string s;
    input >> N;
    for(int i=1;i<=N;i++){

        input >> s;
        input.ignore();
        memset(NUMBER,0,sizeof(int)*10);
        memset(LETTERS,0,sizeof(int)*26);
        for(int j=0;j<s.size();j++){
            LETTERS[s[j]-65]++;
        }
        if(LETTERS['Z'-65]!=0){
            NUMBER[0]=LETTERS['Z'-65];
            LETTERS['Z'-65]=0;
            LETTERS['E'-65]-=NUMBER[0];
            LETTERS['R'-65]-=NUMBER[0];
            LETTERS['O'-65]-=NUMBER[0];
        }
        if(LETTERS['W'-65]!=0){
            NUMBER[2]=LETTERS['W'-65];
            LETTERS['W'-65]=0;
            LETTERS['T'-65]-=NUMBER[2];
            LETTERS['O'-65]-=NUMBER[2];
        }
        if(LETTERS['U'-65]!=0){
            NUMBER[4]=LETTERS['U'-65];
            LETTERS['U'-65]=0;
            LETTERS['F'-65]-=NUMBER[4];
            LETTERS['O'-65]-=NUMBER[4];
            LETTERS['R'-65]-=NUMBER[4];
        }
        if(LETTERS['F'-65]!=0){
            NUMBER[5]=LETTERS['F'-65];
            LETTERS['F'-65]=0;
            LETTERS['I'-65]-=NUMBER[5];
            LETTERS['V'-65]-=NUMBER[5];
            LETTERS['E'-65]-=NUMBER[5];
        }
        if(LETTERS['F'-65]!=0){
            NUMBER[5]=LETTERS['F'-65];
            LETTERS['F'-65]=0;
            LETTERS['I'-65]-=NUMBER[5];
            LETTERS['V'-65]-=NUMBER[5];
            LETTERS['E'-65]-=NUMBER[5];

        }
        if(LETTERS['X'-65]!=0){
            NUMBER[6]=LETTERS['X'-65];
            LETTERS['X'-65]=0;
            LETTERS['S'-65]-=NUMBER[6];
            LETTERS['I'-65]-=NUMBER[6];
        }
        if(LETTERS['V'-65]!=0){
            NUMBER[7]=LETTERS['V'-65];
            LETTERS['V'-65]=0;
            LETTERS['S'-65]-=NUMBER[7];
            LETTERS['E'-65]-=2*NUMBER[7];
            LETTERS['N'-65]-=NUMBER[7];
        }
        if(LETTERS['O'-65]!=0){
            NUMBER[1]=LETTERS['O'-65];
            LETTERS['O'-65]=0;
            LETTERS['N'-65]-=NUMBER[1];
            LETTERS['E'-65]-=NUMBER[1];
        }
        if(LETTERS['N'-65]!=0){
            NUMBER[9]=LETTERS['N'-65]/2;
            LETTERS['N'-65]=0;
            LETTERS['I'-65]-=NUMBER[9];
            LETTERS['E'-65]-=NUMBER[9];
        }
        if(LETTERS['R'-65]!=0){
            NUMBER[3]=LETTERS['R'-65];
            LETTERS['R'-65]=0;
            LETTERS['T'-65]-=NUMBER[3];
            LETTERS['H'-65]-=NUMBER[3];
            LETTERS['E'-65]-=2*NUMBER[3];
        }
        if(LETTERS['H'-65]!=0){
            NUMBER[8]=LETTERS['H'-65];
        }
        output << "Case #" << i << ": ";
        for(int j=0;j<10;j++){
            if(NUMBER[j]!=0){
                for(int k=0;k<NUMBER[j];k++)
                    output << j;
            }
        }
        output << "\n";
    }

    return 0;
}
