#include <iostream>
using namespace std;

// First base class
class Base1 {
public:
    int pub_base1;
protected:
    int prot_base1;
private:
    int priv_base1;
public:
    Base1() : pub_base1(1), prot_base1(2), priv_base1(3) {
        cout << "Base1 constructor called." << endl;
        showBase1(); // Show Base1 members
    }
    void showBase1() {
        cout << "Base1 public: " << pub_base1 << endl;
        cout << "Base1 protected: " << prot_base1 << endl;
        cout << "Base1 private: " << priv_base1 << endl;
    }
};

// Second base class
class Base2 {
public:
    int pub_base2;
protected:
    int prot_base2;
private:
    int priv_base2;
public:
    Base2() : pub_base2(4), prot_base2(5), priv_base2(6) {
        cout << "Base2 constructor called." << endl;
        showBase2(); // Show Base2 members
    }
    void showBase2() {
        cout << "Base2 public: " << pub_base2 << endl;
        cout << "Base2 protected: " << prot_base2 << endl;
        cout << "Base2 private: " << priv_base2 << endl;
    }
};

// Derived1 inherits from Base1 (public)
class Derived1 : public Base1 {
public:
    int pub_derived1;
protected:
    int prot_derived1;
private:
    int priv_derived1;
public:
    Derived1() : pub_derived1(10), prot_derived1(20), priv_derived1(30) {
        // Base1 constructor is called implicitly
        cout << "Derived1 constructor called." << endl;
        showBase1(); // Show Base1 members
    }
    void showDerived1() {
        cout << "Derived1 public: " << pub_derived1 << endl;
        cout << "Derived1 protected: " << prot_derived1 << endl;
        cout << "Derived1 private: " << priv_derived1 << endl;
        cout << "Accessing Base1 public in Derived1: " << pub_base1 << endl;
        cout << "Accessing Base1 protected in Derived1: " << prot_base1 << endl;
    }
};

// Derived2 inherits from Base2 (protected)
class Derived2 : protected Base2 {
public:
    int pub_derived2;
protected:
    int prot_derived2;
private:
    int priv_derived2;
public:
    Derived2() : pub_derived2(100), prot_derived2(200), priv_derived2(300) {
        // Base2 constructor is called implicitly
        cout << "Derived2 constructor called." << endl;
        showBase2(); // Show Base2 members
    }
    void showDerived2() {
        cout << "Derived2 public: " << pub_derived2 << endl;
        cout << "Derived2 protected: " << prot_derived2 << endl;
        cout << "Derived2 private: " << priv_derived2 << endl;
        cout << "Accessing Base2 public in Derived2: " << pub_base2 << endl;
        cout << "Accessing Base2 protected in Derived2: " << prot_base2 << endl;
    }
};

// Hybrid inheritance: Derived3 inherits from both Derived1 and Derived2
class Derived3 : private Derived1, public Derived2 {
public:
    void showAll() {
        // Accessing members from Derived2 (public inheritance)
        cout << "From Derived2 in Derived3: " << pub_derived2 << endl;
        // Accessing base class members through Derived2
        cout << "Base2 public via Derived2: " << pub_base2 << endl;
        cout << "Base2 protected via Derived2: " << prot_base2 << endl;
    }
};

int main() {
    Derived3 obj;
    obj.showAll();
    obj.showDerived2(); // Accessing Derived2 members
    // obj.showDerived1(); // Not accessible due to private inheritance from Derived1 to Derived3
    return 0;
}

/* Output:
 Base1 constructor called.
 Base1 public: 1
 Base1 protected: 2
 Base1 private: 3
 Derived constructor called.
 Base1 public: 1
 Base1 protected: 2
 Base1 private: 3
 Base2 constructor called.
 Base2 public: 4
 Base2 protected: 5
 Base2 private: 6
 Derived2 constructor called.
 Base2 public: 4
 Base2 protected: 5
 Base2 private: 6
 From Derived2 in Derived3: 100
 Base2 public via Derived2: 4
 Base2 protected via Derived2: 5
 Derived2 public: 100
 Derived2 protected: 200
 Derived2 private: 300
 Accessing Base2 public in Derived2: 4
 Accessing Base2 protected in Derived2: 5  */