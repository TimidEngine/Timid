#pragma once

#ifdef TMD_PLATFORM_WINDOWS

extern Timid::Application* Timid::CreateApplication();

int main(int argc, char** argv) {
	auto app = Timid::CreateApplication();
	app->Run();
	delete app;
}

#endif