#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;

    Node *newNode = NULL;
    int readData;
    while(1){
        cout << "input : ";
        cin >> readData;
        if(readData < 1) break;
        newNode = new Node;
        newNode ->data = readData;
        newNode ->next = NULL;
        if(head ==NULL) head=newNode;
        else tail->next = newNode;

        tail = newNode;
    }
    cout << head->data << head->next->data <<endl;
    return 0;
}