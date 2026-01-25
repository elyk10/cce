#include <Cce.h>

class ExampleLayer : public Cce::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void onUpdate() override
	{
		//CCE_INFO("ExampleLayer::Update");
	}

	void onEvent(Cce::Event& event) override
	{
		CCE_INFO("{0}", event.toString());
	}
};

class Sandbox : public Cce::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
		pushOverlay(new Cce::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Cce::Application* Cce::CreateApplication()
{
	return new Sandbox();
}
