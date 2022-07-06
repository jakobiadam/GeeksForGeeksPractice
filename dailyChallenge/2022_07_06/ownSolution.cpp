/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


void recursiveDiagonal(Node *root, map<int, vector<int>*> &m, int diagNum, int &maxDiagNum)
{
    if (!root) return;
    
    if (diagNum > maxDiagNum) maxDiagNum = diagNum;
    
    if (!m[diagNum]) m[diagNum] = new vector<int>;
    (*m[diagNum]).push_back(root->data);
    
    recursiveDiagonal(root->left, m, diagNum + 1, maxDiagNum);
    recursiveDiagonal(root->right, m, diagNum, maxDiagNum);
}


vector<int> diagonal(Node *root)
{
    map<int, vector<int>*> m;
    int maxDiagNum {};
    
    recursiveDiagonal(root, m, 0, maxDiagNum);

    vector<int> res;    
    for (int i = 0; i <= maxDiagNum; ++i)
    {
        for (int j = 0; j < (*(m[i])).size(); ++j)
        {
            res.push_back((*(m[i]))[j]);
        }
    }
    return res;
}
