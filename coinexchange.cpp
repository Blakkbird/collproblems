#include <iostream>
using namespace std;
int main()
{
int k;
cout << "Enter amount : " << endl;
cin >> k;

bool ans=false;
int coins=0;

for(int i=0;i<=k/3;i++)
{
    for(int j=0;j<=k/5;j++)
    {
        for(int l=0;l<=k/10;l++)
        {
            int sum=(10*l) + (5*j) + (3*i);
            if(k-sum == 0)
            {
                ans=true;
                coins=i+j+l;
            }
            
        }
    
    }
}

   if(ans){ cout << "Minimum coins : " << coins << endl;}
   else{cout << "not possible" << endl;}

}
