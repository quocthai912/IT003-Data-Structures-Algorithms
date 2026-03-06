// Đây là cách tối ưu nhất của bài toán Delete elements value trong Linked List
// Bằng cách sử dụng Node ảo (Dummy Node) ta giả sử luôn có 1 nút ảo trỏ tới nút đầu
// Cách này tối ưu ở chỗ, ta không cần phải xử lí riêng các test case có nút đầu có giá trị bằng value
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
    ListNode *removeElements(ListNode *head, int val)
    {
        // Danh sách rỗng
        if (head == nullptr)
            return nullptr;
        // Danh sách chỉ có 1 nút
        if (head->next == nullptr)
        {
            if (head->val == val)
                return nullptr;
            return head;
        }
        ListNode dummyNode(0); // Khai báo 1 đối tượng ListNode dummyNode có value = 0 và có địa chỉ riêng
        dummyNode.next = head;
        ListNode *curr = &dummyNode; // Khai báo con trỏ curr trỏ tới địa chỉ của dummyNode
        // Lúc này dummyNode đã là 1 node chính hiệu
        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }
        return dummyNode.next;
    }
};