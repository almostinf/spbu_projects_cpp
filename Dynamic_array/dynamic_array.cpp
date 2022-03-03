#include "dyn_array.h"

dyn_array::dyn_array(int64_t value, uint64_t size) : capacity_(CAPACITY_DEFAULT), size_(size) {
    if (capacity_ < size)
        capacity_ += size;
    arr_ = new int64_t[capacity_];
    for (uint64_t i = 0; i < size; ++i)
        arr_[i] = value;
}

dyn_array::dyn_array(uint64_t size) : size_(size), capacity_(CAPACITY_DEFAULT) {
    if (capacity_ <= size) capacity_ += size;
    arr_ = new int64_t[capacity_]{0};
}

dyn_array::dyn_array(const dyn_array &d_arr) {
    size_ = d_arr.size_;
    arr_ = new int64_t[d_arr.capacity_];
    for (uint64_t i = 0; i < size_; ++i)
        arr_[i] = d_arr.arr_[i];
}

dyn_array &dyn_array::operator=(const dyn_array &d_arr) {
    if (this != &d_arr) {
        size_ = d_arr.size_;
        delete[] arr_;
        capacity_ = d_arr.capacity_;
        arr_ = new int64_t[capacity_];
        for (uint64_t i = 0; i < size_; ++i)
            arr_[i] = d_arr.arr_[i];
    }
    return *this;
}

int64_t &dyn_array::operator[](uint64_t ind) {
    assert(ind < size_ and ind >= 0);
    return arr_[ind];
}

dyn_array operator+(const dyn_array& left, const dyn_array& right) {
    dyn_array d_arr(left.size_ + right.size_);
    for (uint64_t i = 0; i < left.size_; ++i)
        d_arr.arr_[i] = left.arr_[i];
    for (uint64_t i = left.size_; i < left.size_ + right.size_; ++i)
        d_arr.arr_[i] = right.arr_[i - left.size_];
    return d_arr;
}

//dyn_array &dyn_array::operator+(const dyn_array &sub_d_arr) {
//    dyn_array* p_d_arr = new(dyn_array);
//    p_d_arr->size_ = sub_d_arr.size_ + sub_d_arr.size_;
//    if (p_d_arr->capacity_ <= size_ + sub_d_arr.size_) p_d_arr->capacity_ += (size_ + sub_d_arr.size_);
//    for (uint64_t i = 0; i < size_; ++i)
//        p_d_arr->arr_[i] = arr_[i];
//    for (uint64_t i = size_; i < size_ + sub_d_arr.size_; ++i)
//        p_d_arr->arr_[i] = sub_d_arr.arr_[i - size_];
//    return p_d_arr;
//}

std::ostream& operator<<(std::ostream& out, dyn_array& d_arr) {
    for (uint64_t i = 0; i < d_arr.size(); ++i)
        out << d_arr[i] << ' ';
    out << '\n';
    return out;
}

uint64_t dyn_array::size() const {
    return size_;
}

uint64_t dyn_array::capacity() const {
    return capacity_;
}

void dyn_array::reallocate() {
    int64_t* p_arr = arr_;
    capacity_ *= 2;
    arr_ = new int64_t[capacity_];
    for (uint64_t i = 0; i < size_; ++i)
        arr_[i] = p_arr[i];
    delete[] p_arr;
}

void dyn_array::add(int64_t value) {
    if (size_ + 1 >= capacity_) reallocate();
    arr_[size_++] = value;
}

void dyn_array::remove(uint64_t ind) {
    // 'ind' minus 'index from array' equal one
    assert(ind >= 1 and ind <= size_);
    int64_t* p_arr = arr_;
    arr_ = new int64_t[capacity_];
    for (uint64_t i = 0; i < ind - 1; ++i)
        arr_[i] = p_arr[i];
    for (uint64_t i = ind; i < size_; ++i)
        arr_[i - 1] = p_arr[i];
    delete[] p_arr;
    size_--;
}

void dyn_array::insert(uint64_t ind, int64_t value) {
    // 'ind' minus 'index from array' equal one
    assert(ind >= 1 and ind <= size_);
    int64_t* p_arr = arr_;
    arr_ = new int64_t[capacity_];
    for (uint64_t i = 0; i < ind - 1; ++i)
        arr_[i] = p_arr[i];
    arr_[ind - 1] = value;
    for (uint64_t i = ind - 1; i < size_; ++i)
        arr_[i + 1] = p_arr[i];
    if (size_ + 1 >= capacity_) reallocate();
    size_++;
    delete[] p_arr;
}

void dyn_array::set_n_zeros(uint64_t size) {
    while (capacity_ < size) reallocate();
    size_ = size;
    for (uint64_t i = 0; i < size_; ++i)
        arr_[i] = 0;
}

void dyn_array::clear() {
    delete[] arr_;
    arr_ = new int64_t[capacity_];
    size_ = 0;
}

