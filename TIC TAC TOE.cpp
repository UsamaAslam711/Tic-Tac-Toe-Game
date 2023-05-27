#include<iostream>
#include<iomanip>
using namespace std;
void drawTable(char table[3][3]);
char checkWinner3by3(char table[3][3]);
int main()
{
//This array of character represents the game table. Initially all the characters are
set to blank.
char table[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
char player = 'X';
char winner = ' ';
// These variables will hold the number of the row and column selected
// by the players.
int row;
int column;
//Boolean variables. These are use to check whether the move played by the players is
valid or not.
bool is_move;
bool bool_row;
bool bool_column;
cout << " ^^^^^^^^^^^^^^^^-------------------
^^^^^^^^^^^^^^^^"<<endl;
cout << " >> TIC TAC TOE <<" << endl;
cout << " ^^^^^^^^^^^^^^^^-------------------^^^^^^^^^^^^^^^^"
<< endl << endl << endl << endl ;
// The loop will continoue to run till the game is over.
while (winner == ' ')
{
//Initially setting the boolean variables to false. So the players will cast
their next move.
is_move = false;
bool_row = false;
bool_column = false;
//Drawing the table till the game is over.
drawTable(table);
// This IF statement shows that whose turn is next (player 1 or player 2.
cout << endl << endl;
cout << " +******************+"<<endl;
cout << " | Player ";
if (player == 'X')
{
cout << 1;
}
else
{
cout << 2;
}
cout << "'s turn! |" << endl;cout << " +******************+";
// This two loops which are simultaneously used will continoue to run till the
player
// entered the valid row or column respectively.
is_move = false;
while (!is_move)
{
// This loop is use to enter the row which the player wanna occupy.
// And check whether the player entered input is valid or not.
bool_row = false;
while (!bool_row)
{
cout << endl << endl;
cout << "--> Enter your desired row which you wanna occupy = ";
cin >> row;
if (row == 1 || row == 2 || row == 3)
{
bool_row = true;
}
else
{
cout << endl;
cout << endl << "** The row you Entered is invalid! **" << endl<<
endl<<endl;
}
}
// This loop is use to enter the column which the player wanna occupy.
// And check whether the player entered inut is valid or not.
bool_column = false;
while (!bool_column)
{
cout << "--> Enter your desired column which you wanna occupy = ";
cin >> column;
cout << endl << endl;
if (column == 1 || column == 2 || column == 3)
{
bool_column = true;
}
else
{
cout << endl;
cout << endl << "** The column you Entered is invalid! **" << endl;
}
}
// As the intial address of array starts from 0 and user is starting from 1.
// So we have to subtract 1 from each user entered row and column.
if (table[row - 1][column - 1] == ' ')
{
// Replacing the intially blank ENTRY with the "X" or "O"
table[row - 1][column - 1] = player;
is_move = true;
// Switching to the other player
if (player == 'X')
{
player = 'O';}
else
{
player = 'X';
}
}
// If the space the already occupied then telling the player to choose
another space.
else
{
cout << "WARNING...!"<<endl;
cout << "The Space you want to occupy is already occupied. ";
cout << "Please select a different space." << endl << endl;
drawTable(table);
}
}
cout << endl;
//Checking if the player won or not
winner = checkWinner3by3(table);
//If Either one of the player is won then IF statemnet will execute
if (winner == 'X' || winner == 'O')
{
drawTable(table);
cout << endl << endl << endl << endl;
cout << "
+^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^+"<<endl;
cout << " | >>>>>>>Congratulations! Player ";
if (winner == 'X')
{
cout << 1;
}
else
{
cout << 2;
}
cout << " is the winner! <<<<<<< |" << endl;
cout << "
+^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^+" <<
endl<<endl<<endl;
}
else if (winner == 'T')
{
drawTable(table);
//If no one has won the game then TIE message will be displayed.
cout << endl << endl;
cout << " +*^*^*^*^*^*^*^*^*^*^*^*^+"<<endl;
cout << " | It's a TIE! | "<< endl;
cout << " +*^*^*^*^*^*^*^*^*^*^*^*^+" << endl;
}
}
system("pause");return 0;
}
// Prints the game table
void drawTable(char table[][3])
{
char print[][3] = { {' ',' ',' '},
{' ',' ',' '},
{' ',' ',' '} };
cout << endl;
cout << "----------------------------------------------------------------------------
------------------" << endl;
cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
cout << "----------------------------------------------------------------------------
------------------"<< endl<<endl;
cout << " ^^^^^^-------------------^^^^^^" << endl;
cout << " >> T A B L E <<" << endl;
cout << " ^^^^^^-------------------^^^^^^" << endl << endl ;
cout << " 1 2 3" << endl;
cout << " +--------------+--------------+--------------+" << endl;
cout << " 1 " << "| " << table[0][0] << " | " <<
table[0][1] << " | " << table[0][2] << " |" << endl;
cout << " +--------------+--------------+--------------+" << endl;
cout << " 2 " << "| " << table[1][0] << " | " <<
table[1][1] << " | " << table[1][2] << " |" << endl;
cout << " +--------------+--------------+--------------+" << endl;
cout << " 3 " << "| " << table[2][0] << " | " <<
table[2][1] << " | " << table[2][2] << " |" << endl;
cout << " +--------------+--------------+--------------+" << endl;
}
// Checks the whole table if there is a winner.
char checkWinner3by3(char table[][3])
{
for (int a = 0; a < 3; a++) //For the rows.
{
if (table[a][0] == table[a][1] && table[a][0] == table[a][2])
{
return table[a][0];
}
}
for (int z = 0; z < 3; z++) //For the column.
{if (table[0][z] == table[1][z] && table[0][z] == table[2][z])
{
return table[0][z];
}
}
if (table[0][0] == table[1][1] && table[1][1] == table[2][2])
{
return table[0][0];
}
if (table[0][2] == table[1][1] && table[1][1] == table[2][0])
{
return table[0][2];
}
return 0;
}
