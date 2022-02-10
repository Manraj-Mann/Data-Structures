// Given two binary trees, return true if they are structurally identical


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

bool is_similar(node * root1 , node * root2){

    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }

    if (root1 == NULL || root2 == NULL )
    {
        return 0;
    }


    return (root1->data == root2->data) && is_similar(root1->left , root2->left) && is_similar(root1->right , root2->left); 
    
    
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

    cout<<is_similar(root , NULL);
    

 
    return 0;
}