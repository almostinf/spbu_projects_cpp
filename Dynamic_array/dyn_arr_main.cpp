#include "dyn_array.h"

int main() {
    dyn_array d_arr(5, 10);
    std::cout << "After creation: ";
    std::cout << d_arr;
    d_arr.add(100);
    std::cout << "After using add: ";
    std::cout << d_arr;
    d_arr[10] = 5;
    std::cout << "After assignment: ";
    std::cout << d_arr;
    std::cout << "Capacity: " << d_arr.capacity() << '\n';
    for (uint64_t i = 0; i < d_arr.size(); ++i)
        d_arr[i] = i;
    std::cout << "After assignment all elements: ";
    std::cout << d_arr;
    d_arr.remove(3);
    std::cout << "After using remove: ";
    std::cout << d_arr;
    d_arr.insert(3, 4);
    std::cout << "After using insert: ";
    std::cout << d_arr;
    dyn_array sub_d_arr(3, 5);
    dyn_array new_d_arr = d_arr + sub_d_arr;
    std::cout << "After concatenation: ";
    std::cout << new_d_arr;
    d_arr.set_n_zeros(5);
    std::cout << "After using set_n_zeros: ";
    std::cout << d_arr;
    d_arr.clear();
    std::cout << "After using clear, size: ";
    std::cout << d_arr.size() << '\n';
    dyn_array out_range(6, 99);
    std::cout << "Before trying to get out of capacity: ";
    std::cout << out_range;
    std::cout << "size: " << out_range.size() << "\ncapacity: " << out_range.capacity() << '\n';
    out_range.add(56);
    out_range.add(57);
    std::cout << "After trying to get out of capacity: ";
    std::cout << out_range;
    std::cout << "size: " << out_range.size() << "\ncapacity: " << out_range.capacity() << '\n';
}

