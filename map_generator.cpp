//
// map_generator.cpp for map_generator in /home/korial/rendu/Tek2/cpp_indie_studio/map_generator
// 
// Made by Korial
// Login   <korial@epitech.net>
// 
// Started on  Wed May  4 12:40:18 2016 Korial
// Last update Sun May  8 02:00:55 2016 Korial
//

#include "map_generator.hpp"
#include <unistd.h>
#include <fstream>

int	Map::get_room_nbr() const
{
  return this->room_nbr;
}

int	Map::get_room_max_x() const
{
  return this->room_max_size.x;
}

int	Map::get_room_max_y() const
{
  return this->room_max_size.y;
}

Size	Map::get_map_size() const
{
  return this->map_size;
}

void				Map::generate_map()
{
  std::ofstream			debug;
  Node				_root = Node(Size(0, 0), Size(map_size.x, map_size.y));
  bool				split = true;
  std::vector<Rooms>		tmpRooms;

  srand(time(NULL));
  debug.open("map.txt");
  _nodes.push_back(_root);
  while (split)
    {
      split = false;
      for(int i = 0; i < _nodes.size();i++)
	{
	  if ((_nodes[i].leftChild == NULL && _nodes[i].rightChild == NULL)
	      && (_nodes[i]._size.x > room_max_size.x || _nodes[i]._size.y > room_max_size.y)
	      && (_nodes[i].split(room_max_size, room_min_size)))
	    {
	      _nodes.push_back(*_nodes[i].leftChild);
	      _nodes.push_back(*_nodes[i].rightChild);
	      split = true;
	    }
	}
    }
  for(int i = 0; i < _nodes.size();i++)
    _nodes[i].create_rooms(tmpRooms, room_max_size);
  for (int i = 0; i < room_nbr;i++)
    _rooms.push_back(tmpRooms[rand() % tmpRooms.size()]);
  for(int i = 0; i < _nodes.size();i++)
    {
      delete(_nodes[i].leftChild); 
      delete(_nodes[i].rightChild); 
    }
  blank_map(_map, map_size);
  draw_rooms(_map, _rooms, map_size);
  for (int i = 0; i < _map.size() ; i++)
    debug << _map[i] << std::endl;
  debug.close();
}

void	Map::blank_map(std::vector<std::string>& map, Size _map_size)
{
  std::string	tmp;
  for (int x = 0; x < _map_size.x + 4; x++)
    tmp += ".";
  for (int i = 0; i < _map_size.y + 4; i++)
    map.push_back(tmp);
}

void	Map::draw_rooms(std::vector<std::string>& map, std::vector<Rooms>& rooms, Size map_size)
{
  int	x = 0;
  int	y = 0;

  for (int i = 0;i < rooms.size();i++)
    {
      x = rooms[i]._size.x + rooms[i]._pos.x + 2;
      y = rooms[i]._size.y + rooms[i]._pos.y + 2;
      for (int p = rooms[i]._pos.y + 1; p <= y;p++)
	{
	  for (int o = rooms[i]._pos.x + 1; o <= x;o++)
	    {
	      if (o == x || o == rooms[i]._pos.x + 1)
		map[p][o] = '#';
	      else if  (p == y || p == rooms[i]._pos.y + 1)
	      	map[p][o] = '#';
	      else
		map[p][o] = ' ';
	    }
	}
    }
}

