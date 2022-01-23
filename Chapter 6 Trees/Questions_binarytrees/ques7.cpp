// Give an algorithm for finding the height (or depth) of the binary tree.
#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *init(int data)
{
    node *n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void insert_left(node *root, int data)
{
    root->left = init(data);
}
void insert_right(node *root, int data)
{
    root->right = init(data);
}

void delete_left(node *root)
{
    node *todel = root->left;
    root->left = NULL;
    delete todel;
}
void delete_right(node *root)
{
    node *todel = root->right;
    root->right = NULL;
    delete todel;
}

void levelorder(node *root)
{
    node *temp;
    queue<node *> q;

    if (root == NULL)
    {
        return;
    }

    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

// recursive

int height_of_tree(node *root)
{

    int left, right;

    if (root == NULL)
    {
        return -1;
    }
    else
    {
        left = height_of_tree(root->left);
        right = height_of_tree(root->right);

        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
}

// iterative

int height_of_tree_(node *root)
{

    int level = -1;

    node *temp;
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            level++;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

    return level;
}

int main()
{
    node *root = NULL;

    root = init(1); // root node

    //       1

    insert_left(root, 2);
    insert_right(root, 3);

    //        1
    //       / \'
    //      2   3

    insert_left(root->left, 4);
    insert_right(root->left, 5);

    //        1
    //       / \'
    //      2   3
    //      / \'
    //     4   5

    insert_left(root->right, 6);
    insert_right(root->right, 7);

    //        1
    //       / \'
    //       2   3
    //      / \' / \'
    //     4   5 6  7

    cout << height_of_tree(root) << endl;
    cout << height_of_tree_(root) << endl;

    return 0;
}