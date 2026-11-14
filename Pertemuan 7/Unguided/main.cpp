#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack S;

    cout << "=== Nomor 1 ===" << endl;
    cout << "Hello world!" << endl;
    
    createStack(S);
    Push(S, 3);
    Push(S, 4);
    Push(S, 8);
    pop(S);
    Push(S, 2);
    Push(S, 3);
    pop(S);
    Push(S, 9);
    
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    cout << "=== Nomor 2 ===" << endl;
    cout << "Hello world!" << endl;
    
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    cout << "=== Nomor 3 ===" << endl;
    cout << "Hello world!" << endl;
    
    createStack(S);
    getInputStream(S);
    
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    return 0;
}