#pragma once

#ifdef CCE_PLATFORM_WINDOWS

extern Cce::Application* Cce::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Cce::CreateApplication();
	app->Run();
	delete app;
}

#endif