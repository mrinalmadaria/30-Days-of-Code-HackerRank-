#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

	void levelOrder(Node * root){
      //Write your code here
        queue<Node *> myQueue;
        
        if(root == NULL){
            return;
        } else {
            Node *curr = root;
            myQueue.push(curr);
            
            while(myQueue.size()){
                curr = myQueue.front();
                cout<<curr->data<<" ";
                
                if(curr->left != NULL){
                    myQueue.push(curr->left);
                }
                if(curr->right != NULL){
                    myQueue.push(curr->right);
                }
                
                myQueue.pop();
            }
        }
    
	}

};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}