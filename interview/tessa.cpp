#include <iostream>
#include <string>

using namespace std;

class Shape{
    protected:
        string name;
    public :
        Shape() : name("default"){
            //name = x;
        }

        Shape(string x) : name(x){
            //name = x;
        }
        void virtual show_shape(){
            cout << name << endl;
        } 
};

class triangle : public Shape{
    private:
    //    string name;
    public :
        triangle(string x) : Shape(x){

        }
        void show_shape() override{
            cout << name << "3"<< endl;
        }
};
class rectangular : public Shape{
    private:
        //string name;
    public :
        rectangular(string x) : Shape(x){

        }
        void show_shape() override{
            cout << name << "4"<< endl;
        }
};

int main(void){
    triangle a("tri");
    rectangular b("rec");
    Shape c;
    a.show_shape();
    b.show_shape();
    c.show_shape();


}