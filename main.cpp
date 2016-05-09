//
// main.cpp for main in /home/korial/rendu/Tek2/cpp_indie_studio/map_generator
// 
// Made by Korial
// Login   <korial@epitech.net>
// 
// Started on  Wed May  4 12:34:55 2016 Korial
// Last update Mon May  9 18:28:54 2016 Korial
//

#include "map_generator.hpp"
#include <iostream>

int	main()
{
  Map	_map;

  _map = Map(8, Size(80, 40), Size(11, 8), Size(8, 3));
  //  _map.set_seed(std::string("BITE"));
  _map.generate_map();
  return 0;
}
