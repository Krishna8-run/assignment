#include <iostream>
using namespace std;
class Animal{
public:
    int age; // Publlic member, accessible everywhere
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
              // This function can access private and protected members of dog in main
              age = 5; //  'age' is public in 'Animal'
              numLegs = 4; // This works, as numLegs is private in Dog
              numTeeth = 42; // This works, as numTeeth is protected in Dog
              cout << "Dog has " << numLegs << " legs and " << numTeeth << " teeth " <<"age "<<age<< endl;
       }
 };
 int main() {
         Animal animal;
        Dog dog;
         animal.age = 5; //  'age' is public  in 'Animal' so it can be accessed everywhere
         dog.age = 5; //  'age' is public in 'Animal' and inherited publically in Dog so it can be access  directly
        // dog.numLegs = 4; // Error: 'numLegs' is private in 'Dog'
        // dog.numTeeth = 42; // Error: 'numTeeth' is protected in 'Dog'
        cout << dog.speak() << endl; // This will work
        dog.getdata(); // Call getdata to set numLegs and numTeeth
        return 0;

 }



 /*Output:
 bark!
 Dog has 4 legs and 42 teeth age 5  */

