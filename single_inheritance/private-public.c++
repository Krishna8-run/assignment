#include <iostream>
using namespace std;
class Animal{
private:
    int age; // Private member, not accessible outside this class
};
class Dog : public Animal {
private:
        int numLegs;
protected:
       int numTeeth;
public:
       string speak() {
           return "bark!";
       }
       void getdata(){
              // This function can access private members of Animal
              // age = 5; // Error: 'age' is private in 'Animal'
              numLegs = 4; // This works, as numLegs is private in Dog
              numTeeth = 42; // This works, as numTeeth is protected in Dog
       }
 };
 int main() {
        Dog dog;
        // dog.age = 5; // Error: 'age' is private in 'Animal'
        // dog.numLegs = 4; // Error: 'numLegs' is private in 'Dog'
        // dog.numTeeth = 42; // Error: 'numTeeth' is protected in 'Dog'
        cout << dog.speak() << endl; // This will work
        return 0;

 }