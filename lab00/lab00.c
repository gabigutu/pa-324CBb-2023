#include<iostream>

typedef struct {
    double re;
    double im;
} complex_t;

void print_complex(complex_t c)
{
    printf("%lf + %lfi\n", c.re, c.im);
}

void dont_modify_c(int x) {
    x = 123;
}

void modify_c(int *x) {
    *x = 123;
}

void modify_cpp(int &x) {
    x = 432;
}

int main()
{
    complex_t c = {1, 2}; // 1 + 2i
    print_complex(c);

    int x = 4;
    std::cout << "x = "<< x << std::endl;
    dont_modify_c(x);
    std::cout << "x = "<< x << std::endl;

    int *y = new int[1];
    y[0] = 9;
    modify_c(y);
    std::cout << "y = " << y << std::endl;
    std::cout << "*y = " << *y << std::endl;

    int z = 90;
    std::cout << "z = " << z << std::endl;
    modify_cpp(z);
    std::cout << "z = " << z << std::endl;

    return 0;
}
