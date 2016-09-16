/*
 * [Source] https://leetcode.com/problems/
 * [Difficulty]: 
 * [Tag]: 
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// [Solution]:
// [Corner Case]:
class Solution {
private:
    ListNode* reversePiece(ListNode* slow, ListNode* fast) {
        // reverse nodes from slow+1 to fast
        ListNode* next = fast->next, * tail = slow->next;
        while (tail->next != next) {
            cout << tail->val << endl;
            ListNode* tmp = tail->next;
            tail->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        return tail;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy, * fast = slow;
        while (fast->next != NULL) {
            // first move fast
            for (int i = 0; i < k; ++i) {
                if (fast == NULL)
                    return dummy.next;
                fast = fast->next;
            }

            slow = reversePiece(slow, fast);
            fast = slow;
        }

        return dummy.next;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;

    //ListNode* head = sol.reverseKGroup(&n1, 6);
    //ListNode* head = sol.reverseKGroup(&n1, 7);
    ListNode* head = sol.reverseKGroup(&n1, 3);
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;

    return 0;
}
