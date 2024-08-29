#include <iostream>
#include "Robot.h"
int main() {
   Robot robot({}, Direction::NORTH);
    while (robot.move()){
       std::cout << "Robot made a move. State [";
       robot.report();
       std::cout << "]\n";
    }
    return 0;
}
