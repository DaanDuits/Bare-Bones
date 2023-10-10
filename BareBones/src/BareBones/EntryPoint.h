#pragma once

#ifdef BB_PLATFORM_WINDOWS

extern BareBones::Application* BareBones::CreateApplication();

int main(int argc, char** argv)
{
	BareBones::Log::Init();

	BB_CORE_WARN("Initialized Logger!");
	BB_INFO("Welcome to the Bare Bones engine!");

	auto app = BareBones::CreateApplication();
	app->Run();
	delete app;
}

#endif