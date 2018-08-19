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

using namespace std;

pair<double,double> revenu_bank_and_solde(double solde,double withdraw){
    //cout << endl << "solde: " << solde << " withdraw: " << withdraw << endl;
    double sold=((int)(solde*100))*0.01;
    double soldeNoDec=(int)solde;
    double withd=(int)withdraw;
    int cent=(sold-soldeNoDec)*100;
    pair<double,double> retour;
    double percent=withd/soldeNoDec;
    retour.first=((int)(cent*percent))*0.01;
    //cout << "revenu bank calcul: " << retour.first << endl;
    retour.second=sold-withd-retour.first;
    //cout << "solde compte: "<< retour.second << endl << endl;
    return retour;
}

int find_pos_Account(vector<string> account,string name){
    for(int i=0;i<account.size();i++)
        if(account[i]==name)
            return i;
    return -1;
}

int main()
{
    map<string,vector<double> > withdraw;
    vector<string> AccountName;
    vector<double> AccountSolde;
    pair<double,double> calcul;
    string firstN,lastN,nameA="",nameB;
    double money,accountM,revenu=0;
    int Na,Nw;
    cin >> Na;
    for(int i=0;i<Na;i++){
        cin >> firstN >> lastN;
        cin.ignore(2,'$');
        cin >> money;
        AccountName.push_back(firstN+" "+lastN);
        AccountSolde.push_back(money);
    }
    cin >> Nw;
    for(int i=0;i<Nw;i++){
        cin >> firstN >> lastN;
        cin.ignore(2,'$');
        cin >> money;
        withdraw[firstN+" "+lastN].push_back(money);
    }
    map<string,vector<double> >::iterator it=withdraw.begin();
    int indAccount;
    for(map<string,vector<double> >::iterator it=withdraw.begin();it!=withdraw.end();it++){
        vector<double> V= withdraw[it->first];
        indAccount=find_pos_Account(AccountName,it->first);
        accountM=AccountSolde[indAccount];
        for(int i=0;i<V.size();i++){
            calcul=revenu_bank_and_solde(accountM,V[i]);
            revenu+=calcul.first;
            accountM=calcul.second;
        }
        AccountSolde[indAccount]=accountM;
    }
    for(int i=0;i<AccountName.size();i++){
        //cout << AccountName[i] << " $";
        printf("%s $%.2f\n",AccountName[i].c_str(),AccountSolde[i]);
    }
    printf("$%.2f\n",revenu);
    return 0;
}
