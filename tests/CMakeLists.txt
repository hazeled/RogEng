CMAKE_MINIMUM_REQUIRED(VERSION 3.18)
PROJECT("RogEng_tests")

INCLUDE(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1
)
FetchContent_MakeAvailable(Catch2)

SET(SRC
    tests_entity.cpp)

ADD_DEFINITIONS( -DCATCH_CONFIG_FAST_COMPILE )
ADD_EXECUTABLE(RogEng_tests "${SRC}")
TARGET_INCLUDE_DIRECTORIES(RogEng_tests PRIVATE ${CMAKE_SOURCE_DIRECTORY}/src/)
TARGET_LINK_LIBRARIES(RogEng_tests PRIVATE Catch2::Catch2WithMain RogEng)
