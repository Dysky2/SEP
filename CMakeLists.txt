cmake_minimum_required(VERSION 3.16)

project(SEP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SEP
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        mainpage.h mainpage.cpp mainpage.ui
        user.h
        user.cpp
        admin.h admin.cpp
        mod.h mod.cpp
        teacher.h teacher.cpp

        subject.h subject.cpp
        attendanceWindow.cpp attendanceWindow.h attendanceWindow.ui
        scheduleWindow.cpp scheduleWindow.h scheduleWindow.ui
        gradesWindow.cpp gradesWindow.h gradesWindow.ui
        announcementsWindow.h announcementsWindow.cpp announcementsWindow.ui

        accountWindow.h accountWindow.cpp accountWindow.ui
        mark.h mark.cpp
        mark.h mark.cpp
        signupwindow.h signupwindow.cpp signupwindow.ui
        database.h database.cpp
        announcement.h announcement.cpp
        event.h event.cpp
        lesson.h lesson.cpp
        lesson.h lesson.cpp
        adminpanel.cpp adminpanel.h adminpanel.ui
        adminpanel.h adminpanel.cpp adminpanel.ui
        calendar.h calendar.cpp
        schedulewindow.h schedulewindow.cpp schedulewindow.ui
        schedule.h schedule.cpp
        homework.h homework.cpp
        homeworkwindow.h homeworkwindow.cpp homeworkwindow.ui
        addHomeworkDialog.h addHomeworkDialog.cpp addHomeworkDialog.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SEP APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SEP SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SEP
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SEP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SEP)
endif()
set_target_properties(SEP PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SEP
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SEP)
endif()
