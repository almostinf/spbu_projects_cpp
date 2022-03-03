#include <iostream>
#include "BmpStructures.h"
#include "ImgFunctions.h"

void testBmpIo()
{
    printImgInfo("masterpiece.bmp");
    RgbImg img = readRgbImg("masterpiece.bmp");
    for (size_t row=0; row < 50;++row)
        for (size_t col = 0; col < 50; ++col)
        {
            img.pixels[row][col].Blue = 255;
            img.pixels[row][col].Green = 128;
            img.pixels[row][col].Red = 0;
            //img.pixels[row][col] = {255, 255, 255}; //same as above
        }
    writeRgbImg("out\\ugly_copy.bmp", img);
        deleteRgbImg(img);
}

//Generate dummy image example
void genImgWithSquare()
{
    RGB background = { 255, 128, 0 };
    RgbImg img = createRgbImg(600, 600, background);
    for (size_t row = 50; row < 200; ++row)
        for (size_t col = 100; col < 400; ++col)
            img.pixels[row][col] = { 128, 255, 0 };

        writeRgbImg("out\\ai_masterpiece.bmp", img);
        deleteRgbImg(img);
}

//Autobalancing example
void testAutolevels()
{
    RgbImg img = readRgbImg("data\\Lenna.bmp");
    RgbImg balanced = autolevels(img);
    writeRgbImg("out\\Lenna_avtolevels.bmp", img);
    deleteRgbImg(img);
}

//Another autobalancing example
void testGrayworld()
{
    RgbImg img = readRgbImg("data\\sinichka.bmp");
    RgbImg balanced = grayworld(img);
    writeRgbImg("out\\grayworld.bmp", balanced);
    deleteRgbImg(img);
}

//Box filter example
//void testBoxFilter()
//{
//    RgbImg img = readRgbImg("data\\kidsnoise.bmp");
//    RgbImg filtered = convolution(img, 5);
//    writeRgbImg("out\\kids_filtered.bmp", img);
//    deleteRgbImg(img);
//    deleteRgbImg(filtered);
//}

void testKernelFilter()
{
    size_t const kern_sz = 3;
    double** kernel = new double* [kern_sz];
    for (size_t row = 0; row < kern_sz; ++row)
    {
        kernel[row] = new double[kern_sz];
        for (size_t col = 0; col < kern_sz; ++col)
            kernel[row][col] = 1. / 9;
    }
    RgbImg img = readRgbImg("data\\kidsnoise.bmp");
    RgbImg filtered = convolution(img, 5, kernel);
    writeRgbImg("out\\kids_filtered_kernel.bmp", img);
    deleteRgbImg(img);
    deleteRgbImg(filtered);
}

void rainbow() {
    RgbImg img = createRgbImg(100, 700, {255,255,255});;
    for (size_t t = 0; t < 7; ++t) {
        for (size_t i = 0; i < 100; ++i) {
            for (size_t j = 0 + t * 100; j < 100 * (t + 1); ++j) {
                if (t == 0)
                    img.pixels[i][j] = {0,0,255};
                else if (t == 1)
                    img.pixels[i][j] = {0, 165, 255};
                else if (t == 2)
                    img.pixels[i][j] = {0,255,255};
                else if (t == 3)
                    img.pixels[i][j] = {0,128,0};
                else if (t == 4)
                    img.pixels[i][j] = {255,255,0};
                else if (t == 5)
                    img.pixels[i][j] = {255,0,0};
                else if (t == 6)
                    img.pixels[i][j] = {128,0,128};
            }
        }
    }
    writeRgbImg("outrainbow.bmp", img);
    deleteRgbImg(img);
}
void testContours()
{
    RgbImg img = readRgbImg("data\\sinichka.bmp");
    RgbImg contour_img = contours(img);
    writeRgbImg("out\\contours.bmp", contour_img);
    deleteRgbImg(img);
    deleteRgbImg(contour_img);
}
//void rotate_matrix() {
//    const int n = 2;
//    const int m = 3;
//    int arr[n][m] = {
//            1,0,2,
//            3,4,5
//    };
//    int subarr[m][n] {
//        0,0,
//        0,0,
//        0,0
//    };
//    for (int i = n - 1; i >= 0; --j) {
//        for (int j = 0; j <= m; ++j) {
//            subarr[m - i - 1][j] = arr[i][j];
//        }
//    }
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            std::cout << subarr[i][j] << ' ';
//        }
//        std::cout << '\n';
//    }
//}
void filt() {
    int const rows = 2, cols = 4;
    int arr[rows][cols] = {
            1,2,3,4,
            5,6,7,8
    };
    int arr_out[cols][rows] = {
            0,0,
            0,0,
            0,0,
            0,0
    };
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            std::cout << arr[i][j] << ' ';
        std::cout << '\n';
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = cols - 1; j >= 0; --j) {
            arr_out[cols - 1 - j][i] = arr[i][j];
        }
    }
    std::cout << '\n';
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j)
            std::cout << arr_out[i][j] << ' ';
        std::cout << '\n';
    }
}
void rotate(const char* path,const int angle) {
    RgbImg img = readRgbImg(path);
    try {
        if (angle % 90 != 0)
            throw std::runtime_error("error lol\n");
    } catch (std::exception ex) {
        std::cerr << ex.what();
    }
    if (angle % 360 == 0) {
        RgbImg out = copyRgbImg(img);
        writeRgbImg("out_rotate.bmp", out);
        deleteRgbImg(out);
    }
    else if (angle % 270 == 0) {
        RgbImg out = createRgbImg(img.width, img.height, {0,0,0});
        for (size_t i = 0; i < img.width; ++i) {
            for (size_t j = 0; j < img.height; ++j) {
                out.pixels[i][img.height - j - 1] = img.pixels[j][i];
            }
        }
        writeRgbImg("out_rotate.bmp", out);
        deleteRgbImg(out);
    } else if (angle % 180 == 0) {
        RgbImg out = createRgbImg(img.height, img.width, {0,0,0});
        for (size_t i = 0; i < img.width; ++i) {
            for (size_t j = 0; j < img.height; ++j) {
                out.pixels[j][i] = img.pixels[img.height - j - 1][img.width - i - 1];
            }
        }
        writeRgbImg("out_rotate.bmp", out);
        deleteRgbImg(out);
    } else if (angle % 90 == 0) {
        RgbImg out = createRgbImg(img.width, img.height, {0,0,0});
        for (size_t i = 0; i < img.width; ++i) {
            for (size_t j = 0; j < img.height; ++j) {
                out.pixels[img.width - 1 - i][j] = img.pixels[j][i];
            }
        }
        writeRgbImg("out_rotate.bmp", out);
        deleteRgbImg(out);
    }
    deleteRgbImg(img);
}
void grey_effect(const char* path) {
    RgbImg img = readRgbImg(path);
    for (size_t i = 0; i < img.height; ++i) {
        for (size_t j = 0; j < img.width; ++j) {
            size_t average = (img.pixels[i][j].Red + img.pixels[i][j].Green + img.pixels[i][j].Blue) / 3;
            img.pixels[i][j].Red = average;
            img.pixels[i][j].Blue = average;
            img.pixels[i][j].Green = average;
        }
    }
    writeRgbImg("grey_effect.bmp",img);
    deleteRgbImg(img);
}
void pre_conv(const char* path) {
    RgbImg img = readRgbImg(path);
    RgbImg filtered = convolution(img,5);
    writeRgbImg("pre_filtered_img.bmp", filtered);
    deleteRgbImg(img);
    deleteRgbImg(filtered);
}
void increase_sharpness(const char* path) {
    RgbImg img = readRgbImg(path);
    double** matrix = new double*[3];
    for (int i = 0; i < 3; ++i)
        matrix[i] = new double [3];
    matrix[0][0] = 0; matrix[0][1] = -1; matrix[0][2] = 0; matrix[1][0] = -1; matrix[1][1] = 5; matrix[1][2] = -1;
    matrix[2][0] = 0; matrix[2][1] = -1; matrix[2][2] = 0;
    RgbImg filtered = convolution(img,3,matrix);
    for (int i = 0; i < 3; ++i)
        delete[] matrix[i];
    delete[] matrix;
    writeRgbImg("inc_sharp.bmp",filtered);
    deleteRgbImg(img);
    deleteRgbImg(filtered);
//    for (int i = 2; i < img.height - 2; ++i) {
//        for (int j = 2; j < img.width - 2; ++j) {
//            int total_g = 0;
//            int total_b = 0;
//            int total_r = 0;
//            for (int k = 0; k < 5; ++k) {
//                for (int z = 0; z < 5; ++z) {
//                    size_t const res_row = i + k - 2;
//                    size_t const res_col = j + z - 2;
//                    RGB const& pixel = img.pixels[res_row][res_col];
//                    total_b += pixel.Blue;
//                    total_g += pixel.Green;
//                    total_r += pixel.Red;
//                }
//            }
//            img.pixels[i][j].Red = total_r / 9;
//            img.pixels[i][j].Blue = total_b / 9;
//            img.pixels[i][j].Green = total_g / 9;
//        }
//    }
}
void insertionSort(int arrayPtr[], int length)
{
    int temp, item;
    for (int counter = 1; counter < length; counter++)
    {
        temp = arrayPtr[counter];
        item = counter-1;
        while(item >= 0 && arrayPtr[item] > temp)
            {
            arrayPtr[item + 1] = arrayPtr[item];
            arrayPtr[item] = temp;
            item--;
            }
    }
}
void median_filter(const char* path, int kernel_size) {
    RgbImg img = readRgbImg(path);
    int half = kernel_size / 2;
    int width = img.width;
    int height = img.height;
    const int size = kernel_size * kernel_size;
    int arr_g[size];
    int arr_b[size];
    int arr_r[size];
    for (size_t row = half; row < height - half; ++row)
        for (size_t col = half; col < width - half; ++col)
        {
            for (size_t k_row = 0; k_row < kernel_size; ++k_row) {
                for (size_t k_col = 0; k_col < kernel_size; ++k_col)
                {
                    size_t const res_row = row + k_row - half;
                    size_t const res_col = col + k_col - half;
                    arr_g[k_row * kernel_size + k_col] = img.pixels[res_row][res_col].Green;
                    arr_r[k_row * kernel_size + k_col] = img.pixels[res_row][res_col].Red;
                    arr_b[k_row * kernel_size + k_col] = img.pixels[res_row][res_col].Blue;
                }
            }
            insertionSort(arr_g,size);
            insertionSort(arr_b,size);
            insertionSort(arr_r,size);
            img.pixels[row][col].Red = arr_r[size / 2 + 1];
            img.pixels[row][col].Green = arr_g[size / 2 + 1];
            img.pixels[row][col].Blue = arr_b[size / 2 + 1];
        }
    writeRgbImg("median_filter_out.bmp",img);
    deleteRgbImg(img);
}


int main() {
    //median_filter("kidsnoise_s.bmp",3);
    //prep_for_conv("cb_warm.bmp","cb_warm_out.bmp");
    //rotate("cb_warm.bmp",90);
    //filt();
    pre_conv("kidsnoise_s.bmp");
    increase_sharpness("pre_filtered_img.bmp");
    //rotate_matrix();
    //grey_effect("cb_warm.bmp");
    //rotate("cb_warm.bmp",90);
    //rainbow();
//    try
//    {
//        testContours();
//    }
//    catch (std::exception const& e)
//    {
//        std::cout << "Error: " << e.what() << "\n";
//        return -1;
//    }
    return 0;
}
