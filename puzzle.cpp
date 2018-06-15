#include <iostream>
#include <string>
#include <random>
#include <iomanip>

#include "puzzle.h"

puzzle::puzzle(int depth)
{
  populate_grid();
  shuffle_grid(depth);
}

void puzzle::populate_grid()
{
  //fills game grid
  int z = 0;
  for(int i = 0; i < y_axis; i++)
  {
    for(int j = 0; j < x_axis; j++)
    {
      grid[i][j] = iths(z++);
    }
  }
  
  //adds empty space and sets coordinates
  grid[y_axis-1][x_axis-1] = " ";
  _x = x_axis-1;
  _y = y_axis-1;
}

void puzzle::shuffle_grid(int depth)
{
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist4(1,4);

  for(int i = 0; i < depth; i++)
  {
    switch(dist4(rng))
    {
      case 1:
        if(!move_up()) i--;
        break;
      case 2:
        if(!move_down()) i--;
        break;
      case 3:
        if(!move_left()) i--;
        break;
      case 4:
        if(!move_right()) i--;
        break;
    }
  }
}

std::string puzzle::iths(int d)
{
  std::stringstream stream;
  stream << std::hex << d;
  return stream.str();
}

void puzzle::draw_puzzle()
{ 
  clear_screen();

  for(int i = 0; i < y_axis; i++)
  {
    for(int j = 0; j < x_axis; j++)
    {
      std::cout << grid[i][j];
    }
    
    std::cout << std::endl;
  }
}

void puzzle::clear_screen()
{
  #if defined(_WIN32)
    std::system("cls");
  #elif defined(__linux__)
    std::system("clear");
  #elif defined(__APPLE__)
    std::system("clear");
  //TODO find proper clear commands for BSD and QNX
  #elif defined(BSD)
    //std::system("clear");
  #elif defined(__QNX__)
    //std::system("clear");
 #endif
}

bool puzzle::move_up()
{
  if(check_move(up))
  {
    swap(grid[_y][_x],grid[_y++][_x]);
    return true;
  }
  return false;
}

bool puzzle::move_down()
{
  if(check_move(down))
  {
    swap(grid[_y][_x],grid[_y--][_x]);
    return true;
  }
  return false;
}

bool puzzle::move_left()
{
  if(check_move(left))
  {
    swap(grid[_y][_x],grid[_y][_x++]);
    return true;
  }
  return false;
}

bool puzzle::move_right()
{
  if(check_move(right))
  {
    swap(grid[_y][_x],grid[_y][_x--]);
    return true;
  }
  return false;
}

bool puzzle::check_move(direction_e direction)
{
  switch(direction)
  {
    case up:
      if(_y != y_axis-1)
        return true;
      break;
    case down:
      if(_y != 0)
        return true;
      break;
    case left:
      if(_x != x_axis-1)
        return true;
      break;
    case right:
      if(_x != 0)
        return true;
      break;
  }
  return false;
}

bool puzzle::is_solved()
{
  int indx = 0;
  for(int i = 0; i < y_axis; i++)
  {
    for(int j = 0; j < x_axis; j++)
    {
      if(grid[i][j] != solution[indx++])
      {
        if(grid[i][j] != " ")
          return false;
        else
          indx--;
      }
    }
  }

  return true;
}

