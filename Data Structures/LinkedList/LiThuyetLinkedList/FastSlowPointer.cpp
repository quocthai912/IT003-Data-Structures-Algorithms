// Bài toán tìm và xóa nút giữa trong Linked List
// Đây là phiên bản tối ưu hơn về mặt bộ nhớ so với Kĩ thuật duyệt nút giữa theo index
// Kĩ thuật fast-slow cho phép người dùng không cần biết trước có bao nhiêu nút cũng như nút ở giữa là index thứ mấy
// Độ phức tạp thuật toán vẫn là O(N) nhưng sẽ khó hiểu hơn so với kĩ thuật duyệt index
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
    ListNode *deleteMiddle(ListNode *head)
    {
        // Danh sách chỉ có 1 nút, sau khi xóa sẽ thành danh sách rỗng
        if (head->next == nullptr)
            return nullptr;
        ListNode *prev = nullptr; // Con trỏ để lưu trữ nút giữa
        ListNode *fast = head;
        ListNode *slow = head;
        // Duyệt fast chạy tới nút cuối
        // Do nút cuối luôn có index gấp đôi nút giữa
        // Nếu Fast tiến tới nút cuối cùng thì lúc này slow sẽ nằm ở nút ở giữa
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }
};
