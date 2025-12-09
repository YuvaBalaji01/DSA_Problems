
#include<iostream>
using namespace std;

class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;

    Polynomial(){

        capacity=6;
        degCoeff=new int[capacity];
        for(int i=0;i<6;i++) degCoeff[i]=0;
 
    }

    Polynomial(Polynomial const & p){
       this-> capacity=p.capacity;
       degCoeff=new int[capacity];

      for(int i=0;i<capacity;i++){
          degCoeff[i]=p.degCoeff[i];
      }

    }

    void setCoefficient(int d, int c){
    
      if(d>=capacity){
          int *newdeg=new int [d+1];
          for(int i=0;i<capacity;i++) newdeg[i]=degCoeff[i];
          for(int i=capacity;i<d+1;i++) newdeg[i]=0;

          delete [] degCoeff;
          degCoeff=newdeg;
          capacity=d+1;
      }
      degCoeff[d]=c;

    }

    Polynomial operator+(Polynomial const &p){

        Polynomial P;

        int maxcap=(capacity > p.capacity)?capacity:p.capacity;

        delete [] P.degCoeff;

        P.degCoeff=new int[maxcap];

        P.capacity=maxcap;

        for(int i=0;i<maxcap;i++) P.degCoeff[i]=0;

         for (int i = 0; i < maxcap; i++) {
            int coeff1 = (i < capacity) ? degCoeff[i] : 0;
            int coeff2 = (i < p.capacity) ? p.degCoeff[i] : 0;
            P.degCoeff[i] = coeff1 + coeff2;
        }
        return P;

    }


    Polynomial operator-(Polynomial const &p){

        Polynomial P;
        int maxcap=(capacity>p.capacity)?capacity:p.capacity;

        delete [] P.degCoeff;

        P.degCoeff=new int[maxcap];
        P.capacity=maxcap;

        for(int i=0;i<maxcap;i++) P.degCoeff[i]=0;

        for (int i = 0; i < maxcap; i++) {
            int coeff1 = (i < capacity) ? degCoeff[i] : 0;
            int coeff2 = (i < p.capacity) ? p.degCoeff[i] : 0;
            P.degCoeff[i] = coeff1 - coeff2;
        }
        return P;

    }

    void operator=(Polynomial const &p){
      delete [] degCoeff;
      this-> capacity=p.capacity;
      degCoeff=new int[capacity];

      for(int i=0;i<capacity;i++){
          degCoeff[i]=p.degCoeff[i];
      }

    }

    Polynomial operator*(Polynomial const &p){

      Polynomial P;

      P.capacity=capacity+p.capacity;

      delete [] P.degCoeff;

      P.degCoeff=new int[P.capacity];

      for(int i=0;i<P.capacity;i++) P.degCoeff[i]=0;

      for(int i=0;i<capacity;i++){
          for(int j=0;j<p.capacity;j++){
              P.degCoeff[i+j]+=degCoeff[i]*p.degCoeff[j];
          }
      }



      return P;


    }


    void print(){

        for(int i=0;i<capacity;i++){
            if(degCoeff[i]!=0){
                cout << degCoeff[i]<<"x"<<i<< " ";
            }
        }

        cout << endl;
    }


    

    
};

 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}


