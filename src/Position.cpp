//
// Created by Bernard Che Longho on 2023-10-24.
//

#include <utility>
#include "Position.h"

Position::Position(const int &xPos, const int &yPos)
        : x{xPos}, y{yPos} {}

Position::Position(const int &xPos, const int &yPos, const int &newMinPos, const int &newMaxPos)
: x{xPos}, y{yPos}, minPos{newMinPos}, maxPos{newMaxPos}{}

int Position::getX() const {
    return x;
}

void Position::setX(int xPos) {
    if (xPos >= minPos && xPos <= maxPos) {
        x = xPos;
    }else{
        throw std::invalid_argument("Value of x cannot be less than 0 or greater than "+ std::to_string(maxPos));
    }
}

int Position::getY() const {
    return y;
}

void Position::setY(int yPos) {
    if (yPos >= minPos && yPos <= maxPos) {
        y = yPos;
    }else{
        throw std::invalid_argument("Value of y cannot be less than 0 or greater than "+ std::to_string(maxPos));
    }
}

void Position::setMinPos(int newMinPos){
    minPos = newMinPos;
}

void Position::setMaxPos(int newMaxPos){
    maxPos = newMaxPos;
}

bool Position::operator==(const Position &rhs) const {
    return x == rhs.x &&
           y == rhs.y && 
           minPos == rhs.minPos &&
           maxPos == rhs.maxPos;
}

bool Position::operator!=(const Position &rhs) const {
    return !(rhs == *this);
}

[[maybe_unused]] [[nodiscard]]  int Position::getMinPos() const {
    return minPos;
}

[[maybe_unused]] [[nodiscard]]   int Position::getMaxPos() const {
    return maxPos;
}

bool Position::isValid() const {
    return x >= minPos && x <= maxPos && y >= minPos && y <= maxPos;
}

Position::Position(const Position &&position) noexcept {
    std::exchange(x, position.x);
    std::exchange(y, position.y);
    std::exchange(minPos, position.minPos);
    std::exchange(maxPos, position.maxPos);
}

Position &Position::operator=(const Position &position) noexcept {
    x = position.x;
    y = position.y;
    minPos = position.minPos;
    maxPos = position.maxPos;
    return *this;
}

Position::Position(const Position &position)
:x(position.x), y(position.y), minPos(position.minPos), maxPos(position.maxPos){}

std::ostream &operator<<(std::ostream &os, const Position &position) {
    os  << position.getX() << "," << position.getY();
    return os;
}

