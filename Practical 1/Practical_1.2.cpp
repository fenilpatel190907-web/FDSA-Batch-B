#include <iostream>
using namespace std;
int main()
{
  int n ;

  cout << "Enter no. of Borrowes : ";
  cin >> n ;

  int a[n] ;
  cout << "Enter Borrowed Book ID : " ;
  for (int i = 0 ; i < n ; i++)
  {
        cin >>  a[i];
  }
  for (int i = 0 ; i < n ; i++)
  {
        int c = 0 ;
        int flag =0 ;
    for (int j = i + 1 ; j < n ; j++)
    {
        if (a[i]==a[j])
        {
            c ++ ;
            flag =1 ;
            break;
        }


    }
    if (c>=1)
        {
            for (int k = 0 ; k < i ; k ++)
            {
                if(a[i] == a[k])
                {
                    flag = 0;
                }
            }
        }
        
    if(flag)
        {
            cout << "Book That have borrowed more than 1 time : ";
            cout << a[i] << " ";
        }

  }

    return 0;
}
