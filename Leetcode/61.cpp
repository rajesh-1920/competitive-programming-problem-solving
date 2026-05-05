#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
// cout << fixed << showpoint << setprecision(10);
#define dbg(x) cout << #x << " = " << x << '\n'

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        ListNode *tail = head;
        int n = 1;
        while (tail->next)
        {
            tail = tail->next;
            n++;
        }

        k %= n;
        if (k == 0)
            return head;

        tail->next = head; // make circular
        int stepsToNewTail = n - k;
        ListNode *new_tail = head;
        for (int i = 1; i < stepsToNewTail; ++i)
            new_tail = new_tail->next;

        ListNode *new_head = new_tail->next;
        new_tail->next = nullptr;
        return new_head;
    }
};
//-----------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        ListNode *head = new ListNode(1,
                                      new ListNode(2,
                                                   new ListNode(3,
                                                                new ListNode(4,
                                                                             new ListNode(5)))));
        Solution aa;
        head = aa.rotateRight(head, 2);
        while (head != NULL)
        {
            cout << head->val << ' ';
            head = head->next;
        }
    }
    return 0;
}
