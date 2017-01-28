#include "Comparer.h"

int main(int argv, char* argc[])
{
    // Declare (and create) a comparer object
    Comparer comparer;

    // Have the comparer load all the input files and then do the comparison,
    // which creates the output file
    if (comparer.load(argv, argc)==0)
        comparer.compare();
}