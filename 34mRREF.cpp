// RREF a 3 by 4 matrix. Swaps not yet implemented
#include <iostream>
using namespace std;
void input(double array[3][4])
{
    cout << "enter array elements : " << endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin >> array[i][j];
        }
    }
}
void rref(double array[3][4])
{
    array[1][1]-=((array[0][1]*array[1][0])/array[0][0]);
    array[1][2]-=((array[0][2]*array[1][0])/array[0][0]);
    array[1][3]-=((array[0][3]*array[1][0])/array[0][0]);

    array[2][1]-=((array[0][1]*array[2][0])/array[0][0]);
    array[2][2]-=((array[0][2]*array[2][0])/array[0][0]);
    array[2][3]-=((array[0][3]*array[2][0])/array[0][0]);

    array[1][0]=0,array[2][0]=0;

    array[0][2]-=((array[1][2]*array[0][1])/array[1][1]);
    array[0][3]-=((array[1][3]*array[0][1])/array[1][1]);

    array[2][2]-=((array[1][2]*array[2][1])/array[1][1]);
    array[2][3]-=((array[1][3]*array[2][1])/array[1][1]);

    array[0][1]=0,array[2][1]=0;

    array[0][3]-=((array[2][3]*array[0][2])/array[2][2]);
    array[1][3]-=((array[2][3]*array[1][2])/array[2][2]);

    array[0][2]=0,array[1][2]=0;

}
int main(void)
{
    double matrix34[3][4];

    input(matrix34);
    rref(matrix34);
    double ans1=(matrix34[0][3]/matrix34[0][0]), ans2=(matrix34[1][3]/matrix34[1][1]), ans3=(matrix34[2][3]/matrix34[2][2]);

    cout << "answer 1 : " << ans1 << endl;
    cout << "answer 2 : " << ans2 << endl;
    cout << "answer 3 : " << ans3 << endl;

    return 0;
}
