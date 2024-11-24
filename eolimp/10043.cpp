ListNode* detectCycle(ListNode *head)
{
    ListNode* slow = head, fast = head;
    while(fast != NULL && fast.next != NULL){
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) {
            break;
        }
    }
    if (fast == NULL || fast.next == NULL) {
        return NULL;
    }
    while (head != slow){
        head = head.next;
        slow = slow.next;
    }
    return head;
}
