#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>

using namespace std;

int carlane = 32;
char mov = ' ';
int lane = 1;
int flag = 0;
int score = 0;
char symbol_m = 178;

int OppLoc[5] = {4, 32, 60, 88, 4};
int opp1X[4];
int opp2X[4];
int opp3X[4];

char veh[10][22] = {

    ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
    ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ',
    '|', '\\', '|', ' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ', ' ', '|', '/', '|',
    '|', '/', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', '\\', '|',
    ' ', '|', ' ', ' ', '\\', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '/', ' ', ' ', '|', ' ',
    ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ',
    ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ',
    '|', '\\', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '/', '|',
    '|', '/', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '\\', '|',
    ' ', '|', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '|', ' '};

char Pveh[10][22] = {

    ' ', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', ' ',
    ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ',
    '|', '\\', '|', ' ', ' ', '_', '_', '_', '|', '_', '_', '_', '_', '|', '_', '_', '_', ' ', ' ', '|', '/', '|',
    '|', '/', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', '\\', '|',
    ' ', '|', ' ', ' ', '\\', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '/', ' ', ' ', '|', ' ',
    ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ',
    ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ',
    '|', '\\', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', '/', '|',
    '|', '/', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', '\\', '|',
    ' ', '|', '_', '_', '_', '_', '_', '_', '|', '_', '_', '_', '_', '|', '_', '_', '_', '_', '_', '_', '|', ' '};

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    // handle is a pointer to an object loacted on the GC heap.
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    // GetStdHandle - retrives a handle to the specified standard device(std i/o ,std o/p ,or std error).
    COORD c = {x, y};
    // COORD - Defines the coordinates of a character cell in a console screen buffer.
    /* SYNTAX -
    typedef struct _COORD {
    SHORT X;
    SHORT y;
    } COORD *PCCOORD;
    */
    SetConsoleCursorPosition(h, c);
    // Sets the cursor position in the specified console screen buffer.
}

void loading()
{
    score = 0;
    lane = rand() % (4);
    opp1X[0] = OppLoc[lane];

re:
    lane = rand() % (4);
    if (OppLoc[lane] == opp1X[0])
        goto re;
    else
        opp2X[0] = OppLoc[lane];

re2:
    lane = rand() % (4);
    if (OppLoc[lane] == opp1X[0] || OppLoc[lane] == opp2X[0])
        goto re2;
    else
        opp3X[0] = OppLoc[lane];

    opp1X[1] = 1;
    opp2X[1] = 1;
    opp3X[1] = 1;

    system("cls");
    gotoxy(28, 10);
    cout << "LOADING";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        sleep(1);
    }
    gotoxy(125, 10);
    cout << "|";
    gotoxy(39, 10);
    for (int i = 0; i < 86; i++)
    {
        cout << symbol_m;
        Sleep(50);
    }
}

void player_v()
{

    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 22; i++)
        {
            gotoxy(i + carlane, j + 28);
            cout << Pveh[j][i];
        }
    }
}

void erase_pv()
{
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 22; i++)
        {
            gotoxy(i + carlane, j + 28);
            cout << ' ';
        }
    }
}

int opp_v(int a[])
{

    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 22; i++)
        {
            gotoxy((i) + (a[0]), j + a[1]);
            cout << veh[j][i];
        }
    }
}

int erase_ov(int a[])
{
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 22; i++)
        {
            gotoxy((i) + (a[0]), j + a[1]);
            cout << ' ';
        }
    }
    if (a[1] == opp1X[1])
        opp1X[1]++;
    else if (a[1] == opp2X[1])
        opp2X[1]++;
    else if (a[1] == opp3X[1])
        opp3X[1]++;
    flag = 0;
}

inline int accident()


{
    if(kbhit())
    {
        mov = getch();
    }
    else if((opp1X[1]>=18 || opp2X[1]>=18) && (carlane == opp1X[0] || carlane == opp2X[0]))
        return 1;
    if(opp3X[1]>=18)
    {
        if ((opp1X[0] == carlane || opp2X[0] == carlane) && (opp1X[1] >= 15 && opp2X[1] >= 18))
            return 1;
        else if (opp3X[0] == carlane && opp3X[1] >= 18 && flag == 1)
            return 1;
    }
    return 0;
}

void gameover()
{

    gotoxy(29, 8);
    for (int i = 0; i < 67; i++)
        cout << symbol_m;
    gotoxy(29, 9);
    cout << symbol_m << symbol_m << "                                                               " << symbol_m << symbol_m;
    gotoxy(29, 10);
    cout << symbol_m << symbol_m << "   "
         << "  * * * *         *****       *          *    * * * * * *   " << symbol_m << symbol_m;
    gotoxy(29, 11);
    cout << symbol_m << symbol_m << "   "
         << " *        *      *     *      *  *     * *    *             " << symbol_m << symbol_m;
    gotoxy(29, 12);
    cout << symbol_m << symbol_m << "   "
         << "*               *       *     *   *  *   *    * * * * *     " << symbol_m << symbol_m;
    gotoxy(29, 13);
    cout << symbol_m << symbol_m << "   "
         << "*    * * *     * * * * * *    *    **    *    *             " << symbol_m << symbol_m;
    gotoxy(29, 14);
    cout << symbol_m << symbol_m << "   "
         << "  * *     *    *         *    *          *    * * * * * *   " << symbol_m << symbol_m;
    gotoxy(29, 15);
    cout << symbol_m << symbol_m << "                                                               " << symbol_m << symbol_m;
    gotoxy(29, 16);
    cout << symbol_m << symbol_m << "   "
         << "  * * * *      *         *    * * * * * *     * * * * *     " << symbol_m << symbol_m;
    gotoxy(29, 17);
    cout << symbol_m << symbol_m << "   "
         << "*         *    *         *    *               *        *    " << symbol_m << symbol_m;
    gotoxy(29, 18);
    cout << symbol_m << symbol_m << "   "
         << "*         *     *       *     * * * * *       * * * * *     " << symbol_m << symbol_m;
    gotoxy(29, 19);
    cout << symbol_m << symbol_m << "   "
         << "*         *       *   *       *               *        *    " << symbol_m << symbol_m;
    gotoxy(29, 20);
    cout << symbol_m << symbol_m << "   "
         << "  * * * *           *         * * * * * *     *         *   " << symbol_m << symbol_m;
    gotoxy(29, 21);
    cout << symbol_m << symbol_m << "                                                               " << symbol_m << symbol_m;
    if (!score > 10)
    {
        gotoxy(29, 22);
        cout << symbol_m << symbol_m << "  SCORE : " << score << "  (NOOB)                                            " << symbol_m << symbol_m;
    }
    else
    {
        gotoxy(29, 22);
        cout << symbol_m << symbol_m << "  SCORE : " << score << "  (NOOB)                                           " << symbol_m << symbol_m;
    }
    gotoxy(29, 23);
    cout << symbol_m << symbol_m << "                                                               " << symbol_m << symbol_m;
    gotoxy(29, 24);
    for (int i = 0; i < 66; i++)
        cout << symbol_m;

    getch();
}

void play()
{
    system("cls");
    char border_m = 178;
    for (int i = 0; i <= 145; i++)
        cout << border_m;
    cout << endl;
    for (int j = 1; j < 39; j++)
    {
        gotoxy(0, j);
        cout << border_m;
        gotoxy(28, j);
        cout << "|";
        gotoxy(28 + 29, j);
        cout << "|";
        gotoxy(28 + 29 + 29, j);
        cout << "|";
        gotoxy(115, j);
        cout << border_m;
        gotoxy(145, j);
        cout << border_m;
    }
    gotoxy(125, 5);
    cout << "SCORE : ";
    gotoxy(118, 10);
    cout << "Press 'A' to move LEFT";
    gotoxy(118, 12);
    cout << "Press 'D' to move RIGHT";
    // for (int i = 0; i <= 145; i++) cout<<border_m;
    while (1)
    {
        if (kbhit())
        {
            mov = getch();
            // cin>>mov;
            if (mov == 'a' || mov == 'A')
            {
                if (carlane >= 32)
                    carlane -= 28;
                else
                    goto over;
            }
            else if (mov == 'd' || mov == 'D')
            {
                if (carlane <= 60)
                    carlane += 28;
                else
                    goto over;
            }
            if (mov == '\b')
                goto over;
        }
        player_v();
        opp_v(opp2X);
        opp_v(opp1X);
        erase_pv();
        erase_ov(opp2X);
        
        if (accident() == 1)
        {
        over:
            system("cls");
            gameover();
            return;
        }

        if (score % 5 == 0 && score != 0 && flag == 0 )
        {
            opp_v(opp3X);
            flag = 1;
            if (accident() == 1)
            {
                system("cls");
                gameover();
                return;
            }
            erase_ov(opp3X);
        }

        erase_ov(opp1X);

        gotoxy(133, 5);
        cout << score;

        if (opp1X[1] >= 32)
        {
            lane = rand() % (4);
            opp1X[0] = OppLoc[lane];
            opp1X[1] = 1;
            score++;
        }
        if (opp2X[1] >= 32)
        {
        re2:    
            lane = rand() % (4);
            if (OppLoc[lane] == opp1X[0])
                goto re2;
            else
                opp2X[0] = OppLoc[lane];
            opp2X[1] = 1;
            score++;
        }
        if (opp3X[1] >= 28)
        {
        re3:
            lane = rand() % (4);
            if (OppLoc[lane] == opp1X[0] || OppLoc[lane] == opp2X[0])
                goto re3;
            else
                opp3X[0] = OppLoc[lane];
            opp3X[1] = 1;
            score++;
            flag = 0;
        }
    }
}

int main()
{
    while (1)
    {
        system("cls"); // 178
        gotoxy(50, 1);
        {
            for (int i = 50; i < 120; i++)
                cout << symbol_m;
        }
        for (int i = 50; i < 120; i++)
        {
            gotoxy(i, 2);
            cout << symbol_m;
        }
        gotoxy(72, 3);
        cout << "WELCOME to VALHALLA ";
        for (int i = 50; i < 120; i++)
        {
            gotoxy(i, 4);
            cout << symbol_m;
        }
        for (int i = 50; i < 120; i++)
        {
            gotoxy(i, 5);
            cout << symbol_m;
        }
        cout << endl;
        gotoxy(84, 8);
        cout << "1.PLAY";
        gotoxy(84, 10);
        cout << "2.EXIT\n";

        char choice;
        choice = getch();
        if (choice == '1')
        {
            loading();
            play();
        }
        
        else if (choice != 1)
            exit(1);
    }
}
