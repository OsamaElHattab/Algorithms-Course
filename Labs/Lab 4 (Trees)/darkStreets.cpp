#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


struct node
{
public:
    bool data;
    vector<node*>child;
    //constructor
    node(bool data)
    {
        this->data = data;
    }
};

void check_preorder(struct node* root, int M , int & path ,int darken_consecutive)
{
    if (root != NULL)
    {
        if (root->data == 1)
        {
            darken_consecutive++;
        }
        else
        {
            darken_consecutive = 0;
        }


        if ((root->child).size() == 0 && darken_consecutive  <= M)
        {
            path++;
        }
        else
        {
            if (root->data == 1)
            {
                //darken_consecutive++;
                if (darken_consecutive > M)
                {
                    return;
                }
                for (int i = 0; i < (root->child).size(); i++)
                {
                    check_preorder((root->child)[i], M, path, darken_consecutive);
                }
            }
            else
            {
                //darken_consecutive = 0;
                for (int i = 0; i < (root->child).size(); i++)
                {
                    check_preorder((root->child)[i], M, path, darken_consecutive);
                }
            }
        }

        

        //if (root->data == 1)    //dark root
        //{
        //    //int darken_consecutive = 1;
        //    for (int i = 0; i < (root->child).size(); i++)
        //    {
        //        if ((root->child)[i]->data == 1)
        //        {
        //            darken_consecutive++;
        //        }
        //        if (darken_consecutive > M)
        //        {
        //            return;
        //        }
        //    }
        //}

        /*if ((root->child).size() == 0)
        {
            path++;
        }
        else
        {
            for (int i = 0; i < (root->child).size(); i++)
            {
                check_preorder((root->child)[i], M, path);
            }
        }*/
    }
}

int main()
{
    int N, M;
    bool inserted_value;
    cin >> N >> M;
    vector <node*> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> inserted_value;
        arr[i] = new node(inserted_value);
    }

    /////////////////////////// creation of tree
    int x_i, y_i;
    vector<int>parent;
    parent.push_back(0);
    vector<int>xx;
    vector<int>yy;
    for (int i = 0; i < (N-1); i++)
    {
        cin >> x_i >> y_i;
        x_i--;
        y_i--;
        bool x_i_Is_parent = 0;
        bool y_i_Is_parent = 0;

        for (int i = 0; i < parent.size(); i++)
        {
            if (x_i == parent[i])
            {
                x_i_Is_parent = 1;
                break;
            }
        }
        if (x_i_Is_parent)
        {
           ( arr[x_i]->child ).push_back(arr[y_i]);
           parent.push_back(y_i);
        }
        else
        {
            for (int i = 0; i < parent.size(); i++)
            {
                if (y_i == parent[i])
                {
                    y_i_Is_parent = 1;
                    break;
                }
            }
            if (y_i_Is_parent)
            {
                (arr[y_i]->child).push_back(arr[x_i]);
                parent.push_back(x_i);
            }
            else
            {
                
                xx.push_back(x_i);
                yy.push_back(y_i);
            }
        }


        
    }
    for (int i = 0; i < xx.size(); i++)
    {
        x_i = xx[i];
        y_i = yy[i];
        bool x_i_Is_parent = 0;
        bool y_i_Is_parent = 0;

        if (xx.size() != 0)
        {
            for (int i = 0; i < parent.size(); i++)
            {
                if (x_i == parent[i])
                {
                    x_i_Is_parent = 1;
                    break;
                }
            }
            if (x_i_Is_parent)
            {
                (arr[x_i]->child).push_back(arr[y_i]);
                parent.push_back(y_i);
            }
            else
            {
                for (int i = 0; i < parent.size(); i++)
                {
                    if (y_i == parent[i])
                    {
                        y_i_Is_parent = 1;
                        break;
                    }
                }
                if (y_i_Is_parent)
                {
                    (arr[y_i]->child).push_back(arr[x_i]);
                    parent.push_back(x_i);
                }
                /*else
                {
                    vector<int>xx;
                    vector<int>yy;
                    xx.push_back(x_i);
                    yy.push_back(y_i);
                }*/
            }

        }
    }

    
    //////////////////////////////// pre order traversal

    node* root = arr[0];
    int path = 0;
    if (root != NULL) 
    {
        check_preorder(root, M , path, 0);
    }
    cout << path;

    return 0;
}
