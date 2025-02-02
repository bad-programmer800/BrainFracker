#include "brpch.h"
#include "Brain/Renderer/RenderCommand.h"

namespace Brain {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}