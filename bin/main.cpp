using namespace std;
#include <iostream>
#include "FluxLog.h"
int main(int argc, char const *argv[])
{
    LigneLog l;
    l.AuthenticatedUser="Irvin";
    cout<<l.AuthenticatedUser<<endl;
    FluxLog F("fichier.txt");
    cout<<F.is_open();
    string res;
    getline(F,res);
    cout <<res<<endl;
    F.close();
    return 0;
}
