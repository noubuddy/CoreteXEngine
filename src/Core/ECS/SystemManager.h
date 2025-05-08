#ifndef ECS_SYSTEM_MANAGER_H
#define ECS_SYSTEM_MANAGER_H

#include "System.h"
#include "Types.h"
#include <cassert>
#include <memory>
#include <unordered_map>
#include "../Systems/CameraControlSystem.h"
#include "../Data/String.h"

class SystemManager
{
public:
	template<typename T>
	std::shared_ptr<T> RegisterSystem()
	{
		core::String typeName = typeid(T).name();

		assert(m_systems.find(typeName) == m_systems.end() && "Registering system more than once.");

		std::shared_ptr<CameraControlSystem> system = std::make_shared<CameraControlSystem>();
		
		m_systems.insert(std::make_pair(typeName, std::static_pointer_cast<System>(system)));
		return system;
	}

	// template<typename T>
	// std::shared_ptr<T> GetSystem()
	// {
	// 	return m_systems.at(typeid(T).name());
	// }

	template<typename T>
	void SetSignature(Signature signature)
	{
		core::String typeName = typeid(T).name();

		assert(m_systems.find(typeName) != m_systems.end() && "System used before registered.");

		m_signatures.insert({typeName, signature});
	}

	void EntityDestroyed(Entity t_entity)
	{
		for (auto const& pair : m_systems)
		{
			auto const& system = pair.second;


			system->entities.erase(t_entity);
		}
	}

	void EntitySignatureChanged(Entity t_entity, Signature t_entity_signature)
	{
		for (auto const& pair : m_systems)
		{
			auto const& type = pair.first;
			auto const& system = pair.second;
			auto const& systemSignature = m_signatures[type];

			if ((t_entity_signature & systemSignature) == systemSignature)
			{
				system->entities.insert(t_entity);
			}
			else
			{
				system->entities.erase(t_entity);
			}
		}
	}

private:
	std::unordered_map<core::String, Signature> m_signatures{};
	std::unordered_map<core::String, std::shared_ptr<System>> m_systems{};
};

#endif