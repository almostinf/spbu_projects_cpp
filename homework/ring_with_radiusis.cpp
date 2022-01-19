
#include <iostream>


int main() {
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    int* array = new int[n];
    std::cout << "enter elements of array: ";
    for (int i = 0; i < n; ++i)
        std::cin >> array[i];
    int max_sum = INT_MIN;
    int first_max, second_max;
    for (int i = 0; i < n - 1; ++i) {
        if (array[i] + array[i + 1] > max_sum) {
            first_max = array[i];
            second_max = array[i + 1];
            max_sum = array[i] + array[i + 1];
        }
    }
    std::cout << "first and second maximums: " << first_max << ' ' << second_max << '\n';
    delete[] array;
}