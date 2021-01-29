#include <iostream>
using namespace std;
#include "FluxLog.h"
#include "Stats.h"


int main(int argc, char const *argv[])
{
    Stats S;
    S.AjouterGraphe("page2.html","page1.html");
    S.AjouterGraphe("page1.html","page2.html");
    S.AjouterGraphe("page2.html","page3.html");
    S.AjouterGraphe("page3.html","page2.html");
    S.AjouterGraphe("image.jpg","page3.html");
    S.AjouterGraphe("page2.html","page1.html");
    S.GenererGraphe("good.dot");
    return 0;
}
