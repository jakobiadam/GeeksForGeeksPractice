/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public: 
    void recursiveTreeToDLL(Node *root, Node **nodePrev, Node **head)
    {
        //if no left child -> it is a next node in DLL
        if (!root->left)
        {
            if (*nodePrev != NULL) //skip first DLL node
            {
                (**nodePrev).right = root; //make connections between the previous and the actual node 
                root->left = *nodePrev;
            }
            else
            {
                *head = root; //the first node without left child is the head of the DLL
            }
            *nodePrev = root; //this new DLL node will be the next previous node in the algorithm
            if (root->right) {recursiveTreeToDLL(root->right, nodePrev, head);} //call algorithm on right child if possible
            return;
        }
        recursiveTreeToDLL(root->left, nodePrev, head); //call algorithm on left child
        if (*nodePrev != NULL) //pair nodes only if there is a previous node
        {
            root->left = *nodePrev; //node pairing
            (**nodePrev).right = root;
        }
        *nodePrev = root; //after go left or before go right new previous node will be the actual node
        if (root->right) {recursiveTreeToDLL(root->right, nodePrev, head);} //continue the algorithm on right child
    }
    
    //Returns the head of the DLL created from the binary tree
    Node * bToDLL(Node *root)
    {
        if (root == NULL) {return root;}
        
        //Init
        Node *nodePrev {NULL};
        Node *head {NULL};
        
        Solution::recursiveTreeToDLL(root, &nodePrev, &head);
        
        return head;
    }
};
