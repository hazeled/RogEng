#define CATCH_CONFIG_MAIN
#include <RogEng.hpp>
#include <catch2/catch.hpp>

TEST_CASE("ECS entity id", "[entity]") {
  RE_::EntityManager ecs = RE_::EntityManager();
  RE::EntityId       entity0 = ecs.CreateEntity();
  RE::EntityId       entity1 = ecs.CreateEntity();
  REQUIRE(entity0 == 0); // First entity, id should be 0
  REQUIRE(entity1 == 1); // Second entity, id should be 1
}

TEST_CASE("ECS entity assignement", "[entity]") {
  struct testStruct {
    int x, y, z;
  };
  RE_::EntityManager ecs = RE_::EntityManager();
  RE::EntityId       e = ecs.CreateEntity();
  testStruct*        t = ecs.Put<testStruct>(e);
  t->x = 15;
  testStruct* t2 = ecs.Get<testStruct>(e);
  REQUIRE(t == t2);
  REQUIRE(t2->x == 15);
}
