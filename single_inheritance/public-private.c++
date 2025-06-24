#include <iostream>
using namespace std;
class Animal{
public:
    int age; // Publlic member, accessible everywhere
};
class Dog : private Animal {
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
            // Note: In this case, Dog is privately inheriting from Animal,
            // so the members of Animal are not accessible inside Dog without public and protected method (function).
        Animal animal;
        Dog dog;
         animal.age = 5; //  'age' is public  in 'Animal' so it can be accessed everywhere
        // dog.age = 5; // Error: 'age' is public in 'Animal' but Dog inherits privately, so it cannot access it directly
        // dog.numLegs = 4; // Error: 'numLegs' is private in 'Dog'
        // dog.numTeeth = 42; // Error: 'numTeeth' is protected in 'Dog'
        cout << dog.speak() << endl; // This will work
        dog.getdata(); // Call getdata to set numLegs and numTeeth
        return 0;

 }

// Output:
// bark!
// Dog has 4 legs and 42 teeth.age5


