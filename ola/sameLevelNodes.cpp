#include<iostream>
#include <stdlib.h>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define mai3(a,b,c) mai(a,mai(b,c))
#define READ freopen("input.tit", "r", stdin)
#define WRITE freopen("output.tit", "w", stdout)
#define LL long long
#define MX 100000000000014

#define F first
#define S second
#define pii pair<int,int>
#define p(i) printf("%d",i)
#define inp(i) scanf("%d",&i)
#define inpll(i) scanf("%lld",&i)
#define getci getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getci();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getci();
 n=n*sign;
 }*/

using namespace std;

struct Node{
    int data;
    node* left;
    node* right;
    node* nextRight;
};



//void insertIntoTree(Node node, int val){
//    if(node == null){
//        node = new node();
//        node.val = val;
//        node.left = null;
//        node.right = null;
//        node.nectRight = null;
//        return ;
//    }
//    if(val > node.val)
//        insertIntoTree(node->right);
//    else
//        insertIntoTree(node->left);
//}
//
//void createBinaryTree(){
//    int n,a;
//    cin>>n;
//    Node root;
//    for(int i=0;i<n;i++){
//        cin>>a;
//        insertIntoTree(root,a);
//    }
//}

void connectNodes(Node root){
    if(root == null)
        return;
    if(root->left != null && root->right != null){
        root->left->nextRight = root->right;
        
        if(root->left->right != null){
            
            if(root->right->left != null){
                root->left->right->nextRight = root->right->left;
            }
            else
            if(root->right->right != null){
                root->left->right->nextRight = root->right->right;
            }
        }
        else
        if(root-left->left != null){
            if(root->right->left != null){
                root->left->left->nextRight = root->right->left;
            }
            else
            if(root->right->right != null){
                root->left->left->nextRight = root->right->right;
            }
        }
    }
    connectNodes(root->left);
    connectNodes(root->right);
}

int main(){
    //create binary tree
    connectNodes(root);
    return 0;
}