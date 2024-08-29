//
// Created by Bernard Che Longho on 2023-10-24.
//

#ifndef ROBOT_DIRECTION_H
#define ROBOT_DIRECTION_H

#include <map>
#include <string>

enum class Direction  {
    NORTH,
    SOUTH,
    EAST,
    WEST
};
[[maybe_unused]]  static std::map<Direction, std::string> DirectionMap = {
        {Direction::NORTH, "NORTH"},
        {Direction::SOUTH, "SOUTH"},
        {Direction::EAST,  "EAST"},
        {Direction::WEST,  "WEST"}
};
#endif //ROBOT_DIRECTION_H
