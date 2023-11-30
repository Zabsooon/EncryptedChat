cmake_minimum_required(VERSION 3.16)
project(ChatApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(asio CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenSSL CONFIG REQUIRED)

add_executable(${PROJECT_NAME}
    app/exampleMain.cpp

    include/networking/TcpClient.hpp
    include/networking/TcpConnection.hpp
    include/networking/TcpServer.hpp
    src/networking/TcpClient.cpp
    src/networking/TcpConnection.cpp
    src/networking/TcpServer.cpp

    include/gui/UseImGui.hpp
    src/gui/UseImGui.cpp
    src/gui/bindings/imgui_impl_glfw.cpp
    src/gui/bindings/imgui_impl_opengl3.cpp
    include/gui/bindings/imgui_impl_glfw.h
    include/gui/bindings/imgui_impl_opengl3.h
    include/gui/bindings/imgui_impl_opengl3_loader.h
)

target_link_libraries(${PROJECT_NAME} asio::asio)
target_link_libraries(${PROJECT_NAME} imgui::imgui)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} openssl::openssl)
