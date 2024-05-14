#include <iostream>
using namespace std;

class Node
{
public:
    string judulBuku;
    long ISBN;
    string namaPenulis;
    Node* next;
    Node* prev;
};

class Perpustakaan
{
public:
    Node* head;
    Node* tail;

    Perpustakaan(){
        head = nullptr;
        tail = nullptr;
    }

    void push(string judulBuku, long ISBN, string namaPenulis){
        Node* newNode = new Node;
        newNode->judulBuku = judulBuku;
        newNode->ISBN = ISBN;
        newNode->namaPenulis = namaPenulis;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr)
        {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void hapusbuku(string judulBuku){
        Node* hapus = head;
        while(hapus != nullptr){
            if(hapus->judulBuku == judulBuku){
                if(hapus == head){
                    head = hapus->next;
                if(head != nullptr)
                    head->prev = nullptr;
                } else if(hapus == tail){
                    tail = hapus->prev;
                if(tail != nullptr)
                    tail->next = nullptr;
                } else {
                    hapus->prev->next = hapus->next;
                    hapus->next->prev = hapus->prev;
                }
                delete hapus;
                return;
            }
            hapus = hapus->next;
        }
        cout << "Buku tidak ditemukan\n";
    }
};

int main(){

    Perpustakaan list;
    string judulBuku, namaPenulis;
    long ISBN;
    int pilih, jumlahBuku;

    while (true)
    {
        cout << "Text pembukaan\n";
        cout << "1. Tambah Buku\n";
        cout << "4. Hapus Buku\n"; 
        cout << "Text Menu\n";
        cout << "Text Pilih Menu: "; cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "\nJumlah buku yang ingin di input: "; cin >> jumlahBuku;
            for (int i = 0; i < jumlahBuku; i++) {
                cout << "\nBuku " << i+1 << endl;

                cout << "Judul Buku: ";
                cin.ignore();
                getline(cin, judulBuku);
                cout << "ISBN: ";
                cin >> ISBN;
                cout << "Nama Penulis: ";
                cin.ignore();
                getline(cin, namaPenulis);

                list.push(judulBuku, ISBN, namaPenulis);
            }
            break;
        
        case 4:
            cout << "\nMasukkan buku yang ingin dihapus: ";
            cin.ignore();
            getline(cin, judulBuku);
            list.hapusbuku(judulBuku);
            break;

        default:
            cout << "text salah input\n\n";
            break;
        }
    }
    return 0;
}
