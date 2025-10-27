#include <iostream>
using namespace std;

class Node {
public:
    int id;
    char name[30];
    int tickets;
    Node* next;
    Node(int i, const char* n, int t) {
        id = i; tickets = t;
        int j = 0;
        while (n[j] != '\0') { name[j] = n[j]; j++; }
        name[j] = '\0';
        next = NULL;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;
    Queue() { front = rear = NULL; }

    void enqueue(int id, const char* n, int t) {
        Node* temp = new Node(id, n, t);
        if (!rear) front = rear = temp;
        else {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        if (!front) rear = NULL;
        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->id << " " << temp->name << " " << temp->tickets << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(1, "Ali", 2);
    q.enqueue(2, "Sara", 4);
    q.enqueue(3, "John", 1);
    cout << "Queue:" << endl;
    q.display();
    q.dequeue();
    cout << "\nAfter serving first:" << endl;
    q.display();
    return 0;
}
