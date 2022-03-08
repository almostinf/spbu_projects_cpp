#include "DataBase.h"

bool strcmp(const char* source, const char* some) {
    size_t i = 0;
    while (some[i] != '\0') {
        if (some[i] != source[i]) return false;
        i++;
    }
    return true;
}

int main() {
    DataBase DB;
    //node* nod = new(node);
//    nod->square = 14;
//    node nd;
    //data dt;
    const int n = 100;
    char count_of_rooms[n]{0};
    char price[n]{0};
    char floor[n]{0};
    char address[n]{0};
    char square[n]{0};
    char days[n]{0};
    char month[n]{0};
    char year[n]{0};
    char** arr_func = new char*[8]{days, month, year, count_of_rooms, floor, square, address, price};
    char filename[n]{0};
    char id[n]{0};
    bool exit = false;
    std::cout << "Commands: \n" << "load 'name_of_file'\n" << "save 'name_of_file'\n" <<
    "add date(FORMAT: days month year) count_of_rooms floor square address price\n" <<
    "del ID\n" << "print\n" << "print N\n" << "export 'name_of_file'\n" << "find ID\n" << "exit (to leave)\n";
    while (!exit) {
        std::cout << "Enter your command: ";
        char command[n]{0};
        node* nd = new(node);
        std::cin.getline(command, sizeof(command));
        std::cout << command << '\n';
        char first_word_6[7]{0};
        for (size_t i = 0; i < 6; ++i)
            first_word_6[i] = command[i];
        char first_word_5[6]{0};
        for (size_t i = 0; i < 5; ++i)
            first_word_5[i] = command[i];
        char first_word_4[5]{0};
        for (size_t i = 0; i < 4; ++i)
            first_word_4[i] = command[i];
        char first_word_3[4]{0};
        for (size_t i = 0; i < 3; ++i)
            first_word_3[i] = command[i];
        //std::cout << first_word_3 << ' ' << first_word_4 << '\n';
        try {
            if (strcmp(first_word_6, "export")) {
                size_t i = 7;
                size_t j = 0;
                while (command[i] != '\0') {
                    filename[j++] = command[i++];
                }
                DB.DT_export(filename, DB.get_base());
            } else if (strcmp(first_word_5, "print")) {
                size_t i = 6;
                size_t j = 0;
                if (command[i + 1] == '\0')
                    DB.print(DB.get_base());
                else {
                    while (command[i] != '\0')
                        count_of_rooms[j++] = command[i++];
                    DB.print_n(atoi(count_of_rooms), DB.get_base());
                }
            } else if (strcmp(first_word_4, "load")) {
                size_t i = 5;
                size_t j = 0;
                while (command[i] != '\0') {
                    filename[j++] = command[i++];
                }
                std::cout << filename << '\n';
                DB.load(filename);
            } else if (strcmp(first_word_4, "save")) {
                size_t i = 5;
                size_t j = 0;
                while (command[i] != '\0') {
                    filename[j++] = command[i++];
                }
                DB.save(filename, DB);
            } else if (strcmp(first_word_4, "find")) {
                size_t i = 5;
                size_t j = 0;
                while (command[i] != '\0') {
                    id[j++] = command[i++];
                }
                DB.find(atoi(id), DB.get_base());
            } else if (strcmp(first_word_4, "exit")) {
                exit = true;
            } else if (strcmp(first_word_3, "add")) {
                size_t i = 4;
                size_t j = 0;
                size_t count = 0;
                while (command[i] != '\0') {
                    if (command[i] == ' ') {
                        count++;
                        j = 0;
                        i++;
                        continue;
                    }
                    arr_func[count][j++] = command[i++];
                    //std::cout << arr_func[count] << '\n';
                }
//                for (size_t z = 0; z < 8; ++z)
//                    std::cout << arr_func[z] << ' ';
                data* dt = new(data);
                dt->days = atoi(arr_func[0]);
                dt->month = atoi(arr_func[1]);
                dt->year = atoi(arr_func[2]);
                //data* p_dt = &dt;
                nd->dt = dt;
                nd->count_of_rooms = atoi(arr_func[3]);
                nd->floor = atoi(arr_func[4]);
                nd->square = atoi(arr_func[5]);
                nd->address = arr_func[6];
                arr_func[6] = new char[n]{0};
                nd->price = atoi(arr_func[7]);
                arr_func[7] = new char[n]{0};
//                node* p_nd = node(p_dt, atoi(arr_func[3]), atoi(arr_func[4]), atoi(arr_func[5]), arr_func[6],
//                    atoi(arr_func[7]));
                DB.add(nd, DB.get_base(), nullptr);
                std::cout << "check\n";
            } else if (strcmp(first_word_3, "del")) {
                size_t i = 4;
                size_t j = 0;
                while (command[i] != '\0') {
                    id[j++] = command[i++];
                }
                DB.del(atoi(id));
            } else
                throw "Wrong command: ";
        } catch (const char* err) {
            std::cerr << err << '\n';
        }
    }
//    delete[] address;
//    delete[] count_of_rooms;
//    delete[] price;
//    delete[] floor;
//    delete[] year;
//    delete[] days;
//    delete[] month;
//    delete[] square;
}

