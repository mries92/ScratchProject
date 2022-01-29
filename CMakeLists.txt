cmake_minimum_required(VERSION 3.0.0)
project(Incursion VERSION 0.1.0)
set(CMAKE_CXX_FLAGS "-fsanitize=address -fsanitize=undefined -O1")
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
#add_compile_options(-Wall -Wextra -pedantic -Werror)

# ------------------- #
# ------ Linux ------ #
# ------------------- #
if(UNIX)
    set(LibDir "/home/mike/lib")
    set(GitDir "/home/mike/git")

    # Editor include
    include_directories(SYSTEM
        #${GitDir}/stb
        ${GitDir}/sol2/include
    )

    link_directories(
        /usr/lib
    )

    add_executable(Incursion 
        main.cpp
        game.cpp
        asset_manager.cpp
        lua_bootstrap.cpp
        lua_data.cpp
    )

    target_include_directories(Incursion PUBLIC
        ./
    )

    target_link_directories(Incursion PUBLIC
        /usr/local/lib
    )
endif(UNIX)

target_link_libraries(Incursion lua dl pthread)
set_property(TARGET Incursion PROPERTY CXX_STANDARD 20)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

file(COPY ./assets DESTINATION ../build/)