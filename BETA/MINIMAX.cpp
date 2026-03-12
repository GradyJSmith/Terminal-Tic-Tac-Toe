// INCLUDES
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<ctime>

// GLOBAL VARIABLES
int squares;
bool player1Turn = true; 
bool win = false;
bool ai = false;

char square1 = ' ';
char square2 = ' ';
char square3 = ' ';
char square4 = ' ';
char square5 = ' ';
char square6 = ' ';
char square7 = ' ';
char square8 = ' ';
char square9 = ' ';

char* board[9] = {
    &square1,&square2,&square3,
    &square4,&square5,&square6,
    &square7,&square8,&square9
};

// WIN CHECK
char winner() {
    if(square1==square2&&square2==square3&&square1!=' ') return square1;
    if(square4==square5&&square5==square6&&square4!=' ') return square4;
    if(square7==square8&&square8==square9&&square7!=' ') return square7;

    if(square1==square4&&square4==square7&&square1!=' ') return square1;
    if(square2==square5&&square5==square8&&square2!=' ') return square2;
    if(square3==square6&&square6==square9&&square3!=' ') return square3;

    if(square1==square5&&square5==square9&&square1!=' ') return square1;
    if(square3==square5&&square5==square7&&square3!=' ') return square3;

    return ' ';
}

void winloop(char w){
    std::cout << (w=='X' ? "THE Xs WON!" : "THE Os WON!");
    exit(0);
}

void tieLoop(){
    std::cout << "IT ENDED IN A TIE...";
    exit(0);
}

void checkWin(){
    char w = winner();
    if(w != ' ') winloop(w);
}

// MINIMAX WITH DEPTH
int minimax(bool isMax, int depth) {
    char w = winner();
    if(w == 'O') return 10 - depth;
    if(w == 'X') return -10 + depth;

    bool empty = false;
for(int i=0;i<9;i++) if(*board[i]==' ') empty = true;
if(!empty) return 0;

    if(isMax) {
        int best = -1000;
        for(int i=0;i<9;i++){
            if(*board[i]==' '){
                *board[i]='O';
                best = std::max(best, minimax(false, depth+1));
                *board[i]=' ';
            }
        }
        return best;
    } else {
        int best = 1000;
        for(int i=0;i<9;i++){
            if(*board[i]==' '){
                *board[i]='X';
                best = std::min(best, minimax(true, depth+1));
                *board[i]=' ';
            }
        }
        return best;
    }
}

// CHECK FOR IMMEDIATE WIN
int findWinningMove(char mark){
    for(int i=0;i<9;i++){
        if(*board[i]==' '){
            *board[i]=mark;
            if(winner()==mark){
                *board[i]=' ';
                return i;
            }
            *board[i]=' ';
        }
    }
    return -1;
}

// CHECK FOR FORKS
int findFork(char mark){
    for(int i=0;i<9;i++){
        if(*board[i]==' '){
            *board[i]=mark;
            int winCount = 0;

            for(int j=0;j<9;j++){
                if(*board[j]==' '){
                    *board[j]=mark;
                    if(winner()==mark) winCount++;
                    *board[j]=' ';
                }
            }

            *board[i]=' ';
            if(winCount >= 2) return i;
        }
    }
    return -1;
}

// AI MOVE
void AI() {
    srand(time(0));

    // 1. Immediate win
    int move = findWinningMove('O');
    if(move != -1){ *board[move]='O'; return; }

    // 2. Immediate block
    move = findWinningMove('X');
    if(move != -1){ *board[move]='O'; return; }

    // 3. PURE MINIMAX WITH EVIL TIEBREAKER
    int bestScore = -1000;
    int bestEvil = 1000; // opponent's best reply
    int bestMove = -1;

    for(int i=0;i<9;i++){
        if(*board[i]==' '){
            *board[i]='O';
            int score = minimax(false,0);

            // EVIL MODE: evaluate opponent's best reply
            int opponentBest = 1000;
            for(int j=0;j<9;j++){
                if(*board[j]==' '){
                    *board[j]='X';
                    opponentBest = std::min(opponentBest, minimax(true,1));
                    *board[j]=' ';
                }
            }

            *board[i]=' ';

            // Choose move with highest score
            // If tied, choose move with WORST opponent reply
            if(score > bestScore || (score == bestScore && opponentBest < bestEvil)){
                bestScore = score;
                bestEvil = opponentBest;
                bestMove = i;
            }
        }
    }

    *board[bestMove] = 'O';
}


// DRAW BOARD
void drawBoard(){
    std::cout << " " << square1 << "  |  " << square2 << "  |  " << square3 << "\n";
    std::cout << "--------------\n";
    std::cout << " " << square4 << "  |  " << square5 << "  |  " << square6 << "\n";
    std::cout << "--------------\n";
    std::cout << " " << square7 << "  |  " << square8 << "  |  " << square9 << "\n";
}

// SHOW BOARD NUMBERS
void showboardnum(){
    std::cout << "    |    |    \n";
    std::cout << "  1 |  2 |  3 \n";
    std::cout << "______________\n";
    std::cout << "    |    |    \n";
    std::cout << " 4  |  5 |  6 \n";
    std::cout << "______________\n";
    std::cout << "    |    |    \n";
    std::cout << " 7  |  8 |  9 \n";
}

// GAME LOOP
void squareFill(){
    int squarenum;
    for(; squares < 9; squares++){
        if(!player1Turn && ai){
            AI();
            drawBoard();
            checkWin();
            if(squares==8) tieLoop();
            player1Turn = !player1Turn;
            continue;
        }

        std::cout << (player1Turn ? "Player 1 (X)" : "Player 2 (O)") 
                  << ", which square do you want? ";
        std::cin >> squarenum;

        while(squarenum < 1 || squarenum > 9 || *board[squarenum-1] != ' '){
            std::cout << "Invalid or taken. Choose again: ";
            std::cin >> squarenum;
        }

        *board[squarenum-1] = player1Turn ? 'X' : 'O';

        drawBoard();
        checkWin();
        if(squares==8) tieLoop();

        player1Turn = !player1Turn;
    }
}

// MAIN
int main(){
    squares = 0;
    drawBoard();

    std::string yn;
    std::cout << "Show square numbers (y/n): ";
    std::cin >> yn;
    if(yn=="y") showboardnum();

    std::string aiChoice;
    std::cout << "Play against AI? (y/n): ";
    std::cin >> aiChoice;
    if(aiChoice=="y") ai = true;

    drawBoard();
    squareFill();
}