#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student{
    public:
    string name;
    int score;
    Student(string name, int score){
        this-> name = name;
        this-> score = score;
    }
    bool operator <(Student &a){
        return this->score > a.score;
    }
};
int main(void){
    Student arr[] = {
        Student("Cho", 10),
        Student("Jeon", 8),
        Student("jo", 15),
        Student("bake", 7),
        Student("kwon", 30)
    };
    sort(arr, arr+5);
    for(int i=0; i<5; i++){
        cout << arr[i].name << endl;
    }
    return 0;
}

/*
*/