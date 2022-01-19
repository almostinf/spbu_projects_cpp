#include <iostream>
#include <fstream>
//add more controls later
int main(int argc, const char* argv[]) {
    std::ifstream* files = new std::ifstream[argc - 1];
    if (argc < 4) {
        std::cout << "Not enough arguments\n";
        delete[] files;
        return 1;
    }
    std::ofstream result(argv[argc - 1]);
    if (!result) {
        std::cout << "error. not find result file \n";
        delete[] files;
        return 2;
    }
    for (int i = 0; i < argc - 1; ++i) {
        files[i].open(argv[i + 1]);
        char symb;
        while ((symb = files[i].get()) != EOF) {
            result << symb;
        }
        files[i].close();
    }
    delete[] files;
    return 0;
}
