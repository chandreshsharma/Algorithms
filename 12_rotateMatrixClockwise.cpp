/***
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
***/

void rotate(vector<vector<int>>& matrix) {

/***       
    /// Consider the matrix stored as a vector of int vectors
    /// 1, 2, 3     matrix[0], [0,0] [0,1] [0,2]    R1
    /// 4, 5, 6     matrix[1], [1,0] [1,1] [1,2]    R2
    /// 7, 8, 9     matrix[2], [,0] [0,1] [0,2]     R3
        C1, C2, C3
    using vecOfIntVec = std::vector< std::vector<int> >;

    void printVec(vecOfIntVec vec)
    {
        for(int r=0;r<vec.size();++r)   {
            for(int c=0;c<vec.size();++c){
                std::cout << " vec[" << r << "][" << c << "]:" << vec[r][c];
            }
            std::cout << std::endl;
        }
    }

    int main()
    {
        vecOfIntVec vecIntVec = {   {1,2,3},
                                    {4,5,6},
                                    {7,8,9}
                                };
        printVec(vecIntVec);

        return 0;
    }     

***/        
    const int N = matrix.size();

    for (int r=0; r < N/2; ++r)     /// Make sure only half of the matrix is rotated.
    {                               /// Else we get back the original matrix.
        for (int c = r; c < N - r - 1; ++c) {
            int temp = matrix[r][c];

            // Move values from left to top     /// R=0,C=0 ==> 0,0 = 2,0
            matrix[r][c] = matrix[N - 1 - c][r];

            // Move values from bottom to left  ///         ==> 2,0 = 2,2
            matrix[N - 1 - c][r] = matrix[N - 1 - r][N - 1 - c];

            // Move values from right to bottom ///         ==> 2,2 = 0,2
            matrix[N - 1 - r][N - 1 - c] = matrix[c][N - 1 - r];

            // Assign top to right              ///         ==> 0,2 = 0,0
            matrix[c][N - 1 - r] = temp;
        }
    }
}
