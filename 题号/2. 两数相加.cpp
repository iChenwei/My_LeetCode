// 模拟 - 列竖式加法
/*
    题解：
    - 注意考虑进位
    - 需要变动链表的首节点，就要设置虚拟头节点（dummy）
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *dummy = new ListNode(-1);
       ListNode *curr = dummy;
       int t = 0;  // 进位
       // 模拟加法
       while(l1 || l2 || t) {  // 三个位置需要相加（且两个结点都加完时，进位不为零，需要额外补充一个结点）
           if(l1) {
               t += l1->val;
               l1 = l1->next;
           }
           if(l2) {
               t += l2->val;
               l2 = l2->next;
           }
           curr->next = new ListNode(t % 10); // 更新结果
           curr = curr->next;
           t /= 10; // 更新进位值
       }
       return dummy->next;
    }
};