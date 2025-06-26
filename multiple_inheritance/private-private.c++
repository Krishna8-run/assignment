#include <iostream>
using namespace std;

// Base classes
class Animal {
private:
    string name;
public:
    Animal(string n) : name(n) {}
    void speak() {
         cout << "Animal: " << name << endl; }
};

class Pet {
protected:
    int age;
public:
    Pet(int a) : age(a) {}
    void showAge() {
         cout << "Pet age: " << age << endl; }
};

// Derived classes with different inheritance modes

// 1. Public inheritance from both
class Dog : public Animal, public Pet {
public:
    Dog(string n, int a) : Animal(n), Pet(a) {}
    void info() {
        speak();
        showAge();
    }
};

// 2. Protected inheritance from both
class Cat : protected Animal, protected Pet {
public:
    Cat(string n, int a) : Animal(n), Pet(a) {}
    void info() {
        speak();
        showAge();
    }
};

// 3. Private inheritance from both
class Rabbit : private Animal, private Pet {
public:
    Rabbit(string n, int a) : Animal(n), Pet(a) {}
    void info() {
        speak();
        showAge();
    }
};

// 4. Mixed: public from Animal, private from Pet
class Parrot : public Animal, private Pet {
public:
    Parrot(string n, int a) : Animal(n), Pet(a) {}
    void info() {
        speak();
        showAge();
    }
};

// 5. Mixed: protected from Animal, public from Pet
class Hamster : protected Animal, public Pet {
public:
    Hamster(string n, int a) : Animal(n), Pet(a) {}
    void info() {
        speak();
        showAge();
    }
};

int main() {
    Dog d("Buddy", 5);
    d.info();

    Cat c("Kitty", 3);
    c.info();

    Rabbit r("Bunny", 2);
    r.info();

    Parrot p("Polly", 1);
    p.info();

    Hamster h("Hammy", 4);
    h.info();

    return 0;
}

/*output
 Animal: Buddy
 Pet age: 5
 Animal: Kitty
 Pet age: 3
 Animal: Bunny
 Pet age: 2
 Animal: Polly
 Pet age: 1
 Animal: Hammy
 Pet age: 4 */
