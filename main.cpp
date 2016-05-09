//
// main.cpp for main in /home/korial/rendu/Tek2/cpp_indie_studio/map_generator
// 
// Made by Korial
// Login   <korial@epitech.net>
// 
// Started on  Wed May  4 12:34:55 2016 Korial
// Last update Mon May  9 11:59:15 2016 Korial
//

#include "map_generator.hpp"
#include <iostream>

int	main(int ac, char **av)
{
  Map	_map;

  _map = Map(45, Size(68, 36), Size(15, 8), Size(8, 3));
  _map.generate_map();
  return 0;
}
