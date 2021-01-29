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

TEST_CASE("Verify the width and height of layout when is defined with parameters")
{
	Layoutable layoutable {80, 25};

	CHECK(layoutable.getWidth() == 80);
	CHECK(layoutable.getHeight() == 25);
	CHECK(layoutable.isEmpty() == false);
}

TEST_CASE("Verify the change of width and height of layout when it are set for methods" * doctest::should_fail(true))
{
	Layoutable layoutable {};

	layoutable.setWidth(80);
	layoutable.setHeight(25);

	CHECK(layoutable.getWidth() == 80);
	CHECK(layoutable.getHeight() == 25);
}

TEST_CASE("Verify that a layout constructed by default has 0 children")
{
	Layoutable layoutable {};

	CHECK(layoutable.getChildren() == 0);
}

TEST_CASE("Verify the successful insertion of children into flex container")
{
	Layoutable parent {};
	Layoutable child { &parent};

	CHECK(child.getChildren() == 0);
	CHECK(parent.getChildren() == 1);
}

TEST_CASE("Verify the direction layout for default of any flex container")
{
	Layoutable layoutable {};

	// For default the configuration is Inherit, aka Left to Right.
	CHECK(layoutable.getLayoutDirection() == HPDirection::DirectionInherit);
}