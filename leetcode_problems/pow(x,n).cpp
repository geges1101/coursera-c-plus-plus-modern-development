#include <iostream>

using namespace std;

//class Solution {
//public:
//    double myPow(double x, int n) {
//        int count = 0;
//        double x0 = x;
//
//        while(count <= n){
//            x = x * x0;
//            count++;
//        }
//        return x;
//    }
//};

double myPow(double x, int n) {
    if(n == 0) return 1;

    if(n == INT_MIN)
    {
        return myPow(x, -INT_MAX) * 1/x;
    }

    if(n<0 && n > INT_MIN){
        n = -n;
        x = 1/x;
    }

    if(n < 0){
        n *= -1;
        x = 1/x;
    }

    return n % 2 == 0 ? myPow(x*x, n / 2) : x*myPow(x*x, n / 2);
}

//int main(){
//    cout << myPow(2.10000, 3);
//}