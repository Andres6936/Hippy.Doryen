// Joan Andrés (@Andres6936) Github.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <Hippy/Flex/Hippy.h>
#include <Hippy/Doryen/Layoutable.hpp>

using namespace Hippy;

TEST_CASE("Verify the change of direction of layout.")
{
	SUBCASE("A layout (called root) constructed with parameters of width and height")
	{
		Layoutable root {500, 500};

		REQUIRE(root.getWidth() == 500);
		REQUIRE(root.getHeight() == 500);

		CHECK(root.isEmpty() == false);
		CHECK(root.getChildren() == 0);

		root.setFlexDirection(FLexDirectionRow);
		root.setAlignItems(FlexAlignStart);

		// Insert a child with 80% width and 100% of height
		Layoutable child80 { &root };
		child80.setWidth(root.getWidth() * 0.8f);
		child80.setHeight(root.getHeight() * 1.0f);

		root.doLayout();

		CHECK(child80.getWidth() == 400);
		CHECK(child80.getHeight() == 500);

		// Verify the insertion of child
		CHECK(root.getChildren() == 1);

		{
			Layoutable frameOne {&child80};
			frameOne.setFlexGrow(1.0f);
			frameOne.setWidth(child80.getWidth() * 1.0f);

			root.doLayout();

			// Verify the insertion of child
			CHECK(child80.getChildren() == 1);

			Layoutable frameTwo {&child80};
			frameTwo.setFlexGrow(1.0f);
			frameTwo.setWidth(child80.getWidth() * 1.0f);

			root.doLayout();

			// Verify the insertion of child
			CHECK(child80.getChildren() == 2);

			CHECK(frameOne.getWidth() == 400);
			CHECK(frameOne.getHeight() == 250);

			CHECK(frameTwo.getWidth() == 400);
			CHECK(frameTwo.getHeight() == 250);
		}


		// Insert a child with 20% width and 100% of height
		Layoutable child20 { &root };
		child20.setWidth(root.getWidth() * 0.2f);
		child20.setHeight(root.getHeight() * 1.0f);

		root.doLayout();

		CHECK(child20.getWidth() == 100);
		CHECK(child20.getHeight() == 500);

		// Verify the insertion of child
		CHECK(root.getChildren() == 2);
	}
}