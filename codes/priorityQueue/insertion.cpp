#include <iostream>
#include "minPQ.h"
using namespace std;


int main (){

    minPQ* pq = new minPQ();

    pq->insert(12);
    pq->insert(6);
    pq->insert(5);
    pq->insert(100);
    pq->insert(1);

    cout << pq->getsize() << endl;

    cout << pq->isempty() << endl;

    cout << pq->getmin() << endl;


    for(int i=0;i<pq->data.size();i++){
        cout << pq->data[i] << " ";
    }
}

