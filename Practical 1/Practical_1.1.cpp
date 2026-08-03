#include <iostream>
using namespace std;
int main()
{
    int h , n ;
    cout << "Enter the no. of Items :";
    cin >> n;   
    
    cout << "Enter no. of Hour : ";
    cin >> h;
    
    int a[n];
    cout << "Enter List : " <<endl;
    for (int i = 0 ; i<n ;i++)
    {
        cin >> a[i];
    }

    for(int i = 0 ; i < h; i++)
    {
        int temp = a[0];
        for ( int j = 0 ; j < n ;j++)
        {
            a[j]=a[j+1];
        }
        a[n-1] = temp ;
    }
        cout << "Final Arrangementv : " << endl;
    for (int i=0; i < n ; i++)
    {
        cout << a[i] << " " ;
    }
    return 0;
}