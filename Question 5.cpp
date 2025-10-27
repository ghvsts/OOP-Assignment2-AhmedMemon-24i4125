#include <iostream>
using namespace std;

class StackArray {
    int* arr;
    int top, size;
public:
    StackArray(int s) {
        size = s; top = -1;
        arr = new int[s];
    }
    void push(int x) { if (top < size - 1) arr[++top] = x; }
    void pop() { if (top >= 0) top--; }
    int peek() { return (top >= 0) ? arr[top] : -1; }
    bool empty() { return top == -1; }
};

class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

class StackList {
    Node* top;
public:
    StackList() { top = NULL; }
    void push(int x) {
        Node* n = new Node(x);
        n->next = top;
        top = n;
    }
    void pop() {
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    int peek() { return top ? top->data : -1; }
    bool empty() { return top == NULL; }
};

int main() {
    StackArray sa(5);
    sa.push(1); sa.push(2); sa.push(3);
    cout << "Array stack top: " << sa.peek() << endl;
    sa.pop();
    cout << "After pop: " << sa.peek() << endl;

    StackList sl;
    sl.push(10); sl.push(20); sl.push(30);
    cout << "Linked stack top: " << sl.peek() << endl;
    sl.pop();
    cout << "After pop: " << sl.peek() << endl;
    return 0;
}
