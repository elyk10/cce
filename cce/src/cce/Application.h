#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"


namespace Cce {
	
	class CCE_API Application
	{
	public:
		Application();
		virtual ~Application(); 

		void Run();

		void onEvent(Event& e);

	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;

		bool m_Running = true;
	};

	// to be defined in client
	Application* CreateApplication();
}

