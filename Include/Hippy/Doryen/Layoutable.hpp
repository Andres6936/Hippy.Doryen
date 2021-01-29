// Joan Andrés (@Andres6936) Github.

#ifndef HIPPY_DORYEN_WIDGET_HPP
#define HIPPY_DORYEN_WIDGET_HPP

#include <Hippy/Flex/Hippy.h>

namespace Hippy
{

	/**
	 * Layoutable class defines rectangular component that has elementary
	 * metrical properties like width and height and can be a participant of
	 * layout management process. Layoutable component is container that can
	 * contains other layoutable component as its children. The children
	 * components are ordered by applying a layout manager of its parent
	 * component.
	 *
	 * The definition of an empty Layoutable component is that whose width and
	 * height is zero (0).
	 */
	class Layoutable
	{

	protected:

		// Definitions

		using LayoutableView = Layoutable*;

	private:

		// Properties

		std::uint8_t totalsChildInserted = 0;

		/**
		 * Define the node Hippy, that calculate the disposition of itself and
		 * child, the work of manage the Layout is responsibility of Hippy.
		 */
		const HPNodeRef layout = HPNodeNew();

		const LayoutableView parent { nullptr};

	public:

		// Construct

		/**
		 * Constructs a new instance with a Layout that is initially empty.
		 *
		 * @param parent The parent that content the object.
		 */
		Layoutable(const LayoutableView parent);

		/**
		 * Constructs a new instance with a Layout of dimensions {width x height}.
		 *
		 * @param width The width of layout in cells.
		 * @param height The height of layout in cells.
		 */
		Layoutable(const float width, const float height);

		// Methods

		void printNode();

		/**
		 * Validate the component metrics. The method is called as a one step of
		 * the component validation procedure. The method causes "recalc" method
		 * execution if the method has been implemented and the component is in
		 * invalid state. It is supposed the "recalc" method has to be
		 * implemented by a component as safe place where the component metrics
		 * can be calculated. Component metrics is individual for the given
		 * component properties that has influence to the component preferred
		 * size value. In many cases the properties calculation has to be
		 * minimized what can be done by moving the calculation in "recalc"
		 * method.
		 */
		void recalculate();

		/**
		 * Add the new children component.
		 *
		 * @param child The new children component to be added.
		 */
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
