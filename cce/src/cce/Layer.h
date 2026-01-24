#pragma once

#include "cce/Core.h"
#include "cce/Events/Event.h"

namespace Cce
{
	class CCE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};
}

