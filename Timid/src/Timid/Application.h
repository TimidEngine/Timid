#pragma once

#include "Core.h"

namespace Timid {
	class TIMID_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be Defined in the Client
	Application* CreateApplication();
}