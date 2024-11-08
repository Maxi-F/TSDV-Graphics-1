#pragma once
#include "ExportHeader.h"
#include "Entity2D.h"

namespace GuichernoEngine {
	class GUICHERNO_API CollisionManager {
	public:
		static bool CheckCollision(Entity2D* anEntity, Entity2D* otherEntity);
	};
}
