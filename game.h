#pragma once

#include <iostream>
#include <vector>
using namespace std;

// for convenience/readability of code
const char EMPTY{' '};
const char WALL{'#'};
const char PLAYER{'o'};
const char PRIZE{'.'};

class Game {
  private:
    vector<string>& board;  // intentionally stored as reference to main's structure (so main can observe)

    // define any other data members you wish...
   int current_row;
   int current_col;
   int moves=0;

  public:

    Game(vector<string>& original) : board{original} {}

    int num_moves() const {
      
        return moves;  
    }

    int num_remaining() const {
        int total_prizes=0;
        for (int i=0;i<board.size();i++){
          for (int j=0;j<board[i].size();j++){
            if (board[i][j]==PRIZE){
              total_prizes+=1;
            }
          }
    } return total_prizes;
    }

    void up() {
        // move the player up one spot (if not a wall)
        for (int i=0;i<board.size();i++){
          for (int j=0;j<board[i].size();j++){
            if (board[i][j]==PLAYER){
              current_row=i;
              current_col=j;
              break;
            }
          }
        }
        if (board[current_row-1][current_col]==PRIZE||board[current_row-1][current_col]==EMPTY){
          board[current_row-1][current_col]=PLAYER ;
          board[current_row][current_col]=EMPTY;
          moves+=1;
          
        }
        
    }
    
    void down() {
        // move player down one spot (if not a wall)
        for (int i=0;i<board.size();i++){
          for (int j=0;j<board[i].size();j++){
            if (board[i][j]==PLAYER){
              current_row=i;
              current_col=j;
              break;
            }
          }
        }
        if (board[current_row+1][current_col]==PRIZE||board[current_row+1][current_col]==EMPTY){
          board[current_row+1][current_col]=PLAYER ;
          board[current_row][current_col]=EMPTY;
          moves+=1;
          
        }

    }
    
    void left() {
        // move player left one spot (if not a wall)
        for (int i=0;i<board.size();i++){
          for (int j=0;j<board[i].size();j++){
            if (board[i][j]==PLAYER){
              current_row=i;
              current_col=j;
              break;
            }
          }
        }
        if (board[current_row][current_col-1]==PRIZE||board[current_row][current_col-1]==EMPTY){
          board[current_row][current_col-1]=PLAYER ;
          board[current_row][current_col]=EMPTY;
          moves+=1;
          
        }
    }
    
    void right() {
        // move player right one spot (if not a wall)
        for (int i=0;i<board.size();i++){
          for (int j=0;j<board[i].size();j++){
            if (board[i][j]==PLAYER){
              current_row=i;
              current_col=j;
              break;
            }
          }
        }
        if (board[current_row][current_col+1]==PRIZE||board[current_row][current_col+1]==EMPTY){
          board[current_row][current_col+1]=PLAYER ;
          board[current_row][current_col]=EMPTY;
          moves+=1;
          
        }

    }
    
};
