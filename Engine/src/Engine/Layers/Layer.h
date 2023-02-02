#pragma once
#include "Engine/Events/Events.h"

namespace Engine {
class ENGINE_API Layer
{
public:
	Layer(const std::string& debugName);
	virtual ~Layer();

	virtual void OnAttach() {};
	virtual void OnDetach() {};
	virtual void OnUpdate() {};
	virtual void OnEvent(Event& event) {};

	inline const std::string& GetName() const { return m_DebugName; }

private:
	std::string m_DebugName;
};
}

