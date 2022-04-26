#include <iostream>
#include "../headers/EmbeddedIntentRecognizer.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc > 1)
    {
       EmbeddedIntentRecognizer eir;
       cout << eir.extractIntent(argc, &argv[0]) << endl;
    }
    else if(argc == 1)
    {
        cout << "ERROR: Expected at least 1 argument" << endl;
    }
    return 0;
}