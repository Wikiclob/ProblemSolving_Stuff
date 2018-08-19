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

int main()
{
    std::ios::sync_with_stdio(false);cin.tie(false);
    int letters[26];
    bool found[26];
    bool finish=false;
    int interrog=0,nbLetters=0;
    string word;
    cin >> word;
    if(word.length()<26)
        cout << -1 << endl;
    else{
        int j=0;
        for(int i=0;i<word.length();i++){
            //cout << "(" << i << "): " << word[i] << endl;
            if(!finish){
                if(i<26){
                    if(word[i]!='?'){
                        letters[word[i]-65]++;
                        if(!found[word[i]-65]){
                            nbLetters++;
                            found[word[i]-65]=true;
                        }

                    }
                    else{
                        interrog++;
                    }
                    //cout << "(" << i << "): " << "interrog: " << interrog << " & nbLetters: " << nbLetters << endl;
                    if(nbLetters+interrog>=26){
                        finish=true;
                        vector<char> missing;
                        int Begin=0;
                        for(int k=0;k<26;k++){
                            if(!found[k])
                                missing.push_back(k+65);
                        }
                        for(int k=j;k<j+26;k++){
                            if(word[k]=='?'){
                                if(Begin<missing.size()){
                                    word[k]=missing[Begin];

                                    Begin++;
                                }
                                else{
                                    word[k]='A';

                                }
                            }
                        }

                    }
                }
                else{
                    //cout << "(" << i << "): " << "interrog: " << interrog << " & nbLetters: " << nbLetters << endl;
                    if(word[i]!='?'){
                        letters[word[i]-65]++;
                        if(!found[word[i]-65]){
                            nbLetters++;
                            found[word[i]-65]=true;
                        }
                    }
                    else{
                        interrog++;
                    }

                    if(word[j]=='?'){
                        interrog--;
                    }
                    else{
                        if(letters[word[j]-65]==1){
                            nbLetters--;
                            found[word[j]-65]=false;
                        }
                        letters[word[j]-65]--;
                    }

                    j++;
                        if(word[i]!='?'){
                            letters[word[i]-65]++;

                        if(!found[word[i]-65]){
                            found[word[i]-65]=true;
                            nbLetters++;
                        }
                    }
                    //cout << "changed word length: " << word.length() << endl;
                    if(nbLetters+interrog>=26){
                        finish=true;
                        vector<char> missing;
                        int Begin=0;
                        for(int k=0;k<26;k++){
                            if(!found[k])
                                missing.push_back(k+65);
                        }
                        for(int k=j;k<j+26;k++){
                            if(word[k]=='?'){
                                if(Begin<missing.size()){
                                    word[k]=missing[Begin];

                                    Begin++;
                                }
                                else{
                                    word[k]='A';

                                }
                            }
                        }
                    }
                }
            }
            else if(word[i]=='?'){
                word[i]='A';

            }
            //cout << "length: " << word.length() << endl;
            //cout << "j: " << j << endl;
        }
        if(finish){
            for(int k=0;k<=j;k++){
                if(word[k]=='?')
                    word[k]='A';

            }
            cout << word << endl;
        }
        else
            cout << -1 << endl;
        //cout << "test: " << word << endl;
    }
    return 0;
}
