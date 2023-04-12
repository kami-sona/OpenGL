# What is this

This is my own learning progress of OpenGL by using glfw,imgui and other third libraries.

# How to build it

1.create a folder named OpenGL

2.In OpnGL create source and build two folders

3.In top level, using this command

```sh
git clone https://github.com/kami-sona/OpenGL.git source/
git submodule upgrade --init
```

4.The use CMake Create project

5.In build directory, using this command

```shell
cmake ../source
cmake --build .
```

6.This will create a project and compile it. In windows,if you use Visual studio, you can see .sln project

