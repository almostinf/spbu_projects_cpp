#include <iostream>

int find_left_brackets(char* brackets, int n_brackets, char symb) {
    for (int i = 0; i < n_brackets; ++i)
        if (symb == brackets[i]) return i;
    return -1;
}

int find_right_brackets(char* brackets, int n_brackets, char symb) {
    for (int i = n_brackets; i < 2 * n_brackets; ++i)
        if (symb == brackets[i]) return i;
        return -1;
}

bool is_brakets_right(char *str, int n_word, char* brackets, int n_brackets) {
    int stack[n_word];
    int count = 0;
    for (int i = 0; i < n_word; ++i) {
        int ind = find_left_brackets(brackets, n_brackets / 2, str[i]) != -1 ? find_left_brackets(brackets, n_brackets / 2, str[i]) :
                find_right_brackets(brackets, n_brackets / 2, str[i]);
        if (ind != -1 and ind < n_brackets / 2) stack[count++] = n_brackets - 2 - ind;
        else if (ind != -1 and ind >= n_brackets / 2)
            if (str[i] == brackets[stack[count - 1]])
                count--;
            else
                return false;
    }
    if (count != 0) return false;
    return true;
}
struct word {
    int size;
    char* w = new char[size];
    word(int sz, char* str) : size(sz), w(str) {};
};

void test(word* tests_example,int count_tests,char* brackets, int n_brackets) {
    for (int i = 0; i < count_tests; ++i) {
        if (is_brakets_right(tests_example[i].w, tests_example[i].size, brackets, n_brackets))
            std::cout << "Test " << i << " success\n";
        else
            std::cout << "Test " << i << " mistake\n";
    }
}


int main() {
    const int count_tests = 7;
    word tests_example[7]{ {1, "("}, {1, ")"}, {6, "(dsfa)"}, {2, ")("}};
    //char ** tests_example{"(", ")", "()", "(dsfa)", ")(", "afjk", "))ki"};
    const int n_word = 11;
    char str[n_word] = "()sdjsdfal";
    const int n_brackets = 5;
    char brackets[n_brackets] = "([])";

}

