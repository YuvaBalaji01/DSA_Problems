#include <iostream>
using namespace std;

class Queue{
    int * data;
    int capacity;
    int index;

    public:

    Queue(){
        data=new int[5];
        capacity=5;
        index=0;
    }

    void enqueue(int d){
        if(index>=capacity){
            int * newdata=new int[capacity*2];
            for(int i=0;i<index;i++) newdata[i]=data[i];
            delete data;
            data =newdata;
            capacity*=2;
        }
        data[index]=d;
        index++;
    }

    void dequeue(){
       
       for(int i=0;i<index-1;i++){
        data[i]=data[i+1];
       }
       index--;
    }

    int front(){
        return data[index-1];
    }

    int size(){
        return index;
    }

    bool isEmpty(){
        return index==0;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.dequeue();
     cout <<  q.front() << endl;
    q.dequeue();
cout <<  q.front() << endl;    q.dequeue();
    
    q.dequeue();
cout <<  q.front() << endl;
}