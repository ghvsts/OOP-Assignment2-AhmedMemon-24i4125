#include <iostream>
using namespace std;

class Node {
public:
    int BookID;
    char Title[50];
    char Author[50];
    Node* next;
    Node* prev;
    Node(int id, const char* t, const char* a) {
        BookID = id;
        int i = 0;
        while (t[i] != '\0') { Title[i] = t[i]; i++; }
        Title[i] = '\0';
        i = 0;
        while (a[i] != '\0') { Author[i] = a[i]; i++; }
        Author[i] = '\0';
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() { head = tail = NULL; }

    void addAtBeginning(int id, const char* t, const char* a) {
        Node* n = new Node(id, t, a);
        if (!head) head = tail = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void addAtEnd(int id, const char* t, const char* a) {
        Node* n = new Node(id, t, a);
        if (!tail) head = tail = n;
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void addAtPosition(int pos, int id, const char* t, const char* a) {
        if (pos <= 1) { addAtBeginning(id, t, a); return; }
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
        if (!temp) { addAtEnd(id, t, a); return; }
        Node* n = new Node(id, t, a);
        n->next = temp->next;
        if (temp->next) temp->next->prev = n;
        temp->next = n;
        n->prev = temp;
        if (!n->next) tail = n;
    }

    void deleteByID(int id) {
        Node* temp = head;
        while (temp && temp->BookID != id) temp = temp->next;
        if (!temp) return;
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        else tail = temp->prev;
        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->BookID << " " << temp->Title << " " << temp->Author << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->BookID << " " << temp->Title << " " << temp->Author << endl;
            temp = temp->prev;
        }
    }
};

int main() {
    DoublyLinkedList lib;
    lib.addAtEnd(1, "1984", "Orwell");
    lib.addAtEnd(2, "Hamlet", "Shakespeare");
    lib.addAtBeginning(3, "Inferno", "Dante");
    lib.addAtPosition(2, 4, "Dracula", "Stoker");
    cout << "Books forward:" << endl;
    lib.displayForward();
    lib.deleteByID(2);
    cout << "\nBooks backward:" << endl;
    lib.displayBackward();
    return 0;
}
