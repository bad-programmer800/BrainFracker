#pragma once

#include "Brain/Core/Base.h"
#include "Brain/Core/KeyCodes.h"
#include "Brain/Core/MouseCodes.h"

namespace Brain {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
