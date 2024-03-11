/*1.Define a class complex and overload following operaters as a friend
+ - * 
*/
#include<iostream>
using namespace std ;

class Complex
{
    private : 
        int real , img ;
    public : 
        Complex(int x=0 , int y=0)
        {
            real = x ;
            img = y ;
        }
        void showData ()
        {
            cout<<"\nReal="<<real<<"  Img="<<img<<endl ;
        }
        //friend operator +
        friend Complex operator+ (Complex , Complex) ;
        //friend operator -
        friend Complex operator- (Complex , Complex) ;
        //friend operator *
        friend Complex operator* (Complex , Complex) ;

};

Complex operator+ (Complex A, Complex B)
{
    Complex temp ;
    temp.real = A.real + B.real ;
    temp.img = A.img + B.img ;

    return temp ;
}
Complex operator- (Complex A, Complex B)
{
    Complex temp ;
    temp.real = A.real - B.real ;
    temp.img = A.img - B.img ;

    return temp ;
}
Complex operator* (Complex A, Complex B)
{
    Complex temp ;
    temp.real = A.real * B.real - A.img * B.img ;
    temp.img = A.real * B.img + A.img * B.real ;

    return temp ;
}


int main ()
{
    Complex  c1(6,3) , c2(2,5) , c3 ;

    c1.showData() ;
    c2.showData() ;

    c3 = c1+c2 ;
    c3.showData() ;

    c3 = c2-c1;
    c3.showData() ;

    c3 = c1*c2 ;
    c3.showData() ;
    
    return 0 ;
}
