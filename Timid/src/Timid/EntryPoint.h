#pragma once

#ifdef TMD_PLATFORM_WINDOWS

extern Timid::Application* Timid::CreateApplication();

int main(int argc, char** argv) 
{
	Timid::Log::Init();
	TMD_CORE_WARN("Initialized Log!");
	int a = 5;
	TMD_INFO("Hello Timid! Test Var={0}", a);

	auto app = Timid::CreateApplication();
	app->Run();
	delete app;
}

#endif