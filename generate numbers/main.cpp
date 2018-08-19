#include <iostream>
#include <fstream>

using namespace std;
ofstream output("output.out");


int main()
{
    for(int i=1;i<=300;i++)
        output << i << endl;
    return 0;
}
