#include "brpch.h"
#include "Brain/Renderer/Texture.h"

#include "Brain/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Brain {

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    BR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(width, height);
		}

		BR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    BR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(path);
		}

		BR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	// BEGIN: Overload of Create()
	Ref<Texture2D> Texture2D::Create(cv::Mat cvImage)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    BR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(cvImage);
		}

		BR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	// END - Create texture in platform OpenGLTexture

}