# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build"

# Include any dependencies generated for this target.
include CMakeFiles/MeshViewer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MeshViewer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MeshViewer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MeshViewer.dir/flags.make

CMakeFiles/MeshViewer.dir/codegen:
.PHONY : CMakeFiles/MeshViewer.dir/codegen

CMakeFiles/MeshViewer.dir/main.cpp.o: CMakeFiles/MeshViewer.dir/flags.make
CMakeFiles/MeshViewer.dir/main.cpp.o: /Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1\ 2/main.cpp
CMakeFiles/MeshViewer.dir/main.cpp.o: CMakeFiles/MeshViewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MeshViewer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MeshViewer.dir/main.cpp.o -MF CMakeFiles/MeshViewer.dir/main.cpp.o.d -o CMakeFiles/MeshViewer.dir/main.cpp.o -c "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/main.cpp"

CMakeFiles/MeshViewer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MeshViewer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/main.cpp" > CMakeFiles/MeshViewer.dir/main.cpp.i

CMakeFiles/MeshViewer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MeshViewer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/main.cpp" -o CMakeFiles/MeshViewer.dir/main.cpp.s

CMakeFiles/MeshViewer.dir/myHalfedge.cpp.o: CMakeFiles/MeshViewer.dir/flags.make
CMakeFiles/MeshViewer.dir/myHalfedge.cpp.o: /Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1\ 2/myHalfedge.cpp
CMakeFiles/MeshViewer.dir/myHalfedge.cpp.o: CMakeFiles/MeshViewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MeshViewer.dir/myHalfedge.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MeshViewer.dir/myHalfedge.cpp.o -MF CMakeFiles/MeshViewer.dir/myHalfedge.cpp.o.d -o CMakeFiles/MeshViewer.dir/myHalfedge.cpp.o -c "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myHalfedge.cpp"

CMakeFiles/MeshViewer.dir/myHalfedge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MeshViewer.dir/myHalfedge.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myHalfedge.cpp" > CMakeFiles/MeshViewer.dir/myHalfedge.cpp.i

CMakeFiles/MeshViewer.dir/myHalfedge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MeshViewer.dir/myHalfedge.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myHalfedge.cpp" -o CMakeFiles/MeshViewer.dir/myHalfedge.cpp.s

CMakeFiles/MeshViewer.dir/myVector3D.cpp.o: CMakeFiles/MeshViewer.dir/flags.make
CMakeFiles/MeshViewer.dir/myVector3D.cpp.o: /Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1\ 2/myVector3D.cpp
CMakeFiles/MeshViewer.dir/myVector3D.cpp.o: CMakeFiles/MeshViewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MeshViewer.dir/myVector3D.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MeshViewer.dir/myVector3D.cpp.o -MF CMakeFiles/MeshViewer.dir/myVector3D.cpp.o.d -o CMakeFiles/MeshViewer.dir/myVector3D.cpp.o -c "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myVector3D.cpp"

CMakeFiles/MeshViewer.dir/myVector3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MeshViewer.dir/myVector3D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myVector3D.cpp" > CMakeFiles/MeshViewer.dir/myVector3D.cpp.i

CMakeFiles/MeshViewer.dir/myVector3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MeshViewer.dir/myVector3D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myVector3D.cpp" -o CMakeFiles/MeshViewer.dir/myVector3D.cpp.s

CMakeFiles/MeshViewer.dir/myPoint3D.cpp.o: CMakeFiles/MeshViewer.dir/flags.make
CMakeFiles/MeshViewer.dir/myPoint3D.cpp.o: /Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1\ 2/myPoint3D.cpp
CMakeFiles/MeshViewer.dir/myPoint3D.cpp.o: CMakeFiles/MeshViewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MeshViewer.dir/myPoint3D.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MeshViewer.dir/myPoint3D.cpp.o -MF CMakeFiles/MeshViewer.dir/myPoint3D.cpp.o.d -o CMakeFiles/MeshViewer.dir/myPoint3D.cpp.o -c "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myPoint3D.cpp"

CMakeFiles/MeshViewer.dir/myPoint3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MeshViewer.dir/myPoint3D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myPoint3D.cpp" > CMakeFiles/MeshViewer.dir/myPoint3D.cpp.i

CMakeFiles/MeshViewer.dir/myPoint3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MeshViewer.dir/myPoint3D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myPoint3D.cpp" -o CMakeFiles/MeshViewer.dir/myPoint3D.cpp.s

CMakeFiles/MeshViewer.dir/myFace.cpp.o: CMakeFiles/MeshViewer.dir/flags.make
CMakeFiles/MeshViewer.dir/myFace.cpp.o: /Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1\ 2/myFace.cpp
CMakeFiles/MeshViewer.dir/myFace.cpp.o: CMakeFiles/MeshViewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MeshViewer.dir/myFace.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MeshViewer.dir/myFace.cpp.o -MF CMakeFiles/MeshViewer.dir/myFace.cpp.o.d -o CMakeFiles/MeshViewer.dir/myFace.cpp.o -c "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myFace.cpp"

CMakeFiles/MeshViewer.dir/myFace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MeshViewer.dir/myFace.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myFace.cpp" > CMakeFiles/MeshViewer.dir/myFace.cpp.i

CMakeFiles/MeshViewer.dir/myFace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MeshViewer.dir/myFace.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myFace.cpp" -o CMakeFiles/MeshViewer.dir/myFace.cpp.s

CMakeFiles/MeshViewer.dir/myMesh.cpp.o: CMakeFiles/MeshViewer.dir/flags.make
CMakeFiles/MeshViewer.dir/myMesh.cpp.o: /Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1\ 2/myMesh.cpp
CMakeFiles/MeshViewer.dir/myMesh.cpp.o: CMakeFiles/MeshViewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MeshViewer.dir/myMesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MeshViewer.dir/myMesh.cpp.o -MF CMakeFiles/MeshViewer.dir/myMesh.cpp.o.d -o CMakeFiles/MeshViewer.dir/myMesh.cpp.o -c "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myMesh.cpp"

CMakeFiles/MeshViewer.dir/myMesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MeshViewer.dir/myMesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myMesh.cpp" > CMakeFiles/MeshViewer.dir/myMesh.cpp.i

CMakeFiles/MeshViewer.dir/myMesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MeshViewer.dir/myMesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myMesh.cpp" -o CMakeFiles/MeshViewer.dir/myMesh.cpp.s

CMakeFiles/MeshViewer.dir/myVertex.cpp.o: CMakeFiles/MeshViewer.dir/flags.make
CMakeFiles/MeshViewer.dir/myVertex.cpp.o: /Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1\ 2/myVertex.cpp
CMakeFiles/MeshViewer.dir/myVertex.cpp.o: CMakeFiles/MeshViewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MeshViewer.dir/myVertex.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MeshViewer.dir/myVertex.cpp.o -MF CMakeFiles/MeshViewer.dir/myVertex.cpp.o.d -o CMakeFiles/MeshViewer.dir/myVertex.cpp.o -c "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myVertex.cpp"

CMakeFiles/MeshViewer.dir/myVertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MeshViewer.dir/myVertex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myVertex.cpp" > CMakeFiles/MeshViewer.dir/myVertex.cpp.i

CMakeFiles/MeshViewer.dir/myVertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MeshViewer.dir/myVertex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/myVertex.cpp" -o CMakeFiles/MeshViewer.dir/myVertex.cpp.s

# Object files for target MeshViewer
MeshViewer_OBJECTS = \
"CMakeFiles/MeshViewer.dir/main.cpp.o" \
"CMakeFiles/MeshViewer.dir/myHalfedge.cpp.o" \
"CMakeFiles/MeshViewer.dir/myVector3D.cpp.o" \
"CMakeFiles/MeshViewer.dir/myPoint3D.cpp.o" \
"CMakeFiles/MeshViewer.dir/myFace.cpp.o" \
"CMakeFiles/MeshViewer.dir/myMesh.cpp.o" \
"CMakeFiles/MeshViewer.dir/myVertex.cpp.o"

# External object files for target MeshViewer
MeshViewer_EXTERNAL_OBJECTS =

MeshViewer: CMakeFiles/MeshViewer.dir/main.cpp.o
MeshViewer: CMakeFiles/MeshViewer.dir/myHalfedge.cpp.o
MeshViewer: CMakeFiles/MeshViewer.dir/myVector3D.cpp.o
MeshViewer: CMakeFiles/MeshViewer.dir/myPoint3D.cpp.o
MeshViewer: CMakeFiles/MeshViewer.dir/myFace.cpp.o
MeshViewer: CMakeFiles/MeshViewer.dir/myMesh.cpp.o
MeshViewer: CMakeFiles/MeshViewer.dir/myVertex.cpp.o
MeshViewer: CMakeFiles/MeshViewer.dir/build.make
MeshViewer: /opt/homebrew/lib/libglut.dylib
MeshViewer: /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework
MeshViewer: /opt/homebrew/lib/libGLEW.2.2.0.dylib
MeshViewer: /opt/homebrew/lib/libglm.dylib
MeshViewer: CMakeFiles/MeshViewer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable MeshViewer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MeshViewer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MeshViewer.dir/build: MeshViewer
.PHONY : CMakeFiles/MeshViewer.dir/build

CMakeFiles/MeshViewer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MeshViewer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MeshViewer.dir/clean

CMakeFiles/MeshViewer.dir/depend:
	cd "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2" "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2" "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build" "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build" "/Users/thibault/Documents/ESIEE/Semestre5/GeometricModeling/TP1/TP1 2/build/CMakeFiles/MeshViewer.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/MeshViewer.dir/depend

