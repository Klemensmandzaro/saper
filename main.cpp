#include <iostream>
#include <Windows.h>
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;
void set_cursor(int,int);
void odkryj(int, int);
int ary[12][12];
char gwiazdy[12][12];
void plansza();
//int **ary;
int a, b, d, t, bomba=0;
int main() {
    a=12;
    //cin >> a;
    cin >> b;
    srand(time(NULL));
    //Jak mi sie bedzie chcialo to naprawie zeby byla to dynamiczna tablica
    /*int **ary = new int *[a];
    for (int i = 0; i < a; i++)
    {
        ary[i] = new int[a];
    }*/

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            ary[i][j]=0;
        }
    }

    for (int i = 0; i < b; i++)
    {
        d=rand()%a;
        t=rand()%a;
        if (ary[t][d]==9)
        {
            i--;
        }
        ary[t][d]=9;
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if(ary[i][j]==0 && ary[i+1][j]==9 && (i+1)<a)
            {
                bomba++;
            }
            if(ary[i][j]==0 && ary[i+1][j-1]==9 && (i+1)<a && (j-1)>=0)
            {
                bomba++;
            }
            if(ary[i][j]==0 && ary[i+1][j+1]==9 && (i+1)<a && (j+1)<a)
            {
                bomba++;
            }
            if(ary[i][j]==0 && ary[i][j-1]==9 && (j-1)>=0)
            {
                bomba++;
            }
            if(ary[i][j]==0 && ary[i][j+1]==9 && (j+1)<a)
            {
                bomba++;
            }
            if(ary[i][j]==0 && ary[i-1][j]==9 && (i-1)>=0)
            {
                bomba++;
            }
            if(ary[i][j]==0 && ary[i-1][j-1]==9 && (i-1)>=0 && (j-1)>=0)
            {
                bomba++;
            }
            if(ary[i][j]==0 && ary[i-1][j+1]==9 && (j+1)<a && (i-1)>=0)
            {
                bomba++;
            }
            if(ary[i][j]!=9)
            {
                ary[i][j]=bomba;
            }
            bomba=0;
        }
    }
    system("cls");


    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            gwiazdy[i][j]='*';
        }
        cout << endl;
    }
    plansza();



    int x=0 , y=0;
    int c;
    //system("cls");
    while (true) {
        set_cursor(x, y);
        switch (c = getch()) {
            case KEY_UP:
                if (y>0)y -= 1;
                break;
            case KEY_DOWN:
                if (y<(a-1))y += 1;
                break;
            case KEY_LEFT:
                if(x>0)x -= 1;
                break;
            case KEY_RIGHT:
                if(x<(a-1))x += 1;
                break;
            default:
                if (isdigit(c))
                {

                    odkryj(x,y);
                    if (ary[x][y]!=9)
                    {
                        plansza();
                    }

                }
                else if (c=='f')
                {
                    gwiazdy[y][x]=33;
                    plansza();
                }
        }
    }

    return 0;
}

void set_cursor(int x = 0 , int y = 0)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition ( handle , coordinates );
}

void odkryj(int e, int r)
{
    if(ary[e][r]==9)
    {
        system("cls");
        cout<<"You busted!!!";
        return;
    }
    else if (ary[e][r]==0 && gwiazdy[r][e]=='*')
    {
        gwiazdy[r][e]=ary[e][r]+48;
        if(e>0 && r>0)odkryj(e-1,r-1);
        if(e>0)odkryj(e-1,r);
        if(e>0 && r<(a-1))odkryj(e-1,r+1);
        if(r>0)odkryj(e,r-1);
        if(r<(a-1))odkryj(e,r+1);
        if(e<(a-1) && r>0)odkryj(e+1,r-1);
        if(e<(a-1))odkryj(e+1,r);
        if(e<(a-1) && r<(a-1))odkryj(e+1,r+1);
    }
    else if (ary[e][r]>0)
    {
        gwiazdy[r][e]=ary[e][r]+48;
    }


}

void plansza()
{
    int zyz=0;
    system("cls");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout <<gwiazdy[i][j];
        }
        cout << endl;
    }

    //jakby ktos chcial sciage
    /*for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout << ary[j][i];
        }
        cout << endl;
    }*/
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (gwiazdy[i][j]=='*' || gwiazdy[i][j]==33)
            {
                zyz++;
            }
        }

    }
    if (zyz==b)
    {
        system("cls");
        cout<<"Wygrales!!!";
    }
}