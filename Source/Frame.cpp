// Joan Andrés (@Andres6936) Github.

#include "Hippy/Doryen/Frame.hpp"

using namespace Hippy;

Frame::Frame(Layoutable::LayoutableView const parent) : Layoutable(parent)
{
	// Delegate the construction of object to parent
}

Frame::Frame(const float width, const float height) : Layoutable(width, height)
{
	// Delegate the construction of object to parent
}
