#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>
namespace RE {
using EntityId = std::uint32_t;
} // namespace RE
namespace RE_ {
/**************************************************
 * Internal entity class, used by EntityManager
 */
struct Entity {
  std::size_t       data_size;  // The size of the total data
  void*             data;       // All component data
  std::vector<bool> components; // A bitset of the length of all components
};
/**************************************************
 * Entity Manager class, used in scenes to manage entities
 */
class EntityManager {
public:
  EntityManager();

private:
};
} // namespace RE_
