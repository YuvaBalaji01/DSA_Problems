#include <iostream>
#include <algorithm>

using namespace std;

class Fraction {

    int numerator,denominator,num;

    public:

    Fraction(int n,int d){
        numerator=n;
        denominator=d;
    }

   

    void display(){
        cout << numerator <<"/" << denominator << endl;
    }

    void simplify(){
        int gcd =1;
        int j = max(numerator,denominator);
        for(int i=1;i<=j;i++){
            if (numerator%i==0 && denominator%i==0) gcd =i;
        }
        
        numerator/=gcd;
        denominator/=gcd;
    }

    Fraction  operator+(Fraction const  &f){
        int lcm = denominator * f.denominator;
        int x = numerator*f.denominator;
        int y = f.numerator*denominator;

        int num = x+y;

        Fraction fnew(num,lcm);

        fnew.simplify();

        return fnew;
    }

    Fraction operator*(Fraction const &f){  //this helps us to avoid extra space and const will help us not to change value of f4 Passed
       
        Fraction fnew(numerator*(f.numerator),denominator*(f.denominator));
       

        fnew.simplify();

        return fnew;
    }

    bool operator==(Fraction const &f){
     
       if(numerator==f.numerator && denominator==f.denominator)  return true;

       else return false;

    }

    Fraction& operator++(){    //imp 
        numerator+=denominator;
        simplify();

        return *this;
    }
};


int main (){

    Fraction f1(7,2);

    Fraction f2= ++(++f1);
    
    f2.display();

    f1.display();

    Fraction f3 = f1+f2;

    f3.display();

}