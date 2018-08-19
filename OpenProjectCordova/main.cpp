#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

ifstream input("config.cg");
ofstream output("exec.bat");

int main()
{
    string projectSelected="";
    string newProject="";
    string chemin="D:\\ProjectCordova\\";
    string choix="";
    string creer="cordova create "+newProject+" edu.alecso.mdevelopper."+newProject+" "+newProject;
    vector<string> fileNames;
    WIN32_FIND_DATA File;
    HANDLE hSearch;
    bool fin=false;
    while(!fin){
        if (system("CLS")) system("clear");
        if(projectSelected=="")
            cout << "Selected: " << projectSelected << endl;
        cout << "-----------------------MENU-----------------------" << endl;
        cout << "1- Créer projet cordova" << endl;
        cout << "2- Sélectionner projet cordova" << endl;
        cout << "3- Emuler projet cordova" << endl;
        cout << "4- Quitter" << endl << endl;
        cout << "choisir l'indice: ";
        cin >> choix;
        switch(choix){
        case "1":
            do{
            cout << "choisir un nom: ";
            cin << newProject;
            }while(newProject="");
            system(creer);
            break;
        case "2":
            int cc=1;
            fileNames.clear();
            hSearch = FindFirstFile("*.*", &File);
            if (hSearch != INVALID_HANDLE_VALUE){
                do{
                    printf("%d- %s\n",cc++, File.cFileName);
                    fileNames.push_back(File.cFileName);
                }
                while (FindNextFile(hSearch, &File));
                FindClose(hSearch);
            }
            if(fileNames.size()>0){
                bool quitter=false;
                int choix;
                while(!quitter){
                    cout << "choix(0 pour annuler): ";
                    cin >> choix;
                    if(choix<=fileNames.size() && choix>=0)
                        quitter=true;
                }
                if(choix!=0){
                    projectSelected=fileNames[choix-1];
                }
            }
            else{
                cout << "no project created..." << endl;
                getchar();
            }
            break;
        case "3":
            break;
        case "4":
            fin=true;
            break;
        default:
            break;
        }
    }
    input.close();
    output.close();
    return 0;
}
