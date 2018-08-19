#include <iostream>

using namespace std;

int main()
{
    string name="Daenerys Targaryen, the First of Her Name, Queen of Meereen, Queen of the Andals and the Rhoynar and the First Men, Lord of the Seven Kingdoms, Protector of the Realm, Khaleesi of the Great Grass Sea, called Daenerys Stormborn, the Unburnt, Mother of Dragons";
    string res="";
    string Convert[26]={"ka","zu","mi","te","ku","lu","ji","ri","ki","zu","me","ta","rin","to","mo","no","ke","shi","ari","chi","do","ru","mei","na","fu","zi"};
    for(int i=0;i<name.length();i++){

        if(name[i]>=97 && name[i]<=122)
            res+=Convert[name[i]-97];
        else if(name[i]>=65 && name[i]<=90)
            res+=Convert[name[i]-65];
        else
            res+=name[i];
    }
    cout << res << endl;
    return 0;
}
