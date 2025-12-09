#include <iostream>
using namespace std;

class dynamicarray{

    int* data;
    int element;
    int capacity;
    int nextindex;

    public:

    dynamicarray(){
        nextindex=0;
        data=new int[5];
        capacity=5;
    }

    dynamicarray(dynamicarray const &a){
        //delete []data;
        this->capacity=a.capacity;
        this->nextindex=a.nextindex;
        this->data=new int[capacity];
        for(int i=0;i<nextindex;i++){
            data[i]=a.data[i];
        }
    }
    void operator=(dynamicarray const &a){

        this->capacity=a.capacity;
        this->nextindex=a.nextindex;
        this->data=new int[capacity];
        for(int i=0;i<nextindex;i++){
            data[i]=a.data[i];
        }
    }

    void add(int e){
        if(nextindex >= capacity){
            int *newdata=new int[2*capacity];

            for(int i=0;i<nextindex;i++){
                newdata[i]=data[i];
            }
            
            capacity*=2;

            delete [] data;
            data=newdata;
        }

        data[nextindex++]=e;
    }


    void operator+(int e){
        if(nextindex >= capacity){
            int *newdata=new int[2*capacity];

            for(int i=0;i<nextindex;i++){
                newdata[i]=data[i];
            }
            
            capacity*=2;

            delete [] data;
            data=newdata;
        }

        data[nextindex++]=e;
        
    }

    int getcapacity() const{
        return this->capacity;
    }

    int getsize() const{
        return this->nextindex;
    }

    void print() const {
        for(int i=0;i<nextindex;i++){
            cout << data[i] << " " ;
        }

        cout << endl;
    }


};

int main (){

    dynamicarray a;
    a.add(10);
    a.add(20);
    a.add(30);
    a.add(40);
    a.add(50);
    a.add(60);
    a+70;

    a.print();

    dynamicarray a2=a;

    a2.print();

    dynamicarray a3(a2);

    a3.print();

    cout << a.getsize() << endl;
    cout << a.getcapacity() << endl;

   


}