#pragma once
#include "ExportHeader.h"

namespace GuichernoEngine {
	struct Color {
		float r;
		float g;
		float b;
		float a;
	};

	const Color RED = { 1.0f, 0.0f, 0.0f, 1.0f };
	const Color GREEN = { 0.0f, 1.0f, 0.0f, 1.0f };
	const Color BLUE = { 0.0f, 0.0f, 1.0f, 1.0f };
	const Color WHITE = { 1.0f, 1.0f, 1.0f, 1.0f };
	const Color BLACK = { 0.0f, 0.0f, 0.0f, 1.0f };
	const Color YELLOW = { 1.0f, 1.0f, 0.0f, 1.0f };
	const Color CYAN = { 0.0f, 1.0f, 1.0f, 1.0f };
	const Color MAGENTA = { 1.0f, 0.0f, 1.0f, 1.0f };
}
