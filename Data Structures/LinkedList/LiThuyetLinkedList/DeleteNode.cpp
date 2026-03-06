// Đây là bài 237 trong LeetCode
// Các yêu cầu vô cùng bựa như: không được xài nút đầu, xóa nút nhưng không phải xóa nó khỏi bộ nhớ
// => mà chính là xóa giá trị của nó khỏi Linked List!!!!!!!
// Ý tưởng: copy giá trị của node kế tiếp rồi xóa node kế tiếp
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
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};