//
// Created by Bernard Che Longho on 2023-10-24.
//
#include <catch2/catch_test_macros.hpp>
#include "Position.h"

SCENARIO("Testing position behaviour") {
    WHEN("A position is initialized without any values for x and y") {
        Position position;
        THEN("The values of x and y are equal and both zero") {
            REQUIRE(position.getX() == 0);
            REQUIRE(position.getY() == 0);
            REQUIRE(position.getX() == position.getY());
        }AND_THEN("The values of x and y can vary independently") {
            position.setX(5);
            position.setY(6);
            REQUIRE_FALSE(position.getX() == position.getY());
            REQUIRE(position.getX() == 5);
            REQUIRE(position.getY() == 6);
        }
    }AND_WHEN("The max and min values of the position is set with different values"){
        Position position;
        THEN("This shall take effect and be different from the initial values"){
            REQUIRE(position.getMaxPos() == 10);
            REQUIRE(position.getMinPos() == 0);

            // set the values
            position.setMaxPos(5);
            position.setMinPos(1);

            REQUIRE(position.getMaxPos() == 5);
            REQUIRE(position.getMinPos() == 1);
        }
    }AND_WHEN("The max and min values are set from the constructor"){
        Position newPosition(0,0,0,4);
        THEN("It shall appply through out"){
            REQUIRE(newPosition.getMaxPos() == 4);
            REQUIRE(newPosition.getMinPos() == 0);
            REQUIRE(newPosition.getX() == 0);
            REQUIRE(newPosition.getY() == 0);
            REQUIRE_FALSE(newPosition == (Position(0,1)));
        }
    }
}

SCENARIO("A position is given that is out of the allowed range") {
    Position position(5, -1);
    WHEN("A position has negative values") {
        THEN("It should evaluate as invalid") {
            REQUIRE_FALSE(position.isValid());
            REQUIRE_THROWS_AS(position.setX(11), std::invalid_argument); //  max is 10
            REQUIRE_THROWS_AS(position.setY(11), std::invalid_argument);
            REQUIRE_FALSE(position.isValid());

            REQUIRE_THROWS_AS(position.setX(-1), std::invalid_argument);
            REQUIRE_THROWS_AS(position.setY(-1), std::invalid_argument);

            REQUIRE_FALSE(position.isValid());
        }
    }

}

SCENARIO("Testing equality of two positions") {
    WHEN("A position is initialized") {
        Position position(1, 2);
        THEN("It can be compared to another position") {
            REQUIRE(position == Position(1, 2));
            REQUIRE_FALSE(Position(0, 0) == Position(1, 0));
        }
    }
}