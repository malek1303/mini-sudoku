#include <iostream>//standard input and out  
#include <cstdlib> //for srand and rand function
#include <ctime>   // for srand seeding
using namespace std;

char board[9]; // array for all board positions

void drawboard() // draws the board at the start and after every move 
{
    
    for (int i=0;i<9;i++)
    {
        char ch;
        if(board[i]==' ') // if board pos is empty place a letter for position
        {
            ch = 'a'+i; 
        }
        else ch= board[i]; // if not empty insert the char from the board array
        cout<<" "<<ch;
        if (i%3<2)
            cout<<" |";
        else 
            cout<<"\n";
        if(i%3==2 &&i<8)
        cout<<"---+---+---\n";
    }
    cout<<endl;
}

bool checklose() // checks if the user has inserted a number twice in the same row or colmn returns true if lose false if not
{
    int lose[6][3] ={{0,1,2},{3,4,5},{6,7,8},//row lose
    {0,3,6},{1,4,7},{2,5,8}};//colmn lose
    for (int i=0;i<6;i++) 
    {
        int j = lose[i][0];
        int k = lose[i][1];
        int l = lose[i][2];
        int spacecount = 0; // to not make the user lose if there is two empty spots in the same row or colmn
        if(board[j]==' ') spacecount++;
        if(board[k]==' ') spacecount++;
        if(board[l]==' ') spacecount++;

        if (((board[j]==board[k])||(board[k]==board[l])||(board[j]==board[l]))&&(spacecount<2)) // loss condition
        {    
            cout<<"Sorry you have lost. Better luck next time!\n";
            return true;
        }
    }
    return false;
}

bool checkwin() //checks if there are no spaces left if so the player has won and function returns true else returns false
{
    for (int i=0;i<9;i++) // checks for blank spaces
    {
        if (board[i] == ' ')
        return false;
    }
    cout<<"Congrats you have won!!!!!\n";
    return true;
}

void playerin() // player input. prompts user for position and number and checks if they are valid if so changes board array
{
    char pos , num; // all inputs are chars
    int play;
    while(true)
    {
        cout<<"Please enter the desired positon (a->i) ";
        cin>>pos;
        cout<< "Please enter the number (1->3)";
        cin>>num;
        play = pos -'a'; // the diff between the input char and the start char is the index num of the board array element
        if((((pos-'a')>8)||((pos-'a')<0)||num>51||num<49)||(board[play]!=' ')) // checks for valid input using ASCII code and that the position is empty
        {
            cout<<"You have entered a wrong position or number\n";
            continue;
        }
        break;
    }
    board[play] = num;

}

void randstart() // places 1 , 2 in random position to make the game more challanging
{
    srand((unsigned) time(0)); // seeds the random function with time in seconds from 1970 till now to make rand() different each time
    for (int i =0;i<2;i++) 
    {
        int x = rand()%9; //makes x an int between [0,8] which is the range of the board array
        do {
            x = rand() % 9;
        } while (board[x] != ' ');
        board[x] = '1'+i;
    }
}

int main()
{
    for(int i=0;i<9;i++)// intializes the array with space char
        board[i]=' ';
    randstart();// put 1 , 2 in random positons
    cout<<"Welcome to the sudoko game!!!\n";// welcom message
    while(true)
    {
        drawboard();// draws the board at the start of every play
        playerin();// takes valid player input
        bool lost = checklose(); 
        bool won = checkwin();
        if (lost || won) //when game ends ask if the user wants to play again
            {
                cout<< "\nDo you want to play again? (y/n) ";
                char playagain;
                cin >> playagain;
                cout<< endl;
                if (playagain == 'y')
                {
                    for(int i=0;i<9;i++)// reset the board array
                    board[i]=' ';
                    randstart();// puts the random numbers 
                }
                else if (playagain == 'n')// exits the game if user doesnt want to play again
                {
                    return 0;
                }
            }
      
    }
    

    
}

