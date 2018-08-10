if (NOT FIPS_IMPORT)
    cmake_minimum_required(VERSION 2.8)
    get_filename_component(FIPS_ROOT_DIR "../fips" ABSOLUTE)
    include("${FIPS_ROOT_DIR}/cmake/fips.cmake")
    fips_setup()
    fips_project(fips-miniclib)
endif()

if ((FIPS_MACOS OR FIPS_WINDOWS OR FIPS_LINUX) AND NOT (FIPS_RASPBERRYPI OR FIPS_OSX_USE_ARC OR FIPS_UWP))

     fips_begin_lib(miniclib)



    if (UNIX)
        find_package (Threads REQUIRED)
    endif ()

    file(GLOB CORE_SRC
        "miniclib/Container/*.h"
        "miniclib/Container/*.cpp"
        "miniclib/Core/*.h"
        "miniclib/Core/*.cpp"
        "miniclib/IO/*.h"
        "miniclib/IO/*.cpp"
        "miniclib/Math/*.h"
        "miniclib/Math/*.cpp"
        "miniclib/LZ4/*.h"
        "miniclib/LZ4/*.c"
        )


    include_directories("miniclib")
    fips_src(miniclib RECURSE)

    fips_end_lib()

    #add_library(miniclib ${CORE_SRC})

    #source_group("Common" FILES ${CORE_SRC})
    #source_group("Dxf" FILES ${DXFIO_SRC})

    add_definitions(-DMINI_URHO -DMINICLIB_LOGGING -DMINICLIB_IS_BUILDING)
    set_target_properties(miniclib PROPERTIES LINKER_LANGUAGE CXX)


     if (MSVC)
        string(REPLACE "/WX" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
        string(REPLACE "/WX" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
            target_link_libraries(miniclib winmm.lib)
    endif(MSVC)


    if (UNIX)
        target_link_libraries (miniclib ${CMAKE_THREAD_LIBS_INIT})
    endif ()



endif()

if (NOT FIPS_IMPORT)
    fips_finish()
endif()