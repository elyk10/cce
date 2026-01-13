#include <Cce.h>

class Sandbox : public Cce::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Cce::Application* Cce::CreateApplication()
{
	return new Sandbox();
}
