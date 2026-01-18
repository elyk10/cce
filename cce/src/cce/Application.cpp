#include "ccepch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "cce/Log.h"

namespace Cce
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		CCE_TRACE(e.toString());
		
		while (true);
	}
}
