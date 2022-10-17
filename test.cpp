#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <complex>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef long double ld;
ll num_of_digits, binary_eq[35], dp[35][2][2], tot[35][2][2];

ll compute(ll level, ll parity, ll path){
    if(level == num_of_digits){            //Check if we have reached the end of a valid combination
        tot[level][parity][path] = 1;    //Add this 1 combination to the total number of combinations
        return 0;
    }
    ll u = 0, v = 0;
    if(path == 1){              //Check if we are currently on the exact same path as the binary equivalent
        ll next_digit = num_of_digits - 1 - level;
        if(binary_eq[next_digit] == 1){         //Check if the next digit of the binary representation is 1
            u = compute(level+1, 1, 1) + compute(level+1, 0, 0); //Add both "0" and "1" edge but when "0" is added,
            v = tot[level+1][1][1] + tot[level+1][0][0];        //it is no longer the exact same path, so path = 0
            if(parity == 1) u += tot[level+1][1][1];      //Adjacent bit is found
        }else{
            u = compute(level+1, 0, 1); //Add only "0" edge as adding "1" will make the number greater than N
            v = tot[level+1][0][1];
        }
    }else{
        u = compute(level+1, 0, 0) + compute(level+1, 1, 0); //As the path is "0" already, no matter what the parity is
        v = tot[level+1][0][0] + tot[level+1][1][0];
        if(parity == 1) u += tot[level+1][1][0];         //Adjacent bit is found
    }
    return u;
}

void convert_to_binary(ll x){ //Calculating the binary equivalent binary_eq
    ll pos = 0;
    while(x > 0){
        binary_eq[pos] = x % 2;
        x /= 2;
        pos++;
    }
    num_of_digits = pos;
}

int main()
{
    ll t,no=1;
    scanf("%lld", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        memset(binary_eq, 0, sizeof binary_eq);
        convert_to_binary(n);
        memset(dp, -1, sizeof dp);
        memset(tot, 0, sizeof tot);
        ll ans = compute(0, 0, 1);           //Initialize recursion with level = 0, parity = 0, path = 1
        printf("Case %lld: %lld\n", no++, ans);
    }
    return 0;
}
