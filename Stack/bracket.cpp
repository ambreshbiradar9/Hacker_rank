//Balanced Brackets
#include <bits/stdc++.h>

using namespace std;
struct Node
{
    char data;
    Node* next;
};

Node* root = NULL;

void pop()
{
    Node* temp;
    temp = root;
    root = root->next;
    free(temp);
}

void push(char c)
{
    Node* temp;
    temp = new Node();
    temp->data = c;
    temp->next = root;
    root = temp;
}

bool empty()
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Complete the isBalanced function below.
string isBalanced(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            {
                push(s[i]);
            }
        else
        {
            if (((root->data) == '(') && (s[i] == ')'))
            {
                pop();
            }
            else if (((root->data) == '{') && (s[i] == '}'))
            {
                pop();
            }
            else if (((root->data) == '[') && (s[i] == ']'))
            {
                pop();
            }
            else
            {
                push(s[i]);
            }
        }
    }

    if (empty())
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

/* 
Learnings 
1--Always free the heap memory allocation once the code is over other the memory freezes and affects everything else 
