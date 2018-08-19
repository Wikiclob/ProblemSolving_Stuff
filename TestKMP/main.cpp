#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

vector<int> saut;

//KMP (sous-chaine dans chaine)
void preKMP(string pattern)// si plusieurs fois la meme sous chaine enlever parametre
{
    int m = pattern.length(), k;
    saut[0] = -1;//changer nom si global
    for (int i = 1; i < m; i++)
    {
        k = saut[i - 1];//changer nom si global
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = saut[k];//changer nom si global
        }
        saut[i] = k + 1;//changer nom si global
    }
}
//check whether target string contains pattern
int KMP(string pattern, string target)//modif retour si occurence ou pos
{
    int m = pattern.length();
    int n = target.length();
    //vector<int> f(m);//supp si vector global
    int pos=0;//ajout si calcul occ
    int occ=0;
    //preKMP(pattern, f);//sortir si kmp plusieurs fois (occurence) et enlever le 2eme parametre
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            if(k==0) // ajout si calcul occ
                    pos=i;
            i++;
            k++;
            if (k == m){
                cout << "occ " << i-1 << endl;
                occ++;
                i-=saut[saut.size()-1]+1;
                k=0;
            	//return i-m;//modif avec pos return i-m; si occurence modif avec occ++ && k=0 && i-=saut[saut.size()-1]+1;
            }
        }
        else
            k = saut[k];//changer nom si global
    }
    return occ;// modif -1 si pos et occ si occ
}

int main()
{
    string ch1="tt",ch2="testttetetestttestest";
    int pos;
    cout << "ch2: " << ch2 << endl;
    cout << "ch1: " << ch1 << endl;
    saut.clear();
    saut.resize(ch1.length());
    preKMP(ch1);//sortir si kmp plusieurs fois (occurence)
    for(int i=0;i<saut.size();i++)
        cout << saut[i] << " | ";
    cout << endl;
    if((pos=KMP(ch1,ch2))>=0)
        cout << "trouve dans " << pos << endl;
    else
        cout << "non trouve" << endl;
    return 0;
}
