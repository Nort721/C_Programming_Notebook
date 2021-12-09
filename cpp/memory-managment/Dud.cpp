#include <iostream>

using namespace std;

class Dud 
{
    int points;

    public:
        // constructor
        Dud() {
            points = 0;
            cout << "constructing object in " << this << endl;
        }
        // constructor
        Dud(int p) {
            points = p;
            cout << "constructing object in " << this << endl;
        }
        // destructor
        ~Dud() {
            cout << "removing this object from memory address -> " << this << endl;
        }

    public:
        void talk() {
        cout << "talking talking talking " << points << endl;
    }
};