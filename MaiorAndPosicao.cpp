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
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("\n");
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

    void maiorN(int *maior, int *posicao){
        int pos=1;
        Node* aux = start;
        *maior = aux->value;
        while (aux != NULL) {
            if(aux->value > *maior){
                *maior = aux->value;
                *posicao = pos;
            }
            aux = aux->next;
            pos++;
        }
    }
};

int main() {

    List l;
    l.pushFront(10);
    l.pushFront(3);
    l.pushBack(3);
    l.pushBack(5);
    l.pushFront(8);
    l.pushBack(50);
    l.pushFront(12);
    l.pushBack(1);
    l.pushBack(75);
    l.pushFront(25);
    l.print();
    int m=0, p=0;
    l.maiorN(&m, &p);
    cout << "O maior numero da lista é: " << m << " na posição: " << p << endl;

    return 0;
}
