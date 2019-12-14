#include <iostream>
#include <fstream>
#include "Sorting.h"

using namespace std;

int main (int argc, char** argv)
{
    if (argc != 2) //if filepath not included, throw error
    {
        cout << "Please run again and include the filepath" << endl;
        return 0;
    }

    Sorting s(argv[1]);
    s.process();


    return 0;
}