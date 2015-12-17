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

using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        if(matrix.size() == 0){
            return;
        }
        
        height = (int)matrix.size();
        width = (int)matrix[0].size();
        int N =( width + 1) * ( height + 1 );
        cumulative = new int[ N ];
        std::fill_n( cumulative, N, 0 );
        for( int i = 1; i <= height; i++ ){
            
            for( int j = 1; j <= width; j++ ){
                
                cumulative[i * width + j] = cumulative[(i-1)*width+j] + cumulative[i*width+j-1] - cumulative[(i-1)*width+j-1] + matrix[i-1][j-1];
                
            }
            
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        return cumulative[(row2+1)*width+col2+1] + cumulative[row1*width+col1] - cumulative[row1*width+col2+1] - cumulative[(row2+1)*width+col1];
        
    }
    int* cumulative;
    int width, height;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
int main(int argc, const char * argv[])
{
//    vector<vector<int> > nums = {{3, 0, 1, 4, 2},
//                                {5, 6, 3, 2, 1},
//                                {1, 2, 0, 1, 5},
//                                {4, 1, 0, 1, 7},
//                                {1, 0, 3, 0, 5}};
    vector<vector<int> > nums(1, vector<int>(1,1));
    NumMatrix my(nums);
    std::cout << my.sumRegion(0,0,0,0) << endl;
    return 0;
}

