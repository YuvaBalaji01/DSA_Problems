#include <iostream>
using namespace std;

class employee{
  public:
  int salary;
  virtual void  salarycal(){};//pure virtual funtion
};

class hr : public employee{
    public:

     void salarycal(){
        cout << "1000000" << endl;
    }
};

class tl : public employee{
    public:

     void salarycal(){
        cout << "100000" << endl;
    }
};

class eng : public employee{
    public:

     void salarycal(){
        cout << "10000" << endl;
    }
};


int main (){
    employee* e[3];
     e[0]=new hr();
     e[0]->salarycal();

}