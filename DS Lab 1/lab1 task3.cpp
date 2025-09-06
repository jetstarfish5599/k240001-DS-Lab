#include <iostream>
using namespace std;

class Box {
private:
//required  pointer
    int* data;

public:
    //Constructor
    Box(int value = 0) {
        data = new int(value); 
    }

    //Destructor
    ~Box() {
        delete data;
    }

    //Copy Constructor
    Box(const Box& other) {
        data = new int(*other.data);
    }

    //CopyOperator
    Box& operator=(const Box& other) {
        if (this != &other) {
            delete data;                // free old memory
            data = new int(*other.data); // copy new value
        }
        return *this;
    }

    //Getter setter
    int getValue() const { return *data; }
    void setValue(int value) { *data = value; }
};


int main() {
    Box b1(10);   
    //Copy Coonstructor     
    Box b2 = b1;     

    b2.setValue(20);  

    cout << "b1 value: " << b1.getValue() << endl; 
    cout << "b2 value: " << b2.getValue() << endl; 
    //assign value
    Box b3(30);
    b3 = b1;         
    b3.setValue(40);
    cout << "b1 value: " << b1.getValue() << endl;
    cout << "b3 value: " << b3.getValue() << endl;

    return 0;
}