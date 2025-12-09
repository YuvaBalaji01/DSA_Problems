template <typename T>

class BinaryTree{
    public:
    T data;
    BinaryTree * left;
    BinaryTree* right;

    BinaryTree(T d){
        data=d;
        left=NULL;
        right=NULL;
    }

    ~BinaryTree(){
        delete left;
        delete right;
    }

};
