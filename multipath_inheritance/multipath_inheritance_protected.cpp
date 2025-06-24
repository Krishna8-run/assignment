#include <iostream>
using namespace std;

// Grand base class with public, protected, and private members
class GrandBase {
private:
    int priv = 1;
protected:
    int prot = 2;
public:
    int pub = 3;

    void show() {
        cout << "GrandBase: priv=" << priv << ", prot=" << prot << ", pub=" << pub << endl;
    }
};

// Base1 and Base2 inherit from GrandBase using virtual protected inheritance
class Base1 : virtual protected GrandBase {
public:
    void showBase1() {
        cout << "Base1: pub=" << pub << ", prot=" << prot << endl;
    }
};

class Base2 : virtual protected GrandBase {
public:
    void showBase2() {
        cout << "Base2: pub=" << pub << ", prot=" << prot << endl;
    }
};

// Derived class using public inheritance
class DerivedPublic : public Base1, public Base2 {
public:
    void showDerived() {
        cout << "DerivedPublic accessing pub=" << pub << ", prot=" << prot << endl;
    }
};

// Derived class using protected inheritance
class DerivedProtected : protected Base1, protected Base2 {
public:
    void showDerived() {
        cout << "DerivedProtected accessing pub=" << pub << ", prot=" << prot << endl;
    }
};

// Derived class using private inheritance
class DerivedPrivate : private Base1, private Base2 {
public:
    void showDerived() {
        cout << "DerivedPrivate accessing pub=" << pub << ", prot=" << prot << endl;
    }
};

int main() {
    cout << "\n--- DerivedPublic ---\n";
    DerivedPublic obj1;
    obj1.show();
    obj1.showBase1();
    obj1.showBase2();
    obj1.showDerived();
    // obj1.pub = 100; // ❌ pub is now protected in Base1/Base2

    cout << "\n--- DerivedProtected ---\n";
    DerivedProtected obj2;
    obj2.showDerived();

    cout << "\n--- DerivedPrivate ---\n";
    DerivedPrivate obj3;
    obj3.showDerived();

    return 0;
}
