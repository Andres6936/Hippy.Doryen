// Joan Andrés (@Andres6936) Github.

#include "Hippy/Doryen/Layoutable.hpp"

using namespace Hippy;

// Construct

Layoutable::Layoutable(const LayoutableView _parent) : parent(_parent)
{
	HPNodeInsertChild(parent->layout, this->layout, totalsChildInserted);
	// Increment the numbers of child inserted.
	totalsChildInserted += 1;
}

Layoutable::Layoutable(const float width, const float height)
{
	HPNodeStyleSetWidth(layout, width);
	HPNodeStyleSetHeight(layout, height);
	HPNodeDoLayout(layout, width, height, DirectionLTR);
}

// Methods

void Layoutable::printNode()
{
	HPNodePrint(layout);
}

void Layoutable::insertChild(const Layoutable& child)
{
	HPNodeInsertChild(layout, child.layout, totalsChildInserted);
	// Increment the numbers of child inserted.
	totalsChildInserted += 1;
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

// Getters

float Layoutable::getTop()
{
	return HPNodeLayoutGetTop(layout);
}

float Layoutable::getLeft()
{
	return HPNodeLayoutGetLeft(layout);
}

float Layoutable::getWidth()
{
	return HPNodeLayoutGetWidth(layout);
}

float Layoutable::getHeight()
{
	return HPNodeLayoutGetHeight(layout);
}
