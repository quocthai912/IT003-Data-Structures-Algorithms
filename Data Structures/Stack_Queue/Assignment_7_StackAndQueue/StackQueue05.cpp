/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <iomanip>
using namespace std;

struct NODE_CHAR
{
    char info;
    NODE_CHAR *pNext;
};

struct stack
{
    NODE_CHAR *top;
};
NODE_CHAR *CreateNode(float x)
{
    NODE_CHAR *p = new NODE_CHAR;
    p->info = x;
    p->pNext = NULL;
    return p;
}

NODE_CHAR *CreateNodeChar(char x)
{
    NODE_CHAR *p = new NODE_CHAR;
    p->info = x;
    p->pNext = NULL;
    return p;
}

NODE_CHAR *input_infix()
{
    string input;
    getline(cin, input);
    NODE_CHAR *p = CreateNodeChar(input[0]);
    p->pNext = CreateNodeChar(input[2]);
    return p;
}

int doUuTienToanTu(char s)
{
    if (s == '+' || s == '-')
        return 0;
    else if (s == '^')
        return 2;
    return 1;
}
NODE_CHAR *infix_to_postfix(NODE_CHAR *infix)
{
    int doUuTien1 = doUuTienToanTu(infix->info);
    int doUuTien2 = doUuTienToanTu(infix->pNext->info);
    if (doUuTien1 == doUuTien2)
    {
        NODE_CHAR *p = CreateNodeChar('=');
        p->pNext = infix->pNext;
        infix->pNext = p;
    }
    else if (doUuTien1 > doUuTien2)
    {
        NODE_CHAR *p = CreateNodeChar('>');
        p->pNext = infix->pNext;
        infix->pNext = p;
    }
    else
    {
        NODE_CHAR *p = CreateNodeChar('<');
        p->pNext = infix->pNext;
        infix->pNext = p;
    }
    return infix;
}
void out(NODE_CHAR *postfix)
{
    while (postfix)
    {
        cout << postfix->info << " ";
        postfix = postfix->pNext;
    }
}
int main()
{
    NODE_CHAR *infix = NULL;
    NODE_CHAR *postfix;

    infix = input_infix();

    postfix = infix_to_postfix(infix);
    out(postfix);
    return 0;
}
