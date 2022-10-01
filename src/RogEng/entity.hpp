#pragma once

/* TODO: Refractor void* to std::any */

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <vector>
namespace RE {
using EntityId = std::uint32_t;
using ComponentId = std::uint32_t;
} // namespace RE
namespace RE_ {
using TypeId = std::uint32_t;
struct ComponentDescriptor {
  RE::ComponentId typeId;
  void*           data;
};
/**************************************************
 * Internal entity class, used by EntityManager
 */
struct EntityDescriptor {
  std::vector<ComponentDescriptor> componentDescriptors;
};
/**************************************************
 * Internal type descriptor, used for registering types
 */
struct RegisteredTypeDescriptor {
  // RE_::TypeId type;
  std::size_t size;
};
/**************************************************
 * Entity Manager class, used in scenes to manage entities
 */
class EntityManager {
public:
  EntityManager();
  /**************************************************
   * Creates a new empty entity and returns the id
   *
   * @return The newly created entity ID
   */
  RE::EntityId CreateEntity();

  // Template functions defined in header. Forwards to other functions
  /***************************************************
   * Puts a component (Of type T) into the entity specified by entityId
   *
   * @param T the type of the component to put into the entity
   * @param entityId The entity id of the entity to put the struct in
   */
  template <typename T> T* Put(RE::EntityId entityId) {
    return (T*)PutTypeId(entityId, GetTypeId<T>());
  };
  /***************************************************
   * Returns true if a component (Of type T) is part of the entity specified by
   * entityId otherwise, returns false
   *
   * @param T the type of the component to put into the entity
   * @param entityId The entity id of the entity to put the struct in
   * @return True if the entity has the component specified
   */
  template <typename T> bool Has(RE::EntityId entityId) {
    return HasTypeId(entityId, GetTypeId<T>());
  };
  /***************************************************
   * Returns a reference to the component specified by type T, or a nullptr if
   * it doesn't exist inside of the entity
   *
   * @param T the type of the component to return from the entity
   * @param entityId The entity id of the entity containing the component
   * @return A reference to the component, or a nullptr
   */
  template <typename T> T* Get(RE::EntityId entityId) {
    return (T*)GetTypeId(entityId, GetTypeId<T>());
  };

private:
  // Type registration
  template <typename T> static inline RE_::TypeId GetTypeId() {
    static const RE_::TypeId id = registeredTypeCount;
    if (!IsTypeIdRegistered(id)) {
      RegisterType(id, sizeof(T));
      registeredTypeCount++;
    }
    return id;
  };
  static bool   IsTypeIdRegistered(RE_::TypeId typeId);
  static void   RegisterType(RE_::TypeId typeId, std::size_t typeSize);
  static size_t GetTypeSize(RE_::TypeId typeId);
  static std::vector<RE_::RegisteredTypeDescriptor> registeredTypes;
  static RE_::TypeId registeredTypeCount; // Defaults to 0

  void* PutTypeId(RE::EntityId entityId, RE_::TypeId typeId);
  bool  HasTypeId(RE::EntityId entityId, RE_::TypeId typeId);
  void* GetTypeId(RE::EntityId entityId, RE_::TypeId typeId);
  // Template functions defined in header
  // Will increment registeredTypeCount if not already defined
  std::vector<RE_::EntityDescriptor> entities;
  RE::EntityId                       entityCount = 0;
};
} // namespace RE_
