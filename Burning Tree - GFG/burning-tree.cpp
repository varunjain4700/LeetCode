// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void inorder(Node* root,map<Node*,Node*>&par,int target,Node*& start)
  {
      if(root==NULL)
        return;
    inorder(root->left,par,target,start);
    if(root->left)
        par[root->left]=root;
    if(root->right)
        par[root->right]=root;
    if(root->data==target)
        start=root;
    inorder(root->right,par,target,start);
  }
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>par;
         Node* start;
        inorder(root,par,target,start);
        queue<Node*>q;
        unordered_map<Node*,bool>vis;
        vis[start]=1;
        q.push(start);
        int curr_time=-1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                Node* temp=q.front();
                 //cout<<temp->data<<" ";
                q.pop();
                if(temp->left&&!vis[temp->left])
                {
                    q.push(temp->left);
                    vis[temp->left]=1;
                }
                if(temp->right&&!vis[temp->right])
                {
                    q.push(temp->right);
                    vis[temp->right]=1;
                }
                if(par.find(temp)!=par.end()&&!vis[par[temp]])
                {
                    q.push(par[temp]);
                    vis[par[temp]]=1;
                }
            }
           curr_time++;
        }
        return curr_time;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends