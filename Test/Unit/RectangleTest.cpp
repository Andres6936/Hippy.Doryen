// Joan Andrés (@Andres6936) Github.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <Hippy/Doryen/Rectangle.hpp>

using namespace Doryen::Geometry;

TEST_CASE("Verify that Rectangle class is initialized to 0 for default.")
{
	const Rectangle rectangle {};

	CHECK(rectangle.getX() == 0);
	CHECK(rectangle.getY() == 0);
	CHECK(rectangle.getWidth() == 0);
	CHECK(rectangle.getHeight() == 0);

	CHECK(rectangle.getTop() == 0);
	CHECK(rectangle.getLeft() == 0);
	CHECK(rectangle.getRight() == 0);
	CHECK(rectangle.getBottom() == 0);
}

TEST_CASE("Verify the construction of Rectangle with parameters Int32")
{
	const Rectangle rectangle {6, 9, 3, 6};

	CHECK(rectangle.getX() == 6);
	CHECK(rectangle.getY() == 9);
	CHECK(rectangle.getWidth() == 3);
	CHECK(rectangle.getHeight() == 6);

	CHECK(rectangle.getTop() == 9);
	CHECK(rectangle.getLeft() == 6);
	CHECK(rectangle.getRight() == 9);
	CHECK(rectangle.getBottom() == 15);
}

TEST_CASE("Verify the construction of Rectangle with parameters Point and Size")
{
	const Rectangle rectangle {{ 6, 9 }, { 3, 6 }};

	CHECK(rectangle.getX() == 6);
	CHECK(rectangle.getY() == 9);
	CHECK(rectangle.getWidth() == 3);
	CHECK(rectangle.getHeight() == 6);

	CHECK(rectangle.getTop() == 9);
	CHECK(rectangle.getLeft() == 6);
	CHECK(rectangle.getRight() == 9);
	CHECK(rectangle.getBottom() == 15);
}

TEST_CASE("Verify the change of properties with setters")
{
	Rectangle rectangle {};

	rectangle.setX(9);
	rectangle.setY(7);
	rectangle.setWidth(10);
	rectangle.setHeight(6);

	CHECK(rectangle.getX() == 9);
	CHECK(rectangle.getY() == 7);
	CHECK(rectangle.getWidth() == 10);
	CHECK(rectangle.getHeight() == 6);
}

TEST_CASE("Verify that property Top and Bottom change when the Y property change")
{
	Rectangle rectangle {6, 9, 3, 6};

	CHECK(rectangle.getTop() == 9);
	CHECK(rectangle.getBottom() == 15);

	rectangle.setY(23);

	CHECK(rectangle.getTop() == 23);
	// The property Height not change, is 6.
	CHECK(rectangle.getBottom() == 29);
}