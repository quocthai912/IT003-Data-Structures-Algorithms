/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

struct NODE
{
    char info;
    NODE *pNext;
};
struct queue
{
    NODE *front;
    NODE *back;
};
NODE *CreatNode(int x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
#include <string.h>
#include <sstream>
NODE *initNode(char s)
{
    NODE *p = new NODE;
    p->info = s;
    p->pNext = nullptr;
    return p;
}
bool isEmpty(const queue &q)
{
    return q.front == nullptr;
}
void enQueue(queue &q, NODE *p)
{
    if (isEmpty(q))
        q.front = q.back = p;
    else
    {
        q.back->pNext = p;
        q.back = p;
    }
}
bool deQueue(queue &q)
{
    if (isEmpty(q))
        return false;
    NODE *p = q.front;
    q.front = q.front->pNext;
    delete p;
    if (q.front == nullptr)
        q.front = q.back = nullptr;
    return true;
}
char front(const queue &q)
{
    return q.front->info;
}
char back(const queue &q)
{
    return q.back->info;
}
void chuanHoaChuoi(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
}
void createQueue(queue &q)
{
    q.front = q.back = nullptr;
    string chuoiKiemTra;
    getline(cin, chuoiKiemTra);
    if (chuoiKiemTra == "")
    {
        cout << "Empty";
        return;
    }
    chuanHoaChuoi(chuoiKiemTra);
    for (int i = chuoiKiemTra.length() - 1; i >= 0; i--)
    {
        enQueue(q, initNode(chuoiKiemTra[i]));
    }
    bool palindrome = true;
    NODE *p = q.front;
    for (int i = 0; i < chuoiKiemTra.length(); i++)
    {
        if (chuoiKiemTra[i] != p->info)
        {
            palindrome = false;
            break;
        }
        p = p->pNext;
    }
    if (palindrome)
        cout << "True";
    else
        cout << "False";
}
int main()
{
    queue q;
    createQueue(q);
    return 0;
}
