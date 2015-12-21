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
class Solution {
public:
    int nthUglyNumber( int n )
    {
		vector<int> ugly_numbers = { 1 };
		int index_2 = 0;
		int index_3 = 0;
		int index_5 = 0;
        for( int i = 0; i < n; i++ )
        {
			int l1 = ugly_numbers[index_2] * 2;
			int l2 = ugly_numbers[index_3] * 3;
			int l3 = ugly_numbers[index_5] * 5;
            int res = min( min( l1, l2), l3 );
            ugly_numbers.push_back( res );
			if( res == l1 )
			{
				index_2 ++;
			}
			if( res == l2 )
			{
				index_3 ++;
			}
			if( res == l3 )
			{
				index_5 ++;
			}
        }
        return ugly_numbers[n - 1];
    }
    
};

int main(int argc, const char * argv[])
{
    Solution mySolution;
    
    std::cout << mySolution.nthUglyNumber( 42 ) << endl;
    return 0;
}

