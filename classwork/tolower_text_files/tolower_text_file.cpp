#include <iostream>
#include <fstream>
#include <charconv>
int main(int argc, char * argv[]) {
    std::ifstream* files = new std::ifstream[argc - 2];
    files[2].open((argv[1]));
    if (argc < 3) {
        std::cout << "wrong input\n";
        std::cout << "usage \n";
        return -1;
    }
    char* infile_name = argv[1];
    std::cout << infile_name << '\n';
    char* outfile_name = argv[2];
    std::cout << outfile_name << '\n';
    std::ifstream infile(infile_name);
    std::ofstream outfile(outfile_name);
    if(!infile.is_open()) {
        std::cout << "infile isn't open\n";
        return -1;
    }
    if(!outfile.is_open()) {
        std::cout << "outfile isn't open\n";
        return -1;
    }
    char x;
    while ((x = infile.get()) != EOF) {
        if (x >= 'a' and x <= 'z')
            outfile << static_cast<char>(x - 'a' + 'A');
        else if (x >= 'A' and x <= 'Z')
            outfile << static_cast<char>(x - 'A' + 'a');
        else
            outfile << x;
    }
    infile.close();
    outfile.close();
}

