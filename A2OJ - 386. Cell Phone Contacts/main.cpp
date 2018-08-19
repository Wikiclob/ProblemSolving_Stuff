#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
using namespace std;
const int oo=1e9;
const int MAX=1010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<string,string> ss;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

vector<pair<ss,string > > mail;
vector<pair<ss,string > > number;
vector<ss> names;

bool compare_inc(pair<ss,string> a,pair<ss,string> b){
    if(a.f.s<b.f.s)
        return true;
    else if(a.f.s>b.f.s)
        return false;
    else{
        if(a.f.f<b.f.f)
            return true;
        else if(a.f.f>b.f.f)
            return false;
        else
            return (a.s<b.s);
    }
}

bool compare_inc_names(ss a, ss b){
    if(a.s<b.s)
        return true;
    else if(a.s>b.s)
        return false;
    else
        return (a.f<b.f);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string firstN,lastN,nb_mail;
    ll nbList = 1;
    while(true){
        cin >> n;
        if(!n)
            break;
        mail.clear();
        number.clear();
        names.clear();
        if(nbList!=1)
            cout << endl;
        cout << "Contact list #" << nbList++ <<":" << endl;
        while(n--){
            cin >> firstN >> lastN >> nb_mail;
            names.push_back(ss(firstN,lastN));
            if(nb_mail.find('.')!=string::npos)
                mail.push_back(pair<ss,string>(ss(firstN,lastN),nb_mail));
            else
                number.push_back(pair<ss,string>(ss(firstN,lastN),nb_mail));
        }
        sort(mail.begin(),mail.end(),compare_inc);
        sort(number.begin(),number.end(),compare_inc);
        sort(names.begin(),names.end(),compare_inc_names);
        int ii=0,jj=0,kk=0;
        ss now = ss("","");
        while(ii<names.size()){
            if(now.f!=names[ii].f || now.s != names[ii].s){
                cout << names[ii].f << " " << names[ii].s << endl;
                now.f = names[ii].f;
                now.s = names[ii].s;
            }
            cout << "Phone:" << endl;
            while(jj <number.size() && now.f == number[jj].f.f && now.s == number[jj].f.s){
                cout << "(" << number[jj].s.substr(0,3) << ")";
                cout << number[jj].s.substr(3,3) << "-";
                cout << number[jj].s.substr(6) << endl;
                jj++;
                ii++;
            }
            cout << "E-Mail:" << endl;
            while(kk <mail.size() && now.f == mail[kk].f.f && now.s == mail[kk].f.s){
                cout << mail[kk].s << endl;
                kk++;
                ii++;
            }
            cout << "###" << endl;
        }
    }
    return 0;
}
