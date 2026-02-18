cmake_minimum_required(VERSION 3.28)
project(Project1)

set(FILES 
    main.cpp
    Game/game.cpp
    Game/Map/map.cpp
    Game/Map/Grid/grid.cpp
    Game/Map/Grid/Moveabale/moveable.cpp
    Game/Map/Grid/Separator/separator.cpp
    Game/Map/Grid/Separator/Separator_horizontal/separator_h.cpp
    Game/Map/Grid/Separator/Separator_vertical/separator_v.cpp
    Game/Objects/object.cpp
    Game/Objects/Entity/entity.cpp
    Game/Objects/Entity/Player/player.cpp
    Game/Objects/Weapon/weapon.cpp
    Game/Objects/Weapon/Club/club.cpp
    Game/Objects/Entity/Enemy/enemy.cpp
    Game/Objects/Entity/Enemy/Ork/ork.cpp
)

add_executable(game ${FILES})

target_compile_options(game PRIVATE -fsanitize=address -g)

target_link_options(game PRIVATE -fsanitize=address)