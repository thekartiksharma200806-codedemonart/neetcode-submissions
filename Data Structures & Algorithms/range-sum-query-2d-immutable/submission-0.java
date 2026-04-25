class NumMatrix {

    int[][] matrix;

    public NumMatrix(int[][] m) {
        int n = m.length;
        int mcol = m[0].length;

        // row-wise prefix
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < mcol; j++) {
                m[i][j] += m[i][j - 1];
            }
        }

        // column-wise prefix
        for (int j = 0; j < mcol; j++) {
            for (int i = 1; i < n; i++) {
                m[i][j] += m[i - 1][j];
            }
        }

        matrix = m;
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int res = matrix[row2][col2];

        if (col1 > 0) {
            res -= matrix[row2][col1 - 1];
        }

        if (row1 > 0) {
            res -= matrix[row1 - 1][col2];
        }

        if (row1 > 0 && col1 > 0) {
            res += matrix[row1 - 1][col1 - 1];
        }

        return res;
    }
}