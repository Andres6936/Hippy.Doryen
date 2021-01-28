// Joan Andrés (@Andres6936) Github.

#ifndef HIPPY_FRAME_HPP
#define HIPPY_FRAME_HPP

#include <Hippy/Doryen/Layoutable.hpp>

namespace Hippy
{

	class Frame : public Layoutable
	{

	public:

		Frame( const LayoutableView parent);

		Frame(const float width, const float height);

	};

}

#endif //HIPPY_FRAME_HPP
