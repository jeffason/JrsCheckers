/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Core.h
//
// DESCRIPTION:
//	Core engine functionality commonly used across different parts of the application
//
// jrs051413 - created
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#define INPUT_KEY_ARROW_UP		72
#define INPUT_KEY_ARROW_LEFT	75
#define INPUT_KEY_ARROW_RIGHT	77
#define INPUT_KEY_ARROW_DOWN	80

namespace jrs{

	struct Vec2D
	{
		int x;
		int y;

		Vec2D() : x(0), y(0) {}
		Vec2D(int _x, int _y) : x(_x), y(_y) {}
	};
}