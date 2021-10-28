#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};
class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}
void free_singly_linked_list(SinglyLinkedListNode* node) 
{
    while (node) 
    {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
SinglyLinkedListNode* temp =new SinglyLinkedListNode(data);
SinglyLinkedListNode* p    = head;
int c = 0;
temp ->data = data;
if(position==0)
{
temp ->data = data;
temp->next  = head;
head = temp; 
return head;
}
else
{
    while(position-1!=c)
    {
        p = p->next;
        c++;
    }
   temp->next = p->next;
   p->next = temp;
   return head;

}
}

int main()