// SomePointers.cpp Project
// Code is incomplete but will run

#include <iostream>

int main() {
    const int ARRAY_SIZE = 10;
    const int LAST_ARRAY_ELEM_INDEX = 9;

    char* p_aChars = new char[ARRAY_SIZE];
    int* p_aIntegers = new int[ARRAY_SIZE];

    std::cout << "Pointer Project\n";

    // Comment out the code that initializes the character and integer arrays using #if 0 ... #endif
#if 0
    p_aChars[0] = 'A';
    p_aChars[1] = 'B';
    p_aChars[2] = 'C';
    p_aChars[3] = 'C';
    p_aChars[4] = 'E';
    p_aChars[5] = 'F';
    p_aChars[6] = 'G';
    p_aChars[7] = 'G';
    p_aChars[8] = 'I';
    p_aChars[9] = 'J';

    p_aIntegers[0] = 100;
    p_aIntegers[1] = 101;
    p_aIntegers[2] = 102;
    p_aIntegers[3] = 103;
    p_aIntegers[4] = 104;
    p_aIntegers[5] = 105;
    p_aIntegers[6] = 106;
    p_aIntegers[7] = 107;
    p_aIntegers[8] = 108;
    p_aIntegers[9] = 109;
#endif

    // Character Pointer Code
    char* p_c = p_aChars;

    // Write a while loop that initializes the values of the array pointed to by p_aChars using pointer p_c
    char c = 'A';
    while (p_c <= &(p_aChars[LAST_ARRAY_ELEM_INDEX])) {
        *p_c = c;
        p_c++;
        c++;
    }

    // Display Character Array
    std::cout << "Char Array" << std::endl;
    p_c = p_aChars;
    while (p_c <= &(p_aChars[LAST_ARRAY_ELEM_INDEX])) {
        std::cout << "p_c: " << static_cast<void*>(p_c) << ":  *p_c: " << *p_c << std::endl;
        p_c++;
    }

    // Integer Pointer Code
    int* p_i = p_aIntegers;

    // Write a while loop that initializes the values of the array pointed to by p_aIntegers using pointer p_i
    int i = 100;
    while (p_i <= &(p_aIntegers[LAST_ARRAY_ELEM_INDEX])) {
        *p_i = i;
        p_i++;
        i++;
    }

    // Display Integer Array
    std::cout << "Integer Array" << std::endl;
    p_i = p_aIntegers;
    while (p_i <= &(p_aIntegers[LAST_ARRAY_ELEM_INDEX])) {
        std::cout << "p_i: " << p_i << ":  *p_i: " << *p_i << std::endl;
        p_i++;
    }

    return 0;
}
