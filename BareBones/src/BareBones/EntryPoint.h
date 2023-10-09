#pragma once

#ifdef BB_PLATFORM_WINDOWS

extern BareBones::Application* BareBones::CreateApplication();

int main(int argc, char** argv)
{
	auto app = BareBones::CreateApplication();
	app->Run();
	delete app;
}

#endif