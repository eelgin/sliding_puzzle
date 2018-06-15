#include <iostream>

#include "puzzle.h"

static void show_usage(std::string name)
{
  //TODO add vim and wasd support
  //     add solution checker 
  std::cerr << "Usage: " << name << " <option> [depth]\n"
            << "\nObjective:\n"
            << "\tArrange the puzzle in ascending hexadecimal order (0,1,2,..,c,d,e)\n"
            << "\nOptions:\n"
            << "\t-h, --help\t\tShow this help message\n"
            << "\t-e, --easy\t\tEasy Difficulty: 10 random moves from solution\n"
            << "\t-m, --medium\t\tMedium Difficulty: 50 random moves from solution\n"
            << "\t-s, --standard\t\tStandard Difficulty: 200 random moves from solution\n"
            << "\t-d, --depth\t\tCustom Depth: Specify number of random moves from solution\n"
            << std::endl;
}



int main(int argc,
         char *argv[])
{
  
  int depth;

  if(argc < 2)
  {
    depth = 200;
  }
  else if (argc > 3)
  {
    std::cerr << "Too many Arguments\n";
    return 1;
  }

  for(int i = 1; i < argc; i++)
  {
    std::string arg = argv[i];
    if((arg == "-h") || (arg == "--help"))
    {
      show_usage(argv[0]);
      return 0;
    }
    else if((arg == "-e") || (arg == "--easy"))
    {
      depth = 10;
    }
    else if((arg == "-m") || (arg == "--medium"))
    {
      depth = 50;
    }
    else if((arg == "-s") || (arg == "--standard"))
    {
      depth = 200;
    }
    else if((arg == "-d") || (arg == "--depth"))
    {
      depth = std::stoi(argv[++i]);
    }
    else
    {
      std::cerr << "Unknown Arguments\n";
      return 1;
    }
  }
 
  puzzle _puzzle(depth);
  
  std::string move;
  while(!_puzzle.is_solved())
  {
    _puzzle.draw_puzzle();

    while(1)
    { 
      std::cout << "Slide (u)p, (d)own, (l)eft, (r)ight, or (q)uit?\n";
      std::cout << "(vim and wasd movement supported)\n";
      std::cin >> move;

      if((move == "u") || (move == "up") || (move == "w") || (move == "k"))
      {
        if(_puzzle.move_up()) break;
      }
      else if((move == "d") || (move == "down")|| (move == "s") || (move == "j")) 
      {
        if(_puzzle.move_down()) break;
      }
      else if((move == "l") || (move == "left") || (move == "a") || (move == "h"))
      {
        if(_puzzle.move_left()) break;
      }
      else if((move == "r") || (move == "right") || (move == "d") || (move == "l"))
      {
        if(_puzzle.move_right()) break;
      }
      else if((move == "q") || (move == "quit"))
      {
        return 0;
      }
      
      std::cout << "Illegal move, try again\n";
    }
  }
  
  _puzzle.draw_puzzle(); 
  std::cout << "Puzzle Solved: Congrats\n";
  return 0;

}









