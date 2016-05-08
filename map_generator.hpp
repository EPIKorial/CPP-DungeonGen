//
// map_generator.hpp for map_generator in /home/korial/rendu/Tek2/cpp_indie_studio/map_generator
// 
// Made by Korial
// Login   <korial@epitech.net>
// 
// Started on  Mon May  2 20:14:23 2016 Korial
// Last update Sun May  8 01:59:32 2016 Korial
//

#ifndef MAP_GENERATOR_HPP_
# define MAP_GENERATOR_HPP_

#include <iostream>
#include <vector>
#include "mg_utils.hpp"

class Map
{
private:
  int				room_nbr;
  Size				map_size;
  Size				room_max_size;
  Size				room_min_size;
  std::vector<std::string>	_map;
  std::vector<Node>		_nodes;
  std::vector<Rooms>		_rooms;
  std::vector<Hallways>		_hallways;
  
public:
  Map() : room_nbr(1), map_size(Size(100, 100)), room_max_size(Size(10, 10)), room_min_size(Size(6, 6)) { }
  Map(int nbr) : room_nbr(nbr), map_size(Size(100, 100)), room_max_size(Size(10, 10)), room_min_size(Size(6, 6)) { }
  Map(int nbr, Size mapSize) : room_nbr(nbr), map_size(mapSize), room_max_size(Size(10, 10)), room_min_size(Size(6, 6)) { }
  Map(int nbr, Size mapSize, Size roomMax) : room_nbr(nbr), map_size(mapSize), room_max_size(roomMax), room_min_size(Size(6, 6)) { }
  Map(int nbr, Size mapSize, Size roomMax, Size roomMin) : room_nbr(nbr), map_size(mapSize), room_max_size(roomMax), room_min_size(roomMin) { }
  ~Map() { }
  
private:
  void		blank_map(std::vector<std::string>&, Size);
  void		draw_rooms(std::vector<std::string>&, std::vector<Rooms>&, Size);
  
public:
  int				get_room_nbr() const;
  int				get_room_max_x() const;
  int				get_room_max_y() const;
  Size				get_map_size() const;
  void				generate_map();
};

#endif /*!MAP_GENERATOR_HPP_*/
