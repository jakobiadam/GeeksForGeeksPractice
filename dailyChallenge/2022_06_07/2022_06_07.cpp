//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */



class Solution{
  public:
    
    void recursiveTreeMaker(int *arrOrigin, TNode *node, int left, int right)
    {
        if (left == right)
        {
            node->data = arrOrigin[right];
            return;
        }
        else
        {
            int M = (ceil((left + (float)right) / 2));
            node->data = arrOrigin[M];
            if ((M - 1) >= left)
            {
                node->left = new TNode(-1);
                Solution::recursiveTreeMaker(arrOrigin, node->left, left, M - 1);
            }
            if ((M + 1) <= right)
            {
                node->right = new TNode(-1);
                Solution::recursiveTreeMaker(arrOrigin, node->right, M + 1, right);
            }
        }
        
    }
  
  
    TNode* sortedListToBST(LNode *head) {
        //code here
        
        //Calc length of linked list
        LNode *position = head;
        int length {1};
        while (position->next != NULL)
        {
            ++length;
            position = position->next;
        }
        
        //linked list to array
        int arrOrigin[length];
        int left = 0;
        int right = length - 1;
        
        position = head;
        for (int i = 0; i < length; ++i)
        {
            arrOrigin[i] = position->data;
            position = position->next;
        }
        
        
        TNode *tree = new TNode(-1);
        Solution::recursiveTreeMaker(arrOrigin, tree, left, right);
        
        return tree;
        
        
        
    }
};
