#include <iostream>
using namespace std;

class Polynomial{

    int *data;
    int capacity;

    public:

    Polynomial(){
       capacity=6;
       data = new int[capacity];
       for(int i=0;i<capacity;i++) data[i]=0;
    }

    void setCoefficient(int d,int c){
        if(d>capacity){
            
          int * newdata= new int[d+1];
          for(int i=0;i<d+1;i++) newdata[i]=0;
          for(int i=0;i<capacity;i++) newdata[i]=data[i];

          delete [] data;
          data=newdata;
          capacity=d+1;
        }
        data[d]=c;
    }

    Polynomial(Polynomial const &P){
       capacity=P.capacity;
        data=new int[capacity];
        for(int i=0;i<capacity;i++) data[i]=P.data[i];
    }

    void operator=(Polynomial const &P){
        capacity=P.capacity;
        data=new int[capacity];
        for(int i=0;i<capacity;i++) data[i]=P.data[i];
    }

    Polynomial operator+(Polynomial const & p){
        Polynomial result;
        int max = (capacity>p.capacity)?capacity:p.capacity;
        result.capacity=max;

        result.data=new int[max];

        for(int i=0;i<max;i++){
            int c1 = (i<capacity)?data[i]:0;
            int c2=(i<p.capacity)?p.data[i]:0;

            result.data[i]=c1+c2;
        }

        return result;
    }

    Polynomial operator-(Polynomial const & p){
        Polynomial result;
        int max = (capacity>p.capacity)?capacity:p.capacity;
        result.capacity=max;

        result.data=new int[max];

        for(int i=0;i<max;i++){
            int c1 = (i<capacity)?data[i]:0;
            int c2=(i<p.capacity)?p.data[i]:0;

            result.data[i]=c1-c2;
        }

        return result;
    }

    Polynomial operator*(Polynomial const &P){
        Polynomial result;

        result.capacity=capacity+P.capacity;
        result.data=new int[result.capacity];

        for(int i=0;i<result.capacity;i++){
            int c1 = (i<capacity)?data[i]:1;
            int c2 = (i<P.capacity)?P.data[i]:1;
            result.data[i]=c1*c2;
        }

        return result;
    }

    void print(){
        for(int i=0;i<capacity;i++){
            if(data[i]!=0){
                cout << data[i] <<"x"<<i<<" ";
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
//Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            
        }
            
    }
    
    return 0;
}