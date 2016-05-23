//
// main.cpp for main in /home/korial/rendu/Tek2/cpp_indie_studio/map_generator
// 
// Made by Korial
// Login   <korial@epitech.net>
// 
// Started on  Wed May  4 12:34:55 2016 Korial
// Last update Mon May 23 19:48:47 2016 Korial
//

#include "MapGenerator.hpp"
#include <iostream>

int	main()
{
  Map	_map;

  _map = Map(25, Size(80, 40), Size(25, 8), Size(6, 3));
  _map.set_seed(std::string("ninja !!!"));
  _map.generate_map();
  return 0;
}
