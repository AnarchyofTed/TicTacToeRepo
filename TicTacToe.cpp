#include <iostream>
using namespace std;

const int SIZE=3;

void InitBoard(char gameArray[][SIZE], int rows, int cols)
{
  for (int i=0; i<rows; ++i)
  {
    for (int j=0; j<cols; ++j)
    {
       gameArray[i][j]=' ';
    }
  }
}

void OutputBoard(char gameArray[][SIZE], int rows, int cols)
{
  for (int i =0; i<SIZE; ++i)
  {
  for (int j=0; j<SIZE; ++j)
  {
    cout<<gameArray[i][j];
    if(j==0 || j==1)
    {
      cout<<" | ";
    }
    if (j==2 && i!=2)
    {
      cout<<endl<<"---------"<<endl;
    }
  }
  }
  cout<<endl;
}
void UserOneInput(char gameArray[][SIZE], int rows, int cols)
{ int i, j;
  int pass=0;
  do {
      cout<<"Where would you like to place an X?"<<endl;
cout<<"X-coordinate: ";
cin>> i;
cout<<"Y-coordinate: ";
cin>> j;
if(gameArray[i-1][j-1]=='X' || gameArray[i-1][j-1]=='O')
  {
    cout<<"Can't place your marker here, try again"<<endl;
  }
  else
  {
    gameArray[i-1][j-1]='X';
    ++pass;
  }
} while(pass==0);
}
void UserTwoInput(char gameArray[][SIZE], int rows, int cols)
{ int i, j;
  int pass=0;
  do {
      cout<<"Where would you like to place an O?"<<endl;
cout<<"X-coordinate: ";
cin>> i;
cout<<"Y-coordinate: ";
cin>> j;
if(gameArray[i-1][j-1]=='X' || gameArray[i-1][j-1]=='O')
  {
    cout<<"Can't place your marker here, try again"<<endl;
  }
  else
  {
    gameArray[i-1][j-1]='O';
    ++pass;
  }
} while(pass==0);
}
int CheckForWinX(char gameArray[][SIZE], int rows, int cols)
{
  int win=0;
  if (gameArray[0][0]=='X'&& gameArray[0][1]=='X' && gameArray[0][2]=='X')
  {
    cout<<"X WINS!"<<endl;
    ++win;
  }
  else if (gameArray[1][0]=='X'&& gameArray[1][1]=='X' && gameArray[1][2]=='X')
  {
    cout<<"X WINS!"<<endl;
    ++win;
  }
  else if (gameArray[2][0]=='X'&& gameArray[2][1]=='X' && gameArray[2][2]=='X')
  {
    cout<<"X WINS!"<<endl;
    ++win;
  }
  else if (gameArray[0][0]=='X'&& gameArray[1][0]=='X' && gameArray[2][0]=='X')
  {
    cout<<"X WINS!"<<endl;
    ++win;
  }
  else if (gameArray[0][1]=='X'&& gameArray[1][1]=='X' && gameArray[2][1]=='X')
  {
    cout<<"X WINS!"<<endl;
    ++win;
  }
  else if (gameArray[0][2]=='X'&& gameArray[1][2]=='X' && gameArray[2][2]=='X')
  {
    cout<<"X WINS!"<<endl;
    ++win;
  }
  else if (gameArray[0][0]=='X'&& gameArray[1][1]=='X' && gameArray[2][2]=='X')
  {
    cout<<"X WINS!"<<endl;
    ++win;
  }
  else if (gameArray[0][2]=='X'&& gameArray[1][1]=='X' && gameArray[2][2]=='X')
  {
    cout<<"X WINS!"<<endl;
    ++win;
  }
  else
  {
    win=0;
  }
  return win;
}

int CheckForWinO(char gameArray[][SIZE], int rows, int cols)
{
  int win=0;
  if (gameArray[0][0]=='O'&& gameArray[0][1]=='O' && gameArray[0][2]=='O')
  {
    cout<<"O WINS!"<<endl;
    ++win;
  }
  else if (gameArray[1][0]=='O'&& gameArray[1][1]=='O' && gameArray[1][2]=='O')
  {
    cout<<"O WINS!"<<endl;
    ++win;
  }
  else if (gameArray[2][0]=='O'&& gameArray[2][1]=='O' && gameArray[2][2]=='O')
  {
    cout<<"O WINS!"<<endl;
    ++win;
  }
  else if (gameArray[0][0]=='O'&& gameArray[1][0]=='O' && gameArray[2][0]=='O')
  {
    cout<<"O WINS!"<<endl;
    ++win;
  }
  else if (gameArray[0][1]=='O'&& gameArray[1][1]=='O' && gameArray[2][1]=='O')
  {
    cout<<"O WINS!"<<endl;
    ++win;
  }
  else if (gameArray[0][2]=='O'&& gameArray[1][2]=='O' && gameArray[2][2]=='O')
  {
    cout<<"O WINS!"<<endl;
    ++win;
  }
  else if (gameArray[0][0]=='O'&& gameArray[1][1]=='O' && gameArray[2][2]=='O')
  {
    cout<<"O WINS!"<<endl;
    ++win;
  }
  else if (gameArray[0][2]=='O'&& gameArray[1][1]=='O' && gameArray[2][2]=='O')
  {
    cout<<"O WINS!"<<endl;
    ++win;
  }
  else
  {
    win=0;
  }
  return win;
}
int CheckForCat(char gameArray[][SIZE], int rows, int cols)
{int count=0;
  int win=0;
  for (int i=0;i<3;++i)
    {
      for (int j=0;j<3;++j)
      {
        if(gameArray[i][j]=='X' || gameArray[i][j]=='O')
        {
          ++count;
        }
      }
    }
    if(count == 9)
    {
      cout<<"Game Over! \n Cat Game\n";
      win=1;
    }
    return win;
}
int main()
{ int win=0;
  char gameArray[SIZE][SIZE];
  InitBoard(gameArray, SIZE, SIZE);
  OutputBoard(gameArray, SIZE, SIZE);
do {
  UserOneInput(gameArray, SIZE, SIZE);
  win=CheckForWinX(gameArray, SIZE, SIZE);
  OutputBoard(gameArray, SIZE, SIZE);
  if(win==0)
  {
    UserTwoInput(gameArray, SIZE, SIZE);
    win=CheckForWinO(gameArray, SIZE, SIZE);
    OutputBoard(gameArray, SIZE, SIZE);
  }
  win=CheckForCat(gameArray, SIZE, SIZE);
} while(win==0);
  return 0;
}
