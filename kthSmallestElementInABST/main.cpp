//
//  main.cpp
//  Solution
//
//  Created by Yang on 17/12/15.
//  Copyright (c) 2015 Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int kthSmallest( TreeNode * root, int k ) {
        std::stack< TreeNode * > s;
        TreeNode * node = root;
        
        // go to left-most node
        while ( node != NULL )
        {
            s.push( node );
            node = node->left;
        }
        TreeNode * l = NULL;
        TreeNode * r = NULL;
        
        // inorder traversal
        for( unsigned long i = 1; i <= k && !s.empty(); i++ )
        {
            l = s.top();
            s.pop();
            r = l->right;
            while( r != NULL ) {
                s.push( r );
                r = r->left;
            }
        }
        return l->val;
    }
};

int main(int argc, const char * argv[])
{
    Solution mySolution;
    
    TreeNode root(20);
    TreeNode n4(4);
    TreeNode n8(8);
    TreeNode n10(10);
    TreeNode n12(12);
    TreeNode n14(14);
    TreeNode n22(22);
    root.left = &n8;
    root.right = &n22;
    n8.left = &n4;
    n8.right = &n12;
    n12.left = &n10;
    n12.right = &n14;
    
    std::cout << mySolution.kthSmallest( &root , 1 ) << endl;
    std::cout << mySolution.kthSmallest( &root , 2 ) << endl;
    std::cout << mySolution.kthSmallest( &root , 3 ) << endl;
    std::cout << mySolution.kthSmallest( &root , 4 ) << endl;
    std::cout << mySolution.kthSmallest( &root , 5 ) << endl;
    std::cout << mySolution.kthSmallest( &root , 6 ) << endl;
    std::cout << mySolution.kthSmallest( &root , 7 ) << endl;
    std::cout << mySolution.kthSmallest( &root , 8 ) << endl;
    
    TreeNode root2 (1);
    std::cout << mySolution.kthSmallest( &root2 , 1 ) << endl;
    return 0;
}

