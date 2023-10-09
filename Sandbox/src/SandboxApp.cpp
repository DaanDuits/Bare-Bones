#include <BareBones.h>

class Sandbox : public BareBones::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

BareBones::Application* BareBones::CreateApplication()
{
	return new Sandbox();
}