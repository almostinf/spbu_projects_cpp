#include <iostream>
#include <fstream>

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cout << "not enough arguments\n";
        return 1;
    }
    std::fstream file(argv[1], std::ios::binary | std::ios::in | std::ios::out );
    if (!file) {
        std::cout << "file is not open\n";
        return 2;
    }
    int arr[256] = { 0 };
    char symb;
    while ((symb = file.get()) != EOF) {
        file.seekp(-1, file.cur);
        file.put(char(48 + arr[int(symb)]++));
        file.flush();
    }
    file.close();
}

