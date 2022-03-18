// 链表
/*
    思路：
    - 由于头节点会被改变，所以需要设置虚拟头节点
    - 交换两个结点，每次指针移动的位置都是两个结点的前面!
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *p = dummy;
        while(p->next && p->next->next) { // 只有两个需要被交换的结点都存在时，才会执行交换操作
            ListNode *a = p->next, *b = p->next->next;
            p->next = b;
            a->next = b->next;
            b->next = a;
            p = p->next->next;  // p = a;
        }
        return dummy->next;
    }
};