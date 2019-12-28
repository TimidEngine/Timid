#include <Timid.h>

class Sandbox : public Timid::Application {
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{
	
	}
};

Timid::Application* Timid::CreateApplication() {
	return new Sandbox();
}