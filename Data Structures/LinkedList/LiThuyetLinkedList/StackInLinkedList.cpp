// Bài Tập đầu tiên sử dụng Stack (Ngăn xếp)
// Chiếm O(n) độ phức tạp thuật toán và O(n) bộ nhớ do sử dụng Stack
#include <bits/stdc++.h>
#include <stack>
using namespace std;
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
    ListNode *doubleIt(ListNode *head)
    {
        // Xây dựng Stack với dữ liệu là các Node
        stack<ListNode *> st;
        ListNode *curr = head;
        // Đấy tất cả các Node vào stack
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->next;
        }
        int carry = 0;
        while (!st.empty())
        {
            // Truyền tham chiếu và thay đổi giá trị
            ListNode *node = st.top();       // Lấy node ở đỉnh stack
            st.pop();                        // Sau khi xử lí xong, lấy node ra khỏi stack
            int sum = node->val * 2 + carry; // Carry là phần dư ở số trước
            node->val = sum % 10;            // Bảo đảm node có giá trị không vượt quá 10
            carry = sum / 10;                // Phần dư cho node tiếp theo
        }
        // Phần dư còn tồn đọng, tức phải thêm node mới
        if (carry > 0)
        {
            ListNode *newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};