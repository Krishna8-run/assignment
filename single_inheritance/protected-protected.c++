#include <iostream>
using namespace std;
class Animal{
protected:
    int age; // Protected member, accessible in derived classes
};
class Dog : protected Animal {
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
              age = 5; //  'age' is protected in 'Animal'
              numLegs = 4; // This works, as numLegs is private in Dog
              numTeeth = 42; // This works, as numTeeth is protected in Dog
              cout << "Dog has " << numLegs << " legs and " << numTeeth << " teeth." <<"age"<<age<< endl;
       }
 };
 int main() {
        Dog dog;
        // dog.age = 5; // Error: 'age' is protected in 'Animal'
        // dog.numLegs = 4; // Error: 'numLegs' is private in 'Dog'
        // dog.numTeeth = 42; // Error: 'numTeeth' is protected in 'Dog'
        cout << dog.speak() << endl; // This will work
        dog.getdata(); // Call getdata to set numLegs and numTeeth
        return 0;

 }
