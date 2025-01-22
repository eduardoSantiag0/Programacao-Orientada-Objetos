#include <iostream>

class Complex {
private:
    int real, img;

public:
    Complex(int r, int i) 
    {
        real = r;
        img = i;
    }

    void print() {
        std::cout << real << " i: " << img << std::endl;
    }


    friend Complex operator+ (Complex const& c1,Complex const& c2) {
        return Complex (c1.real + c2.real, c1.img + c2.img);
    }
};

int main (void)
{
    Complex c1(10,5), c2(2, 4);
    Complex c3 = c1 + c2;

    c3.print();
}