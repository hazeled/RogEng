CMAKE_MINIMUM_REQUIRED(VERSION 3.18)
PROJECT("RogEng")
OPTION(Global "Global" OFF)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_CXX_STANDARD 20)
ADD_LIBRARY(RogEng "${SRC}")
SET(SRC
    src/RogEng/RE.cpp
    src/RogEng/context.cpp
    src/RogEng/scene.cpp
    src/RogEng/entity.cpp
    src/RogEng/logging.cpp)
SET(PUBLIC_HEADERS
    src/RogEng/RE.hpp
    src/RogEng/context.hpp
    src/RogEng/scene.hpp
    src/RogEng/entity.hpp
    src/RogEng/core.hpp
    src/RogEng/logging.hpp)
SET(MAIN_HEADER
    src/RogEng.hpp)
TARGET_SOURCES(RogEng PRIVATE
    ${SRC}
    ${PUBLIC_HEADERS})
FILE(COPY ${MAIN_HEADER} DESTINATION ${CMAKE_BINARY_DIR}/include/)
FILE(COPY ${PUBLIC_HEADERS} DESTINATION ${CMAKE_BINARY_DIR}/include/RogEng)
INSTALL(FILES ${PUBLIC_HEADERS} DESTINATION include/RogEng)
INSTALL(FILES ${MAIN_HEADER} DESTINATION include/)
INSTALL(TARGETS RogEng LIBRARY DESTINATION lib)

