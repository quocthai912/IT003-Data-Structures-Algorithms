#include <iostream>
#include <sstream>
#include <string.h>
#include <cctype>
using namespace std;
#define MAX 100
struct User
{
    string mssv;
    string name;
};
struct NODE
{
    User info;
    NODE *pNext;
};
NODE *initNODE(User info)
{
    NODE *p = new NODE;
    p->info = info;
    p->pNext = nullptr;
    return p;
}
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
void CreateList(LIST &l)
{
    l.pHead = l.pTail = nullptr;
}
void addTail(LIST &l, NODE *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}
string chuanHoa(string s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
        result += tolower(s[i]);
    return result;
}
void SelectionSort(LIST &l)
{
    NODE *i = l.pHead;
    while (i)
    {
        NODE *minTen = i;
        NODE *j = i->pNext;
        while (j)
        {
            if (chuanHoa(j->info.name) < chuanHoa(minTen->info.name))
            {
                minTen = j;
            }
            j = j->pNext;
        }
        User temp;
        temp = i->info;
        i->info = minTen->info;
        minTen->info = temp;
        i = i->pNext;
    }
}
void Fun(LIST &l)
{
    int soLuong;
    cin >> soLuong;
    cin.ignore();
    for (int i = 0; i < soLuong; i++)
    {
        User thongTin;
        cin >> thongTin.mssv;
        cin.ignore();
        getline(cin, thongTin.name);
        addTail(l, initNODE(thongTin));
    }
    SelectionSort(l);
    NODE *p = l.pHead;
    while (p)
    {
        cout << p->info.mssv << " " << p->info.name << endl;
        p = p->pNext;
    }
}
int main()
{
    LIST l;
    CreateList(l);
    Fun(l);
    return 0;
}