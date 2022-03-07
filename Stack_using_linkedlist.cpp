#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *top = NULL;

void push()
{
    int val;
    Node *temp = new Node;
    if (temp == NULL)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Push data: ";
        cin >> val;
        temp->data = val;
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    Node *ptr = top;
    cout << ptr->data << " is removed" << endl;
    top = top->next;
    delete (ptr);
}

void display()
{
    Node *p = top;
    while (p != NULL)
    {
        cout << p->data << " " << endl;
        p = p->next;
    }
}

int main()
{

    int ch;
    do
    {
        cout << "1) Push\n2) Pop\n3) Display\n4) Peek\n5) Empty" << endl;
        cout << "Enter the choice you want to perform:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

            // case 4:
            //     s.peek();
            //     break;

            // case 5:
            //     s.isEmpty();
            //     break;
        }

    } while (ch != 6);
}