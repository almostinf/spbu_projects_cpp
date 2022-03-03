#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile("C://My_Projects_C++//spbu_projects_cpp//homework//replace_latex//latex_code.txt");
    std::ofstream outfile("C://My_Projects_C++//spbu_projects_cpp//homework//replace_latex//vhanged_file.txt");
    if (!infile.is_open()) {
        std::cout << "error!\n";
        exit(-1);
    }
    char byte;
    bool check = false;
    while ((byte = infile.get()) != EOF) {
        if (byte == '$' and infile.peek() == '$' and !check) {
            infile.seekg(1,std::ios::cur);
            outfile << "<math>";
            check = true;
        } else if (byte == '$' and infile.peek() == '$' and check) {
            infile.seekg(1,std::ios::cur);
            outfile << "</math>";
            check = false;
        } else if (byte == '$' and infile.peek() != '$' and !check) {
            outfile << "<math>";
            check = true;
        } else if (byte == '$' and infile.peek() != '$' and check) {
            outfile << "</math>";
            check = false;
        } else
            outfile << byte;
    }
    infile.close();
    outfile.close();
}

