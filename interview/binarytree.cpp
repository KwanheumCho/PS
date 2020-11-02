#include <iostream>

using namespace std;

struct node{
    int x;
    node* leftchild;
    node* rightchild;
};
void preorder(node* a){
    if(a){
        cout << a->x << endl;
        preorder(a->leftchild);
        preorder(a->rightchild);
        }
}

int main(void){
    node arr[16];
    for(int i=1; i<=15; i++){
        arr[i].x = i;
        arr[i].leftchild = NULL;
        arr[i].rightchild = NULL;
    }
    for(int i=1; i<=15; i++){
        if(i%2 ==0) arr[i/2].leftchild = &arr[i];
        else arr[i/2].rightchild = &arr[i];
    }
    preorder(&arr[1]);
}