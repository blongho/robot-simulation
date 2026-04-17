# Robot Simulation

A C++17 implementation of the classic Toy Robot simulation. The robot moves on a 5x5 (configurable) grid table and responds to commands like MOVE, LEFT, RIGHT, and REPORT.

## Overview

This project simulates a toy robot placed on a rectangular table. The robot can move in four cardinal directions (NORTH, SOUTH, EAST, WEST) and must not fall off the table. The simulation includes position validation to prevent the robot from moving outside the table boundaries.

## Features

- **Grid-based movement**: Robot moves on a configurable NxN grid (default 10x10)
- **Direction control**: LEFT and RIGHT commands rotate the robot 90 degrees
- **Position validation**: Prevents the robot from falling off the table
- **State reporting**: REPORT command outputs current position and direction
- **Comprehensive tests**: Unit tests using Catch2 framework

## Project Structure

```
robot-simulation/
├── include/           # Header files
│   ├── Direction.h    # Direction enum and mapping
│   ├── Position.h     # Position class for grid coordinates
│   └── Robot.h        # Robot class with movement logic
├── src/               # Source files
│   ├── Direction.cpp  # Direction implementation
│   ├── Position.cpp   # Position implementation
│   └── Robot.cpp      # Robot implementation
├── test-cases/        # Test files
│   ├── CMakeLists.txt # Test CMake configuration
│   └── test_position.cpp # Position unit tests
├── CMakeLists.txt     # Main build configuration
└── main.cpp           # Entry point demo
```

## Requirements

- C++17 compatible compiler
- CMake 3.5 or higher
- Catch2 (fetched automatically via CMake)

## Building

### Using the build directory

```bash
mkdir build && cd build
cmake ..
make
```

### Using the existing build directory

```bash
cd build
make
```

### Running the application

```bash
./robot
```

### Running tests

```bash
cd build
ctest
# or run tests directly
./test_position
```

## Usage

### Basic Usage

The demo in `main.cpp` creates a robot and demonstrates movement:

```cpp
#include <iostream>
#include "Robot.h"

int main() {
    Robot robot({}, Direction::NORTH);
    while (robot.move()) {
        std::cout << "Robot made a move. State [";
        robot.report();
        std::cout << "]\n\n";
    }
    return 0;
}
```

### Programming Interface

```cpp
#include "Robot.h"
#include "Position.h"
#include "Direction.h"

// Create a robot at position (0, 0) facing NORTH
Robot robot(Position(0, 0), Direction::NORTH);

// Move the robot one step in its current direction
robot.move();

// Turn the robot 90 degrees left
robot.left();

// Turn the robot 90 degrees right
robot.right();

// Report current position and direction
robot.report(); // Output: x,y,DIRECTION
```

### Position Configuration

The default grid is 0-10 in both X and Y axes. You can customize the bounds:

```cpp
// Create position with custom bounds (min: 0, max: 5)
Position position(0, 0, 0, 5);
```

## Commands

| Command | Description |
|---------|-------------|
| `MOVE` | Move the robot one unit in its current direction |
| `LEFT` | Rotate the robot 90 degrees counter-clockwise |
| `RIGHT` | Rotate the robot 90 degrees clockwise |
| `REPORT` | Output the current position and direction |

## Direction Mapping

```
    NORTH
      ^
      |
WEST <----> EAST
      |
      v
    SOUTH
```

Left rotation: NORTH → WEST → SOUTH → EAST → NORTH  
Right rotation: NORTH → EAST → SOUTH → WEST → NORTH

## Safety Features

- The robot checks if a move would take it outside the table boundary
- Moves that would cause the robot to fall are rejected
- Position validation ensures coordinates remain within bounds
- Invalid position assignments throw `std::invalid_argument` exceptions

## Running Tests

The project includes unit tests for the Position class:

```bash
cd build
cmake ..
make
ctest --verbose
```

Sample test output:
```
test_position.cpp:7: PASSED:
Scenario: Testing position behaviour
  A position is initialized without any values for x and y
    The values of x and y are equal and both zero
    The values of x and y can vary independently
```

## License

This project is for educational purposes.

## Author

Bernard Che Longho