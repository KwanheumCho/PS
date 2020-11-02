#include <iostream>
#include <string>
using namespace std;
#define max_size 10
struct Node{
    string key;
    int value;
    Node *next;
};

// hash table
Node* hashtable[max_size];

// hash function
int hash_func(string key){
    int tmp = 0;
    for(int j=0; j<key.size(); j++){
        tmp += (key[j]-'A');
    }
    return tmp % max_size ;
}
void add(string key, int value){
    Node* new_node = new Node();
    new_node -> key = key;
    new_node -> value = value;
    new_node -> next = NULL;
    int index = hash_func(key);
    if(hashtable[index]==NULL){
        hashtable[index] = new_node;
    }
    else{
        Node* head = hashtable[index];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        } // 중복체크
        new_node -> next = hashtable[index];
        hashtable[index] = new_node;
    }

}


int main(void){
    for(int i=0; i<max_size; i++){
        hashtable[i] = NULL;
    }
    add("hi", 3);
    add("hello", 5);
    for(int i=0; i<max_size; i++){
        if(hashtable[i]!=NULL) cout << i << " "<<hashtable[i]->value << endl;
    }


}