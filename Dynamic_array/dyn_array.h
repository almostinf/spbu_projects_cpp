#ifndef SPBU_PROJECTS_CPP_DYN_ARRAY_H
#define SPBU_PROJECTS_CPP_DYN_ARRAY_H
#include <iostream>
#include <cassert>

#define CAPACITY_DEFAULT 100

class dyn_array {
private:
    uint64_t size_;
    uint64_t capacity_;
    int64_t* arr_;
    void reallocate(uint64_t);
public:
    dyn_array() : size_(0), capacity_(CAPACITY_DEFAULT), arr_(new int64_t[capacity_]) {};
    dyn_array(uint64_t, int64_t);
    dyn_array(const dyn_array&);
    ~dyn_array();

    dyn_array& operator=(const dyn_array&);
    int64_t& operator[](uint64_t);
    dyn_array operator+=(const dyn_array&);
    friend dyn_array operator+(const dyn_array&, const dyn_array&);
    friend std::ostream& operator<<(std::ostream&, dyn_array&);

    void add(int64_t);
    void remove(uint64_t);
    void insert(uint64_t, int64_t);
    uint64_t capacity() const;
    uint64_t size() const;
    void set_n_zeros(uint64_t);
    void clear();
    uint64_t find_binary(int64_t) const;
    uint64_t find(int64_t) const;
    void sort();
};

std::ostream& operator<<(std::ostream&, dyn_array&);
dyn_array operator+(const dyn_array&, const dyn_array&);

#endif //SPBU_PROJECTS_CPP_DYN_ARRAY_H
