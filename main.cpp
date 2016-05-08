//
// main.cpp for main in /home/korial/rendu/Tek2/cpp_indie_studio/map_generator
// 
// Made by Korial
// Login   <korial@epitech.net>
// 
// Started on  Wed May  4 12:34:55 2016 Korial
// Last update Sun May  8 02:01:54 2016 Korial
//

#include "map_generator.hpp"
#include <iostream>

int	main(int ac, char **av)
{
  Map	_map;

  _map = Map(25, Size(100, 100), Size(10, 10), Size(5, 5));
  _map.generate_map();
  return 0;
}
