#include<iostream>
using namespace std;

class student{

    int age;

    public:

    int rollnum;

    student(){
        cout << "c1" << endl;
    }

    student(int age){
        cout << "c2" << endl;
        this-> age= age;
    }

    student(int a,int r){
        cout << "c3" << endl;
        age =a ;
        rollnum=r;
    }

    void dispaly(){
        cout << this->age << " " << this->rollnum << endl;
    }

    ~student(){
       cout <<  "cleared" << endl;
    }
};

int main (){

    student s1;
    student s2(19);
    student s3(19,119);
    
    student *s4=new student(18,118);

    s1=s3; //copy assingment operator;

    student s5=s1; //copy constructor;

    student *s6 = new student(s5); // copy constructor

    s1.dispaly();
    s2.dispaly();
    s3.dispaly();
    s4->dispaly();
    s5.dispaly();
    s6->dispaly();

    delete s4;
    delete s6;
    

}