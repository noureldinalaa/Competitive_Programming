#include <iostream>
using namespace std;

int n;
string array[4];

//check wether there is a block or not

bool checkElementBefore(int x,int y)
{
    for(int i=x-1;i>-1;i--)
    {
        if(array[i][y] == 'X') break;
        if(array[i][y] == 'T')
            return 0;
    }
    for(int i=y-1;i>-1;i--)
    {
        if(array[x][i] == 'X') break;
        if(array[x][i] == 'T')
            return 0;
    }
    return 1;
}

//This function will go through route 1 and 2 to give the maximum number of ticks can be there
int getResult(int x,int y)
{
    if (y==n)
        return getResult(x+1,0);
    if (x==n)
        return 0;

    int route1 = 0 ; int route2 = 0;

    if (array [x][y]=='.' && checkElementBefore(x,y))
    {
        array[x][y]='T'; //This will check that '.' is ticked
        route1 = 1+ getResult(x,y+1);
        array[x][y]= '.';
    }
    route2 = getResult(x,y+1);
    return max(route1,route2);
}

int main() {
while(cin >> n)
    {
        for(int i=0;i<n;i++)
            cin >> array[i];

        cout << getResult(0,0) << endl;
    }


    return 0;
}
