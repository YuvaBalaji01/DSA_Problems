#include<iostream>
using namespace std;
#include"maxPQ.h"

int main(){

    maxPQ *pq =new maxPQ();

    pq->insert(10);
    pq->insert(12);
    pq->insert(9);
    pq->insert(7);
    pq->insert(15);

    pq->print();

}