#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct node
{
public:
    int data;
    node *left, *right;
    int level;

    //constructor
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        level = 0;
    }
};

int getHeight(node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHieght = getHeight(root->left) +1;
    int rightHieght = getHeight(root->right) +1;
    if (leftHieght > rightHieght)
    {
        return leftHieght;
    }
    else
    {
        return rightHieght;
    }
}

void assignLevelToNodes(node* root , int level)
{
    if (root == NULL)
        return;
    root->level = level;
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    else if (root->left != NULL && root->right == NULL)
    {
        assignLevelToNodes(root->left, level+1);
    }
    else if (root->left == NULL && root->right != NULL)
    {
        assignLevelToNodes(root->right, level+1);
    }
    else
    {
        assignLevelToNodes(root->left, level+1);
        assignLevelToNodes(root->right, level+1);
    }
}

int getMinOfLevel(vector <node*>& vec, int level)
{
    int min = INT_MAX;
    for (int i=0; i < vec.size(); i++)
    {
        if (vec[i]->level == level)
        {
            if (vec[i]->data < min)
                min = vec[i]->data;
        }
    }
    return min;
}

int getSumOfLevel(vector <node*>& vec, int level)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i]->level == level)
            sum += vec[i]->data;
    }
    return sum;
}

int main() 
{
    /////////////////////////////////////////////////// creation of tree 
    int N, data, E, parent, child;
    cin >> N;
    vector <node *> vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        vec[i] = new node(data);
    }

    char LorR;
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> LorR >> parent >> child;
        if (LorR == 'L')
        {
            vec[parent]->left = vec[child];
        }
        else 
        {
            vec[parent]->right = vec[child];
        }
    }
    //////////////////////////////////////////////////////////////////////////
    int L, k;
    int height = getHeight(vec[0]);
    L = (vec[0]->data) % (height);

    assignLevelToNodes(vec[0], 0);
    int min = getMinOfLevel(vec, L);
    k = min % height;
    if (k == 0)
        k = 1;

    int certainLevel = 0;
    while (certainLevel < height)
    {
        cout << getSumOfLevel(vec, certainLevel);
        certainLevel += k;
    }

    return 0;
}
