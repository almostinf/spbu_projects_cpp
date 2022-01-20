#include <iostream>
#include <fstream>


int main(int argc, const char* argv[]) {
    if (argc < 3) {
        std::cout << "not enough arguments\n";
        return 1;
    }
    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cout << "infile is not open\n";
        return 2;
    }
    std::ofstream outfile(argv[2]);
    if (!outfile) {
        std::cout << "outfile is not open\n";
        infile.close();
        return 3;
    }
    const int size = 1025;
    char str1[size];
    int len1 = 0;
    char str2[size];
    int len2 = 0;
    char symb;
    while ((symb = infile.get()) != '\n') {
        str1[len1++] = symb;
    }
    while ((symb = infile.get()) != EOF) {
        str2[len2++] = symb;
    }
    int leftover = 0;
    if (len1 < len2) {
        std::swap(str1, str2);
        std::swap(len1, len2);
    }
    int temp1 = int(str1[len1 - 1]) - 48;
    int temp2 = int(str2[len2 - 1]) - 48;
    int* result = new int[len1 + 2];
    int count = 0;
    if (temp1 + temp2 >= 10) {
        result[count++] = (temp1 + temp2) % 10;
        leftover = 1;
    }
    else result[count++] = temp1 + temp2;
    int dif = len1 - len2;
    for (int i = len1 - 2; i >= 0; --i) {
        temp1 = int(str1[i]) - 48;
        if (i == 0) {
            if (len1 != len2) temp2 = 0;
            else temp2 = int(str2[i - dif]) - 48;
            if (temp1 + temp2 + leftover >= 10) {
                result[count++] = (temp1 + temp2 + leftover) % 10;
                result[count++] = 1;
            }
            else {
                result[count++] = (temp1 + temp2 + leftover) % 10;
            }
        }else if (len1 - 2 - i < len2 - 1) {
            temp2 = int(str2[i - dif]) - 48;
            result[count++] = (temp1 + temp2 + leftover) % 10;
            leftover = (temp1 + temp2 + leftover >= 10) ? 1 : 0;
        }
        else if (len1 - 2 - i >= len2 - 1) {
            result[count++] = (temp1 + leftover) % 10;
            leftover = (temp1 + leftover >= 10) ? 1 : 0;
        }
    }
    for (int i = count - 1; i >= 0; --i)
        outfile << result[i];
    delete[] result;
    infile.close();
    outfile.close();
}

