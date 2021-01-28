CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
PROJECT(Hippy)

INCLUDE(CMakeModules/CPM.cmake)

CPMAddPackage(
        NAME Doryen
        VERSION 2021.0124
        GITHUB_REPOSITORY Andres6936/Doryen
)

ADD_SUBDIRECTORY(Dependency/Hippy.Layout)

#[[ This sets an header-only project.

Don't worry, no actual binaries will be generated if you should try and build it.
The command <SET_TARGET_PROPERTIES> is there because CMake will otherwise complain
that it cannot infer the target language from .hpp files only.
]]
ADD_LIBRARY(Hippy.Doryen INTERFACE)
ADD_LIBRARY(Hippy::Doryen ALIAS Hippy.Doryen)
# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
TARGET_INCLUDE_DIRECTORIES(Hippy.Doryen INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>)
# Support to compiler on mode C++ 17 standard.
TARGET_COMPILE_FEATURES(Hippy.Doryen INTERFACE cxx_std_17)
# Needed the Doryen Framework because it is used in the header, needed mark PUBLIC
# the link to library, but Hippy.Doryen it is a INTERFACE so that is most important
# mark INTERFACE over PUBLIC
TARGET_LINK_LIBRARIES(Hippy.Doryen INTERFACE Doryen::Framework)

ADD_EXECUTABLE(Hippy.Doryen.App
        Source/App.cpp
        Source/Frame.cpp
        Source/Layoutable.cpp)
SET_TARGET_PROPERTIES(Hippy.Doryen.App PROPERTIES CXX_STANDARD 17)
TARGET_LINK_LIBRARIES(Hippy.Doryen.App PRIVATE Hippy::Doryen)
TARGET_LINK_LIBRARIES(Hippy.Doryen.App PRIVATE Hippy::Flex)

ADD_SUBDIRECTORY(Test/)