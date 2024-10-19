#include <iostream>
using namespace std;
int r,c;
int main()
{
    cout << "Enter matrix size" << endl;
    cin >> r;
    cin >> c;

    int matrix[r][c];

    cout << "Enter elements : " << endl;


    for(int i=0;i<r;i++) // input elements
    {
        for(int j=0;j<c;j++)
        {
            cin >> matrix[i][j];
        }
    }

int pr,pc,elm; // row and column position
    cout << "Enter position of new element " << endl;
    cin >> pr;
    cin >> pc;
    cout << "Value of new element " << endl;
    cin >> elm;

int arr[(r+1)*c];
int l=((r+1)*c);

for (int i=0;i<l;i++){arr[i]=0;} // initialise
int ind=((pr-1)*c)+pc-1; // index of input element

arr[ind]=elm;

//input rest of stuff in SDA
for(int i=0;i<ind;i++)
{arr[i]=matrix[i/c][i%c];}
for(int i=ind;i<(r*c);i++)
{arr[i+1]=matrix[i/c][i%c];}

for(int i=0;i<l;i++) // print SDA, you can convert it back into DDA (exercise for reader)
{
   cout << arr[i] << " ";
   if(i%c == c-1){cout << "" << endl;}
}

}
