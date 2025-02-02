#include <Brain.h>
#include <Brain/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Brain {

	class BrainFracker : public Application
	{
	public:
		BrainFracker()
			: Application("BrainFracker")
		{
			PushLayer(new EditorLayer());
		}

		~BrainFracker()
		{
		}
	};

	Application* CreateApplication()
	{
		return new BrainFracker();
	}

}