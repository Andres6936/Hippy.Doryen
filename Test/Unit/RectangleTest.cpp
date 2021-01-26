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
}