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
	HPNodeStyleSetWidth(root, 100.0f);
	HPNodeStyleSetHeight(root, 100.0f);
	HPNodeStyleSetFlexDirection(root, FLexDirectionRow);
	HPNodeStyleSetAlignItems(root, FlexAlignStart);
	HPNodeDoLayout(root, 100.0f, 100.0f, DirectionLTR);

	const HPNodeRef wrapper = HPNodeNew();
	HPNodeStyleSetWidth(wrapper, 80.0f);
	HPNodeStyleSetHeight(wrapper, HPNodeLayoutGetHeight(root) * 1.0f);
	HPNodeInsertChild(root, wrapper, 0);

	const HPNodeRef root_child1 = HPNodeNew();
	HPNodeStyleSetWidth(root_child1, 80.0f);
	HPNodeStyleSetFlexGrow(root_child1, 1.0f);
	HPNodeInsertChild(wrapper, root_child1, 0);

	const HPNodeRef root_child2 = HPNodeNew();
	HPNodeStyleSetWidth(root_child2, 80.0f);
	HPNodeStyleSetFlexGrow(root_child2, 1.0f);
	HPNodeInsertChild(wrapper, root_child2, 1);

	const HPNodeRef lastElement = HPNodeNew();
	HPNodeStyleSetWidth(lastElement, 20.0f);
	HPNodeStyleSetHeight(lastElement, HPNodeLayoutGetHeight(root) * 1.0f);
	HPNodeInsertChild(root, lastElement, 1);

	HPNodeDoLayout(root, 100.0f, 100.0f, DirectionLTR);
	HPNodeDoLayout(wrapper, HPNodeLayoutGetWidth(root), HPNodeLayoutGetHeight(root), DirectionInherit);

	HPNodePrint(root);

	while (console.isRunning())
	{
		console.clear();

		const KeyCode key = console.getKeyPressed().getKeyCode();

		if (key == KeyCode::ENTER)
		{
			HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionRTL);
			HPNodePrint(root);
		}
		else if (key == KeyCode::SPACE)
		{
			HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED, DirectionLTR);
			HPNodePrint(root);
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

