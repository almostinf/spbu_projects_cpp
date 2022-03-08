#ifndef SPBU_PROJECTS_CPP_DATABASE_H
#define SPBU_PROJECTS_CPP_DATABASE_H
#include <iostream>
#include <fstream>

struct data {
    size_t days;
    size_t month;
    size_t year;
    data() : days(0), month(0), year(0) {};
    data& operator=(const data& dt) {
        if (this != &dt) {
            days = dt.days;
            month = dt.month;
            year = dt.year;
        }
        return *this;
    };
    //data(size_t d, size_t m, size_t y) : days(d), month(m), year(y) {};
    //data(const data& dt) : days(dt.days), month(dt.month), year(dt.year) {};
    //friend std::ostream& operator<<(std::ostream& out, const data& dt);
};

struct node : data {
//protected:
    struct node *before;
    struct node *left;
    struct node *right;
    size_t count_of_rooms;
    size_t price;
    size_t floor;
    char* address;
    size_t square;
    bool deleted;
    data* dt;
    node() : deleted(false),before(nullptr), left(nullptr), right(nullptr), count_of_rooms(0), dt(nullptr),
    price(0), floor(0), address(new char[20]), square(0) {};
    node& operator=(const node& n) {
        if (this != &n) {
            count_of_rooms = n.count_of_rooms;
            price = n.price;
            floor = n.floor;
            square = n.square;
            deleted = n.deleted;
            delete before;
            before = n.before;
            delete left;
            left = n.left;
            delete right;
            right = n.right;
            delete[] address;
            for (int i = 0; i < 20; ++i)
                address[i] = n.address[i];
            delete dt;
            dt = n.dt;
        }
        return *this;
    }
    ~node() {
        delete before;
        delete left;
        delete right;
        delete[] address;
        delete dt;
    }
//    node(data* d, size_t c_of_r, size_t f, size_t s, char* adr, size_t pr) : dt(d),
//        count_of_rooms(c_of_r), floor(f), square(s), address(adr), price(pr) {};
//    data* get_data() const;
//    size_t get_count_of_rooms() const;
//    size_t get_price() const;
//    size_t get_floor() const;
//    size_t get_square() const;
//    char* get_address() const;
//    bool get_deleted() const;
    //std::ostream& operator<<(std::ostream& out, const node& nd);
};

class DataBase : node {
private:
    node* base;
    static size_t ID;
    static size_t arr_size;
    node** arr;
    //size_t database_len;
public:
    DataBase() : arr(new node*[100]), base(nullptr) { };
    ~DataBase();
    node* get_base() const;
    //size_t len() const;
    void load(const char*) const;
    void save(const char*, const DataBase&);
    void add(node*, node*, node*);
    void del(size_t);
    void print(node*) const;
    void print_n(size_t, node*) const;
    void DT_export(const char*, node*);
    void find(size_t, node*) const;
    //size_t get_arr_size() const;
    friend std::ostream& operator<<(std::ostream&, const DataBase&);
};

std::ostream& operator<<(std::ostream&, const data&);

std::ostream& operator<<(std::ostream&, const node&);

std::ostream& operator<<(std::ostream&, const DataBase&);

#endif //SPBU_PROJECTS_CPP_DATABASE_H
