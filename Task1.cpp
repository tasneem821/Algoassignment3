#include "iostream"
#include <vector>
using namespace  std;
typedef long long ll;

//fibonacci using recursion
ll fib_rec(int number){
    //best case f(0) => 0 and f(1)=>1
    if(number==0||number==1){
        return number;
    }
    // it will call the function but with number-2 and number-1 and adding them
    return fib_rec(number-2)+ fib_rec(number-1);
}
// fibonacci using divide and conquer
vector<vector<ll >> matrixMultiply(const vector<vector<ll >>& A, const vector<vector<long long>>& B) {
    return {
            {A[0][0] * B[0][0] + A[0][1] * B[1][0],
                    A[0][0] * B[0][1] + A[0][1] * B[1][1]},
            {A[1][0] * B[0][0] + A[1][1] * B[1][0],
                    A[1][0] * B[0][1] + A[1][1] * B[1][1]}
    };
}

vector<vector<ll>> matrixPower(const vector<vector<ll>>& A,  ll n) {
    if (n == 1) return A;

    // Divide and conquer approach
    if (n % 2 == 0) {
        vector<vector<long long>> halfPower = matrixPower(A, n / 2);
        return matrixMultiply(halfPower, halfPower);
    } else {
        return matrixMultiply(A, matrixPower(A, n - 1));
    }
}

ll fib_DC(ll n) {
    if (n == 0) return 0;
    else if( n==1) return 1;

    // Base matrix for Fibonacci calculation
    vector<vector<long long>> baseMatrix = {{1, 1}, {1, 0}};
    vector<vector<long long>> resultMatrix = matrixPower(baseMatrix, n - 1);

    // F(n) is located at resultMatrix[0][0]
    return resultMatrix[0][0];
}
//fibonacci using dynamic programming
ll fib_DP(ll n) {
    if (n <= 1) return n;

    vector<ll> f(n + 1);
    f[0] = 0;
    f[1] = 1;

    for (ll i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main(){
    cout<<"please chose the number of task:\n"
          "1: Recursive fibonacci\n"
          "2: Divide and conquer fibonacci\n"
          "3: Dynamic programming fibonacci\n"
          "0:exit\n";
    cout<<"Enter your choice: ";
    int choice ;
    while (cin>>choice){
        if(choice==1){
            cout<<"Recursive Fibonacci\n";
            cout<<"Enter number : ";
            ll num;
            cin>>num;
            cout<<"Fibonacci of "<< num <<" is : "<<fib_rec(num)<<"\n";
        }
        else if(choice==2){
            cout<<"Divide and conquer Fibonacci\n";
            cout<<"Enter number : ";
            ll num;
            cin>>num;
            cout<<"Fibonacci of "<< num <<" is : "<<fib_DC(num)<<'\n';

        }
        else if(choice==3){
            cout<<"DP Fibonacci\n";
            cout<<"Enter number: ";
            ll num;
            cin>>num;
            ll res= fib_DP(num);
            cout<<"Fibonacci of "<< num <<" is : "<<res<<endl;
        }
        else{
            break;
        }
    }
}


