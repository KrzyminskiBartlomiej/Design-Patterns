#include <iostream>
#include <vector>

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

    void getName(){

        cout << "Hi, give me Your name" << endl;
        cin >> guestName;
        guestList.push_back(guestName);
    }

    void readList(){

        for(int i = 0; i < guestList.size(); i++){

            cout << guestList[i] << endl;
        }
    }

private:
    string guestName;
    vector < string > guestList;

    // private constructor and destructor
    SingletonClass(){

        cout << "SingletonClass instance created!\n"; // constructor
    }

    ~SingletonClass(){} // destructor

    // private copy constructor and assignment operator
    SingletonClass(const SingletonClass &); // copy constructor
    SingletonClass & operator = (const SingletonClass &); // assignment operator

    static SingletonClass * m_instanceSingleton;
};


SingletonClass * SingletonClass::m_instanceSingleton = nullptr; //creating singleton instance

int main() {

    // these two blocks of code shows that we are working on one and only instance
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

    cout << endl << endl << endl;

    // now it's time to use Singleton in basic example
    // in this case Singleton will be guest list
    // assume that Singleton gather informations about new guests
    // when they came (create new pointer) to our party (program).
    // all data will be stored in std::vector

    SingletonClass * guest1;
    guest1 = guest1->getInstance();
    guest1->getName();

    SingletonClass * guest2;
    guest2 = guest2->getInstance();
    guest2->getName();

    SingletonClass * guest3;
    guest3 = guest3->getInstance();
    guest3->getName();

    cout << endl;

    SingletonClass * locay;
    locay = locay->getInstance();
    locay->readList();

    return 0;
}
