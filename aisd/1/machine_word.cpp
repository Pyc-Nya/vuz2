#include <iostream>
#include <bitset>

typedef unsigned int Word;

Word inputWord(const char name) {
    Word word = 0;
    char A[80] = {0};
    std::cout << "Input array " << name << " of decimal digits: ";
    std::cin >> A;

    for (int i = 0; A[i] != '\0'; ++i) {
        if ('0' <= A[i] && A[i] <= '9') {
            int digit = A[i] - '0';
            word |= (1 << digit);
        }
    }
    return word;
}

void outputWord(const char name, Word word) {
    std::cout << "Array " << name << ": [";
    bool first = true;
    for (int i = 0; i <= 9; ++i) {
        if (word & (1 << i)) {
            if (!first) std::cout << ", ";
            std::cout << i;
            first = false;
        }
    }
    std::cout << "]" << std::endl;
}

Word processWords(Word a, Word b, Word c, Word d) {
    Word result = (a & b) & ~(c | d); // E = (A && B) \ (C || D)
    return result;
}

int main() {
    Word a = inputWord('A');
    Word b = inputWord('B');
    Word c = inputWord('C');
    Word d = inputWord('D');

    Word e = processWords(a, b, c, d);

    outputWord('A', a);
    outputWord('B', b);
    outputWord('C', c);
    outputWord('D', d);
    std::cout << "Result is array E: E = (A && B) \\ (C || D)" << std::endl;
    outputWord('E', e);

    return 0;
}
