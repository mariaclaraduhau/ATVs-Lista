#include<iostream>
using namespace std;


struct Node {

    int value;
    Node* next;

    Node(int _value) {
        value = _value;
        next = NULL;
    }

};

struct List {

    Node* start;
    Node* end;
    int s;

    List() {
        start = NULL;
        end = NULL;
        s = 0;
    }

    // O(1)
    bool empty() {
        return start == NULL && end == NULL;
    }

    // O(1)
    void pushBack(int value) {
        Node* n = new Node(value);
        s++;
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        end->next = n;
        end = n;
    }

    // O(1)
    void pushFront(int value) {
        Node* n = new Node(value);
        s++;
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        n->next = start;
        start = n;
    }

    // O(n)
    void print() {
        Node* aux = start;
        while (aux != NULL) {
            cout << aux->value << " -> ";
            aux = aux->next;
        }
        cout << "\n";
    }

    // O(1)
    int size() {
        return s;
    }

    // O(1)
    void popFront() {

        if (empty()) return;

        if (size() == 1) {
            delete(start);
            start = NULL;
            end = NULL;
            s = 0;
            return;
        }

        Node *aux = start;
        start = start->next;
        delete(aux);
        s--;

    }

    // O(n)
    void popBack() {

        if (empty()) return;

        if (size() == 1) {
            delete(start);
            start = NULL;
            end = NULL;
            s = 0;
            return;
        }

        Node *aux = start;
        while (aux->next != end) {
            aux = aux->next;
        }

        delete(end);
        end = aux;
        end->next = NULL;
        s--;

    }

    //O(n)
    void insert(int v, int p) {

        if (p <= 0) {
            pushFront(v);
            return;
        }

        if (p >= s) {
            pushBack(v);
            return;
        }

        Node *n = new Node(v);
        s++;

        Node *a = start;
        for (int i = 0; i < p - 1; i++) {
            a = a->next;
        }

        n->next = a->next;
        a->next = n;

    }

};

int main() {

    List l;
    int n, m, pag, cont=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m;
        l.pushBack(m);
    }

    cin >> pag;

    Node* aux = l.start;
    while (aux != NULL) {
        if(aux ->value - pag <= 0){
            cont++;
            pag -= aux->value;
        }
        aux = aux->next;
    }
    l.print();
    cout << cont;

    return 0;
}