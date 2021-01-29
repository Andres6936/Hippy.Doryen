// Joan Andrés (@Andres6936) Github.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <Hippy/Flex/Hippy.h>
#include <Hippy/Doryen/Layoutable.hpp>

using namespace Hippy;

TEST_CASE("Verify the associativity order for default of any flex container")
{
	Layoutable layoutable {20, 20};

	CHECK(layoutable.getLayoutDirection() == HPDirection::DirectionLTR);
}