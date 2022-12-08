#include <iostream>
using namespace std;
#include "Node.cpp"
template <class E>
class BSTree{
    BNode<E>* root;
    BNode<E> *& search(const E & k, BNode<E>* &a){
        if(!a){
            cout<<"khong co";
            return a;
        }
        if(k==a->element) return a;
        else if(k<a->element) return search(k, a->left);
        return search(k, a->right);
    }
    void add(const E &a, BNode<E> *&b){
        if(!b){
            b=new BNode<E>(a);
            return;
        }
        if(a==b->element) cout<<"da co";
        else if(a<b->element) add(a, b->left);
        else if(a>b->element) add(a, b->right);
    }
    void print1(BNode<E> *a) const{
        if(!a) return;
        print1(a->left);
        cout << a->element <<" ";
        print1(a->right);
    }
    void remove(BNode<E> *&r){
        BNode<E> *cur = r;
        if(!r->left) r = r->right;
        else if(!r->right) r = r->left;
        else {
            BNode<E> *parent = r;
            while (cur->right)
            {
                parent = cur;
                cur = cur->right;
            }
            r->element = cur->element;
            if(cur == r->left) parent->left = cur->left;
            else parent->right = cur->left;   
        }
        delete cur;
        cur = 0;
    }
    int height(BNode<E> *a) const {
        if(a){
            if(a->isLa()) return 0;
            return 1+ max(height(a->left), height(a->right));
        }
        else return -1;
    }
    void clear(BNode<E> *&a){
    //neu van ton tai node goc
    if(a){
        //de quy sang nhanh trai
        clear(a->left);
        //de quy sang nhanh phai 
        clear(a->right);
        //xoa node goc 
        delete(a);
        }
        return;
    }
    void canbang(BNode<E>*a){
        if(height(a->left) - height(a->right)>1){
            cout<<"khong";
            return;
        }
        cout<<"can bang";
       
    }
    public:
    BSTree() : root(NULL) {}
    BNode<E>*& BSsearch(const E & k) {
        return search(k, root);
    }
    void add1(const E &k){
        add(k, root);
    }
    void print() const {
        print1(root);
    }
    void remove2(const E & k){
        remove(BSsearch(k));
    }
    int h() const { return height(root); }
    void clear1(){
        clear(root);
    }
    void canbang1(){
        return canbang(root);
    }
};
int main()
{
    BSTree<int> t;
    // for(int i = 0; i < 5; i++) t.add1(i);
    t.add1(50);
    t.add1(40);
    t.add1(30);
    t.add1(600);
    t.add1(500);
    t.print();
    t.clear1();
    // t.remove2(30);
    // cout<<t.BSsearch(3);
    cout<<endl;
     t.add1(30);
    t.add1(600);
    t.add1(500);
    t.print();
    // cout<<endl;
    // t.canbang1();
    
    return 0;
}