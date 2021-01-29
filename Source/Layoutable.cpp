// Joan Andrés (@Andres6936) Github.

#include "Hippy/Doryen/Layoutable.hpp"

using namespace Hippy;

// Construct

Layoutable::Layoutable()
{
	HPNodeStyleSetWidth(layout, 0.0f);
	HPNodeStyleSetHeight(layout, 0.0f);
}

Layoutable::Layoutable(const LayoutableView _parent) : parent(_parent)
{
	HPNodeInsertChild(parent->layout, this->layout, parent->children);
	// Increment the numbers of child inserted.
	parent->children += 1;
}

Layoutable::Layoutable(const float width, const float height)
{
	HPNodeStyleSetWidth(layout, width);
	HPNodeStyleSetHeight(layout, height);
	HPNodeDoLayout(layout, width, height, DirectionLTR);
}

// Destructor

Layoutable::~Layoutable()
{
	HPNodeFree(layout);
}

// Methods

void Layoutable::printNode()
{
	HPNodePrint(layout);
}

void Layoutable::recalculate()
{
	// The code layout->style.dim[0] store the style width of node.
	// The code layout->style.dim[1] store the style height of node.
	HPNodeDoLayout(layout, layout->style.dim[0], layout->style.dim[1], DirectionLTR);
}

void Layoutable::addChild(const Layoutable& child)
{
	HPNodeInsertChild(layout, child.layout, children);
	// Increment the numbers of child inserted.
	children += 1;
}

bool Layoutable::isEmpty() const
{
	return getWidth() == 0 and getHeight() == 0;
}

// Setters

void Layoutable::setWidth(const float width)
{
	HPNodeStyleSetWidth(layout, width);
}

void Layoutable::setHeight(const float height)
{
	HPNodeStyleSetHeight(layout, height);
}

void Layoutable::setFlexGrow(const float grow)
{
	HPNodeStyleSetFlexGrow(layout, grow);
}

void Layoutable::setAlignItems(const FlexAlign align)
{
	HPNodeStyleSetAlignItems(layout, align);
}

void Layoutable::setFlexDirection(const FlexDirection direction)
{
	HPNodeStyleSetFlexDirection(layout, direction);
}

void Layoutable::setLayoutDirection(const HPDirection direction)
{
	HPNodeDoLayout(layout, VALUE_UNDEFINED, VALUE_UNDEFINED, direction);
}

// Getters

float Layoutable::getTop() const
{
	return HPNodeLayoutGetTop(layout);
}

float Layoutable::getLeft() const
{
	return HPNodeLayoutGetLeft(layout);
}

float Layoutable::getWidth() const
{
	return HPNodeLayoutGetWidth(layout);
}

float Layoutable::getHeight() const
{
	return HPNodeLayoutGetHeight(layout);
}

float Layoutable::getAbsoluteTop() const
{
	if (parent not_eq nullptr)
	{
		// Calculate recursively the y-coordinate absolute (in cells) of the
		// left edge of this flex container.
		return this->getTop() + parent->getAbsoluteTop();
	}
	else
	{
		// Case base: The parent is null (aka. the flex container is the root).
		return this->getTop();
	}
}

float Layoutable::getAbsoluteLeft() const
{
	if (parent not_eq nullptr)
	{
		// Calculate recursively the x-coordinate absolute (in cells) of the
		// left edge of this flex container.
		return this->getLeft() + parent->getAbsoluteLeft();
	}
	else
	{
		// Case base: The parent is null (aka. the flex container is the root).
		return this->getLeft();
	}
}

HPDirection Layoutable::getLayoutDirection() const
{
	return layout->result.direction;
}
