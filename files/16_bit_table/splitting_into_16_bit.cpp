#include <iostream>
#include <fstream>
void dec_to_hex_for_symb(int num, char symb[3]) {
    int temp = num;
    int deg = 1;
    while ((temp /= 16) != 0)
        deg *= 16;
    int count = 0;
    if (deg == 1) symb[count++] = '0';
    while (deg) {
        std::cout << num << ' ' << num / deg << '\n';
        if (num / deg > 9)
            symb[count++]= static_cast<char>(55 + num / deg);
        else
            symb[count++]= static_cast<char>(48 + num / deg);
        num %= deg;
        deg /= 16;
    }
    symb[3] = 0;
}

int dec_to_hex(int num, char symb[10]) {
    int temp = num;
    int deg = 1;
    while ((temp /= 16) != 0)
        deg *= 16;
    int count = 0;
    while (deg) {
        if (num / deg > 9)
            symb[count++]= static_cast<char>(55 + num / deg);
        else
            symb[count++]= static_cast<char>(48 + num / deg);
        num %= deg;
        deg /= 16;
    }
    return count;
}
void print_bin(int num, std::ofstream& outfile) {
    char string[10];
    int start = dec_to_hex(num, string);
    int iter = 0;
    for (int i = 0; i < 10; ++i) {
        if (i >= 10 - start)
            outfile << string[iter++];
        else
            outfile << '0';
    }
    outfile << ": ";
}
int main() {
    std::ifstream file("C:\\My_Projects_C++\\spbu_projects_cpp\\homework\\16_bit_table\\source.txt", std::ios::binary);
    std::ofstream out_file("C:\\My_Projects_C++\\spbu_projects_cpp\\homework\\16_bit_table\\out.txt",std::ios::binary);
    char byte;
    if (!file.is_open()) {
        std::cout << "error \n";
        exit(1);
    }
    int count_in = 0;
    int const temp_count = 100;
    char string[temp_count];
    while ((byte = file.get()) != EOF) {
        string[count_in++] = byte;
    }
    string[count_in] = 0;
    char substring[17];
    int count = 0;
    int iter_substring = 0;
    int num = 16;
    print_bin(num,out_file);
    while (true) {
        if (string[count] == '\0') {
            while (count % 16 != 0) {
                if (count % 8 == 0)
                    out_file << "| ";
                count++;
                out_file << "   ";
            }
            out_file << ' ';
            for (int j = 0; j < iter_substring; ++j)
                out_file << substring[j];
            out_file << '\n';
            break;
        }
        if (count % 16 == 0 and count != 0) {
            out_file << ' ';
            for (int j = 0; j < iter_substring; ++j)
                out_file << substring[j];
            out_file << '\n';
            num += 16;
            print_bin(num,out_file);
            iter_substring = 0;
        } else if (count % 8 == 0 and count != 0)
            out_file << "| ";
        //if (string[count] == '\n') string[count] = ' ';
        if (static_cast<int>(string[count]) <= 32) {
            substring[iter_substring++] = '.';
        } else
            substring[iter_substring++] = string[count];
        char symb[3];
        dec_to_hex_for_symb(static_cast<int>(string[count]), symb);
        out_file << symb << ' ';
        count++;
    }
    file.close();
    out_file.close();
}

