#include <iostream>
#include <cstring>
using namespace std;
int main()
{
 char str[100] ,temp[100], longest[100] ;
 int j=0 , len=0 ,max=0;
 cout << "Enter TEXT : ";
 cin.getline(str ,100);
 for (int i = 0 ; ;i ++)
 {
     if (str[i] != ' ' && str[i] != '\0')
     {
         temp[j] = str[i];
         j++;
         len++;
         if(len >= max)
         {
             max = len ;
             temp[j]='\0' ;
             strcpy(longest , temp);

         }
         len = 0 ;
          j= 0;
         if (str[i] == '\0')
            break;
     }
 }
 cout << "longestest : " << longest<< endl;
 cout << "length : " << max ;
}
