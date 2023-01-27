#pragma once
#include "Core.h";

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();
		void Run();
		virtual ~Application();

	private:

	};

	Application* CreateApplication();
};

