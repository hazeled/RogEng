#include "scene.hpp"
#include "logging.hpp"

RE::Scene::Scene() {
  EntityManager = RE_::EntityManager();
  RE__LOG_INFO("Scene created\n");
}
