CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
PROJECT(Hippy)

INCLUDE(CMakeModules/CPM.cmake)

CPMAddPackage(
        NAME Doryen
        VERSION 2021.0131
        GITHUB_REPOSITORY Andres6936/Doryen
)

CPMAddPackage(
        NAME HippyFlex
        VERSION 2021.0108
        GITHUB_REPOSITORY Andres6936/Hippy.Flex
)

#[[ This sets an header-only project.

Don't worry, no actual binaries will be generated if you should try and build it.
The command <SET_TARGET_PROPERTIES> is there because CMake will otherwise complain
that it cannot infer the target language from .hpp files only.
]]
ADD_LIBRARY(Hippy.Doryen STATIC
        Source/Frame.cpp
        Source/Layoutable.cpp
        )
ADD_LIBRARY(Hippy::Doryen ALIAS Hippy.Doryen)
# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
TARGET_INCLUDE_DIRECTORIES(Hippy.Doryen PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>)
# Support to compiler on mode C++ 17 standard.
SET_TARGET_PROPERTIES(Hippy.Doryen PROPERTIES CXX_STANDARD 17)
# Needed the Doryen Framework and Hippy Flex, because it libraries are used in
# the header needed mark PUBLIC the link to library for avoid undefined references.
TARGET_LINK_LIBRARIES(Hippy.Doryen PUBLIC Hippy::Flex)
TARGET_LINK_LIBRARIES(Hippy.Doryen PUBLIC Doryen::Framework)

ADD_EXECUTABLE(Hippy.Doryen.App Source/App.cpp)
SET_TARGET_PROPERTIES(Hippy.Doryen.App PROPERTIES CXX_STANDARD 17)
TARGET_LINK_LIBRARIES(Hippy.Doryen.App PRIVATE Hippy::Doryen)

ADD_SUBDIRECTORY(Test/)