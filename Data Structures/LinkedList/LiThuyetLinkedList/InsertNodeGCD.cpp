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
public:
    int Euclid(int a, int b)
    {
        while (b != 0)
        {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode *prev = &dummyNode;
        while (prev->next != nullptr && prev->next->next != nullptr)
        {
            int gcd = Euclid(prev->next->val, prev->next->next->val);
            ListNode *insertNode = new ListNode(gcd);
            insertNode->next = prev->next->next;
            prev->next->next = insertNode;
            prev = prev->next->next;
        }
        return dummyNode.next;
    }
};