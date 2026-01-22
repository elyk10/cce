#include "ccepch.h"
#include "Application.h"

#include "cce/Log.h"

namespace Cce
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application()
	{

	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
		
		CCE_CORE_TRACE("{0}", e);
	}


	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->onUpdate();
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		std::cout << "hellow" << std::endl;
		return true;
	}
}
