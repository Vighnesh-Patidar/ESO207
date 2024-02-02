#include<iostream>
#include<cmath>

using namespace std;

// implement a circular linked list with the following operations:
// 1. remove the next kth node from the current node
// list must be initialized with n nodes, each with a unique integer value from 1 to n
// list must be printed after only the last node remains
// dont use any other inbuilt functions or libraries
// implement from scratch
// print the deleted nodes in the order they are deleted

struct Node {
    int data;
    Node* next;
};

int main(){
    int n, k;
    cin >> n >> k;
    Node* head = new Node;
    head->data = 1;
    Node* current = head;
    for(int i = 2; i <= n; i++){
        current->next = new Node;
        current = current->next;
        current->data = i;
    }
    current->next = head;
    current = head;
    while(current->next != current){
        for(int i = 1; i < k-1; i++){
            current = current->next;
        }
        Node* temp = current->next;
        cout << temp->data << " ";
        current->next = current->next->next;
        delete temp;
        current = current->next;
    }
    cout << current->data << endl;
    return 0;
}