#include <iostream>
#include <cstring>

const int MAX_DIGITS = 10;

void inputSet(const char name, bool bitArray[]) {
    char A[80] = {0};
    std::cout << "Input array " << name << " of decimal digits: ";
    std::cin >> A;

    for (int i = 0; i < MAX_DIGITS; ++i) {
        bitArray[i] = false; 
    }

    for (int i = 0; A[i] != '\0'; ++i) {
        if ('0' <= A[i] && A[i] <= '9') {
            int digit = A[i] - '0';
            bitArray[digit] = true; 
        }
    }
}

void outputSet(const char name, const bool bitArray[]) {
    std::cout << "Set " << name << ": [";
    bool first = true;
    for (int i = 0; i < MAX_DIGITS; ++i) {
        if (bitArray[i]) {
            if (!first) std::cout << ", ";
            std::cout << i;
            first = false;
        }
    }
    std::cout << "]" << std::endl;
}

void processSets(const bool a[], const bool b[], const bool c[], const bool d[], bool result[]) {
    for (int i = 0; i < MAX_DIGITS; ++i) {
        result[i] = (a[i] && b[i]) && !(c[i] || d[i]);
    }
}

int main() {
    bool a[MAX_DIGITS], b[MAX_DIGITS], c[MAX_DIGITS], d[MAX_DIGITS], e[MAX_DIGITS];

    inputSet('A', a);
    inputSet('B', b);
    inputSet('C', c);
    inputSet('D', d);

    processSets(a, b, c, d, e);

    outputSet('A', a);
    outputSet('B', b);
    outputSet('C', c);
    outputSet('D', d);
    std::cout << "Result is set E: E = (A && B) \\ (C || D)" << std::endl;
    outputSet('E', e);

    return 0;
}
