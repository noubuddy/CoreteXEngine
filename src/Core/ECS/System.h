#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include "Types.h"
#include <set>


class System
{
public:
	std::set<Entity> mEntities;
};

#endif