#include <bits/stdc++.h>
#include <dirent.h>
#include <sys/types.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
#define BE(x) x.begin(),x.end()
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
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

static vector<string> list_dir(const char *path)
{
    vector<string> retour;
    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return retour;
    }

    while ((entry = readdir(dir)) != NULL) {
        retour.push_back(entry->d_name);
        //printf("%s\n",entry->d_name);
    }

    closedir(dir);
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> fileList = list_dir("latexFilesInput/");

    for(int i=0;i<fileList.size();i++){
        string in(fileList[i]);
        string out("latexFilesOutput/" + in);
        in = "latexFilesInput/" + in;
        ifstream input(in.c_str());
        ofstream output(out.c_str());
        cout << "now: " << fileList[i] << endl;
        stringstream strStream;
        strStream << input.rdbuf();//read the file
        string ch = strStream.str();
        replaceAll(ch,"é","\\'{e}");
        replaceAll(ch,"è","\\`{e}");
        replaceAll(ch,"à","\\`{a}");
        replaceAll(ch,"ê","\\^{e}");
        replaceAll(ch,"ç","\\c{c}");
        replaceAll(ch,"â","\\^{a}");
        replaceAll(ch,"ô","\\^o");
        output << ch;
        input.close();
        output.close();
    }
    return 0;
}

