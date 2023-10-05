#include <cstdlib>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "termios.h"
using namespace std;

#include "game.h"

string levels[] = {
    "level01.txt",
    "level02.txt",
    "level03.txt",
    "level04.txt",
    "level05.txt",
};


void status(const Game& game, const vector<string>& board) {
    cout << endl << endl;
    for (string line : board) cout << line << endl;
    cout << "Moves:  " << game.num_moves() << endl;
    cout << "Prizes: " << game.num_remaining() << endl;
}


int main() {

    int k{0};
    int num_levels = sizeof(levels)/sizeof(string);

   for (int j=0; j < 40; j++) cout << endl;
    
    while (k < 1 || k > num_levels) {
        cout << "Pick a level from 1 to " << num_levels << ": ";
        cin >> k;
    }

    ifstream level_file("levels/" + levels[k-1]);
    string line;
    vector<string> board;
    while (getline(level_file, line)) {
        board.push_back(line);
    }

    Game game(board);

    cout << "Welcome to game." << endl;
    cout << "Use the arrow keys to move the player" << endl;
    cout << endl;
    
    cout << "The player is 'o'. The prizes are '.'" << endl;
        
    status(game,board);

    struct termios original_termios, new_termios;
    tcgetattr(STDIN_FILENO, &original_termios);
    new_termios = original_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    char c;
    while (1) {
        c = getchar();
        if (c == 27) { // 27 is the escape key code (ASCII)
            c = getchar(); // Read the next character
            if (c == 91) { // 91 is the code for '['
                c = getchar(); // Read the final key code
                bool arrow{false};
                switch (c) {
                    case 65: // Up arrow
                        game.up();
                        arrow = true;
                        break;
                    case 66: // Down arrow
                        game.down();
                        arrow = true;
                        break;
                    case 67: // Right arrow
                        game.right();
                        arrow = true;
                        break;
                    case 68: // Left arrow
                        game.left();
                        arrow = true;
                        break;
                    default:
                        break;
                }
                if (arrow) {
                    status(game,board);
                    if (game.num_remaining() == 0)
                        break;
                }
            }
        }
    }

    // Restore original terminal settings before exiting
    tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);

    cout << endl << endl << "Congratulations!!!!!!!" << endl;
    
    return EXIT_SUCCESS;
}
