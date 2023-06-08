#include <bits/stdc++.h>
using namespace std;

class node
{
    private:
        int data;
        bool left_thread,right_thread;
        node* left;
        node* right;
    public:
        node()
        {
            data = 0;
            left_thread= 0;
            right_thread = 0;
            left = NULL;
            right = NULL;
        }
        node(int key)
        {
            data = key;
            left_thread= 0;
            right_thread = 0;
            left = NULL;
            right = NULL;
        }
        friend class TBST;        
};

class TBST
{
    private:
        node* root;
        node* dummy_node = new node(-1);
    public:
        TBST()
        {
            root = NULL;     
            dummy_node->left = root;
            dummy_node->right = dummy_node;
        }
        void insert();
        void inorder();
        void BST_insert();
        void conversion();
	void preorder();
	node* preorderSuccessor(node*);
};

// In Threaded binary search tree
// the left pointer of every node
// points to its Inorder predecessor,
// whereas its right pointer points
// to the Inorder Successor
void TBST::preorder()
{
    node* c = root->left;
 
    // Loop to traverse the tree in
    // the preorder fashion
    while (c != root) {
        cout << " " << c->data;
        c = preorderSuccessor(c);
    }
}
 
// Function to find the preorder
// Successor of the node
node* TBST::preorderSuccessor(node* c)
{
    if (c->left_thread == 1) {
        return c->left;
    }
    while (c->right_thread == 0) {
        c = c->right;
    }
    return c->right;
}

void TBST :: insert()
{
    int key;
    cout<<"Enter element to enter :";
    cin>>key;
    node* ptr = new node(key);
    if(root == NULL)       
    { root = ptr;
        dummy_node->data = root->data;
        root->left = dummy_node;
        root->left_thread = 1;
        root->right = dummy_node;
        root->right_thread = 1;
    
    }
    else
    {
        node* temp = root;
        while(1)
        {
            if(key < temp->data)
            {
                if(temp->left_thread)
                {
                    ptr->left = temp->left;
                    ptr->right = temp;
                    temp->left = ptr;
                    temp->left_thread = 0;
                    ptr->left_thread = 1;
                    ptr->right_thread = 1;
                    break;
                }
                else    temp = temp->left;
            }
            else
            {
                if(temp->right_thread)
                {
                    ptr->right = temp->right;
                    ptr->left = temp;
                    temp->right = ptr;
                    temp->right_thread = 0;
                    ptr->left_thread = 1;
                    ptr->right_thread = 1;
                    break;
                }
                else    temp = temp->right;
            }
        }
    }
}

void TBST :: inorder()
{
    node* temp = root;
    cout<<"inorder :";
    if(root == NULL)    {cout<<"empty"<<endl; return;}
    else{
    while(!temp->left_thread)       temp = temp->left;
    
    while(temp!= dummy_node)
    {
        cout<<temp->data<<" ";
        if(temp->right_thread)      temp = temp->right;
        else{
            temp = temp->right;
            while(!temp->left_thread)   temp = temp->left;
        }
    }
    }
}


void TBST :: BST_insert()
{
    cout<<"enter element:";
    int key;
    cin>>key;
    node *ptr = new node(key);
    if (root == NULL)        root = ptr;

    else
    {
        node *temp = root;
        while (1)
        {
            if (key < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = ptr;
                    break;
                }
                else                    temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = ptr;
                    break;
                }
                else                    temp = temp->right;
            }
        }
    }
}

static vector<node*> v;
void TBST :: conversion()
{
    //store inorder
    stack<node*> st;
    node* temp = root;
    while(temp != NULL || st.empty() == false)
    {
        while(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        v.push_back(temp);
        st.pop();
        temp= temp->right;
    }
     for(int i = 0; i < v.size(); i++)
    {
        v[i]->left_thread = 0;
        v[i]->right_thread = 0;
    }

    for(int i= 0; i< v.size(); i++ )
    {
        if(i==0)
        {
            v[i]->left = dummy_node;
            v[i]->left_thread = 1;

            if(v[i]->right == NULL)
            {
                v[i]->right = v[i+1];
                v[i]->right_thread = 1;
            }
        }
        else if(i==v.size()-1)
        {
            v[i]->right = dummy_node;
            v[i]->right_thread = 1;
            if(v[i]->left == NULL)
            {
                v[i]->left = v[i-1];
                v[i]->left_thread = 1;
            }
        }
        else
        {
            if(v[i]->left == NULL && v[i]->right == NULL)
            {
                v[i]->left = v[i-1];
                v[i]->left_thread = 1;
                v[i]->right = v[i+1];
                v[i]->right_thread = 1;
            }
            if(v[i]->left != NULL && v[i]->right == NULL)
            {
                v[i]->right = v[i+1];
                v[i]->right_thread = 1;
            }
            if(v[i]->left == NULL && v[i]->right != NULL)
            {
                v[i]->left = v[i-1];
                v[i]->left_thread = 1;
            }
            else                         continue;
        }
    }
}

int main()
{
    TBST tree;
    int choice;
    do
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. inorder"<<endl;
	cout << "3.preorder" << endl;
        cout<<"4. BST insert"<<endl;
        cout<<"5. BST to threaded"<<endl;
        cout<<" Enter choice :";
        cin>>choice;
        switch (choice)
        {
            case 1:
                tree.insert();
                break;
            case 2:
                tree.inorder();
                break;
	    case 3 :
		tree.preorder();
		break;
            case 4:
                tree.BST_insert();
                break;
            case 5:
                tree.conversion();
                break;
            default:
                exit(0);
        }
    } while (0<choice<5);
}
