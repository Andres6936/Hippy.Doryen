// Joan Andrés (@Andres6936) Github.

#ifndef HIPPY_DORYEN_RECTANGLE_HPP
#define HIPPY_DORYEN_RECTANGLE_HPP

#include <cstdint>

#include <Doryen/Geometry/Size.hpp>
#include <Doryen/Geometry/Point2D.hpp>

namespace Doryen::Geometry
{

	/**
	 * @brief Stores a set of four integers that represent the location and size
	 * of a rectangle.
	 *
	 * A Rectangle specifies an area in a coordinate space that is enclosed by
	 * the Rectangle object's upper-left point (x,y) in the coordinate space,
	 * its width, and its height.
	 *
	 * A Rectangle object's width and height are private fields. The
	 * constructors that create a Rectangle, and the methods that can modify
	 * one, do not prevent setting a negative value for width or height.
	 *
	 * A Rectangle whose width or height is exactly zero has location along
	 * those axes with zero dimension, but is otherwise considered empty.
	 *
	 * Methods which affect only the location of a Rectangle will operate on its
	 * location regardless of whether or not it has a negative or zero dimension
	 * along either axis.
	 *
	 * Note that a Rectangle constructed with the default no-argument
	 * constructor will have dimensions of 0x0 and therefore be empty. That
	 * Rectangle will still have a location of (0,0) and will contribute that
	 * location to the union and add operations.
	 *
	 * This class uses 32-bit integers to store its location and dimensions.
	 * Frequently operations may produce a result that exceeds the range of a
	 * 32-bit integer.
	 */
	class Rectangle
	{

	private:

		// Properties

		/**
		 * The x-coordinate of the upper-left corner of this Rectangle structure.
		 * The default is 0.
		 */
		std::int32_t x {0};

		/**
		 * The y-coordinate of the upper-left corner of this Rectangle structure.
		 * The default is 0.
		 */
		std::int32_t y {0};

		/**
		 * The width of this Rectangle structure. The default is 0.
		 */
		std::int32_t width {0};

		/**
		 * The height of this Rectangle structure. The default is 0.
		 */
		std::int32_t height {0};

	public:

		// Constructs

		/**
		 * Constructs a new Rectangle whose upper-left corner is at (0, 0) in
		 * the coordinate space, and whose width and height are both zero.
		 */
		Rectangle() noexcept = default;


		/**
		 * Initializes a new instance of the Rectangle class with the specified
		 * location and size.
		 *
		 * @param point A Point that represents the upper-left corner of the rectangular region.
		 * @param size A Size that represents the width and height of the rectangular region.
		 */
		Rectangle(const Point2D<>& point, const Size& size) noexcept
			: x(point.x), y(point.y), width(size.w), height(size.h)
		{

		}

		/**
		 * Initializes a new instance of the Rectangle class with the specified
		 * location and size.
		 *
		 * @param _x The x-coordinate of the upper-left corner of the rectangle.
		 * @param _y The y-coordinate of the upper-left corner of the rectangle.
		 * @param _w The width of the rectangle.
		 * @param _h The height of the rectangle.
		 */
		Rectangle(std::int32_t _x, std::int32_t _y, std::int32_t _w, std::int32_t _h) noexcept
			: x(_x), y(_y), width(_w), height(_h)
		{

		}

		// Getters

		/**
		 * @return Gets the x-coordinate of the upper-left corner of this
		 * Rectangle structure.
		 */
		std::int32_t getX() const noexcept
		{
			return x;
		}

		/**
		 * @return Gets the y-coordinate of the upper-left corner of this
		 * Rectangle structure.
		 */
		std::int32_t getY() const noexcept
		{
			return y;
		}

		/**
		 * @return Gets the width of this Rectangle structure.
		 */
		std::int32_t getWidth() const noexcept
		{
			return width;
		}

		/**
		 * @return Gets the height of this Rectangle structure.
		 */
		std::int32_t getHeight() const noexcept
		{
			return height;
		}

		/**
		 * @return Gets the y-coordinate of the top edge of this Rectangle structure.
		 */
		std::int32_t getTop() const noexcept
		{
			return y;
		}

		/**
		 * @return Gets the x-coordinate of the left edge of this Rectangle structure.
		 */
		std::int32_t getLeft() const noexcept
		{
			return x;
		}

		/**
		 * @note The value of the Right property represents the x-coordinate of
		 * the first point at the right edge of the rectangle that is not
		 * contained in the rectangle.
		 *
		 * @return Gets the x-coordinate that is the sum of X and Width property
		 * values of this Rectangle structure.
		 */
		std::int32_t getRight() const noexcept
		{
			return x + width;
		}

		/**
		 * @note The value of the Bottom property represents the y-coordinate of
		 * the first point at the bottom edge of the Rectangle that is not
		 * contained in the Rectangle.
		 *
		 * @return Gets the y-coordinate that is the sum of the Y and Height
		 * property values of this Rectangle structure.
		 */
		std::int32_t getBottom() const noexcept
		{
			return y + height;
		}

		// Setters

		/**
		 * Sets the x-coordinate of the upper-left corner of this Rectangle structure.
		 *
		 * @note Changing the X property will also cause a change in the Right
		 * property of the Rectangle.
		 *
		 * @param _x The x-coordinate of the upper-left corner of this Rectangle structure.
		 */
		void setX(const std::int32_t _x) noexcept
		{
			this->x = _x;
		}

		/**
		 * Sets the y-coordinate of the upper-left corner of this Rectangle structure.
		 *
		 * @note Changing the Y property will also cause a change in the Bottom
		 * property of the Rectangle.
		 *
		 * @param _y The y-coordinate of the upper-left corner of this Rectangle structure.
		 */
		void setY(const std::int32_t _y) noexcept
		{
			this->y = _y;
		}

		/**
		 * Sets the width of this Rectangle structure.
		 *
		 * @note Changing the Width property will also cause a change in the
		 * Right property of the Rectangle.
		 *
		 * @param _width The width of this Rectangle structure.
		 */
		void setWidth(const std::int32_t _width) noexcept
		{
			this->width = _width;
		}

		/**
		 * Sets the height of this Rectangle structure.
		 *
		 * @note Changing the Height property will also cause a change in the
		 * Bottom property of the Rectangle.
		 *
		 * @param _height The height of this Rectangle structure.
		 */
		void setHeight(const std::int32_t _height) noexcept
		{
			this->height = _height;
		}

	};

}

#endif //HIPPY_DORYEN_RECTANGLE_HPP
