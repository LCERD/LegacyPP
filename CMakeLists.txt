cmake_minimum_required(VERSION 3.26)
project(LegacyPlusPlus VERSION 1.1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

file(GLOB_RECURSE LegacyPlusPlusSrc CONFIGURE_DEPENDS
        "src/*.h"
        "src/*.cpp"
)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)
qt_standard_project_setup()

option(LOCAL_LIBLCE "use local libLCE" OFF)

# NFD
# note: leftover from when I was using ImGui... is it really needed?
FetchContent_Declare(
        nfd
        GIT_REPOSITORY https://github.com/btzy/nativefiledialog-extended.git
        GIT_TAG        master
)
FetchContent_MakeAvailable(nfd)

# libLCE
if(!LOCAL_LIBLCE)
    FetchContent_Declare(
            LCE
            GIT_REPOSITORY https://github.com/DexrnZacAttack/libLCE.git
            GIT_TAG        main
    )
    FetchContent_MakeAvailable(LCE)
else()
    add_subdirectory("lib/libLCE")

    include_directories(LegacyPlusPlus PRIVATE "lib/libLCE/include")
endif()

include_directories("src")

qt_add_executable(LegacyPlusPlus
        ${LegacyPlusPlusSrc}
)

target_link_libraries(${PROJECT_NAME} PRIVATE LCE nfd Qt6::Core Qt6::Gui Qt6::Widgets)

target_compile_definitions(LegacyPlusPlus PRIVATE LPP_VERSION="${PROJECT_VERSION}")