#include<iostream>
using namespace std;

int RecursiveSearch(int arr[] , int n , int value , int i=0)
{
    if(i>=n)
        return -1;
    if(arr[i] == value)
        return i;
    return RecursiveSearch(arr , n , value , i+1);
}
void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Iterative Sequential Search\n";
    cout << "2. Recursive Sequential Search\n";
    cout << "3. Iterative Binary Search\n";
    cout << "4. Recursive Binary Search\n";
    cout << "5. Exit\n";
}
int main()
{
    int c;
    do{
        displayMenu();
        cout<<"Enter the choice: ";
        cin>>c;

        if(c==1)
        {

        }
        else if(c==2)
        {
            int n;
            cout<<"Enter the size of the array: ";
            cin>>n;
            int arr[n];
            cout<<"Enter the values of the array: ";
            for(int i=0;i<n;i++)
            {
                cin>>arr[i];
            }
            cout<<"Enter the target value you want to search about: ";
            int x;
            cin>>x;
            int result = RecursiveSearch(arr , n , x );
            if(result == -1)
                cout<<"The target value not found !";
            else
                cout<<"The value is at index "<<result;

        }
        else if(c==3)
        {

        }
        else if(c==4)
        {

        }
        else
        {
            cout << "Exiting..." << endl;
        }
        cout<<endl;
    } while (c!= 5);


}


