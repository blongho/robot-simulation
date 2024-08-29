//
// Created by Bernard Che Longho on 2023-10-24.
//

#ifndef ROBOT_ROBOT_H
#define ROBOT_ROBOT_H

#include <ostream>
#include "Direction.h"
#include "Position.h"

class Robot final  {
private:
    Position position{};
    Direction direction{Direction::WEST};

    bool moveNorth(std::ostream &os = std::cout);

    bool moveSouth(std::ostream &os = std::cout);

    bool moveEast(std::ostream &os = std::cout);

    bool moveWest(std::ostream &os = std::cout);

    bool isMovePossible(std::ostream &os = std::cout) const;

    void left(std::ostream &os = std::cout);

    void right(std::ostream &os = std::cout);

    friend std::ostream &operator<<(std::ostream &os, const Robot &robot);
public:
    Robot(const Position &currentPosition, const Direction &currentDirection);

    Robot() = default;

    bool move(std::ostream &os = std::cout);

    void report(std::ostream &os = std::cout) const;

    void place(std::ostream &os = std::cout);
};




#endif //ROBOT_ROBOT_H