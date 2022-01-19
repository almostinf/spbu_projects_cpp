#include <iostream>
#include <fstream>

// очень некрасивое решение, намного лучше будет делать с динамическим массивом
int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cout << "not enough arguments\n";
        return 1;
    }
    std::fstream infile(argv[1], std::ios_base::in);
    if (!infile) {
        std::cout << "infile is not open\n";
        return 2;
    }
    const int size = 1000;
    char first_str[size];
    char second_str[size];
    char symb;
    int positions1 = 0;
    while ((symb = infile.get()) != '\n') {
        first_str[positions1++] = symb;
    }
    first_str[positions1] = '\0';
    int positions2 = 0;
    while ((symb = infile.get()) != EOF) {
        second_str[positions2++] = symb;
    }
    second_str[positions2] = '\0';
    infile.close();
    infile.open(argv[1], std::ios_base::app);
    infile << "\n------------------------\n";
    int position = (positions1 > positions2) ? positions1 : positions2;
    char temp1[size];
    char temp2[size];
    if (positions1 > positions2) {
        for (int i = 0; i < positions1; ++i) {
            if (i < (positions1 - positions2)) {
                temp2[i] = '0';
                temp1[i] = first_str[i];
            }
            else {
                temp2[i] = second_str[i - ((positions1 - positions2))];
                temp1[i] = first_str[i];
            }
        }
    }
    else {
        for (int i = 0; i < positions2; ++i) {
            if (i < (positions2 - positions1)) {
                temp1[i] = '0';
                temp2[i] = second_str[i];
            }
            else {
                temp1[i] = first_str[i - ((positions1 - positions2))];
                temp2[i] = second_str[i];
            }
        }
    }
    int result[size];
    int count = 0;
    temp1[position] = '\0';
    temp2[position] = '\0';
    int first_digit = int(temp1[position - 1]) - 48;
    int second_digit = int(temp2[position - 1]) - 48;
    int leftover = 0;
    if (first_digit + second_digit == 2) {
        leftover = 1;
        result[count++] = 0;
    }
    else result[count++] = first_digit + second_digit;
    for (int i = position - 2; i >= 0; --i) {
        if (position - 2 - i < positions1 and position - 2 - i < positions2) {
            first_digit = int(temp1[i]) - 48;
            second_digit = int(temp2[i]) - 48;
            if (first_digit + second_digit + leftover == 2) {
                leftover = 1;
                result[count++] = 0;
            }
            else if (first_digit + second_digit + leftover == 3) {
                leftover = 1;
                result[count++] = 1;
            }
            else {
                result[count++] = first_digit + second_digit + leftover;
                leftover = 0;
            }
        }
        else if (position - 1 - i < positions1 and position - 1 - i > positions2) {
            first_digit = int(first_str[i]) - 48;
            if (first_digit + leftover == 2) {
                leftover = 1;
                result[count++] = 0;
            }
            else {
                leftover = 0;
                result[count++] = first_digit + leftover;
            }
        }
        else if (position - 1 - i > positions1 and position - 1 - i < positions2)
        {
            second_digit = int(second_str[i]) - 48;
            if (second_digit + leftover == 2) {
                leftover = 1;
                result[count++] = 0;
            }
            else {
                leftover = 0;
                result[count++] = second_digit + leftover;
            }
        }
    }
    for (int i = count - 1; i >= 0; --i) {
        infile << result[i];
    }
    infile.close();
}