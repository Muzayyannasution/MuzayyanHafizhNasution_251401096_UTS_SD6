#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insertFirst( int n ) {
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail -> next = head;
    } else {
        newNode -> next = head;
        head = newNode;
        tail -> next = head;
    }   
}

void insertLast ( int n ) {
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL){
        head = newNode;
        tail = newNode;
        tail -> next = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
        tail -> next = head;
    }
}

void deleteLast () {
    if (head == NULL) {
        cout << "Kosong!";
        return;
    }

    if (head == tail) {
        delete head;
        head == NULL;
        tail = NULL;
        return;
    }

    node *p = head;
    while (p -> next != tail) {
        p = p -> next;
    }

    delete tail;
    tail = p;
    tail -> next = head;
}

void display () {
    if (head = NULL) { 
        cout << "Nama kosong!";
        return;
    }
    node *temp = head;
    cout << "Isi nama dengan presentase: ";
    do {
        cout << temp -> value << " ->";
        temp = temp -> next;
    } while (temp != head);
    cout << "(head)" << endl;
    }

int main()
{
    system("cls");
    cout << "pilih menu: " << "\n1. Insert tail" << "\n2. Insert head" << "\n3. Delete tail" << "\n4. Tampilkan karyawan sempurna";
    if (1) {
        cout << "nama: ";
    }
}