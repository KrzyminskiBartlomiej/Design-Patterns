#include <iostream>

using namespace std;

class SingletonClass {

public:
    static SingletonClass * getInstance() { // static method that returns new SingletonClass object
                                            // if theres no any instance yet

    return (!m_instanceSingleton) ? // condition
        m_instanceSingleton = new SingletonClass : // result if true
        m_instanceSingleton; // result if false
    }

    void readMe(){

        cout << "I can read my adress: ";
    }

private:
    // private constructor and destructor
    SingletonClass() { cout << "SingletonClass instance created!\n";} // constructor
    ~SingletonClass() {} // destructor

    // private copy constructor and assignment operator
    SingletonClass(const SingletonClass &); // copy constructor
    SingletonClass & operator = (const SingletonClass &); // assignment operator

    static SingletonClass * m_instanceSingleton;
};


SingletonClass * SingletonClass::m_instanceSingleton = nullptr; //creating singleton instance

int main() {

    SingletonClass * singleton;
    singleton = singleton->getInstance();
    singleton->readMe();
    cout << singleton << endl;

    // Another object gets the reference of the first object!
    SingletonClass * anotherSingleton;
    anotherSingleton = anotherSingleton->getInstance();
    anotherSingleton->readMe();
    cout << anotherSingleton << endl;

    // is the memory location of singleton Object,
    // same for the duration of the program but
    // different each time the program is run.

    return 0;
}
