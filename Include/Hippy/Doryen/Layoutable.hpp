// Joan Andrés (@Andres6936) Github.

#ifndef HIPPY_DORYEN_WIDGET_HPP
#define HIPPY_DORYEN_WIDGET_HPP

#include <Hippy/Flex/Hippy.h>

namespace Hippy
{

	/**
	 * Layoutable class defines rectangular component (aka flex container) that
	 * has elementary metrical properties like width and height and can be a
	 * participant of layout management process. Layoutable component is
	 * container that can contains other layoutable component as its children.
	 * The children components are ordered by applying a layout manager of its
	 * parent component.
	 *
	 * The definition of an empty flex container is whose width and height
	 * is zero (0).
	 *
	 * For default this class use a flex layout model, the children of a flex
	 * container can be laid out in any direction, and can “flex” their sizes,
	 * either growing to fill unused space or shrinking to avoid overflowing the
	 * parent. Both horizontal and vertical alignment of the children can be
	 * easily manipulated. Nesting of these boxes (horizontal inside vertical,
	 * or vertical inside horizontal) can be used to build layouts in two
	 * dimensions.
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
		 * Define the node Hippy, it is the that calculate the disposition of
		 * itself and of all child, the work of manage the flex container is
		 * responsibility of Hippy.
		 */
		const HPNodeRef layout = HPNodeNew();

		/**
		 * The parent flex container of the this flex. If it is null, it
		 * indicate that this container is responsible for calculating the
		 * disposition for itself and all children recursively.
		 */
		const LayoutableView parent { nullptr};

	public:

		// Construct

		/**
		 * Constructs a new instance with a flex container that is initially empty.
		 *
		 * @param parent The parent that content the object.
		 */
		Layoutable(const LayoutableView parent);

		/**
		 * Constructs a new instance with a flex container of dimensions {width x height}.
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
		 * Add the new children component to it flex container.
		 *
		 * @param child The new children component to be added.
		 */
		void insertChild(const Layoutable& child);

		// Setters

		/**
		 * Set the width of flex container in cells.
		 *
		 * @param width The width of Layout in cells.
		 */
		void setWidth(const float width);

		/**
		 * Set the height of flex container in cells.
		 *
		 * @param height The height of Layout in cells.
		 */
		void setHeight(const float height);

		/**
		 * Set the flex grow of element in the parent flex container.
		 *
		 * This property specifies how much of the remaining space in the flex
		 * container should be assigned to the item (the flex grow factor).
		 *
		 * @param grow The flex grow. Negative values are invalid. Defaults to 0.
		 */
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
