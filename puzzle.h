#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>

class puzzle
{
  public:
    puzzle(int depth);
    void draw_puzzle();
    bool move_up();
    bool move_down();
    bool move_left();
    bool move_right();
    bool is_solved();

  private:
    enum direction_e
    {
      up,
      down,
      left,
      right
    };
    
    // x/y axis size
    const int x_axis = 4, y_axis = 4;
    const std::string solution[15] = 
    { 
      "0","1","2","3","4","5","6","7",
      "8","9","a","b","c","d","e"
    };
    //x and y coordinates for open space
    int _x, _y;

    //array to hold board data
    std::string grid[x_axis][y_axis];
    
    //fills grid once constructed
    void populate_grid();
    
    //shuffles grid by applying random moves
    void shuffle_grid(int depth);
    
    //int to hex string function
    std::string iths(int d);
    
    //function to clear console
    void clear_screen();
    
    //answer checker
    bool check_move(direction_e direction);

};


#endif /* PUZZLE_H */
