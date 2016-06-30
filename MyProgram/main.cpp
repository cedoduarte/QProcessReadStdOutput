/**************************************************************************
** Author: Carlos Enrique Duarte Ortiz
** Company: DuarteCorporation Tutoriales
** WebPage: https://www.youtube.com/c/duartecorporationtutoriales
**
**************************************************************************/
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cerr << "Error: (argc == 1)" << endl;
        return -1;
    }
    for (int x = 1; x < argc; ++x) {
        cout << "Argumento: " << argv[x] << endl;
    }
    return 0;
}
