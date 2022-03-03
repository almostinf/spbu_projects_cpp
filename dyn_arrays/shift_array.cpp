//Написать функцию
//void shiftArray(int A[], int n, int k)
//которая осуществляет циклический сдвиг элементов массива на k влево. Например, если был массив
//A[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//То после вызова функции shiftArray(A, 10, 3); Должен получиться массив {3, 4, 5, 6, 7, 8, 9, 0, 1,2};

#include <iostream>
#include <cmath>
void shiftArray(const int arr[], int n, int k) {
    int k_ = k % n;
    int tmp_k_arr[k_];
    int tmp_n_arr[n - k_];
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (i < k_)
            tmp_k_arr[i] = arr[i];
        else {
            tmp_n_arr[count] = arr[i];
            count++;
        }
    }
    int count_k = 0;
    for (int i = 0; i < n; ++i) {
        if (count) {
            std::cout << tmp_n_arr[i] << ' ';
            count--;
        } else {
            std::cout << tmp_k_arr[count_k] << ' ';
            count_k++;
        }
    }
}
void shiftArray_advanced(int arr[], int n, int k) {
    int k_ = k % n;
    if (k_ < n/2) {
        for (int i = 0; i < k_; ++i) {
            std::swap(arr[i],arr[k_ + i]);
        }
    } else {
        for (int i = 0; i < n - k_; ++i) {
            std::swap(arr[i], arr[n - k_ + i]);
        }
    }
    for (int i = n - std::abs(n - k_ - k_); i < n; ++i) {
        int temp_k;
        if (k_ > n/2)
            temp_k = n - k_;
        else
            temp_k  = k_;
        int j = i - 1;
        while (temp_k) {
            std::swap(arr[j], arr[j + 1]);
            temp_k--;
            j--;
        }
    }
}
int main() {
    int n, k;
    std::cout << "enter n, k: ";
    std::cin >> n >> k;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = i;
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
    //shiftArray(arr, n, k);
    shiftArray_advanced(arr,n,k);
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    delete[] arr;
}
