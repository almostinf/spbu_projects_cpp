#include <iostream>

void letters(int num) {
    if (num == 1000) std::cout << 'M';
    else if (num == 500) std::cout << 'D';
    else if (num == 100) std::cout << 'C';
    else if (num == 50) std::cout << 'L';
    else if (num == 10) std::cout << 'X';
    else if (num == 9) std::cout << "IX";
    else if (num == 5) std::cout << 'V';
    else if (num == 4) std::cout << "IV";
    else if (num == 1) std::cout << 'I';
}
void translate(int num) {
    int temp_num = num;
    if (num / 1000 > 0 ) {
        int deg = num / 1000;
        num %= 1000;
        while (deg) {
            letters(1000);
            deg--;
        }
    }
    if (num / 500)
}
//int size = 0;
//int temp = num;
//while (temp /= 10) size++;
//size++;
//char c_num[size];
//int temp_size = size - 1;
//while (num) {
//    c_num[temp_size] = char('0' + num % 10);
//    temp_size--;
//    num /= 10;
//}
//for (int i = 0; i < size; ++i) {
//    int razryad = c_num[i] - '0';
//    while (razryad) {
//
//        razryad--;
//    }
//}
void translate(char* num, int size) {
    int out_num = 0;
    bool check = false;
    for (int i = 0; i < size; ++i) {
        if (check) {
            check = false;
            continue;
        }
        if (num[i] == 'M') out_num += 1000;
        else if (num[i] == 'D') out_num += 500;
        else if (num[i] == 'C') out_num += 100;
        else if (num[i] == 'L') out_num += 50;
        else if (num[i] == 'I' and i + 1 < size and num[i + 1] == 'X') {
            out_num += 9;
            check = true;
        }
        else if (num[i] == 'X') out_num += 10;
        else if (num[i] == 'I' and i + 1 < size and num[i + 1] == 'V') {
            out_num += 4;
            check = true;
        }
        else if (num[i] == 'V') out_num += 5;
        else if (num[i] == 'I') out_num += 1;
    }
    std::cout << out_num << '\n';
}

int main() {
    int num1 = 12340;
    char num2[5] = "CLIV";
    translate(num2, 4);
    translate(num1);
}