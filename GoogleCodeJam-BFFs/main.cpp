#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int TAILLE;
int SEARCH;
bool visited[1001];
int T[1001];
bool search_for(int first){
    for(int i=1;i<=TAILLE;i++){
        if(!visited[i] && T[i]==first){
            SEARCH=i;
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream input("input.in");
    ofstream output("output.out");
    int N;
    input >> N;
    for(int i=1;i<=N;i++){
        input >> TAILLE;
        int max_taille=0;
        for(int j=1;j<=TAILLE;j++){
            input >> T[j];
        }
        int now;
        int count_size;
        cout << "***** " << "CASE " << i << " ******\n";
        for(int j=1;j<=TAILLE;j++){
            cout << T[j] << " | ";
        }
        cout << endl;
        for(int j=1;j<=TAILLE;j++){
            now=j;
            memset(visited,false,sizeof(bool)*(TAILLE+1));
            visited[now]=true;
            count_size=1;
            cout << j;
            while(!visited[T[now]]){
                visited[T[now]]=true;
                now=T[now];
                count_size++;
                cout << "=>" << now;
            }
            cout << "\nnow : " << now;
            int first=j;
            cout << "\nsecond part: ";
            bool verif=false;
            bool last_verif=false;
            int temp=0;

            while((verif=search_for(first))){
                last_verif=(T[now]==SEARCH);
                visited[SEARCH]=true;
                first=SEARCH;
                verif=false;
                temp++;
                if(last_verif){
                    count_size+=temp;
                    break;
                }
                cout << "(v)=>" << first;
            }
            //cout << " : " << T[now];
            cout << endl;

            if(T[now]==j || last_verif){
                cout << ":::::::VERIFIED\n";
                max_taille=max(max_taille,count_size);
            }
        }
        output << "Case #" << i << ": " << max_taille << "\n";
    }
    return 0;
}
