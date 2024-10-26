#include<iostream>
#include "vector"
#include "algorithm"
using namespace std;
typedef long long ll;

// Iterative Sequential Search
ll sequentialSearch( vector<ll>& v, ll target) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == target) {
            return i;  // Return the index if target is found
        }
    }
    // Return -1 if target is not found
    return -1;
}
// Recursive Sequential Search
ll RecursiveSearch(ll arr[] , ll n , ll value , ll i=0)
{
    if(i>=n)
        return -1;
    if(arr[i] == value)
        return i;
    return RecursiveSearch(arr , n , value , i+1);
}
// find number in sorted array using binary search but iterative
ll iterative_binary_search(vector<ll>&numbers,ll target){
    ll least_number=0;
    ll highest_number=numbers.size()-1;
    while (least_number<=highest_number){
        ll mid_number= least_number+(highest_number-least_number)/2;
        if(numbers[mid_number]==target){
            return mid_number;
        }
        else if(numbers[mid_number]<target){
            least_number=mid_number+1;
        }
        else{
            highest_number = mid_number-1;
        }
    }
    return -1;
}
// recursive binary search that return the target number from sorted array
ll recursive_binary_search(vector<ll>&numbers,ll target,ll least_number,ll highest_number){

    if (least_number<=highest_number){
        ll mid_number= least_number+(highest_number-least_number)/2;
        if(numbers[mid_number]==target){
            //base case
            return mid_number;
        }
        else if(numbers[mid_number]<target){
            // see numbers that highest than middle number
            return recursive_binary_search(numbers,target,mid_number+1,highest_number);
        }
        else{
            //see the numbers that is lower than the middle number
            return recursive_binary_search(numbers,target,least_number,mid_number-1);
        }
    }
    return -1;
}
void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Iterative Sequential Search\n";
    cout << "2. Recursive Sequential Search\n";
    cout << "3. Iterative Binary Search\n";
    cout << "4. Recursive Binary Search\n";
    cout << "5. Exit\n";
}
int main(){
    ll c;
    do{
        displayMenu();
        cout<<"Enter the choice: ";
        cin>>c;

        if(c==1)
        {
            vector<ll>nums;
            cout<<"please enter the size of array:\n";
            ll n;
            cin>>n;
            cout<<"please enter the numbers in array :\n";
            for(ll i=0;i<n;i++){
                ll x;
                cin>>x;
                nums.push_back(x);
            }
            ll target;
            cout<<"Enter target number:  ";
            cin>>target;
            ll res= sequentialSearch(nums,target);
            if(res<0){
                cout<<"the target number is not found!\n";
            }
            else {
                cout << "the number is found in index " << res << " and its " << nums[res] << "\n";
            }
        }
        else if(c==2)
        {
            ll n;
            cout<<"Enter the size of the array: ";
            cin>>n;
            ll arr[n];
            cout<<"Enter the values of the array: ";
            for(ll i=0;i<n;i++)
            {
                cin>>arr[i];
            }
            cout<<"Enter the target value you want to search about: ";
            ll x;
            cin>>x;
            ll result = RecursiveSearch(arr , n , x );
            if(result == -1)
                cout<<"The target value not found !";
            else
                cout<<"The value is at index "<<result;

        }
        else if(c==3)
        {
            vector<ll>nums;
            cout<<"please enter the size of array: \n";
            ll n;
            cin>>n;
            cout<<"please enter the numbers in array: \n";
            for(ll i=0;i<n;i++){
                ll x;
                cin>>x;
                nums.push_back(x);
            }
            sort(nums.begin(),nums.end());
            cout<<"pls enter the target number:\n";
            ll target;
            cin>>target;
            ll res = iterative_binary_search(nums,target);
            if(res<0){
                cout<<"the target number is not found!\n";
            }
            else{
                cout<<"the number is found in index "<<res<<" and its "<<nums[res]<<"\n";
            }
        }
        else if(c==4)
        {
            vector<ll>nums;
            cout<<"please enter the size of array:\n";
            ll n;
            cin>>n;
            cout<<"please enter the numbers in array:\n";
            for(ll i=0;i<n;i++){
                ll x;
                cin>>x;
                nums.push_back(x);
            }
            sort(nums.begin(),nums.end());
            cout<<"pls enter the target number\n";
            ll target;
            cin>>target;
            ll res = recursive_binary_search(nums,target,0,nums.size()-1);
            if(res<0){
                cout<<"the target number is not found!\n";
            }
            else{
                cout<<"the number is found in index "<<res<<" and its "<<nums[res]<<"\n";
            }
        }
        else
        {
            cout << "Exiting..." << endl;
        }
        cout<<endl;
    } while (c!= 5);


}
