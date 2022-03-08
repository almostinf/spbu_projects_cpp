#include "DataBase.h"

size_t DataBase::arr_size = 0;
size_t DataBase::ID = 0;

DataBase::~DataBase() {
    for (int i = 0; i < arr_size; ++i)
        delete arr[i];
    delete[] arr;
    delete base;
    delete[] arr;
}

node *DataBase::get_base() const {
    return base;
}

std::ostream& operator<<(std::ostream& out, const data& dt) {
    out << "\nData: " << dt.days << '.' << dt.month << '.' << dt.year << '\n';
    return out;
}

std::ostream& operator<<(std::ostream& out, const node& nd) {
    out << nd.price << ',' << nd.count_of_rooms << ',' <<
    nd.floor << ',' << nd.square << ',' << nd.address << *nd.dt;
    return out;
}

std::ostream& operator<<(std::ostream& out, const DataBase& DB) {
    for (size_t i = 0; i < DataBase::arr_size; ++i) {
        if (DB.arr[i]->deleted)
            continue;
        out << i << ',' << *DB.arr[i] << '\n';
    }
    return out;
};

//size_t DataBase::len() const {
//    return database_len;
//}
//
//size_t DataBase::get_arr_size() const {
//    return arr_size;
//}
//
//char *node::get_address() const {
//    return address;
//}
//
//size_t node::get_count_of_rooms() const {
//    return count_of_rooms;
//}
//
//bool node::get_deleted() const {
//    return deleted;
//}
//
//data* node::get_data() const {
//    return dt;
//}
//
//size_t node::get_floor() const {
//    return floor;
//}
//
//size_t node::get_square() const {
//    return square;
//}
//
//size_t node::get_price() const {
//    return price;
//}

void DataBase::load(const char *filename) const {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw "file is not open\n";
        //return;
    }
    char byte;
    while ((byte = file.get()) != EOF)
        std::cout << byte;
    file.close();
}

void DataBase::save(const char *filename, const DataBase& dt) {
    std::ofstream file(filename, std::ios::app);
    file << dt;
    file.close();
}

void DataBase::add(node * current, node * current_base, node *before) {
    static bool check = false;
    if (arr_size == 0) {
        base = current;
        arr[ID++] = current;
        arr_size++;
        return;
    }
    if (current_base->price > current->price and !current_base->before) {
        node* p_cur_base = current_base;
        base = current;
        base->before = nullptr;
        base->right = p_cur_base;
        base->right->before = base;
        arr[ID++] = current;
        arr_size++;
        return;
    } else if (current_base->right and !current_base->left and !current_base->right->right and
                                                                current->price > current_base->right->price) {
        current_base->left = current;
        current_base->left->before = current_base;
        arr[ID++] = current;
        arr_size++;
        check = true;
        return;
    } else if (current_base->right and !current_base->left and !current_base->right->right and
                                                                current->price < current_base->right->price) {
        std::swap(current_base->left, current_base->right);
        current_base->right = current;
        current_base->right->before = current_base;
        arr[ID++] = current;
        arr_size++;
        check = true;
        return;
    } else if (current_base->right and current_base->left and current->price < current_base->right->price) {
        node* p_cur_base_right = current_base->right;
        node * p_cur_base_left = current_base->left;
        current_base->right = current;
        current_base->right->before = current_base;
        current_base->right->right = p_cur_base_right;
        current_base->right->right->before = current_base->right;
        current_base->right->left = p_cur_base_left;
        current_base->right->left->before = current_base->right;
        current_base->left = nullptr;
        arr[ID++] = current;
        arr_size++;
        check = true;
        return;
    } else if (current_base->left and current_base->left->price > current->price) {
        node* p_cur_base_left = current_base->left;
        current_base->left = current;
        current_base->left->before = current_base;
        current_base->left->right = p_cur_base_left;
        current_base->left->right->before = current_base->left->right;
        arr[ID++] = current;
        arr_size++;
        check = true;
        return;
    } else if (!current_base->right and !current_base->left and !(current_base->before and
                                                            current_base->before->left->price < current->price)) {
        current_base->right = current;
        current_base->right->before = current_base;
        arr[ID++] = current;
        arr_size++;
        check = true;
        return;
    } else {
        check = false;
        if (current_base->right)
            add(current, current_base->right, current_base);
        if (!check and current_base->left)
            add(current, current_base->left, current_base);
    }
}
//} else if (current_base->price > current->price) {
//    node* p_cur_base = current_base;
//    current_base = current;
//    current_base->before = before;
//    current_base->right = p_cur_base;
//    current_base->right->before = current_base;
//    arr[ID++] = current;
//    arr_size++;
//    return;
//void DataBase::add(node* current, node* current_base, node* before) {
//    static bool check = false;
//    if (arr_size == 0) {
//        base = current;
//        arr[ID++] = current;
//        arr_size++;
//        return;
//    }
//    if ((current_base->right or current_base->left) and current_base->price > current->price and !current_base->before) {
//        node* temp = current_base;
//        base = current;
//        base->right = temp;
//        base->before = before;
//        arr[ID++] = current;
//        arr_size++;
//        check = true;
//        return;
//    } else if ((current_base->right or current_base->left) and current_base->price > current->price and current_base->before) {
//        node* temp = current_base;
//        current_base = current;
//        current_base->before = temp->before;
//        if (temp->right) {
//            current_base->left = temp->right;
//            current_base->left = current_base;
//        }
//        if (temp->left) add(temp->left, current_base->right, current_base);
//        return;
//    }
//    else if (current_base->right and current_base->right->price > current->price) {
//        node* temp_right = current_base->right;
//        current_base->right = current;
//        current_base->right->before = temp_right->before;
//        node* temp_left = current_base->left;
//        current_base->left = temp_right;
//        current_base->left->before = temp_left->before;
//        current_base->left->right = temp_left;
//        current_base->left->right->before = current_base->left;
//        arr[ID++] = current;
//        arr_size++;
//        check = true;
//        return;
//        //add(current, current_base->right, current_base);
//    }
//    else if (current_base->left and current_base->left->price > current->price) {
//        node* temp_left = current_base->left;
//        current_base->left = current;
//        current_base->left->before = temp_left->before;
//        current_base->left->right = temp_left;
//        current_base->left->right->before = current_base->left;
//        arr[ID++] = current;
//        arr_size++;
//        check = true;
//        return;
//    } else if (current_base->right and !current_base->left and !current_base->right->right) {
//        current_base->left = current;
//        current_base->left->before = current_base;
//        arr[ID++] = current;
//        arr_size++;
//        check = true;
//        return;
//    } else if (current_base->right and !current_base->left and current_base->right->right) {
//        add(current, current_base->right, current_base);
//        if (!check) {
//            current_base->left = current;
//            current_base->left->before = current_base;
//            arr[ID++] = current;
//            arr_size++;
//            check = true;
//        }
//        return;
//    } else if (!current_base->left and !current_base->right) {
//        current_base->right = current;
//        current_base->right->before = current_base;
//        arr[ID++] = current;
//        arr_size++;
//        check = true;
//        return;
//    } else {
//        add(current, current_base->right, current_base);
//        if (!check)
//            add(current, current_base->left, current_base);
//    }
//}

void DataBase::del(size_t id) {
    arr[id]->deleted = true;
    arr[id]->before->right = arr[id]->right;
    arr[id]->before->left = arr[id]->left;
    arr_size--;
}

void DataBase::print(node* current_base) const {
    if (current_base != nullptr) {
        std::cout << *current_base;
        if (current_base->right) print(current_base->right);
        if (current_base->left) print(current_base->left);
    }
}

void DataBase::print_n(size_t need_count_of_rooms, node* current_base) const {
    if (current_base != nullptr) {
        if (current_base->count_of_rooms == need_count_of_rooms)
            std::cout << *current_base;
        if (current_base->right) print_n(need_count_of_rooms, current_base->right);
        if (current_base->left) print_n(need_count_of_rooms, current_base->left);
    }
}

void DataBase::DT_export(const char *filename, node* current_base) {
    std::ofstream file(filename, std::ios::app);
    if (current_base != nullptr) {
        file << *base;
        if (current_base->right) DT_export(filename, current_base->right);
        if (current_base->left) DT_export(filename, current_base->left);
    }
}

void DataBase::find(size_t id, node* current_base) const {
    if (current_base != nullptr) {
        if (arr[id]->count_of_rooms == base->count_of_rooms and arr[id]->floor == base->floor and (base->square >=
        arr[id]->square * 0.8 and base->square <= arr[id]->square * 1.2))
            std::cout << *base;
        if (current_base->right) find(id, base->right);
        if (current_base->left) find(id, base->left);
    }
}