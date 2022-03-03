#include "matrix.h"
// "" ищет сначала в родных директорияз
// <> ищет сначала в системнх директорияъ
double** create_matrix(size_t rows, size_t cols) {
    double** matrix = new double*[rows];
    for (size_t i = 0; i < rows; ++i)
        matrix[i] = new double[cols];
    return matrix;
}

void delete_matrix(double** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

void input_matrix(double** matrix, size_t rows, size_t cols) {
    std::cout << "enter nums: ";
    for (int i = 0; i < rows; ++i) {
        std::cout << "input: " << i << "row\n";
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void print_matrix(double** matrix, size_t rows, size_t cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

void fill(double** matrix, size_t rows, size_t cols, double val) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = val;
        }
    }
}

void zeros(double** matrix, size_t rows, size_t cols) {
    fill(matrix, rows, cols, 0);
}

void ones(double** matrix, size_t rows, size_t cols) {
    fill(matrix, rows, cols, 1);
}

double **linspace(size_t length) {
    double** vec = create_matrix(1, length);
    for (size_t idx = 0; idx < length; ++idx)
        vec[0][idx] = idx + 1;
    return vec;
}

double** transpose(double** matrix, size_t rows, size_t cols)
{
    double** transposed = create_matrix(cols, rows);
    for (size_t r = 0; r < rows; ++r) {
        for (size_t c = 0; c < cols; ++c)
            transposed[c][r] = matrix[r][c];
    }
    return transposed;
}

template <typename Type>
void Swap(Type& a, Type& b)
{
    Type tmp = a;
    a = b;
    b = tmp;
}

void rotate180(double** matrix, size_t rows, size_t cols)
{
    // Step 1. reverse elements in each row
    for (size_t r = 0; r < rows; ++r) {
        for (size_t c = 0; c < cols / 2; ++c)
            Swap(matrix[r][c], matrix[r][cols - c - 1]);
    }
    //Step 2. reverse rows
    for (size_t r = 0; r < rows / 2; ++r)
        Swap(matrix[r], matrix[rows - r - 1]);
}

double& findMinimum(double** matrix, size_t rows, size_t cols)
{
    double minimum = **matrix;
    size_t r_min = 0;
    size_t c_min = 0;
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            if (matrix[r][c] < minimum)
            {
                minimum = matrix[r][c];
                r_min = r;
                c_min = c;
            }
    return matrix[r_min][c_min];
}

double** sum(double** matrix1, double** matrix2, size_t rows, size_t cols) {
    double ** sum_matrix = create_matrix(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j)
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
    return sum_matrix;
}

double** min(double** matrix1, double** matrix2, size_t rows, size_t cols) {
    double** min_matrix = create_matrix(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j)
            min_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
    }
    return min_matrix;
}

double** product(double** matrix1, double** matrix2, size_t rows1, size_t cols1, size_t rows2, size_t cols2) {
    double** buffer = create_matrix(rows1, cols2);
    if (cols1 != rows2) {
        std::cout << "error. product doesn't work with those matrix\n";
        return nullptr;
    }
    for (size_t i = 0; i < rows1; ++i) {
        size_t temp_cols = 0;
        while (temp_cols != cols2) {
            double elem = 0;
            for (size_t j = 0; j < cols1; ++j)
                elem += (matrix1[i][j] * matrix2[j][temp_cols]);
            buffer[i][temp_cols] = elem;
            temp_cols++;
        }
    }
    return buffer;
}

void transfom_matrix(double** matrix, double** sing, size_t size, size_t start) {
    for (size_t i = start; i < size; ++i) {
        double temp = matrix[i][start];
        if (temp == 0) {
            std::cout << "bad example\n";
            exit(1);
        }
        //sing[i][start] /= temp;
        matrix[i][start] = 1;
        for (size_t j = 0; j < size; ++j) {
            if (j >= start + 1)
                matrix[i][j] /= temp;
            sing[i][j] /= temp;
        }
        std::cout << "matrix: \n";
        print_matrix(matrix,size,size);
        std::cout << "sing: \n";
        print_matrix(sing,size,size);
    }
}

double** create_single_matrix(size_t size) {
    double** matrix = create_matrix(size,size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (i == j) matrix[i][j] = 1;
            else matrix[i][j] = 0;
        }
    }
    return matrix;
}

void treug(double** matrix, double** sing, size_t size) {
    for (size_t z = 0; z < size; ++z) {
        transfom_matrix(matrix,sing,size,z);
        for (size_t i = z + 1; i < size; ++i) {
            for (size_t j = z; j < size; ++j) {
                matrix[i][j] -= matrix[z][j];
                sing[i][j] -= matrix[z][j];
            }
        }
        std::cout << "matrix: \n";
        print_matrix(matrix,size,size);
        std::cout << "sing: \n";
        print_matrix(sing,size,size);
    }
}
void fix_matrix(double** matrix, size_t size,size_t start) {
    bool check = true;
    int count = 1;
    while (true) {
        std::swap(matrix[start], matrix[count]);
        if (matrix[start][start] != 0) break;
        else std::swap(matrix[start], matrix[count]);
        count++;
        if (count == size) break;
    }
}
double deter(double** matrix, size_t size) {
    for (size_t z = 0; z < size; ++z) {
        if (matrix[z][z] == 0)
            fix_matrix(matrix,size,z);
        for (size_t i = z + 1; i < size;++i) {
            double temp = matrix[i][z];
            if (temp == 0.) continue;
            for (size_t j = z; j < size; ++j) {
                matrix[i][j] -= ((temp / matrix[z][z]) * matrix[z][j]);
            }
        }
    }
    int main_i = 0, main_j = 0;
    double det = 1;
    for (size_t i = 0; i < size; ++i)
        det *= matrix[main_i++][main_j++];
    return det;
}
double** create_alg_adv(double** matrix, size_t size, size_t row, size_t col) {
    double** alg_adv = create_matrix(size - 1, size - 1);
    size_t iter1= 0, iter2 = 0;
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            if (i != row and j != col) {
                alg_adv[iter1][iter2] = matrix[i][j];
                iter2++;
                if (iter2 == size - 1) {
                    iter2 = 0;
                    iter1++;
                }
            }
    std::cout << "---------------------------------\n";
    std::cout << "alg adv: \n";
    print_matrix(alg_adv, size -1 ,size - 1);
    return alg_adv;
}

double** product_on_num(double** matrix, size_t size, double num) {
    double** result = create_matrix(size, size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result[i][j] = num * matrix[i][j];
    return result;
}

double** reverse_matrix(double** matrix, size_t size) {
    double** prod2 = create_matrix(size, size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            double** alg_adv = create_alg_adv(matrix, size, i, j);
            prod2[i][j] = pow(-1, (i + j)) * deter(alg_adv, size - 1);
            delete_matrix(alg_adv, size, size);
        }
    }
    double prod1 = 1 / deter(matrix, size);
    std::cout << "prod2:   \n";
    print_matrix(prod2,size, size);
    double** prod3 = transpose(prod2, size, size);
    std::cout << "prod3:   \n";
    print_matrix(prod3,size, size);
    delete_matrix(prod2, size, size);
    double** result = product_on_num(prod3, size, prod1);
    delete_matrix(prod3,size,size);
    return result;
}
void up_treug(double** matrix, double** sing, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (matrix[i][j] == 0) continue;
            for (size_t z = 0; z < size; ++z) {
                if (z >= j)
                    matrix[j][z] *= matrix[i][j];
                sing[j][z] *= matrix[i][j];
                if (z >= j)
                    matrix[i][z] -= matrix[j][z];
                sing[i][z] -= matrix[j][z];
                if (j == z) {
                    for (int k = 0; k < size; ++k)
                        sing[z][k] /= matrix[j][z];
                    matrix[j][z] = 1;
                }
                std::cout << "matrix: \n";
                print_matrix(matrix,size,size);
                std::cout << "sign: \n";
                print_matrix(sing,size,size);
            }
        }

    }
}
void reverse(double** matrix, double** sing, size_t size) {
    std::cout << "treug: \n";
    treug(matrix, sing, size);
//    print_matrix(matrix,size,size);
//    print_matrix(sing,size,size);
    std::cout << "uptreg: \n";
    up_treug(matrix, sing, size);
//    print_matrix(matrix, size, size);
//    print_matrix(sing, size, size);
}