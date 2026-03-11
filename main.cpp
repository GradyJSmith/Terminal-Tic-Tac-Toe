// INCLUDES
#include<iostream>

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

//YOUR WORST NIGHTMARE
void AI(){

    // --- WINNING LOGIC: make 0 win ---

    // Row 1
    if(square1 == 'O' && square2 == 'O' && square3 == ' ') { square3 = 'O'; return; }
    if(square1 == 'O' && square3 == 'O' && square2 == ' ') { square2 = 'O'; return; }
    if(square2 == 'O' && square3 == 'O' && square1 == ' ') { square1 = 'O'; return; }

    // Row 2
    if(square4 == 'O' && square5 == 'O' && square6 == ' ') { square6 = 'O'; return; }
    if(square4 == 'O' && square6 == 'O' && square5 == ' ') { square5 = 'O'; return; }
    if(square5 == 'O' && square6 == 'O' && square4 == ' ') { square4 = 'O'; return; }

    // Row 3
    if(square7 == 'O' && square8 == 'O' && square9 == ' ') { square9 = 'O'; return; }
    if(square7 == 'O' && square9 == 'O' && square8 == ' ') { square8 = 'O'; return; }
    if(square8 == 'O' && square9 == 'O' && square7 == ' ') { square7 = 'O'; return; }

    // Column 1
    if(square1 == 'O' && square4 == 'O' && square7 == ' ') { square7 = 'O'; return; }
    if(square1 == 'O' && square7 == 'O' && square4 == ' ') { square4 = 'O'; return; }
    if(square4 == 'O' && square7 == 'O' && square1 == ' ') { square1 = 'O'; return; }

    // Column 2
    if(square2 == 'O' && square5 == 'O' && square8 == ' ') { square8 = 'O'; return; }
    if(square2 == 'O' && square8 == 'O' && square5 == ' ') { square5 = 'O'; return; }
    if(square5 == 'O' && square8 == 'O' && square2 == ' ') { square2 = 'O'; return; }

    // Column 3
    if(square3 == 'O' && square6 == 'O' && square9 == ' ') { square9 = 'O'; return; }
    if(square3 == 'O' && square9 == 'O' && square6 == ' ') { square6 = 'O'; return; }
    if(square6 == 'O' && square9 == 'O' && square3 == ' ') { square3 = 'O'; return; }

    // Diagonal 1
    if(square1 == 'O' && square5 == 'O' && square9 == ' ') { square9 = 'O'; return; }
    if(square1 == 'O' && square9 == 'O' && square5 == ' ') { square5 = 'O'; return; }
    if(square5 == 'O' && square9 == 'O' && square1 == ' ') { square1 = 'O'; return; }

    // Diagonal 2
    if(square3 == 'O' && square5 == 'O' && square7 == ' ') { square7 = 'O'; return; }
    if(square3 == 'O' && square7 == 'O' && square5 == ' ') { square5 = 'O'; return; }
    if(square5 == 'O' && square7 == 'O' && square3 == ' ') { square3 = 'O'; return; }

    
    // --- BLOCKING LOGIC: stop X from winning ---

    // Row 1
    if(square1 == 'X' && square2 == 'X' && square3 == ' ') { square3 = 'O'; return; }
    if(square1 == 'X' && square3 == 'X' && square2 == ' ') { square2 = 'O'; return; }
    if(square2 == 'X' && square3 == 'X' && square1 == ' ') { square1 = 'O'; return; }

    // Row 2
    if(square4 == 'X' && square5 == 'X' && square6 == ' ') { square6 = 'O'; return; }
    if(square4 == 'X' && square6 == 'X' && square5 == ' ') { square5 = 'O'; return; }
    if(square5 == 'X' && square6 == 'X' && square4 == ' ') { square4 = 'O'; return; }

    // Row 3
    if(square7 == 'X' && square8 == 'X' && square9 == ' ') { square9 = 'O'; return; }
    if(square7 == 'X' && square9 == 'X' && square8 == ' ') { square8 = 'O'; return; }
    if(square8 == 'X' && square9 == 'X' && square7 == ' ') { square7 = 'O'; return; }

    // Column 1
    if(square1 == 'X' && square4 == 'X' && square7 == ' ') { square7 = 'O'; return; }
    if(square1 == 'X' && square7 == 'X' && square4 == ' ') { square4 = 'O'; return; }
    if(square4 == 'X' && square7 == 'X' && square1 == ' ') { square1 = 'O'; return; }

    // Column 2
    if(square2 == 'X' && square5 == 'X' && square8 == ' ') { square8 = 'O'; return; }
    if(square2 == 'X' && square8 == 'X' && square5 == ' ') { square5 = 'O'; return; }
    if(square5 == 'X' && square8 == 'X' && square2 == ' ') { square2 = 'O'; return; }

    // Column 3
    if(square3 == 'X' && square6 == 'X' && square9 == ' ') { square9 = 'O'; return; }
    if(square3 == 'X' && square9 == 'X' && square6 == ' ') { square6 = 'O'; return; }
    if(square6 == 'X' && square9 == 'X' && square3 == ' ') { square3 = 'O'; return; }

    // Diagonal 1
    if(square1 == 'X' && square5 == 'X' && square9 == ' ') { square9 = 'O'; return; }
    if(square1 == 'X' && square9 == 'X' && square5 == ' ') { square5 = 'O'; return; }
    if(square5 == 'X' && square9 == 'X' && square1 == ' ') { square1 = 'O'; return; }

    // Diagonal 2
    if(square3 == 'X' && square5 == 'X' && square7 == ' ') { square7 = 'O'; return; }
    if(square3 == 'X' && square7 == 'X' && square5 == ' ') { square5 = 'O'; return; }
    if(square5 == 'X' && square7 == 'X' && square3 == ' ') { square3 = 'O'; return; }

    // --- FORK LOGIC ---
    // Case 1: X takes opposite corners (classic fork setup)
    if(square1 == 'X' && square9 == 'X' && square5 == 'O') {
        // Take any edge to break the fork
        if(square2 == ' ') { square2 = 'O'; return; }
        if(square4 == ' ') { square4 = 'O'; return; }
        if(square6 == ' ') { square6 = 'O'; return; }
        if(square8 == ' ') { square8 = 'O'; return; }
    }

    if(square3 == 'X' && square7 == 'X' && square5 == 'O') {
        if(square2 == ' ') { square2 = 'O'; return; }
        if(square4 == ' ') { square4 = 'O'; return; }
        if(square6 == ' ') { square6 = 'O'; return; }
        if(square8 == ' ') { square8 = 'O'; return; }
    }

    // Case 2: X plays a corner and an adjacent edge (another fork setup)
    if(square1 == 'X' && square2 == 'X' && square5 == 'O' && square3 == ' ') { square3 = 'O'; return; }
    if(square1 == 'X' && square4 == 'X' && square5 == 'O' && square7 == ' ') { square7 = 'O'; return; }

    if(square3 == 'X' && square2 == 'X' && square5 == 'O' && square1 == ' ') { square1 = 'O'; return; }
    if(square3 == 'X' && square6 == 'X' && square5 == 'O' && square9 == ' ') { square9 = 'O'; return; }

    if(square7 == 'X' && square4 == 'X' && square5 == 'O' && square1 == ' ') { square1 = 'O'; return; }
    if(square7 == 'X' && square8 == 'X' && square5 == 'O' && square9 == ' ') { square9 = 'O'; return; }

    if(square9 == 'X' && square6 == 'X' && square5 == 'O' && square3 == ' ') { square3 = 'O'; return; }
    if(square9 == 'X' && square8 == 'X' && square5 == 'O' && square7 == ' ') { square7 = 'O'; return; }

    // Case 3: X plays two edges that create a corner fork
    if(square2 == 'X' && square6 == 'X' && square3 == ' ') { square3 = 'O'; return; }
    if(square2 == 'X' && square4 == 'X' && square1 == ' ') { square1 = 'O'; return; }
    if(square8 == 'X' && square6 == 'X' && square9 == ' ') { square9 = 'O'; return; }
    if(square8 == 'X' && square4 == 'X' && square7 == ' ') { square7 = 'O'; return; }

    // --- Opening Strategy ---
    // 1. Take center
    if(square5 == ' ') { square5 = 'O'; return; }

    // 2. Take a corner
    if(square1 == ' ') { square1 = 'O'; return; }
    if(square3 == ' ') { square3 = 'O'; return; }
    if(square7 == ' ') { square7 = 'O'; return; }
    if(square9 == ' ') { square9 = 'O'; return; }

    // 3. Take an edge
    if(square2 == ' ') { square2 = 'O'; return; }
    if(square4 == ' ') { square4 = 'O'; return; }
    if(square6 == ' ') { square6 = 'O'; return; }
    if(square8 == ' ') { square8 = 'O'; return; }

    // --- If no blocking needed, fallback to your original logic ---

    if(square1 == ' ') { square1 = 'O'; return; }
    if(square2 == ' ') { square2 = 'O'; return; }
    if(square3 == ' ') { square3 = 'O'; return; }
    if(square4 == ' ') { square4 = 'O'; return; }
    if(square5 == ' ') { square5 = 'O'; return; }
    if(square6 == ' ') { square6 = 'O'; return; }
    if(square7 == ' ') { square7 = 'O'; return; }
    if(square8 == ' ') { square8 = 'O'; return; }
    if(square9 == ' ') { square9 = 'O'; return; }
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

        // Ask again if the square is already taken
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
    std::cout << "Would you like to see the square numbers (y/n):";
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
