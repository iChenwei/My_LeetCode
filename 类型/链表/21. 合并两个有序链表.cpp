// 链表
/*
    思路：
    - 二路归并算法，每次取两者中较小的结点，加入到新链表中
    - 注意头节点：
        凡是可能改变头节点的操作，都要提前设置一个虚拟头节点（dummy）
    证明：
    - 每次找到当前两个链表中的最小元素
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 设置新链表，采用尾插法，所以设置一个尾结点
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        // 比较并插入
        while(list1 && list2) {
            if(list1->val < list2->val) {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            } 
            else {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        // 有多余
        if(list1) tail->next = list1; 
        if(list2) tail->next = list2;

        return dummy->next;
    }
};