//
// Created by Bernard Che Longho on 2023-10-24.
//

#include <iostream>
#include "Robot.h"


Robot::Robot(const Position &currentPosition, const Direction &currentDirection)
        : position(currentPosition), direction{currentDirection} {

}

bool Robot::move(std::ostream &os) {
    os << "Attempting to move " << DirectionMap[direction] << " from the state " << *this << std::endl;
    try {
        switch (direction) {
            case Direction::NORTH:
                return moveNorth(os);
            case Direction::SOUTH:
                return moveSouth(os);
            case Direction::EAST:
                return moveEast(os);
            case Direction::WEST:
                return moveWest(os);
            default:
                return false;
        }
    } catch (const std::exception &exception) {
        os << exception.what() << std::endl;
        return false;
    }
}

void Robot::left(std::ostream &os) {
    os << "Robot's current direction is " << DirectionMap[direction] << std::endl;
    switch (direction) {
        case Direction::NORTH:
            direction = Direction::WEST;
            break;
        case Direction::SOUTH:
            direction = Direction::EAST;
            break;
        case Direction::EAST:
            direction = Direction::NORTH;
            break;
        case Direction::WEST:
            direction = Direction::SOUTH;
            break;
        default:
            break;
    }
    os << "Robot's direction changed to " << DirectionMap[direction] << " after calling LEFT" << std::endl;
}

void Robot::right(std::ostream &os) {
    os << "Robot's current direction is " << DirectionMap[direction] << std::endl;
    switch (direction) {
        case Direction::NORTH:
            direction = Direction::EAST;
            break;
        case Direction::SOUTH:
            direction = Direction::WEST;
            break;
        case Direction::EAST:
            direction = Direction::SOUTH;
            break;
        case Direction::WEST:
            direction = Direction::NORTH;
            break;
        default:
            break;
    }
    os << "Robot's direction changed to " << DirectionMap[direction] << " after calling RIGHT" << std::endl;
}

void Robot::place(std::ostream &os) {
    return;
}

bool Robot::isMovePossible(std::ostream &os) const {
    if (!position.isValid()) {
        os << "Robot will go out of table if move is made\n";
        return false;
    }
    return true;
}

void Robot::report(std::ostream &os) const {
    os << *this << std::endl;
}

bool Robot::moveNorth(std::ostream &os) {
    if (!isMovePossible()) {
        return false;
    }
    if ((position.getY() + 1) > position.getMaxPos()) {
        os << "Robot will go out of the table if this move is made\n";
        return false;
    } else {
        position.setY(position.getY() + 1);
        os << "Robot moved one step northwards. Current position [" << *this << "]\n";
        return true;
    }
}

bool Robot::moveSouth(std::ostream &os) {
    if (!isMovePossible()) {
        return false;
    }
    if ((position.getY() - 1) < position.getMinPos()) {
        os << "Robot will fall if this move is made. State: [" << *this << "]\n";
        return false;
    } else {
        position.setY(position.getY() - 1);
        os << "Moved to the south. State: [" << *this << "]\n";
        return true;
    }

}

bool Robot::moveEast(std::ostream &os) {
    if (!isMovePossible()) {
        return false;
    }
    if ((position.getX() + 1) > position.getMaxPos()) {
        os << "Robot will fall if this move is made. State: [" << *this << "]\n";
        return false;
    } else {
        position.setX(position.getX() + 1);
        os << "Moved to the east. State: [" << *this << "]\n";
        return true;
    }
}

bool Robot::moveWest(std::ostream &os) {
    if (!isMovePossible()) {
        return false;
    }
    if ((position.getX() - 1) < position.getMinPos()) {
        os << "Robot will fall if this move is made. State: [" << *this << "]\n";
        return false;
    } else {
        position.setX(position.getX() - 1);
        os << "Moved to the WEST. State: [" << *this << "]\n";
        return true;
    }
}

std::ostream &operator<<(std::ostream &os, const Robot &robot) {
    return os << robot.position << "," << DirectionMap[robot.direction];
}
