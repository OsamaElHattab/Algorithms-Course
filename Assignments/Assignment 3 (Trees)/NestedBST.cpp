#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct nodeID
{
public:
    int ID;
    nodeID* left, * right;

    //constructor
    nodeID(int ID)
    {
        this->ID = ID;
        left = NULL;
        right = NULL;
    }
};

struct nodeDep
{
public:
    int dep;
    nodeID* IDs;
    nodeDep* left, * right;

    //constructor
    nodeDep(int dep)
    {
        this->dep = dep;
        left = NULL;
        right = NULL;
        IDs = NULL;
    }
};

void insertBST_ID(nodeID* & rootid, int idValue)
{
    nodeID* id = new nodeID(idValue);
    if (rootid == NULL)
    {
        rootid = id;
        return;
    }
    nodeID* prev = NULL;
    nodeID* temp = rootid;
    while (temp != NULL)
    {
        if (temp->ID > idValue)
        {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->ID < idValue)
        {
            prev = temp;
            temp = temp->right;
        }
    }

    if (prev->ID > idValue)
        prev->left = id;
    else if (prev->ID < idValue)
        prev->right = id;
}

void insertBST(nodeDep* & rootdep, int depValue, int idValue)
{
    nodeDep* dep = new nodeDep(depValue);
    if (rootdep == NULL)
    {
        rootdep = dep;
        insertBST_ID(rootdep->IDs, idValue);
        return;
    }
    nodeDep* prev = NULL;
    nodeDep* temp = rootdep;
    while (temp != NULL)
    {
        if (temp->dep > depValue)
        {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->dep < depValue)
        {
            prev = temp;
            temp = temp->right;
        }
        else // (=)
        {
            break;
        }
    }

    if (rootdep->dep == depValue)
    {
        insertBST_ID(rootdep->IDs, idValue);
        return;
    }
    if (temp != NULL)
    {
        if ((temp->dep) == depValue)
        {
            insertBST_ID(temp->IDs, idValue);
            return;
        }
    }

    if ((prev->dep) > depValue)
    {
        prev->left = dep;
        insertBST_ID(dep->IDs, idValue);
    }
    else if ((prev->dep) < depValue)
    {
        prev->right = dep;
        insertBST_ID(dep->IDs, idValue);
    }
}

void search(nodeDep* &rootDep, int& dep, int& id, int& nodeCounter, bool& found)
{
    nodeDep* temp = rootDep;
    while (temp != NULL && temp->dep != dep)
    {
        nodeCounter++;
        if (temp->dep > dep)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }


    if (temp == NULL)
    {
        return;
    }
    else if ((temp->dep) == dep)
    {
        nodeCounter++;
        nodeID* tempID = temp->IDs;
        while (tempID != NULL && tempID->ID != id)
        {
            nodeCounter++;
            if (tempID->ID > id)
            {
                tempID = tempID->left;
            }
            else
            {
                tempID = tempID->right;
            }
        }
        if (tempID == NULL)
        {
            return;
        }
        else if ((tempID->ID) == id)
        {
            nodeCounter++;
            found = 1;
        }
    }
}



int main()
{
    //////////////////////////////////////////////////////// creation of tree 
    int N, Q, dep, id, nodeCounter;
    cin >> N >> Q;
    nodeDep* rootdep = NULL;
    for (int i = 0; i < N; i++)
    {
        cin >> dep >> id;
        insertBST(rootdep, dep, id);
    }
    //////////////////////////////////////////////////////////////////////////
    
    ////////////////////////////////////////////////////  print trees to debug
    //while (rootdep != NULL)
    //{
    //    cout << "dep  " << rootdep->dep << endl;
    //    cout << "ids  ";
    //    nodeID* idsptr = rootdep->IDs;
    //    while (idsptr != NULL)
    //    {
    //        cout << idsptr->ID << ' ';
    //        idsptr = idsptr->left;
    //    }
    //    cout << endl;
    //    rootdep = rootdep->right;
    //}
    ///////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////// search for queries
    bool found;
    for (int i = 0; i < Q; i++)
    {
        nodeCounter = 0;
        found = 0;
        cin >> dep >> id;
        search(rootdep, dep, id, nodeCounter, found);
        cout << nodeCounter << ' ' << found << endl;
    }
    ///////////////////////////////////////////////////////////////////////////

    return 0;
}
