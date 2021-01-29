// Joan Andrés (@Andres6936) Github.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <Hippy/Flex/Hippy.h>
#include <Hippy/Doryen/Layoutable.hpp>

using namespace Hippy;

SCENARIO("Verify the change of direction of layout.")
{
	GIVEN("A layout (called root) constructed with parameters of width and height")
	{
		Layoutable root {500, 500};

		REQUIRE(root.getWidth() == 500);
		REQUIRE(root.getHeight() == 500);

		CHECK(root.isEmpty() == false);
		CHECK(root.getChildren() == 0);

		AND_WHEN("the root layout is set with flex direction to row")
		{
			root.setFlexDirection(FLexDirectionRow);
		}

		AND_WHEN("the root layout align their item in the start of layout")
		{
			root.setAlignItems(FlexAlignStart);
		}

		AND_WHEN("one child is inserted with 80% of width and 100% of height")
		{
			Layoutable child80 {root};
			child80.setWidth(root.getWidth() * 0.8f);
			child80.setHeight(root.getHeight() * 1.0f);

			CHECK(child80.getWidth() == 400);
			CHECK(child80.getHeight() == 500);
		}

		THEN("verify the insertion of child")
		{
			CHECK(root.getChildren() == 1);
		}

		AND_WHEN("other child is inserted with 20% width and 100% height")
		{
			Layoutable child20 {root};
			child20.setWidth(root.getWidth() * 0.2f);
			child20.setHeight(root.getHeight() * 1.0f);

			CHECK(child20.getWidth() == 100);
			CHECK(child20.getHeight() == 500);
		}

		THEN("verify the insertion of child")
		{
			CHECK(root.getChildren() == 1);
		}
	}
}