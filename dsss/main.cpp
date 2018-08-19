#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

long long m_w, m_z;
int get_random()
{
m_z = 36969 * (m_z & 65535) + (m_z >> 16);
m_w = 18000 * (m_w & 65535) + (m_w >> 16);
long long res = (m_z << 16) + m_w;
return res % 1000000000;
}

int main()
{
    int N;
    int n,k;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&n,&k);
        scanf("%d%d",&m_w,&m_z);
        int T[n];
        for(int j=0;j<n;j++){
            T[j]=get_random();
            cout << T[j] << endl;
        }
    }
    return 0;
}
