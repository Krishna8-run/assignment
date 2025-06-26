#include <iostream>
using namespace std;

// Base class with private, protected, and public members
class Base {
private:
    int privateVar;
protected:
    int protectedVar;
public:
    int publicVar;
    Base() : privateVar(1), protectedVar(2), publicVar(3) {
        cout << "Base constructor called." << endl;
    }
    void showBase() {
        cout << "Base privateVar: " << privateVar << endl;
        cout << "Base protectedVar: " << protectedVar << endl;
        cout << "Base publicVar: " << publicVar << endl;
    }
};

// First derived class (protected inheritance)
class Derived1 : protected Base {
public:
    void showDerived1() {
        // cout << privateVar; // Not accessible
        cout << "Derived1 protectedVar: " << protectedVar << endl; // Accessible
        cout << "Derived1 publicVar: " << publicVar << endl;       // Accessible
    }
};

// Second derived class (public inheritance)
class Derived2 : public Derived1 {
public:
    void showDerived2() {
        // cout << privateVar; // Not accessible
        cout << "Derived2 protectedVar: " << protectedVar << endl; // Accessible
        cout << "Derived2 publicVar: " << publicVar << endl;       // Accessible
    }
};

int main() {
    Derived2 obj;
    obj.showDerived2();
    obj.showDerived1();
    // obj.showBase(); // Not accessible due to protected inheritance in Derived1   
    // obj.protectedVar; // Not accessible
    // obj.publicVar;    // Not accessible due to protected inheritance in Derived1
    Derived1 obj1;
    obj1.showDerived1();
    // obj1.showBase(); // Not accessible due to protected inheritance
    //obj1.Base();
    
    return 0;
}

/*Output:
Base constructor called.
Derived2 protectedVar: 2
Derived2 publicVar: 3
Derived1 protectedVar: 2
Derived1 publicVar: 3
Base constructor called.
Derived1 protectedVar: 2
Derived1 publicVar: 3
*/
