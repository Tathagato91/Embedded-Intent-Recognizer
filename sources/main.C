#include <iostream>
#include "EmbeddedIntentRecognizer.h"

int main(int argc, char** argv[])
{
    if(argc > 1)
    {
       EmbeddedIntentRecognizer eir;
       std::cout << eir.extractIntent(argc-1, &argv[1]) << std::endl;
	   
    }
}