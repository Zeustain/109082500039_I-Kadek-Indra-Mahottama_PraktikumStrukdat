#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype temp = S.info[S.top];
        S.top--;
        return temp;
    } else {
        return -1;
    }
}

void printInfo(Stack S) {
    if (S.top >= 0) {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp1, temp2;
    createStack(temp1);
    createStack(temp2);
    while (S.top != -1) {
        Push(temp1, pop(S));
    }
    while (temp1.top != -1) {
        Push(temp2, pop(temp1));
    }
    while (temp2.top != -1) {
        Push(S, pop(temp2));
    }
}

//Nomor 2
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.info[S.top] > x) {
        Push(temp, pop(S));
    }
    Push(S, x);
    while (temp.top != -1) {
        Push(S, pop(temp));
    }
}

//Nomor 3
void getInputStream(Stack &S) {
    char input;
    cout << "Masukkan angka: ";
    while (cin.get(input) && input != '\n') {
        if (input >= '0' && input <= '9') {
            int n = input - '0';
            Push(S, n);
        }
    }
}