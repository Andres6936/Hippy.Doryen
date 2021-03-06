#include <Doryen/Doryen.hpp>
#include <Hippy/Flex/Hippy.h>
#include <Hippy/Doryen/Frame.hpp>

using namespace Doryen;

void DrawNode(const std::shared_ptr<Hippy::Frame> node, Console& console, const Color& background)
{
	const unsigned int leftCorner = node->getAbsoluteLeft();
	const unsigned int topCorner = node->getAbsoluteTop();

	const unsigned int widthRoot = node->getWidth();
	const unsigned int heightRoot = node->getHeight();

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

	auto root = std::make_shared<Hippy::Frame>(100, 100);
	root->setFlexDirection(FLexDirectionRow);
	root->setAlignItems(FlexAlignStart);

	auto wrapper = std::make_shared<Hippy::Frame>( root );
	wrapper->setWidth(80);
	wrapper->setHeight(root->getHeight() * 1.0f);

	auto root_child1 = std::make_shared<Hippy::Frame>( wrapper );
	root_child1->setWidth(80.f);
	root_child1->setFlexGrow(1.0f);

	auto root_child2 = std::make_shared<Hippy::Frame> (wrapper );
	root_child2->setWidth(80.0f);
	root_child2->setFlexGrow(1.0f);

	auto lastElement = std::make_shared<Hippy::Frame> (root );
	lastElement->setWidth(20.0f);
	lastElement->setHeight( root->getHeight() * 1.0f );

	root->doLayout();
	root->printNode();

	while (console.isRunning())
	{
		console.clear();

		const KeyCode key = console.getKeyPressed().getKeyCode();

		if (key == KeyCode::ENTER)
		{
			root->setLayoutDirection(DirectionRTL);
		}
		else if (key == KeyCode::SPACE)
		{
			root->setLayoutDirection(DirectionLTR);
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

