#include <iostream>
#include <cstdlib>
#include <cstdint>
#include "numToWords.h"

using namespace std;


int main(int argc, char** argv) {

    acs::numToWords nw;
    uint64_t n = 8;
    
    //printf("N is %lld = %s \n", n, nw.words(n));
    cout << "N is " << n << ", " << nw.words(n) << endl;
    n = 14;
    cout << "N is " << n << ", " << nw.words(n) << endl;
    n = 30;
    cout << "N is " << n << ", " << nw.words(n) << endl;
    n = 53;
    cout << "N is " << n << ", " << nw.words(n) << endl;
    n = 99;
    cout << "N is " << n << ", " << nw.words(n) << endl;
    n = 105;
    cout << "N is " << n << ", " << nw.words(n) << endl;

    return 0;
}

