//
// Created by Bernard Che Longho on 2023-10-24.
//

#ifndef ROBOT_POSITION_H
#define ROBOT_POSITION_H

#include <ostream>

class Position  final {
private:
    const int minPos = 0;
    const int maxPos = 10;
    int x{};
    int y{};
public:
    explicit Position(const int &xPos, const int &yPos);
    Position() = default;
    Position(const Position &&position) noexcept ;
    Position & operator=(const Position &position) noexcept;
    Position(const Position&position);
    ~Position() = default;

    bool operator==(const Position &rhs) const;

    bool operator!=(const Position &rhs) const;

    [[nodiscard]] int getX() const;

    void setX(int x);

    [[nodiscard]] int getY() const;

    void setY(int y);

    [[maybe_unused]] [[nodiscard]]  int getMinPos() const;

    [[maybe_unused]] [[nodiscard]]  int getMaxPos() const;

    [[nodiscard]] bool isValid() const;

    friend std::ostream &operator<<(std::ostream &os, const Position &position);
};

std::ostream &operator<<(std::ostream &os, const Position &position);

#endif //ROBOT_POSITION_H
