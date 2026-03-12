// INCLUDES
#include<iostream>
#include<algorithm>

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

//LOOP RUNS IF SOMEONE WINS
void winloop(char winner){
    if(winner == 'X'){
        std::cout << "THE Xs WON!";
    } else if(winner == 'O'){
        std::cout << "THE Os WON!";
    }
    exit(0);
}

//LOOP RUNS IF THE GAME ENDS IN A TIE (ALL SQUARES FULL WITH NO WIN)
void tieLoop(){
    std::cout << "IT ENDED IN A TIE...";
    exit(0);
}

//LOOP TO CHECK IF SOMEONE WON
void checkWin(){
    // Row 1
    if(square1 == square2 && square2 == square3 && square1 != ' '){
        winloop(square1);
    }
    // Row 2
    if(square4 == square5 && square5 == square6 && square4 != ' '){
        winloop(square4);
    }
    // Row 3
    if(square7 == square8 && square8 == square9 && square7 != ' '){
        winloop(square7);
    }
    // Column 1
    if(square1 == square4 && square4 == square7 && square1 != ' '){
        winloop(square1);
    }
    // Column 2
    if(square2 == square5 && square5 == square8 && square2 != ' '){
        winloop(square2);
    }
    // Column 3
    if(square3 == square6 && square6 == square9 && square3 != ' '){
        winloop(square3);
    }
    // Diagonal 1
    if(square1 == square5 && square5 == square9 && square1 != ' '){
        winloop(square1);
    }
    // Diagonal 2
    if(square3 == square5 && square5 == square7 && square3 != ' '){
        winloop(square3);
    }
}

// MINIMAX HELPER
int minimax(bool isMaximizing, int depth) {
    char* squares_arr[9] = {
        &square1,&square2,&square3,
        &square4,&square5,&square6,
        &square7,&square8,&square9
    };

    auto winner = [&]() -> char {
        if(square1==square2&&square2==square3&&square1!=' ') return square1;
        if(square4==square5&&square5==square6&&square4!=' ') return square4;
        if(square7==square8&&square8==square9&&square7!=' ') return square7;
        if(square1==square4&&square4==square7&&square1!=' ') return square1;
        if(square2==square5&&square5==square8&&square2!=' ') return square2;
        if(square3==square6&&square6==square9&&square3!=' ') return square3;
        if(square1==square5&&square5==square9&&square1!=' ') return square1;
        if(square3==square5&&square5==square7&&square3!=' ') return square3;
        return ' ';
    };

    char w = winner();
    if(w == 'O') return 10 - depth;   // prefer faster wins
    if(w == 'X') return -10 + depth;  // prefer slower losses

    bool anyEmpty = false;
    for(int i = 0; i < 9; i++) if(*squares_arr[i] == ' ') { anyEmpty = true; break; }
    if(!anyEmpty) return 0;

    if(isMaximizing) {
        int best = -1000;
        for(int i = 0; i < 9; i++) {
            if(*squares_arr[i] == ' ') {
                *squares_arr[i] = 'O';
                best = std::max(best, minimax(false));
                *squares_arr[i] = ' ';
            }
        }
        return best;
    } else {
        int best = 1000;
        for(int i = 0; i < 9; i++) {
            if(*squares_arr[i] == ' ') {
                *squares_arr[i] = 'X';
                best = std::min(best, minimax(true));
                *squares_arr[i] = ' ';
            }
        }
        return best;
    }
}

//YOUR WORST NIGHTMARE
void AI() {
    char* squares_arr[9] = {
        &square1,&square2,&square3,
        &square4,&square5,&square6,
        &square7,&square8,&square9
    };

    int bestScore = -1000;
    int bestMove = -1;

    for(int i = 0; i < 9; i++) {
        if(*squares_arr[i] == ' ') {
            *squares_arr[i] = 'O';
            int score = minimax(false);
            *squares_arr[i] = ' ';
            if(score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    if(bestMove != -1) *squares_arr[bestMove] = 'O';
}

//DRAWS THE BOARD EACH TURN
void drawBoard(){
    std::cout << " " << square1 << "  |  " << square2 << "  |  " << square3 << "\n";
    std::cout << "--------------\n";
    std::cout << " " << square4 << "  |  " << square5 << "  |  " << square6 << "\n";
    std::cout << "--------------\n";
    std::cout << " " << square7 << "  |  " << square8 << "  |  " << square9 << "\n";
}

//SHOWS THE BOARD SQUARE INDEX
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

//RUNS EACH TURN ASKING USER TO PICK THEIR SQUARE
void squareFill(){
    int squarenum;
    for( ; squares < 9 ; squares++){
        if(!player1Turn && ai){
            AI();
            drawBoard();
            checkWin();
            if(squares == 8 && win == false){
                tieLoop();
            }
            player1Turn = !player1Turn;
            continue;
        }

        std::cout << (player1Turn ? "Player 1 (X)" : "Player 2 (O)") 
                  << ", which square do you want? ";
        std::cin >> squarenum;

        while (
            (squarenum == 1 && square1 != ' ') ||
            (squarenum == 2 && square2 != ' ') ||
            (squarenum == 3 && square3 != ' ') ||
            (squarenum == 4 && square4 != ' ') ||
            (squarenum == 5 && square5 != ' ') ||
            (squarenum == 6 && square6 != ' ') ||
            (squarenum == 7 && square7 != ' ') ||
            (squarenum == 8 && square8 != ' ') ||
            (squarenum == 9 && square9 != ' ')
        ) {
            std::cout << "That square is already taken. Choose another: ";
            std::cin >> squarenum;
        }

        char mark = player1Turn ? 'X' : 'O';

        switch(squarenum){
            case 1: if(square1 == ' ') square1 = mark; break;
            case 2: if(square2 == ' ') square2 = mark; break;
            case 3: if(square3 == ' ') square3 = mark; break;
            case 4: if(square4 == ' ') square4 = mark; break;
            case 5: if(square5 == ' ') square5 = mark; break;
            case 6: if(square6 == ' ') square6 = mark; break;
            case 7: if(square7 == ' ') square7 = mark; break;
            case 8: if(square8 == ' ') square8 = mark; break;
            case 9: if(square9 == ' ') square9 = mark; break;
        }

        drawBoard();
        checkWin();

        if(squares == 8 && win == false){
            tieLoop();
        }

        player1Turn = !player1Turn;
    }
}

//MAIN LOOP
int main(){
    squares = 0;
    drawBoard();
    std::string yn;
    std::cout << "Would you like to see the square numbers (y/n): ";
    std::cin >> yn;
    if(yn == "y"){
        showboardnum();
    }
    std::string aiChoice;
    std::cout << "Do you want to play against ai?: ";
    std::cin >> aiChoice;
    if(aiChoice == "y"){
        ai = true;
    }

    drawBoard();
    squareFill();
}