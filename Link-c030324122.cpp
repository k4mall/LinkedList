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
