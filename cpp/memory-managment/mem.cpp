#include "iostream"
#include <memory>
#include "Dud.cpp"

using namespace std;

/**
 * A pointer itself is a small object thats contained in the stack
 * and points to an object in the free-store
 */

void openingStatement() {
    // creating a new pointer that points to a new Dud instance
    // the word new allocates the new instance space in the free-store
    // while the pointer is saved on the Stack and will be cleaned from
    // memory automatically once it goes out of scope
    Dud* dud = new Dud();

    // our Dud talks a lot
    dud->talk();

    // deleting our Dud instance from the free-store since we don't need it anymore
    // if our Dud instance is not cleaned from memory like that we got a memory leak
    delete(dud);
}

void stackVsFreeStore() {
    // creating dud on the stack
    Dud dud(1);
    // this will invoke the constructor and will create a new dud on the stack
    // the advantage of creating objects on the stack is once the dud is out of scope
    // he will be automatically poped from the stack therefore cleaned from memory
    // the disadvantage however is that we can't move ownership of that memory object
    // to a different function, that means that once the function it was created in ends
    // it will be deleted from memory, which means we shouldn't pass pointers to it
    // to different functions as arguments since once the calling function ends, the
    // object will be deleted which can cause a null exception in the second function
    // that might still try to access it

    // the solution is to construct the object on the free-store using the 'new' keyword
    Dud* dud2 = new Dud();
    // then we can pass our dud2 pointer to the function as an argument and the object
    // will remaind on the free-store until we decide to delete it with the 'delete()' function
    // but be careful if somehow we forget to delete it, it will stay in memory forever
    // which will cause a memory-leak
}

void commonMistake1() {
    // this is an example of cases where an object instance is created on the free-store
    // but would never get cleaned which ends up in a memory-leak

    Dud* dud = new Dud();

    // example 1, if statements
    string userInput = "";

    // this if statement could miss the delete call and not remove our dud from memory depending
    // on the users input
    if (userInput == "start talking") {
        dud->talk();
        delete(dud);
    } else {
        cout << "are you sure our Dud shouldn't start talking? Y/N? ";
        userInput = "getting input";
        if (userInput == "N") {
            // get input again...
        }
    }
}

void funcThatThrowsException() {
    throw new exception();
}

void commonMistake2() {
    // this is an example of cases where an object instance is created on the free-store
    // but would never get cleaned which ends up in a memory-leak

    try {

        Dud* dud = new Dud();

        dud->talk();

        // our function could throw an exception which will cause it to
        // skip the rest of the code and will directly run the catch statement
        // meaning dud will never get deleted from the free-store

        funcThatThrowsException();

        // this will not run if the function call above will throw an exception
        // which will cause a memory leak
        delete(dud);

    } catch (exception e) {
        cout << "we got an exception" << endl;
    }
}

void stack_tutorial() {
    // This will create our dud on the stack, which means that once it goes out
    // of scope, it will be removed from the memory automatically
    Dud j(1);
    j.talk();
}

void movingPointerOwnershipExample(unique_ptr<Dud> j) {}
void passingPointerByReferrenceExample(unique_ptr<Dud>& j) {
    j->talk();
    j.reset();
}
void passingPointerByReferrenceSaferExample(const unique_ptr<Dud>& j) {
    // this function cannot modify the unique pointer itself, it can
    // however modify the data itself
    j->talk();
}


void unique_pointer_tutorial() {
    // This will create our dud on the free-store, with the unique pointer our data will
    // be removed from the free-store automatically once it goes out of scope
    unique_ptr<Dud> j = unique_ptr<Dud>(new Dud(1));

    // an empoty unique pointer contains null
    unique_ptr<Dud> j3;

    // access the object that a pointer points to with the arrow '->'
    j->talk();

    // get the pointer
    Dud* p2 = j.get();

    // note!
    // this
    j->talk();
    // is equal to this
    j.get()->talk();

    // To delete the data inside a unique pointer never use the delete method
    // instead use the 'reset()' function, it will delete the data from memory and
    // will make the pointer empty
    j.reset();
    // you can also reset a pointer and give it a new value by doing:
    j.reset(new Dud);

    // checking if a pointer is empty or not
    if (j) 
    {
        // not empty
    }
    else
    {
        // empty
    }

    // its impossible to copy a unique pointer!
    // which is why when we need to pass the pointer to a function
    // we are moving it to that function using the 'move(pointer_here)' function
    movingPointerOwnershipExample(move(j));

    // NOTE!
    // moving the pointer to another function will make the pointer in the 
    // calling function empty,

    // to get around this we can lend the pointer and not give the new function
    // ownership of it in the case that we still need it in the calling function
    // so if we want to do something with the pointer without moving ownership of it
    // we simply pass it to the new function by referrence

    passingPointerByReferrenceExample(j);

    // Warning! the pointer could go out of scope in the calling function which will
    // delete the memory it points to! the function that uses the referrence could also
    // reset the pointer which will make it empty in the calling function as well, to protect
    // us from that we can pass the pointer referrence as const
    passingPointerByReferrenceSaferExample(j);

    // also once the unique pointer is moved (not lended) the a new function it becomes its
    // new scope which means the memory it points to will be deleted only after
    // it goes out of scope in the new function, basically the new function gets ownership of it

    // print out the contents of a pointer
    cout << j.get() << endl;

    // its also possible to return a unique pointer from a function
    // and its wonership will be passed to where the function returns to
}

int main(int argc, char const *argv[])
{
    cout << "=+= memory managment class =+=" << endl << endl;

    openingStatement();

    commonMistake1();

    commonMistake2();

    stack_tutorial();

    unique_pointer_tutorial();

    cout << "" << endl;

    system("pause");

    return 0;
}