// 链表
/*
    思路：
    - 确定链表的长度
    - 找到倒数第i个对应的正数的序号:
        倒数第1个结点，对应正数第n个，二者之和为(n+1);
        倒数第k个结点，对应正数第(n - k + 1)，二者
    - 移动到被删结点前一个结点处，将目标结点删除
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        // 求链表长度
        int len = 0;
        for(ListNode *l = head; l != nullptr; l = l->next) {
            len ++;
        }

        if(k == len) return head = head->next; // 删除第一个结点

        ListNode *h = head;
        for(int i = 0; i < len - k - 1; i++) { // 找到目标结点的前一个结点
            h = h->next;
        }
        h->next = h->next->next; // 删除目标结点
        return head;
    }
};

