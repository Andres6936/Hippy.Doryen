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
		 * Initializes a new instance of the Rectangle class with the specified
		 * location and size.
		 *
		 * @param point A Point that represents the upper-left corner of the rectangular region.
		 * @param size A Size that represents the width and height of the rectangular region.
		 */
		Rectangle(const Point2D<>& point, const Size& size)
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
		Rectangle(std::int32_t _x, std::int32_t _y, std::int32_t _w, std::int32_t _h)
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

	};

}

#endif //HIPPY_DORYEN_RECTANGLE_HPP
