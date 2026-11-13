#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

struct Queue {
    char data[MAX];
    int front;
    int rear;
};

void init(Queue &q) {
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(Queue q) {
    return q.front == -1 || q.front > q.rear;
}

bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

void enqueue(Queue &q, char huruf) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak dapat menambah data." << endl;
        return;
    }
    if (q.front == -1) {
        q.front = 0;
    }
    q.rear++;
    q.data[q.rear] = huruf;
}

char dequeue(Queue &q) {
    if (isEmpty(q)) {
        return '\0';
    }
    char hurufKeluar = q.data[q.front];
    q.front++;
    
    if (q.front > q.rear) {
        init(q);
    }
    return hurufKeluar;
}

bool isVokal(char c) {
    return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
            c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O');
}

int main() {
    Queue q;
    init(q);

    string kata;
    cout << "Masukkan Kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        enqueue(q, kata[i]);
    }

    cout << "Hasil huruf vokal: ";
    while (!isEmpty(q)) {
        char huruf = dequeue(q);
        
        if (isVokal(huruf)) {
            cout << huruf << " ";
        }
    }
    cout << endl;

    return 0;
}