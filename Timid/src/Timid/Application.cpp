#include "tmdpch.h"
#include "Application.h"

#include "Timid/Events/ApplicationEvent.h"
#include "Timid/Log.h"

namespace Timid {
	Application::Application() {

	}

	Application::~Application() {
	
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		TMD_TRACE(e);

		while (true);
	}
}