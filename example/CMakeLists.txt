set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

###
add_executable(RadialExample_noParent
    main.cpp
    res.qrc
)    
target_link_libraries(RadialExample_noParent PRIVATE Qt${QT_VERSION_MAJOR}::Widgets RadialPopMenu)    

###
add_executable(RadialExample_withParent
    main2.cpp
    res.qrc
)    
target_link_libraries(RadialExample_withParent PRIVATE Qt${QT_VERSION_MAJOR}::Widgets RadialPopMenu)    

###
add_library(RadialExampleLib 
    RadialMenuExample.cpp
    RadialMenuExample.h
    res.qrc
)
target_link_libraries(RadialExampleLib 
    PRIVATE 
        Qt${QT_VERSION_MAJOR}::Widgets 
    PUBLIC 
        RadialPopMenu)    

###
add_executable(RadialPopMenuExample3
    main3.cpp
)    
target_link_libraries(RadialPopMenuExample3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets RadialExampleLib)    
