#include <Doryen/Doryen.hpp>
#include <Hippy/Flex/Hippy.h>

using namespace Doryen;

void DrawNode(HPNodeRef node, Console& console, const Color& background)
{
	const unsigned int leftCorner = HPNodeLayoutGetLeft(node);
	const unsigned int topCorner = HPNodeLayoutGetTop(node);

	const unsigned int widthRoot = HPNodeLayoutGetWidth(node);
	const unsigned int heightRoot = HPNodeLayoutGetHeight(node);

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

	const HPNodeRef root = HPNodeNew();
	HPNodeStyleSetWidth(root, 100);
	HPNodeStyleSetHeight(root, 100);
	HPNodeStyleSetAlignItems(root, FlexAlignStart);

	const HPNodeRef wrapper = HPNodeNew();
	HPNodeStyleSetWidth(wrapper, 80);
	HPNodeStyleSetHeight(wrapper, 100);
	HPNodeInsertChild(root, wrapper, 0);
	HPNodeStyleSetFlexWrap(wrapper, FlexWrap);

	const HPNodeRef root_child1 = HPNodeNew();
	HPNodeStyleSetWidth(root_child1, 80);
	HPNodeStyleSetHeight(root_child1, 50);
	HPNodeStyleSetFlexGrow(root_child1, 1);
	HPNodeStyleSetFlexShrink(root_child1, 1);
	HPNodeStyleSetFlexWrap(root_child1, FlexWrap);
	HPNodeInsertChild(wrapper, root_child1, 0);

	const HPNodeRef root_child2 = HPNodeNew();
	HPNodeStyleSetWidth(root_child2, 80);
	HPNodeStyleSetHeight(root_child2, 50);
	HPNodeStyleSetFlexGrow(root_child2, 1);
	HPNodeStyleSetFlexWrap(root_child2, FlexWrap);
	HPNodeInsertChild(wrapper, root_child2, 1);

	const HPNodeRef lastElement = HPNodeNew();
	HPNodeStyleSetWidth(lastElement, 20);
	HPNodeStyleSetHeight(lastElement, 100);
	HPNodeInsertChild(root, lastElement, 1);

	HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

	while (console.isRunning())
	{
		console.clear();

		const KeyCode key = console.getKeyPressed().getKeyCode();

		if (key == KeyCode::ENTER)
		{
			HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);
		}
		else if (key == KeyCode::SPACE)
		{
			HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionLTR);
		}

		DrawNode(root, console, {127, 127, 127});
		DrawNode(wrapper, console, { 255, 255, 0});
		DrawNode(root_child1, console, {255, 0, 0});
		DrawNode(root_child2, console, {0, 255, 0});
		DrawNode(lastElement, console, {0, 0, 255});

		console.draw();
	}

	HPNodeFreeRecursive(root);
}

