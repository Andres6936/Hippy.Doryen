#include <Doryen/Doryen.hpp>
#include <Hippy/Flex/Hippy.h>
#include <Hippy/Doryen/Frame.hpp>

using namespace Doryen;

void DrawNode(Hippy::Frame& node, Console& console, const Color& background)
{
	const unsigned int leftCorner = node.getLeft();
	const unsigned int topCorner = node.getTop();

	const unsigned int widthRoot = node.getWidth();
	const unsigned int heightRoot = node.getHeight();

	const unsigned int endX = std::clamp((unsigned) widthRoot + leftCorner, 0u, console.getWidth());
	const unsigned int endY = std::clamp((unsigned) heightRoot + topCorner, 0u, console.getWidth());

	for(std::size_t startX = leftCorner; startX < endX; startX += 1)
	{
		for(std::size_t startY = topCorner; startY < endY; startY += 1)
		{
			console.writeChar(startX, startY, 178, {0, 0, 0}, background);
		}
	}
}

int main()
{
	Console console {100, 100};
	console.setFramePerSeconds(24);

	Hippy::Frame root {100, 100};
	root.setFlexDirection(FLexDirectionRow);
	root.setAlignItems(FlexAlignStart);

	Hippy::Frame wrapper { &root };
	wrapper.setWidth(80);
	wrapper.setHeight(root.getHeight() * 1.0f);

	Hippy::Frame root_child1 { &wrapper };
	root_child1.setWidth(80.f);
	root_child1.setFlexGrow(1.0f);

	Hippy::Frame root_child2 { &wrapper };
	root_child2.setWidth(80.0f);
	root_child2.setFlexGrow(1.0f);

	Hippy::Frame lastElement { &root };
	lastElement.setWidth(20.0f);
	lastElement.setHeight( root.getHeight() * 1.0f );

	root.recalculate();
	root.printNode();

	while (console.isRunning())
	{
		console.clear();

		const KeyCode key = console.getKeyPressed().getKeyCode();

		if (key == KeyCode::ENTER)
		{
			root.setAssociativity(DirectionRTL);
		}
		else if (key == KeyCode::SPACE)
		{
			root.setAssociativity(DirectionLTR);
		}

		DrawNode(root, console, {127, 127, 127});
		DrawNode(wrapper, console, { 255, 255, 0});
		DrawNode(root_child1, console, {255, 0, 0});
		DrawNode(root_child2, console, {0, 255, 0});
		DrawNode(lastElement, console, {0, 0, 255});

		console.draw();
	}

//	HPNodeFreeRecursive(root);
}

