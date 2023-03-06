#include <iostream>
using namespace std;

// C++ struct
class Complex {
    private:
        double re, im;

    public:
        Complex() {
            cout << "constructor" << endl;
        }
        Complex(double re, double im): re(re), im(im) {
        }
        // Complex(double re, double im) {
        //     this->re = re;
        //     this->im = im;
        // }

        ~Complex() {
            std::cout << "complex destroyed" << std::endl;
        }

        void setRe(double re) {
            this->re = re;
        }

        void print() {
            // the im and re members for the current Complex object are accessed
            std::cout << re << "+" << im << "i" << "\n";
        }

};

template<typename X> void something(X a) {
    cout << "am primit: " << a << ", sizeof(a) = " << sizeof(a) << endl;
}

template<typename T>
void func(T& a, T&b) {
    cout << a << ' ' << b << endl;
}

int main()
{
    Complex c = Complex(2, 1);
    c.print();

    int *x = new int[10];
    Complex *comp = new Complex[10];
    comp[0].setRe(5);
    comp[1].setRe(7);
    comp[0].print();

    Complex *compMalloc = (Complex *) malloc(sizeof(Complex) * 10);
    compMalloc[0].setRe(8);
    compMalloc[0].print();

    auto a = 10.0; // the type of x is automatically deduced to double because 10.0 it's a double
    cout << "sizeof(x) = " << sizeof(a) << endl;

    something<int>(8);
    something<float>(9.8f);
    something<float>(13);
    something<double>(9.8);
    something<double>(900.f);

    // int a1 = 9;
    // int a2 = (int)'d';
    // char b1 = 8;
    // int b2 = 90;
    // func<int>(b1, b2);

    return 0;
}