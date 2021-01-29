// Joan Andrés (@Andres6936) Github.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <Hippy/Flex/Hippy.h>
#include <Hippy/Doryen/Layoutable.hpp>

using namespace Hippy;

TEST_CASE("Verify if a layout constructed by default is empty")
{
	Layoutable layoutable {};

	CHECK(layoutable.getWidth() == 0);
	CHECK(layoutable.getHeight() == 0);
	CHECK(layoutable.isEmpty() == true);
}

TEST_CASE("Verify the direction layout for default of any flex container")
{
	Layoutable layoutable {};

	// For default the configuration is Inherit, aka Left to Right.
	CHECK(layoutable.getLayoutDirection() == HPDirection::DirectionInherit);
}