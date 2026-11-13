#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* addNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->kiri = nullptr;
    newNode->kanan = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return addNode(value);
    }
    if (value < root->data) {
        root->kiri = insert(root->kiri, value);
    } else if (value > root->data) {
        root->kanan = insert(root->kanan, value);
    }
    return root;
}

void inOrder(Node* root, int &totalSum, int &nodeCount) {
    if (root != nullptr) {
        inOrder(root->kiri, totalSum, nodeCount);
        
        cout << root->data << " ";
        totalSum += root->data;
        nodeCount++;
        
        inOrder(root->kanan, totalSum, nodeCount);
    }
}

int findMin(Node* root) {
    Node* current = root;
    while (current->kiri != nullptr) {
        current = current->kiri;
    }
    return current->data;
}

int main() {
    Node* root = nullptr;
    int input;

    cout << "Masukkan angka:" << endl;
    while (true) {
        cin >> input;
        if (input == 0) {
            break;
        }
        root = insert(root, input);
    }

    if (root == nullptr) {
        cout << "Tree kosong!" << endl;
        return 0;
    }

    int totalSum = 0;
    int nodeCount = 0;

    cout << "\nHasil: ";
    inOrder(root, totalSum, nodeCount);
    cout << endl;

    int minVal = findMin(root);
    double average = (double)totalSum / nodeCount;

    cout << "Nilai Terkecil  : " << minVal << endl;
    cout << "Nilai Rata-rata : " << average << endl;

    return 0;
}