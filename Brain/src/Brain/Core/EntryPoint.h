#pragma once
#include "Brain/Core/Base.h"

#ifdef BR_PLATFORM_WINDOWS

extern Brain::Application* Brain::CreateApplication();

int main(int argc, char** argv)
{
	Brain::Log::Init();

	BR_PROFILE_BEGIN_SESSION("Startup", "BrainProfile-Startup.json");
	auto app = Brain::CreateApplication();
	BR_PROFILE_END_SESSION();

	BR_PROFILE_BEGIN_SESSION("Runtime", "BrainProfile-Runtime.json");
	app->Run();
	BR_PROFILE_END_SESSION();

	BR_PROFILE_BEGIN_SESSION("Shutdown", "BrainProfile-Shutdown.json");
	delete app;
	BR_PROFILE_END_SESSION();
}

#endif
