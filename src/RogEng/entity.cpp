#include "entity.hpp"
#include <cstdlib>

RE_::TypeId RE_::EntityManager::registeredTypeCount = 0;
std::vector<RE_::RegisteredTypeDescriptor> RE_::EntityManager::registeredTypes =
    std::vector<RE_::RegisteredTypeDescriptor>();

RE_::EntityManager::EntityManager() {}
RE::EntityId RE_::EntityManager::CreateEntity() {
  entities.push_back((RE_::EntityDescriptor){});
  return entityCount++;
}
bool RE_::EntityManager::IsTypeIdRegistered(RE_::TypeId typeId) {
  return registeredTypeCount > typeId;
}
void RE_::EntityManager::RegisterType(RE_::TypeId typeId,
                                      std::size_t typeSize) {
  registeredTypes.push_back((RE_::RegisteredTypeDescriptor){.size = typeSize});
}
size_t RE_::EntityManager::GetTypeSize(RE_::TypeId typeId) {
  return registeredTypes[typeId].size;
}
void* RE_::EntityManager::PutTypeId(RE::EntityId entityId, RE_::TypeId typeId) {
  entities[entityId].componentDescriptors.push_back((ComponentDescriptor){
      .typeId = typeId, .data = malloc(GetTypeSize(typeId))});
  return entities[entityId].componentDescriptors.back().data;
};
// Could be optimized with a variable-size bitset (std::vector<bool>), but would
// require non-staticing the type functions
bool RE_::EntityManager::HasTypeId(RE::EntityId entityId, RE_::TypeId typeId) {
  for (auto component : entities[entityId].componentDescriptors) {
    if (component.typeId == typeId) {
      return true;
    }
  }
  return false;
};

void* RE_::EntityManager::GetTypeId(RE::EntityId entityId, RE_::TypeId typeId) {
  for (auto& component : entities[entityId].componentDescriptors) {
    if (component.typeId == typeId) {
      return component.data;
    }
  }
  return nullptr;
}
