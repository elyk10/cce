#pragma once

#include "cce/Layer.h"

namespace Cce
{


	class CCE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& event);

	private:
		float m_Time = 0.0f;
	};

}
