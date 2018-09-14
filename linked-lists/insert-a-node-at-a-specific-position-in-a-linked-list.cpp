
// Hackerrank Insert node into linkedlist Solution
// Runs in O(n) where n is length of linkedlist
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {

    SinglyLinkedListNode* n = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    n->data = data;
    
    if(head == NULL)
        return newNode;
    
    
    if(position == 0){
        n->next = head;
        return n;
    }
  
    head->next = insertNodeAtPosition(head->next, data, position - 1);
    
    return head;
}