#include "bbpch.h"
#include "Application.h"

#include "BareBones/Events/ApplicationEvent.h"
#include "BareBones/Log.h"

#include "GLFW/glfw3.h"

namespace BareBones {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.95, 0.9, 0.9, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}