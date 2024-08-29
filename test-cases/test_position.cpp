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
            REQUIRE_TRUE(position.getMax() == 10);
            REQUIRE_TRUE(position.getMin() == 0);

            // set the values
            position.setMax(5);
            position.setMin(1);

            REQUIRE_TRUE(position.getMax() == 5);
            REQUIRE_TRUE(position.getMin() == 1);
        }
    }AND_WHEN("The max and min values are set from the constructor"){
        Position newPosition(0,0,0,4);
        THEN("It shall appply through out"){
            REQUIRE_TRUE(newPosition.getMax() == 4);
            REQUIRE_TRUE(newPosition.getMin() == 0);
            REQUIRE_TRUE(newPosition.getX() == 0);
            REQUIRE_TRUE(newPosition.getY() == 0);
            REQUIRE_FALSE(newPosition == (Position(0,1)));
        }
    }
}

SCENARIO("A position is given that is out of the allowed range") {
    Position position(5, -1);
    WHEN("A position has negative values") {
        THEN("It should evaluate as invalid") {
            REQUIRE_FALSE(position.isValid());
            position.setX(11); //  max is 10
            position.setY(11);
            REQUIRE_FALSE(position.isValid());

            position.setX(-1);
            position.setY(-1);

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