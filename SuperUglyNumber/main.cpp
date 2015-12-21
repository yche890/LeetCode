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
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
		vector<int> ugly_numbers = { 1 };
		vector<int> indexes(primes.size(), 0);
		vector<int> list(primes.size(), 0);
        for( int i = 0; i < n; i++ )
        {
			for( int j = 0; j < primes.size(); j++)
			{
				list[j] = ugly_numbers[indexes[j]] * primes[j];
			}
			int res = *min_element( list.begin(), list.end() );
            ugly_numbers.push_back( res );
			for( int j = 0; j < primes.size(); j++)
			{
				if( res == list[j] )
				{
					indexes[j] ++;
				}
			}
        }
        return ugly_numbers[n-1];
    }
};
int main(int argc, const char * argv[])
{
    Solution mySolution;
    vector<int> primes = {2, 3, 5, 7};
    std::cout << mySolution.nthSuperUglyNumber( 42, primes ) << endl;
    return 0;
}

