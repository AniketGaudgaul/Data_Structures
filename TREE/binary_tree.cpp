#include <iostream>
#include <stdio.h>
#include "Queue.h"
#include "stack.h"
using namespace std;
class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};
class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        ;
        Q = new Node *[size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty() { return front == rear; }
};
void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
        printf("Queue Full\n");
    else
    {
        rear++;
        Q[rear] = x;
    }
}
Node *Queue::dequeue()
{
    Node *x = NULL;
    if (front == rear)
        printf("Queue is Empty\n");
    else
    {

        x = Q[front + 1];
        front++;
    }
    return x;
}
class Tree
{
    Node *root;

public:
    Tree() { root = NULL; }
    void CreateTree();
    void Preorder() { Preorder(root); }
    void Preorder(Node *p);
    void Postorder() { Postorder(root); }
    void Postorder(Node *p);
    void Inorder() { Inorder(root); }
    void Inorder(Node *p);
    void Levelorder() { Levelorder(root); }
    void Levelorder(Node *p);
    int Height() { return Height(root); }
    int Height(Node *root);
};
void Tree::CreateTree()
{
    Node *p, *t = NULL;
    int x;
    Queue q(100);
    printf("Eneter root value ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void Tree::Preorder(struct Node *p)
{
    if (p)
    {

        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(struct Node *p)
{
    if (p)
    {

        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Tree::Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}
void Tree::Levelorder(struct Node *p)
{

    Queue q(100);
    printf("%d ", root->data);
    q.enqueue(root);
    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
        }
        printf("%d ", root->rchild->data);
        q.enqueue(root->rchild);
    }
}
int Tree::Height(struct Node *root)
{

    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

void Tree::iterativePreorder(Node *p)
{
    stack<Node *> stk;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node *p)
{
    stack<Node *> stk;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            stk.emplace(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node *p)
{
    stack<long int> stk;
    long int temp;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            stk.emplace((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = stk.top();
            stk.pop();
            if (temp > 0)
            {
                stk.emplace(-temp);
                p = ((Node *)temp)->rchild;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

int main()
{
    Tree t;
    t.CreateTree();
    cout << "Preorder ";
    t.Preorder();
    cout << endl;
    cout << "Inorder ";
    t.Inorder();
    cout << endl
         << endl;
    return 0;
}