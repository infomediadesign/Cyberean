﻿cmake_minimum_required(VERSION 3.11)

include(../cmake/raylib.cmake)

project(game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cpp ../Library/tileson.hpp masterhead.h mainmenu.cpp mainmenu.h musicplayer.cpp musicplayer.h gameszene.cpp gameszene.h player.cpp player.h gameobject.cpp gameobject.h Enemy.cpp Enemy.h pausescreen.h pausescreen.cpp SoundPlayer.cpp SoundPlayer.h mastervolumecontroll.cpp mastervolumecontroll.h levelselect.cpp levelselect.h credits.cpp credits.h cutscene.cpp cutscene.h masterhead.cpp gameoverscreen.h gameoverscreen.cpp storymode.cpp storymode.h cutscene2.cpp cutscene2.h cutscene3.cpp cutscene3.h cutscene4.cpp cutscene4.h cutscene5.cpp cutscene5.h epilogue.cpp epilogue.h
        TextureManager.h
        TextureManager.cpp)

# Add config.h.in file
configure_file(config.h.in config.h)
target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

#  Link to Raylib
target_link_libraries(${PROJECT_NAME} raylib)

# Copy assets to assets path
add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_LIST_DIR}/../cmake/copy-assets.cmake"
        )
add_dependencies(${PROJECT_NAME} copy_assets)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()

# CPack instructions
# call e.g. cpack -G ZIP -C Debug to create a binary distribution
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${PROJECT_NAME}_Bundle")
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/assets" DESTINATION "${PROJECT_NAME}_Bundle")