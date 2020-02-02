#include <iostream>
using namespace std;
// fully efficient, except for has_played array, we'll write the function later(basic math)
// (3, 1, 1) grid translation to integer mappings form 1 to 9
class game
{
private:
    char b[3][3]; // b for board
    int p;        // player 1 or 2
    bool played[9];

public:
    game();
    void disp();
    void flip();
    void move();
    bool hasWon();
    void running_game();
    void move_AI();
    ~game();
};

game::game() : b{'1', '2', '3', '4', '5', '6', '7', '8', '9'}, p(2),
               played{false, false, false, false, false, false, false, false, false} {}

void game::disp()
{
    // cout << "\n--------------------------------------------";
    cout << "After move-->";
    for (int i = 0; i < 3; i++)
    {
        cout << "\n\t";
        for (int j = 0; j < 3; j++)
        {
            if (!j)
                cout << b[i][j] << " ";
            else
                cout << " |  " << b[i][j] << " ";
        }
    }
    cout << "\n--------------------------------------------";
}

void game::flip()
{
    p = p == 1 ? 2 : 1;
}

void game::move()
{
    // disp();
    flip();
    cout << "\nPlayer " << p << "'s move: ";
    unsigned move_made;
    cin >> move_made;
    char tok = p == 1 ? 'X' : 'O';
    while (move_made < 0 || move_made > 10 || played[move_made - 1])
    {
        if (move_made < 0 || move_made > 10)
            cout << "Invalid move, enter again: ";
        else
            cout << "Position full, choose another position: ";
        cin >> move_made;
    }
    played[move_made - 1] = true;
    switch (move_made)
    {
    case 1:
        b[0][0] = tok;
        break;
    case 2:
        b[0][1] = tok;
        break;
    case 3:
        b[0][2] = tok;
        break;
    case 4:
        b[1][0] = tok;
        break;
    case 5:
        b[1][1] = tok;
        break;
    case 6:
        b[1][2] = tok;
        break;
    case 7:
        b[2][0] = tok;
        break;
    case 8:
        b[2][1] = tok;
        break;
    case 9:
        b[2][2] = tok;
        break;
    }
    // flip();
}

bool game::hasWon()
{
    bool flag = false;
    // diagonals
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
        flag = true;
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && !flag)
        flag = true;

    //rows first
    for (int i = 0; i < 3 && !flag; i++)
    {
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2])
            flag = true;
        // cout << "rows ";
    }

    // columns
    for (int i = 0; i < 3 && !flag; i++)
    {
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i])
            flag = true;
        // cout << "columns ";
    }
    if (flag)
    {
        cout << "\n"
             << p << " has won\n";
    }
    // flip();
    return flag;
}

void game::move_AI()
{

    // disp();
    flip();
    cout << "\nPlayer " << p << "'s move: ";
    char tok = p == 1 ? 'X' : 'O'; // This decides which token is to be used based on p. Leave this as it is.

    unsigned move_made;
    if (tok == 'O')
    {
        unsigned i = 0, j = 0;
        // while (b[i][j] == 'O' || b[i][j] != 'X')
        // {
        //     if (i < 3)
        //         i++;
        //     else
        //         j++;
        // }

        // AI tries to win

    }
    else // for human player
    {
        cin >> move_made;
        while (tok == c && move_made < 0 || move_made > 10 || played[move_made - 1])
        {
            if (move_made < 0 || move_made > 10)
                cout << "Invalid move, enter again: ";
            else
                cout << "Position full, choose another position: ";
            cin >> move_made;
        }
    }
    played[move_made - 1] = true;
    switch (move_made)
    {
    case 1:
        b[0][0] = tok;
        break;
    case 2:
        b[0][1] = tok;
        break;
    case 3:
        b[0][2] = tok;
        break;
    case 4:
        b[1][0] = tok;
        break;
    case 5:
        b[1][1] = tok;
        break;
    case 6:
        b[1][2] = tok;
        break;
    case 7:
        b[2][0] = tok;
        break;
    case 8:
        b[2][1] = tok;
        break;
    case 9:
        b[2][2] = tok;
        break;
    }
    // flip();
}

void game::running_game()
{
    disp();
    int i = 0;
    while (i < 9)
    {
        //move_AI();
        move();
        disp();
        if (hasWon())
            return;
        i++;
    }
    cout << "\nDraw\n";
}

game::~game()
{
    // cout << "\Destructor called\n";
}

int main()
{
    game g;
    cout << "No move made\n";
    g.running_game();
    return 0;
}
