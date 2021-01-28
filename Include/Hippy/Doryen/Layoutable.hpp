// Joan Andrés (@Andres6936) Github.

#ifndef HIPPY_DORYEN_WIDGET_HPP
#define HIPPY_DORYEN_WIDGET_HPP

#include <Hippy/Flex/Hippy.h>

namespace Hippy
{

	class Layoutable
	{

	protected:

		// Definitions

		using LayoutableView = Layoutable*;

	private:

		// Properties

		std::uint8_t totalsChildInserted = 0;

		const HPNodeRef layout = HPNodeNew();

		const LayoutableView parent { nullptr};

	public:

		// Construct

		Layoutable(const LayoutableView parent);

		Layoutable(const float width, const float height);

		// Methods

		void printNode();

		void recalculate();

		void insertChild(const Layoutable& child);

		// Setters

		void setWidth(const float width);

		void setHeight(const float height);

		void setFlexGrow(const float grow);

		void setAlignItems(const FlexAlign align);

		void setFlexDirection(const FlexDirection direction);

		// Getters

		float getTop();

		float getLeft();

		float getWidth();

		float getHeight();

	};

}

#endif //HIPPY_DORYEN_WIDGET_HPP
