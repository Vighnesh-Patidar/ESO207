#include<iostream>
#include<cmath>
#include<iomanip>
#include<ctime>
using namespace std;



struct Node {
    int data;
    Node* next;
};

void timeTaken(clock_t start) {
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class CircularLinkedList {
    private:
        Node* head;
        int n;
    public:
        CircularLinkedList(int n) {
            this->n = n;
            head = new Node;
            head->data = 1;
            head->next = head;
            Node* temp = head;
            for(int i = 2; i <= n; i++) {
                Node* newNode = new Node;
                newNode->data = i;
                newNode->next = head;
                temp->next = newNode;
                temp = newNode;
            }
        }

        void removeKthNode(int k) {
            Node* temp = head;
            while(temp->next != temp) {
                for(int i = 1; i < k - 1; i++) {
                    temp = temp->next;
                }
                cout << temp->next->data << " ";
                temp->next = temp->next->next;
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
};

int main() {
    int n, k;
    cin >> n >> k;
    clock_t start = clock();
    CircularLinkedList list(n);
    list.removeKthNode(k);
    timeTaken(start);
    return 0;
    
}

// Time Complexity: O(n)log(n)