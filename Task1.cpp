#include "iostream"
#include <vector>
using namespace  std;

//fibonacci using recursion
int fibonacci(int number){
    //best case f(0) => 0 and f(1)=>1
    if(number==0||number==1){
        return number;
    }
    // it will call the function but with number-2 and number-1 and adding them
    return fibonacci(number-2)+ fibonacci(number-1);
}
long long fib_DP(long long n) {
    if (n <= 1) return n;

    // Use vector to handle large values of n
    vector<long long> f(n + 1);
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main(){
    cout<<"please chose the number of task\n"
          "1:recursive fibonacii\n"
          "2: divide and conquer fibonacii\n"
          "3: dynamic programming fibonacii\n"
          "0:exit\n";
    cout<<"Enter your choice: ";
    int choice ;
    while (cin>>choice){
        if(choice==1){
            cout<<"enter number :\n";
            int num;
            cin>>num;
            cout<<"the answer of the fibonacci number is "<<fibonacci(num)<<"\n";
        }
        else if(choice==2){}
        else if(choice==3){
            cout<<"DP Fibonacci\n";
            cout<<"Enter the number: ";
            long long n;
            cin>>n;
            long long res= fib_DP(n);
            cout<<"Fibonacci of "<< n <<" is : "<<res<<endl;
        }
        else{
            break;
        }
    }
}


