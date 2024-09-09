//2326. Spiral Matrix IV
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize the matrix with -1
        vector<vector<int>> grid(m, vector<int>(n, -1));
        
        // Set boundaries for the spiral traversal
        int left = 0, right = n, top = 0, bottom = m;
        
        // Directions array for the spiral movement: right, down, left, up
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Initial positions
        int row = 0, column = 0, dir = 0;  // direction index starts at 0 (right)
        
        while (head) {
            // Traverse in the current direction
            grid[row][column] = head->val;
            head = head->next;
            
            // Move in the current direction
            int newRow = row + directions[dir][0];
            int newColumn = column + directions[dir][1];
            
            // Check if we need to change direction (if out of bounds or if the cell is already filled)
            if (newRow < top || newRow >= bottom || newColumn < left || newColumn >= right || grid[newRow][newColumn] != -1) {
                // Adjust the boundaries based on the current direction
                if (dir == 0) top++;       // Moving right, shrink top boundary
                else if (dir == 1) right--; // Moving down, shrink right boundary
                else if (dir == 2) bottom--; // Moving left, shrink bottom boundary
                else if (dir == 3) left++;   // Moving up, shrink left boundary
                
                // Change direction (right -> down -> left -> up)
                dir = (dir + 1) % 4;
                
                // Recalculate new row and column based on new direction
                newRow = row + directions[dir][0];
                newColumn = column + directions[dir][1];
            }
            
            // Update row and column
            row = newRow;
            column = newColumn;
        }
        
        return grid;

    }
};