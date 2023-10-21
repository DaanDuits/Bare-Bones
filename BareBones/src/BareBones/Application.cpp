#include "Application.h"

#include "BareBones/Events/ApplicationEvent.h"
#include "BareBones/Log.h"

namespace BareBones {
	Application::Application()
	{

	}
	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		BB_TRACE(e);

		while (true);
	}
}