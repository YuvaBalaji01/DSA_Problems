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

    void add(Fraction f){
        int lcm = denominator * f.denominator;
        int x = lcm/numerator;
        int y = lcm/f.numerator;

        int num = numerator*x+(f.numerator*y);

        numerator=num;
        denominator=lcm;

        simplify();
    }

    void multiply(Fraction const &f){  //this helps us to avoid extra space and const will help us not to change value of f4 Passed
       
        numerator=numerator*(f.numerator);
        denominator=denominator*(f.denominator);

        simplify();
    }
};


int main (){

    Fraction f1(19,9);

    Fraction f2(10,7);


    f1.multiply(f2);

    f1.display();
    f2.display();


    f1.add(f2);

    f1.display();
    f2.display();

}