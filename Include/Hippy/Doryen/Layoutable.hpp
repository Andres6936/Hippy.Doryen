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
	 * <br><br>
	 *
	 * The definition of an empty flex container is whose width and height
	 * is zero (0).
	 * <br><br>
	 *
	 * For default this class use a flex layout model, the children of a flex
	 * container can be laid out in any direction, and can “flex” their sizes,
	 * either growing to fill unused space or shrinking to avoid overflowing the
	 * parent. Both horizontal and vertical alignment of the children can be
	 * easily manipulated. Nesting of these boxes (horizontal inside vertical,
	 * or vertical inside horizontal) can be used to build layouts in two
	 * dimensions.
	 * <br><br>
	 *
	 * For default the associativity order for any flex container is left to
	 * right, if need change the order of associativity use the function
	 * setAssociativityOrder. The values allow are LTR (Left to Right) and RTL
	 * (Right to Left).
	 *
	 * Flex layout is superficially similar to block layout. It lacks many of
	 * the more complex text- or document-centric properties that can be used in
	 * block layout, such as floats and columns. In return it gains simple and
	 * powerful tools for distributing space and aligning content in ways that
	 * web apps and complex web pages often need.
	 * The contents of a flex container:
	 * <br><br>
	 *
	 * 	- Can be laid out in any flow direction (leftwards, rightwards,
	 * 	downwards, or even upwards!). <br>
	 * 	- Can have their display order reversed or rearranged at the style layer
	 * 	(i.e., visual order can be independent of source and speech order). <br>
	 * 	- Can be laid out linearly along a single (main) axis or wrapped into
	 * 	multiple lines along a secondary (cross) axis. <br>
	 * 	- Can “flex” their sizes to respond to the available space. <br>
	 * 	- Can be aligned with respect to their container or each other on the
	 * 	secondary (cross). <br>
	 * 	- Can be dynamically collapsed or uncollapsed along the main axis while
	 * 	preserving the container’s cross size. <br><br>
	 *
	 * For default the flex model layout calculate the position of children
	 * container relatives to parent flex container, this result in the need
	 * to transform these relatives measurements into absolute measurement,
	 * which allow, among other things, the correct drawing of the child
	 * containers. For get the coordinates relatives use the methods getTop,
	 * getLeft, getRight and getBottom, for the absolute coordinates use the
	 * methods getAbsoluteTop, getAbsoluteLeft, getAbsoluteRight and
	 * getAbsoluteBottom.
	 *
	 */
	class Layoutable
	{

	protected:

		// Definitions

		/**
		 * Define a pointer to a element of same type {Layoutable} that takes
		 * the role of the parent of the element.
		 */
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

		// Destructor

		/**
		 * Responsible of destroy the instance of Hippy flex layout model.
		 */
		virtual ~Layoutable();

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
		 * Add the new children component to this flex container.
		 *
		 * @param child The new children component to be added.
		 */
		void addChild(const Layoutable& child);

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

		/**
		 * Set the align of children items as a group in this flex container.
		 *
		 * @param align Set the align-self value on all direct children as a
		 * group. In Flexbox, it controls the alignment of items on the Cross
		 * Axis.
		 */
		void setAlignItems(const FlexAlign align);

		/**
		 * Set the direction that define how flex items are placed in the flex
		 * container defining the main axis and the direction (normal or
		 * reversed).
		 *
		 * @param direction Sets how flex items are placed in the flex container.
		 */
		void setFlexDirection(const FlexDirection direction);

		/**
		 * Set the associativity of left to right (LTR) or right to left (RTL)
		 * of flex container.
		 *
		 * The mean of associativity for this method is: The arrangement or
		 * disposition of children container in relation to each other according
		 * to a particular sequence or pattern.
		 *
		 * @param direction The associativity LTR or RTL of flex container.
		 */
		void setAssociativityOrder(const HPDirection direction);

		// Getters

		/**
		 * @return Gets the y-coordinate relative to parent flex container (in
		 * cells) of the top edge of this flex container.
		 */
		float getTop();

		/**
		 * @return Gets the x-coordinate relative to parent flex container (in
		 * cells) of the left edge of this flex container.
		 */
		float getLeft();

		/**
		 * @return Gets the width (in cells) of this flex container.
		 */
		float getWidth();

		/**
		 * @return Gets the height (in cells) of this flex container.
		 */
		float getHeight();

		/**
		 * @return Get the y-coordinate absolute (in cells) of the top edge of
		 * this flex container.
		 */
		float getAbsoluteTop();

		/**
		 * @return Gets the x-coordinate absolute (in cells) of the left edge
		 * of this flex container.
		 */
		float getAbsoluteLeft();

	};

}

#endif //HIPPY_DORYEN_WIDGET_HPP
