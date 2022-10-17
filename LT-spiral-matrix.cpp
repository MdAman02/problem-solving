class Solution {
public:
    int n, m;
    void traverse(int completedCycle, vector<int>& res, vector<vector<int>>& matrix) {
        int minRow = 0 + completedCycle , maxRow = m - completedCycle-1; // 1, 2
        int minCol = 0 + completedCycle, maxCol = n - completedCycle-1; // 1, 2
        
        if (minRow > maxRow || minCol > maxCol) return;
        
        for (int i=minCol; i<=maxCol && minRow <= maxRow  ; i++)
            res.push_back(matrix[minRow][i]);
        minRow++;
        for (int i=minRow; i<=maxRow && minCol <= maxCol ; i++)
            res.push_back(matrix[i][maxCol]);
        maxCol--;
        for (int i=maxCol; i>=minCol && minRow <= maxRow ; i--)
            res.push_back(matrix[maxRow][i]);
        maxRow--;
        for (int i=maxRow; i>=minRow && minCol <= maxCol ; i--)
            res.push_back(matrix[i][minCol]);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        int totalCycle = (min(m, n) + 1)/2;
        vector<int> res;
        
        for (int i=0; i<totalCycle; i++)
            traverse(i, res, matrix);
        return res;
    }
};