/***
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
***/

void setZeroes(vector<vector<int>>& matrix) {

    const int row = matrix.size();
    const int column = matrix[0].size();

    std::vector< std::pair<int,int> > vecPairs; /// vector to store the 0 indices

    /// Store all the vector indices with 0.
    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<column; ++j)
        {
            if(matrix[i][j] == 0){
                vecPairs.push_back(make_pair(i,j)); 
            }
        }
    }

    for(const auto & p: vecPairs)
    {
        for(int i=0; i<column; i++) /// Set all indices with column as 0 to 0. 
            matrix[p.first][i] = 0;

        for(int i=0; i<row; i++)    /// Set all indices with row as 0 to 0.
            matrix[i][p.second] = 0;
    }   
}
