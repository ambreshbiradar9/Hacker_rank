/*You have an empty sequence, and you will be given  queries. Each query is one of these three types:

1 x  -Push the element x into the stack.
2    -Delete the element present at the top of the stack.
3    -Print the maximum element in the stack.
Input Format

The first line of input contains an integer, . The next  lines each contain an above mentioned query. (It is guaranteed that each query is valid.)

Constraints



Output Format

For each type  query, print the maximum element in the stack on a new line.

Sample Input

10
1 97
2
1 20
2
1 26
1 20
2
3
1 91
3
Sample Output

26
91
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
int data;
Node *next;
};

Node *root=NULL,*root1=NULL;
void push(int x) 
{ 
    Node *temp,*temp1;
    temp=new Node();
    temp->data = x;
    temp->next=root;
    temp1=new Node();
    if((root1==NULL)||(x>root1->data))
    {
        temp1->data=x;
    }
    else
    {
        temp1->data=root1->data;cd 
    }
    temp1->next=root1;
    root1=temp1;
    root=temp;
} 
  
void pop() 
{ 
    Node *temp,*temp1;
    temp1=root1;
    root1=root1->next;
    free(temp1);
    temp=root;
    root=root->next;
    free(temp);
} 

void search()
{
    Node *temp;
    temp=root1;
    cout<<temp->data<<"\n";
}

int main() 
{
    int n,t,t1;
    cin>>n;
    for (int i=0;i<n;i++)
    {   
        t1=0;
        cin>>t;
        if(t==1)
        {
            cin>>t1;
            push(t1);
        }
        if(t==2)
        {
           pop();
        }
        if(t==3)
        {
            search();
        }
    }
    return 0;
}
