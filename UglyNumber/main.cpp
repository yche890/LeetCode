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
    bool isUgly( int num )
    {
        if( num == 0 )
        {
            return false;
        }
        if( num == 1 )
        {
            return true;
        }
        if( num % 2 == 0 )
        {
            return isUgly( num/2 );
        }
        if( num % 3 == 0 )
        {
            return isUgly( num/3 );
        }
        if( num % 5 == 0 )
        {
            return isUgly( num/5 );
        }
        
        return false;
    }
};
int main(int argc, const char * argv[])
{
    Solution mySolution;
    
    std::cout << mySolution.isUgly( 42 ) << endl;
    return 0;
}

