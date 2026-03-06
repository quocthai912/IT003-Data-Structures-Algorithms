// Sắp xếp nửa trái của danh sách liên kết nhỏ hơn số nguyên x và nửa phải lớn hơn hoặc bằng số nguyên x
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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        ListNode *newHead = nullptr;
        ListNode dummyNode(0);
        ListNode *duyetLan1 = head;
        ListNode *duyetLan2 = head;
        bool found = false;
        while (duyetLan1 != nullptr)
        {
            if (duyetLan1->val < x)
            {
                if (found == false)
                {
                    newHead = new ListNode(duyetLan1->val);
                    dummyNode.next = newHead;
                    found = true;
                }
                else
                {
                    newHead->next = new ListNode(duyetLan1->val);
                    newHead = newHead->next;
                }
            }
            duyetLan1 = duyetLan1->next;
        }
        while (duyetLan2 != nullptr)
        {
            if (duyetLan2->val >= x)
            {
                if (found == true)
                {
                    newHead->next = new ListNode(duyetLan2->val);
                    newHead = newHead->next;
                }
                else
                {
                    newHead = new ListNode(duyetLan2->val);
                    dummyNode.next = newHead;
                    found = true;
                }
            }
            duyetLan2 = duyetLan2->next;
        }
        return dummyNode.next;
    }
};