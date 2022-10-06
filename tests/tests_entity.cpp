#define CATCH_CONFIG_MAIN
#include <RogEng.hpp>
#include <catch2/catch.hpp>

TEST_CASE("ECS entity id", "[entity]") {
  RE_::EntityManager ecs = RE_::EntityManager();
  RE::EntityId       e = ecs.CreateEntity();
  RE::EntityId       e1 = ecs.CreateEntity();
  RE::EntityId       e2 = ecs.CreateEntity();
  REQUIRE(e == 0);  // First entity, id should be 0
  REQUIRE(e1 == 1); // First entity, id should be 0
  REQUIRE(e2 == 2); // First entity, id should be 0
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
