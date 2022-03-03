//Составьте программу, читающую целое положительное число, не превышающее миллиард, и
//выводящее это же число на естественном языке.
//
//Входные данные: 1024.
//
//Выход: одна тысяча двадцать четыре.

#include <iostream>
#include <cstring>
#include <clocale>


int main() {
    setlocale(LC_ALL, "ru");
    int64_t num;
    char main_word[15][100];
    std::cout << "enter num: ";
    std::cin >> num;
    int* array = new int[15];
    for (int i = 0; i < 10; ++i)
        array[i] = -1;
    int iter = 0;
    while (num) {
        array[iter] = num % 10;
        iter++;
        num /= 10;
    }
    int* sub_array = new int[iter];
    for (int i = 0; i < iter; ++i)
        sub_array[i] = array[i];
    int count = 1;
    for (int i = 0; i < iter; ++i) {
        if (i == 3) {
            if (sub_array[i] == 0)
                strcpy_s(main_word[i], sizeof main_word[i] + 10, "ноль");
            else if (sub_array[i] == 1)
                strcpy_s(main_word[i], sizeof main_word[i] + 10, "одна");
            else if (sub_array[i] == 2)
                strcpy_s(main_word[i], sizeof main_word[i] + 10, "две");
            else if (sub_array[i] == 3)
                strcpy_s(main_word[i], sizeof main_word[i] + 10, "три");
            else if (sub_array[i] == 4)
                strcpy_s(main_word[i], sizeof main_word[i] + 10, "четыре");
            else if (sub_array[i] == 5)
                strcpy_s(main_word[i], sizeof main_word[i] + 10, "пять");
            else if (sub_array[i] == 6)
                strcpy_s(main_word[i], sizeof main_word[i] + 10, "шесть");
            else if (sub_array[i] == 7)
                strcpy_s(main_word[i], sizeof main_word[i] + 10, "семь");
            else if (sub_array[i] == 8)
                strcpy_s(main_word[i], sizeof main_word[i] + 10, "восемь");
            else if (sub_array[i] == 9)
                strcpy_s(main_word[i], sizeof main_word[i] + 10, "девять");
        }
        else {
            if (count == 1) {
                if (sub_array[i] == 0)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "ноль");
                else if (sub_array[i] == 1)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "один");
                else if (sub_array[i] == 2)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "два");
                else if (sub_array[i] == 3)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "три");
                else if (sub_array[i] == 4)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "четыре");
                else if (sub_array[i] == 5)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "пять");
                else if (sub_array[i] == 6)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "шесть");
                else if (sub_array[i] == 7)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "семь");
                else if (sub_array[i] == 8)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "восемь");
                else if (sub_array[i] == 9)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "девять");
            }
            else if (count == 2) {
                if (sub_array[i] == 0)
                    strcpy_s(main_word[i], sizeof main_word[i] + 10, "ноль");
                else if (sub_array[i] == 1) {
                    if (strcmp(main_word[i - 1], "ноль") == 0)
                        strcpy_s(main_word[i], sizeof main_word[i] + 15, "десять");
                    else if ((strcmp(main_word[i - 1], "один") == 0) or (strcmp(main_word[i - 1], "одна") == 0))
                        strcpy_s(main_word[i], sizeof main_word[i] + 15, "одиннадцать");
                    else if ((strcmp(main_word[i - 1], "два") == 0) or (strcmp(main_word[i - 1], "две") == 0))
                        strcpy_s(main_word[i], sizeof main_word[i] + 15, "двенадцать");
                    else if (strcmp(main_word[i - 1], "три") == 0)
                        strcpy_s(main_word[i], sizeof main_word[i] + 15, "тринадцать");
                    else if (strcmp(main_word[i - 1], "четыре") == 0)
                        strcpy_s(main_word[i], sizeof main_word[i] + 15, "четырнадцать");
                    else if ((strcmp(main_word[i - 1], "пять") == 0))
                        strcpy_s(main_word[i], sizeof main_word[i] + 15, "пятнадцать");
                    else if ((strcmp(main_word[i - 1], "шесть") == 0))
                        strcpy_s(main_word[i], sizeof main_word[i] + 15, "шестнадцать");
                    else if ((strcmp(main_word[i - 1], "семь") == 0))
                        strcpy_s(main_word[i], sizeof main_word[i] + 15, "семнадцать");
                    else if ((strcmp(main_word[i - 1], "восемь") == 0))
                        strcpy_s(main_word[i], sizeof main_word[i] + 15, "восемнадцать");
                    else if ((strcmp(main_word[i - 1], "девять") == 0))
                        strcpy_s(main_word[i], sizeof main_word[i] + 15, "девятнадцать");
                    strcpy_s(main_word[i - 1], sizeof main_word[i - 1], "ноль");
                }
                else if (sub_array[i] == 2)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "двадцать");
                else if (sub_array[i] == 3)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "тридцать");
                else if (sub_array[i] == 4)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "сорок");
                else if (sub_array[i] == 5)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "пятьдесят");
                else if (sub_array[i] == 6)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "шестьдесят");
                else if (sub_array[i] == 7)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "семьдесят");
                else if (sub_array[i] == 8)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "восемьдесят");
                else if (sub_array[i] == 9)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "девяносто");
            }
            else if (count == 3) {
                if (sub_array[i] == 0)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "ноль");
                else if (sub_array[i] == 1)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "сто");
                else if (sub_array[i] == 2)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "двести");
                else if (sub_array[i] == 3)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "триста");
                else if (sub_array[i] == 4)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "четыреста");
                else if (sub_array[i] == 5)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "пятьсот");
                else if (sub_array[i] == 6)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "шестьсот");
                else if (sub_array[i] == 7)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "семьсот");
                else if (sub_array[i] == 8)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "восемьсот");
                else if (sub_array[i] == 9)
                    strcpy_s(main_word[i], sizeof main_word[i] + 15, "девятьсот");
                count = 0;
            }
        }
        count++;
    }
    char words[1000] = "";
    for (int i = iter - 1; i >= 0; --i) {
        if (((strcmp(main_word[i], "ноль") != 0)) and i != 3 and i != 6 and i != 9) {
            strcat_s(words, sizeof words, main_word[i]);
            strcat_s(words, sizeof words, " ");
        }
        else if ((strcmp(main_word[i], "ноль") != 0) and (i == 3 or i == 6 or i == 9))
        {
            if (i == 3 and (strcmp(main_word[i], "одна") == 0)) {
                strcat_s(words, sizeof words, main_word[i]);
                strcat_s(words, sizeof words, " тысяча ");
            }
            else if (i == 3 and ((strcmp(main_word[i], "две") == 0) or (strcmp(main_word[i], "три") == 0) or
            (strcmp(main_word[i], "четыре") == 0))) {
                strcat_s(words, sizeof words, main_word[i]);
                strcat_s(words, sizeof words, " тысячи ");
            }
            else if (i == 3 and ((strcmp(main_word[i], "пять") == 0) or (strcmp(main_word[i], "шесть") == 0) or
            (strcmp(main_word[i], "семь") == 0) or (strcmp(main_word[i], "восемь") == 0) or (strcmp(main_word[i], "девять") == 0))) {
                strcat_s(words, sizeof words, main_word[i]);
                strcat_s(words, sizeof words, " тысяч ");
            }
            else if (i == 6 and (strcmp(main_word[i], "один") == 0)) {
                strcat_s(words, sizeof words, main_word[i]);
                strcat_s(words, sizeof words, " миллион ");
            }
            else if (i == 6 and ((strcmp(main_word[i], "два") == 0) or (strcmp(main_word[i], "три") == 0) or
            (strcmp(main_word[i], "четыре") == 0))) {
                strcat_s(words, sizeof words, main_word[i]);
                strcat_s(words, sizeof words, " миллиона ");
            }
            else if (i == 6 and ((strcmp(main_word[i], "пять") == 0) or (strcmp(main_word[i], "шесть") == 0) or
            (strcmp(main_word[i], "семь") == 0) or (strcmp(main_word[i], "восемь") == 0) or (strcmp(main_word[i], "девять") == 0))) {
                strcat_s(words, sizeof words, main_word[i]);
                strcat_s(words, sizeof words, " миллионов ");
            }
            else if (i == 9 and (strcmp(main_word[i], "один") == 0)) {
                strcat_s(words, sizeof words, main_word[i]);
                strcat_s(words, sizeof words, " миллиард ");
            }
            else if (i == 9 and ((strcmp(main_word[i], "два") == 0) or (strcmp(main_word[i], "три") == 0) or
            (strcmp(main_word[i], "четыре") == 0))) {
                strcat_s(words, sizeof words, main_word[i]);
                strcat_s(words, sizeof words, " миллиарда ");
            }
            else if (i == 9 and ((strcmp(main_word[i], "пять") == 0) or (strcmp(main_word[i], "шесть") == 0) or
            (strcmp(main_word[i], "семь") == 0) or (strcmp(main_word[i], "восемь") == 0) or (strcmp(main_word[i], "девять") == 0))) {
                strcat_s(words, sizeof words, main_word[i]);
                strcat_s(words, sizeof words, " миллиардов ");
            }
        }
        else if ((strcmp(main_word[i], "ноль") == 0) and (i == 3 or i == 6 or i == 9)) {
            if (i == 3)
                strcat_s(words, sizeof words, " тысяч ");
            else if (i == 6)
                strcat_s(words, sizeof words, " миллионов ");
            else if (i == 9)
                strcat_s(words, sizeof words, " миллиардов ");
        }
    }
    std::cout << words << '\n';
    delete[] sub_array;
    delete[] array;
}