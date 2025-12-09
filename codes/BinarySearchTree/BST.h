template<typename T>

class BST{
    public:
    T data;
    int count;
    BST*left;
    BST*right;

    BST(T d){
        data=d;
        left=NULL;
        right=NULL;
        count=1;
    }

    ~BST(){
        delete left;
        delete right;
    }

};