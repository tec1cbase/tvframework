cmake_minimum_required(VERSION 2.8)
project( tvnx )

#Find pkgconfig
find_package(PkgConfig REQUIRED)

pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0 gstreamer-app-1.0 gstreamer-video-1.0)
pkg_check_modules(TCAMLIB tcam)

#Find GSTREAMER
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
add_definitions(${GSTREAMER_DEFINITIONS})
find_package(GSTREAMER REQUIRED)
include_directories( ${CMAKE_CURRENT_BINARY_DIR}  ${GSTREAMER_INCLUDE_DIRS} ${TCAM_INCLUDE_DIRS} )
add_definitions(${GSTREAMER_CFLAGS_OTHER})  
if(NOT GSTREAMER_FOUND)
    message(ERROR " GSTREAMER not found!")
endif(NOT GSTREAMER_FOUND)

#Find GLUT
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

#find GLUT_Xmu
find_package(GLUT_Xmu)

#Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

#Find OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
link_directories(${OpenCV_LIBRARY_DIRS})
if(NOT OPENCV_FOUND)
    message(ERROR " OPENCV not found!")
endif(NOT OPENGL_FOUND)

add_executable(tvnx main.cpp tcamimage.cpp tcamcamera.cpp)
TARGET_LINK_LIBRARIES(tvnx ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GSTREAMER_INCLUDE_DIRS} ${TCAM_INCLUDE_DIRS} ${OpenCV_LIBS} )
install(TARGETS tvnx RUNTIME DESTINATION bin)


