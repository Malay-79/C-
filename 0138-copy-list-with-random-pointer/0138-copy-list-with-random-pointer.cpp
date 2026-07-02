/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertcopyinbetween(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
    }
    void connectRandompointers(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copyNode = temp->next;
            if(temp->random){
                copyNode->random = temp->random->next;
            }
            else{
                copyNode->random=nullptr;
            }
            temp  = temp->next->next;

        }
    }
    Node* getdeepcopy(Node* head){
        Node* temp = head;
        Node* dummynode = new Node(-1);
        Node* res = dummynode;
        while(temp!=NULL){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummynode->next;
    }
    Node* copyRandomList(Node* head) {
        insertcopyinbetween(head);
        connectRandompointers(head);
        return getdeepcopy(head);
    }
};