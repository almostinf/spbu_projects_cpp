//Задача 6. Вывести в консоль график области заданной неравенством (x^2 + y^2 - 1)^3 - x^2 y^3 <= 0.
//x меняется от -1.5 до 1.5, y меняется от -1.5 до 1.5. Вывести график в height=21 строк из width=41 символов.
//Первый символв первой строке соответствует точке (-1.5, 1.5),
//а последний (width) символ в последней (height) строке соответвует точке (1.5, -1.5).
//Если координаты точки удовлетворяют неравенству, то выводить символ *, иначе символ .

#include <iostream>
#include <cmath>


bool function(int x, int y) {
    return pow((pow(static_cast<double>(x) / 10, 2) + pow(static_cast<double>(y) / 10, 2) - 1), 3)
    - pow(static_cast<double>(x) / 10, 2) * pow(static_cast<double>(y) / 10, 3) <= 0;
}


int main() {
    for (int x = 15; x >= -15; --x) {
         for (int y = 15; y >= -15; --y) {
             if (function(y, x))
                 std::cout << "*";
             else
                 std::cout << " ";
             if (y == 15)
                 std::cout << '\n';
         }
    }
}
