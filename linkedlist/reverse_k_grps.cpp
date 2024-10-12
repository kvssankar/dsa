/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* kReverse(Node* head, int k) {
    // Check if there are at least 'k' nodes left in the list
    int length = getLength(head);
    if (length < k) return head;  // Not enough nodes to reverse, return original head

    Node *curr, *prev, *next;
    curr=next=head;
    prev=NULL;

    int count = 0;

    // Reverse the first 'k' nodes
    while (next != NULL && count < k) {
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // 'head' is now the last node in the reversed group. Connect it to the next group.
    if (next != NULL) {
        head->next = kReverse(next, k);
    }

    // 'prev' is the new head of the reversed group
    return prev;
}

//1 2 3 4 5 6 7 8
//will becomee
//3 2 1 6 5 4 7 8