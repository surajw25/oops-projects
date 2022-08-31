#include <iostream>

using namespace std;

class ComplexNumber
{
    private:
        float real;
        float img;
    public:
        ComplexNumber(float r = 0, float i = 0) : real(r) , img(i)
        {
            cout << "Constructor of ComplexNumber" << endl;
        }
        ComplexNumber(const ComplexNumber& n)
        {
            real = n.real;
            img = n.img;
            cout << "Copy Constructor of ComplexNumber" << endl;
        }
        ~ComplexNumber()
        {
            cout << "Destructor of Complex Number" << endl;
        }
        int get_real()const
        {
            return real;
        }
        int get_imaginary()const
        {
            return img;
        }
        void set_real(float i)
        {
            real = i;
        }
        void set_imaginary(float i)
        {
            img = i;
        }
        //Operator overloading
        friend void display(const ComplexNumber&);
        ComplexNumber operator+ (const ComplexNumber& x)
        {
            ComplexNumber n;
            n.real = real + x.real;
            n.img = img + x.img;
            return n;
        }
        ComplexNumber operator- (const ComplexNumber& x)
        {
            ComplexNumber n;
            n.real = real - x.real;
            n.img = img - x.img;
            return n;
        }
        ComplexNumber operator* (const ComplexNumber& x)
        {
            ComplexNumber n;
            n.real = (real) * (x.real) - (img) * (x.img);
            n.img = (real) * (x.img) + (img) * (x.real);
            return n;
        }
        ComplexNumber operator/ (const ComplexNumber& x)
        {
            try
            {
                if (x.real == 0 && x.img == 0)
                {
                    throw 404;
                }
                else
                {
                    ComplexNumber n;
                    n.real = (((real*(x.real)) + (img*(x.img)))/((x.real * x.real) + (x.img * x.img)));
                    n.img = (((img * x.real) - (real * x.img))/((x.real * x.real) + (x.img * x.img)));
                    return n;
                }
            }
            catch(...)
            {
                cout << "Division by zero" << endl;
            }
        }
        void operator= (const ComplexNumber& x)
        {
            real = x.real;
            img = x.img;
        }
        void operator= (float i)
        {
            real = i;
            img = 0;
        }
        /*void operator<> ()
        {
            float a = real;
            real = img;
            img = a;
        }*/
        //void
};

void display(const ComplexNumber& num)
{
    cout << "Number : " << num.real << " + " << num.img << "i" << endl;
}

/*int main()
{
    ComplexNumber n1(10,12),n2(10,18);
    display(n1);
    display(n2);
    ComplexNumber sum(2,4);
    display(sum);
    sum = n1+n2;
    display(n1);
    return 0;
}*/
