// Joan Andrés (@Andres6936) Github.

#ifndef HIPPY_DORYEN_WIDGET_HPP
#define HIPPY_DORYEN_WIDGET_HPP

#include <memory>
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
	 * It is important to keep in mint the two types of dimensions that a flex
	 * container defines, the first type of dimension define by the flex
	 * container is the style, and the second type of dimension is the layout.
	 * The second type of dimension is special, since the correct arrangement of
	 * all the elements it contains (the children) depends on it. <br><br>
	 *
	 * If not layout is configured throughout the entire hierarchy, the layout
	 * will be inexistent and no matter if style have been defined, they will
	 * not seen at all since is no way to apply styles to containers that do not
	 * have a layout as a parent. <br><br>
	 *
	 * For default the direction of layout for any flex container is left to
	 * right (inherit), if need change the direction of layout use the
	 * function setLayoutDirection. The values allow are LTR (Left to Right)
	 * and RTL (Right to Left). <br><br>
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
		using LayoutableView = std::shared_ptr<Layoutable>;

	private:

		// Properties

		/**
		 * Define the total of children that has the flex container. In
		 * addition, define the order of insertion of the children inside the
		 * flex container. If the value of the variable is 0 (parent has not a
		 * children yet), the possible child to be inserted will be inserted in
		 * the first position of array. If on the other hand the flex container
		 * already has a child and an attempt is made to insert the new child
		 * at position 0, the children already in the flex container will be
		 * moved one position to the right.
		 *
		 * This variable only define the total of children that has the current
		 * flex container, the total of children in the hierarchy not will be
		 * counted.
		 *
		 * The maximum possible number of children that each container may have
		 * is 255 children (Integer of 8 bits).
		 */
		std::uint8_t children = 0;

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
		 * Construct a new instance flex container that is initially empty.
		 */
		Layoutable();

		/**
		 * Constructs a new instance flex container that is initially empty.
		 *
		 * @param parent The parent that content the object.
		 */
		Layoutable(const LayoutableView parent);

		/**
		 * Constructs a new instance flex container of dimensions {width x height}.
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

		/**
		 * 	Causes this container to lay out its components.
		 */
		void doLayout();

		/**
		 * Print the node in form of HTML element.
		 */
		void printNode();

		/**
		 * Add the new children component to this flex container.
		 *
		 * @param child The new children component to be added.
		 */
		void addChild(const Layoutable& child);

		/**
		 * @return True if the flex container is empty (Its height and width
		 * dimensions are both zero), false in otherwise.
		 */
		bool isEmpty() const;

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
		 * Set the direction og layout of left to right (LTR) or right to left
		 * (RTL) of flex container.
		 *
		 * @param direction The direction of layout, LTR or RTL of flex container.
		 */
		void setLayoutDirection(const HPDirection direction);

		// Getters

		/**
		 * @return Gets the y-coordinate relative to parent flex container (in
		 * cells) of the top edge of this flex container.
		 */
		float getTop() const;

		/**
		 * @return Gets the x-coordinate relative to parent flex container (in
		 * cells) of the left edge of this flex container.
		 */
		float getLeft() const;

		/**
		 * @return Gets the width (in cells) of this flex container.
		 */
		float getWidth() const;

		/**
		 * @return Gets the height (in cells) of this flex container.
		 */
		float getHeight() const;

		/**
		 * @return Get the y-coordinate absolute (in cells) of the top edge of
		 * this flex container.
		 */
		float getAbsoluteTop() const;

		/**
		 * @return Gets the x-coordinate absolute (in cells) of the left edge
		 * of this flex container.
		 */
		float getAbsoluteLeft() const;

		/**
		 * @note (This method not count the total number of children throughout
		 * the hierarchy).
		 *
		 * @return Get the total of children that this flex container has.
		 */
		std::uint8_t getChildren() const;

		/**
		 * @return Get the direction of layout for this flex container.
		 */
		HPDirection getLayoutDirection() const;

	};

}

#endif //HIPPY_DORYEN_WIDGET_HPP
