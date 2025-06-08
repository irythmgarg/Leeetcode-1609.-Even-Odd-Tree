/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;               // Value of the node
    TreeNode *left;        // Pointer to the left child
    TreeNode *right;       // Pointer to the right child

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * Determines if a binary tree satisfies the even-odd level conditions:
     * - At even-indexed levels (0, 2, 4...): all node values must be odd and strictly increasing.
     * - At odd-indexed levels (1, 3, 5...): all node values must be even and strictly decreasing.
     */
    bool isEvenOddTree(TreeNode* root) {
        bool leveleven = true;              // Start at level 0 (even)
        queue<TreeNode*> q;                 // Queue for level-order traversal
        q.push(root);

        while (!q.empty()) {
            int n = q.size();               // Number of nodes at current level
            int prevelement = leveleven ? INT_MIN : INT_MAX;  // Previous value for comparison

            while (n--) {
                TreeNode* top = q.front();  // Current node
                q.pop();

                if (leveleven) {
                    // Even level: values must be odd and strictly increasing
                    if (top->val <= prevelement || top->val % 2 == 0)
                        return false;
                } else {
                    // Odd level: values must be even and strictly decreasing
                    if (top->val >= prevelement || top->val % 2 != 0)
                        return false;
                }

                // Update previous value for the level
                prevelement = top->val;

                // Add child nodes to queue for next level
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }

            // Flip the level indicator
            leveleven = !leveleven;
        }

        return true;  // All levels satisfied the constraints
    }
};
