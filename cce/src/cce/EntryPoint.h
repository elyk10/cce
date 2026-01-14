#pragma once

#ifdef CCE_PLATFORM_WINDOWS

extern Cce::Application* Cce::CreateApplication();

int main(int argc, char** argv)
{
	Cce::Log::Init();
	CCE_CORE_WARN("Initialized Log!");
	int a = 5;
	CCE_INFO("Hello Var={0}", a);

	
	auto app = Cce::CreateApplication();
	app->Run();
	delete app;
}

#endif