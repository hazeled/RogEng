#pragma once
#include "context.hpp"
#include "core.hpp"
#include "entity.hpp"
#include "logging.hpp"
#include "scene.hpp"

namespace RE {
/**************************************************
 * Initialize all of RogEng. Must be called only once.
 *
 * @return Non-zero if initialization error
 */
int  Initialize();
void Exit();
} // namespace RE
