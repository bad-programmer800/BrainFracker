#include "brpch.h"
#include "Brain/Core/Window.h"

#ifdef BR_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Brain
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef BR_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		BR_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}