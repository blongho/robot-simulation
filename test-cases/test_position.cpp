//
// Created by Bernard Che Longho on 2023-10-24.
//
#include <catch2/catch_test_macros.hpp>
#include "Position.h"

SCENARIO("Testing point behaviour") {
    WHEN("A point is initialized without any values for x and y") {
        Position point;
        THEN("The values of x and y are equal and both zero") {
            REQUIRE(point.getX() == 0);
            REQUIRE(point.getY() == 0);
            REQUIRE(point.getX() == point.getY());
        }AND_THEN("The values of x and y can vary independently") {
            point.setX(5);
            point.setY(6);
            REQUIRE_FALSE(point.getX() == point.getY());
            REQUIRE(point.getX() == 5);
            REQUIRE(point.getY() == 6);
        }
    }
}

SCENARIO("A point is given that is out of the table") {
    WHEN("A point has negative values") {
        Position point(5, -1);
        THEN("It should evaluate as invalid") {
            REQUIRE_FALSE(point.isValid());
        }
    }

}

SCENARIO("Testing equality of two points") {
    WHEN("A point is initialized") {
        Position point(1, 2);
        THEN("It can be compared to another point") {
            REQUIRE(point == Position(1, 2));
            REQUIRE_FALSE(Position(0, 0) == Position(1, 0));
        }
    }
}