#include <iostream>
using namespace std;

class Feature {
public:
    char Name[30];
    Feature(const char n[]) {
        int i = 0;
        while (n[i] != '\0') { Name[i] = n[i]; i++; }
        Name[i] = '\0';
    }
    virtual void analyze() = 0;
    virtual ~Feature() {}
};

class LandFeature : public Feature {
public:
    LandFeature(const char n[]) : Feature(n) {}
    void analyze() { cout << Name << " - Land feature detected" << endl; }
};

class WaterFeature : public Feature {
public:
    WaterFeature(const char n[]) : Feature(n) {}
    void analyze() { cout << Name << " - Water feature detected" << endl; }
};

class Node {
public:
    int FeatureID;
    Feature* data;
    Node* next;
    Node(int id, Feature* f) {
        FeatureID = id;
        data = f;
        next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() { head = NULL; }

    void insertAtEnd(int id, Feature* f) {
        Node* n = new Node(id, f);
        if (!head) head = n;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
        }
    }

    void deleteByID(int id) {
        if (!head) return;
        if (head->FeatureID == id) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->FeatureID != id) temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    void displayAll() {
        Node* temp = head;
        while (temp) {
            cout << "ID: " << temp->FeatureID << " -> ";
            temp->data->analyze();
            temp = temp->next;
        }
    }

    void reverseList() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Mountain"));
    list.insertAtEnd(4, new WaterFeature("Ocean"));
    cout << "All features:" << endl;
    list.displayAll();
    list.deleteByID(2);
    cout << "\nAfter deleting ID 2:" << endl;
    list.displayAll();
    list.reverseList();
    cout << "\nAfter reversing list:" << endl;
    list.displayAll();
    return 0;
}
