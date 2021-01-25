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
	HPNodeStyleSetFlexDirection(root, FLexDirectionRow);
	HPNodeStyleSetWidth(root, 100);
	HPNodeStyleSetHeight(root, 100);

	const HPNodeRef root_child0 = HPNodeNew();
	HPNodeStyleSetMargin(root_child0, CSSStart, 10);
	HPNodeStyleSetWidth(root_child0, 10);
	HPNodeInsertChild(root, root_child0, 0);
	HPNodeDoLayout(root, VALUE_UNDEFINED, VALUE_UNDEFINED);

	while (console.isRunning())
	{
		console.clear();

		DrawNode(root, console, {127, 127, 127});
		DrawNode(root_child0, console, {255, 255, 0});

		console.draw();
	}

	HPNodeFreeRecursive(root);
}

