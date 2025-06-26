#include <iostream>
using namespace std;
class Animal{
private:
    int age; // Private member, not accessible outside this class
public:
    int setAge() {
        age = 6;
        return age; // Public method to set the private member
    }
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
              // age = 5; // Error: 'age' is private in 'Animal'
              numLegs = 4; // This works, as numLegs is private in Dog
              numTeeth = 42; // This works, as numTeeth is protected in Dog
              cout << "Dog has " << numLegs << " legs and " << numTeeth << " teeth age " << setAge() << endl;
       }
 };
 int main() {
        Dog dog;
        // dog.age = 5; // Error: 'age' is private in 'Animal'
        // dog.numLegs = 4; // Error: 'numLegs' is private in 'Dog'
        // dog.numTeeth = 42; // Error: 'numTeeth' is protected in 'Dog'
        cout << dog.speak() << endl; // This will work
              dog.getdata(); // Call getdata to set numLegs and numTeeth and setAge
        return 0;

 }

 /*Output:
 bark!
 Dog has 4 legs and 42 teeth age 6   
 
 */