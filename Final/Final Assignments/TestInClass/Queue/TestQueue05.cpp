/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
sort
template
class
typedef
vector
pair
set
map
exit
[
]
###End banned keyword*/
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

void Input(queue<int> &q)
{
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < y; i++)
        x *= 2;
    q.push(x);
}

void Output(queue<int> q)
{
    cout << q.front();
}

int main()
{
    queue<int> q;
    Input(q);
    Output(q);
    return 0;
}
