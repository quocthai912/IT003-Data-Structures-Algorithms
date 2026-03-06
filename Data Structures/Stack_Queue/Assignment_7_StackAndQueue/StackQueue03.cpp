/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

struct NODE
{
    float info;
    NODE *pNext;
};

NODE *CreateNode(float x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
struct stack
{
    NODE *top;
};
bool empty(const stack &s)
{
    return (s.top == NULL);
}
void CreateEmptyStack(stack &s)
{
    s.top = NULL;
}
void push(stack &s, float x)
{
    NODE *p = CreateNode(x);
    if (s.top == NULL)
        s.top = p;
    else
    {
        p->pNext = s.top;
        s.top = p;
    }
}
void pop(stack &s)
{
    if (s.top == NULL)
        return;
    NODE *p = s.top;
    s.top = s.top->pNext;
    delete p;
}
float &top(stack s)
{
    return s.top->info;
}
bool isOperator(char x)
{
    return ((x == '-') || (x == '+') || (x == '*') || (x == '/') || (x == '^'));
}
bool isBracket(char x)
{
    return ((x == '(') || (x == ')'));
}
void InputPostFix(char postix[], int &n)
{
    char k;
    cin >> k;
    n = 0;
    while (k != '#')
    {
        postix[n++] = k;
        cin >> k;
    }
}

float evaluate_expression(char postfix[], int np)
{
    stack st;
    CreateEmptyStack(st);
    for (int i = 0; i < np; i++)
    {
        if (postfix[i] == ' ')
            continue;
        else if (isdigit(postfix[i]))
        {
            string chuyenDoi = "";
            chuyenDoi += postfix[i];
            float so = stof(chuyenDoi);
            push(st, so);
        }
        else
        {
            if (postfix[i] == '+')
            {
                float giaTri1 = top(st);
                pop(st);
                float giaTri2 = top(st);
                pop(st);
                push(st, giaTri1 + giaTri2);
            }
            else if (postfix[i] == '-')
            {
                float giaTri1 = top(st);
                pop(st);
                float giaTri2 = top(st);
                pop(st);
                push(st, giaTri2 - giaTri1);
            }
            else if (postfix[i] == '*')
            {
                float giaTri1 = top(st);
                pop(st);
                float giaTri2 = top(st);
                pop(st);
                push(st, giaTri1 * giaTri2);
            }
            else if (postfix[i] == '/')
            {
                float giaTri1 = top(st);
                pop(st);
                float giaTri2 = top(st);
                pop(st);
                push(st, giaTri2 / giaTri1);
            }
            else if (postfix[i] == '^')
            {
                float giaTri1 = top(st);
                pop(st);
                float giaTri2 = top(st);
                pop(st);
                push(st, pow(giaTri2, giaTri1));
            }
            else
                continue;
        }
    }
    return top(st);
}

int main()
{
    char postfix[MAXN];
    int np;

    InputPostFix(postfix, np);
    // Output(postfix, np);

    cout.precision(3);
    cout << evaluate_expression(postfix, np);

    return 0;
}
