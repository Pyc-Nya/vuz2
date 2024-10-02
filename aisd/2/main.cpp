#include "SetArray.h"  

int main() {
    Set A, B, C, D, E;

    A.input('A');
    B.input('B');
    C.input('C');
    D.input('D');

    E = (A & B) - (C | D);

    E.output('E');

    return 0;
}
