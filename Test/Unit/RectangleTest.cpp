// Joan Andrés (@Andres6936) Github.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <Hippy/Doryen/Rectangle.hpp>

using namespace Doryen::Geometry;

TEST_CASE("Rectangle class is initialized to 0 for default.")
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

TEST_CASE("Verify the construction of Rectangle with parameters")
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