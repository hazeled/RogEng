#pragma once
#include "entity.hpp"
namespace RE {
/**************************************************
 * Implementation of a single scene.
 *
 * Contains an entity component manager.
 */
class Scene {
public:
  Scene();
  RE_::EntityManager* EntityManager;

private:
};
} // namespace RE
