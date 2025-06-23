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
