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
void display() {
    if (head == nullptr) {
        cout << "Linked list kosong.\n";
        return;
    }

    Node* temp = head;
    cout << "\n== Daftar Mahasiswa ==\n";
    while (temp != nullptr) {
        cout << "NIM     : " << temp->data.nim << endl;
        cout << "Nama    : " << temp->data.nama << endl;
        cout << "Jurusan : " << temp->data.jurusan << endl;
        cout << "-------------------------\n";
        temp = temp->next;
    }
}
void remove(string nim) {
    if (head == nullptr) {
        cout << "Linked list kosong.\n";
        return;
    }

    if (head->data.nim == nim) {
        Node* del = head;
        head = head->next;
        delete del;
        cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data.nim != nim) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
    } else {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus.\n";
    }
}
int main() {
    int pilihan, posisi;
    Mahasiswa mhs;
    string nimCari;

    do {
        cout << "\n=== MENU DATA MAHASISWA (LINKED LIST) ===\n";
        cout << "1. Tambah Mahasiswa (Add)\n";
        cout << "2. Sisipkan Mahasiswa (Insert)\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Hapus Mahasiswa (berdasarkan NIM)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM     : "; cin >> mhs.nim;
                cout << "Masukkan Nama    : "; cin.ignore(); getline(cin, mhs.nama);
                cout << "Masukkan Jurusan : "; getline(cin, mhs.jurusan);
                add(mhs);
                break;
            case 2:
                cout << "Masukkan NIM     : "; cin >> mhs.nim;
                cout << "Masukkan Nama    : "; cin.ignore(); getline(cin, mhs.nama);
                cout << "Masukkan Jurusan : "; getline(cin, mhs.jurusan);
                cout << "Masukkan posisi penyisipan: "; cin >> posisi;
                insert(mhs, posisi);
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> nimCari;
                remove(nimCari);
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}


