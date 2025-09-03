cmake_minimum_required(VERSION 3.26)
project(LegacyPlusPlus VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

file(GLOB_RECURSE LegacyPlusPlusSrc CONFIGURE_DEPENDS
        "src/*.h"
        "src/*.cpp"
)

find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

# NFD
# note: leftover from when I was using ImGui... is it really needed?
FetchContent_Declare(
        nfd
        GIT_REPOSITORY https://github.com/btzy/nativefiledialog-extended.git
        GIT_TAG        master
)
FetchContent_MakeAvailable(nfd)

# libLCE
FetchContent_Declare(
        libLCE
        GIT_REPOSITORY https://github.com/DexrnZacAttack/libLCE.git
        GIT_TAG        main
)
FetchContent_MakeAvailable(nfd)

include_directories("src")

qt_add_executable(LegacyPlusPlus
        ${LegacyPlusPlusSrc}
)

target_link_libraries(${PROJECT_NAME} PRIVATE libLCE nfd)
