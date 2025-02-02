#include "brpch.h"
#include "Brain/Renderer/GraphicsContext.h"

#include "Brain/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Brain {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    BR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		BR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}