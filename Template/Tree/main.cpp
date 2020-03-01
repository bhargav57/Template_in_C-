#include <iostream>
#include<vector>
using namespace std;
/* 
   Author : Bhargav Patel
   C++11 based code
   non recursive traverse
   template base tree
*/
/* This is a node template class which is use to create a node object */
template<typename T>
class node
{
public:
    T data;
    node* l;
    node* r;
    node* p;
    bool visited;
    node() :l(nullptr), r(nullptr), p(nullptr), visited(false)
    {

    }
};


/* This is a tree template class which is use to create a tree object */
template<typename T>
class tree
{
    node<T>* root;
    bool val;
    int count;
public:
    tree() :root(nullptr), val(false),count(0)
    {

    }
    /* This member function creates a tree object */
    node<T>* createNode(T data);
    /* This member fucntion inserts a tree object created by the createNode() to
    appropriate location in the tree. It starts from root object */
    void insertNode(T data);

    /* This member fucntion traverses a tree in a non recursive manner to avoid 
    stack overflow */
    void travese();
};
template<typename T>
node<T>* tree<T>::createNode(T data)
{
    node<T>* temp = new node<T>();
    if (temp == nullptr)
    {
        std::cout << "error";
    }
    else
    {
        temp->data = data;
        temp->l = nullptr;
        temp->r = nullptr;
        temp->p = nullptr;
    }
    return temp;
}
template<typename T>
void tree<T>::insertNode(T data)
{
    node<T>* tempNode = createNode(data);

    if (tempNode != nullptr)
    {
        if (root == nullptr)
        {
            root = tempNode;
        }
        else
        {
            node<T>* temp = root;
            node<T>* curPtr = nullptr;
            while (temp != nullptr)
            {
                curPtr = temp;
                if (data <= temp->data)
                {
                    temp = temp->l;
                }
                else
                {
                    temp = temp->r;
                }
            }


            if (tempNode->data <= curPtr->data)
            {
                curPtr->l = tempNode;
                tempNode->p = curPtr;
            }
            else
            {
                curPtr->r = tempNode;
                tempNode->p = curPtr;
            }

        }
    }
}
template<typename T>
void tree<T>::travese()
{
    node<T>* tnode = root;
    while (tnode->visited == val)
    {
        while (tnode->l != nullptr && tnode->l->visited == val)
        {
            tnode = tnode->l;
        }
        std::cout << tnode->data << " ";
        tnode->visited = !val;

        if (tnode->r != nullptr)
        {
            tnode = tnode->r;
        }
        else
        {
            tnode = tnode->p;
            while (tnode->visited == !val && tnode->p != nullptr)
            {
                tnode = tnode->p;
            }

        }
    }
    val = !val;
}
int main()
{
    vector<int> v{ 6,3,9,2,4,5,7,10,-1,-3,15,18,-20 };
    tree<int> obj;

    for (auto const& ele : v)
    {
        obj.insertNode(ele);
    }

    obj.travese();
    std::cout << "\nsecond time \n";
    obj.travese();
    std::cout << "\nthird time \n";
    obj.travese();
    return 0;
}

