#include <iostream>
using namespace std;

class vehicle{
  public:
   virtual void  print(){
    cout << "vehicle" << endl;
  }
};

class car : public vehicle{
    public:

     virtual void print(){
        cout << "car" << endl;
    }
};


int main (){
    vehicle* v= new car();
    v->print();
}