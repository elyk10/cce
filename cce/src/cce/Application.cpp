#include "ccepch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "cce/Log.h"

namespace Cce
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (true)
		{
			m_Window->onUpdate();
		}
	}
}
