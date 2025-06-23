#include <iostream>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string jurusan;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

Node* head = nullptr;

void add(Mahasiswa mhs) {
    Node* newNode = new Node{mhs, nullptr};

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    cout << "Data mahasiswa berhasil ditambahkan.\n";
}

void insert(Mahasiswa mhs, int posisi) {
    Node* newNode = new Node{mhs, nullptr};

    if (posisi == 0) {
        newNode->next = head;
        head = newNode;
        cout << "Data mahasiswa disisipkan di posisi 0.\n";
        return;
    }

    Node* temp = head;
    int index = 0;
    while (temp != nullptr && index < posisi - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr) {
        cout << "Posisi tidak valid.\n";
        delete newNode;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Data mahasiswa disisipkan di posisi " << posisi << ".\n";
    }
}

