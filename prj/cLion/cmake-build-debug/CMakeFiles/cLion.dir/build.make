# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cLion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cLion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cLion.dir/flags.make

CMakeFiles/cLion.dir/main.cpp.o: CMakeFiles/cLion.dir/flags.make
CMakeFiles/cLion.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cLion.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cLion.dir/main.cpp.o -c /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion/main.cpp

CMakeFiles/cLion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cLion.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion/main.cpp > CMakeFiles/cLion.dir/main.cpp.i

CMakeFiles/cLion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cLion.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion/main.cpp -o CMakeFiles/cLion.dir/main.cpp.s

CMakeFiles/cLion.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/cLion.dir/main.cpp.o.requires

CMakeFiles/cLion.dir/main.cpp.o.provides: CMakeFiles/cLion.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/cLion.dir/build.make CMakeFiles/cLion.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/cLion.dir/main.cpp.o.provides

CMakeFiles/cLion.dir/main.cpp.o.provides.build: CMakeFiles/cLion.dir/main.cpp.o


# Object files for target cLion
cLion_OBJECTS = \
"CMakeFiles/cLion.dir/main.cpp.o"

# External object files for target cLion
cLion_EXTERNAL_OBJECTS =

cLion: CMakeFiles/cLion.dir/main.cpp.o
cLion: CMakeFiles/cLion.dir/build.make
cLion: CMakeFiles/cLion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cLion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cLion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cLion.dir/build: cLion

.PHONY : CMakeFiles/cLion.dir/build

CMakeFiles/cLion.dir/requires: CMakeFiles/cLion.dir/main.cpp.o.requires

.PHONY : CMakeFiles/cLion.dir/requires

CMakeFiles/cLion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cLion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cLion.dir/clean

CMakeFiles/cLion.dir/depend:
	cd /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion/cmake-build-debug /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion/cmake-build-debug /Users/ShiHua/Downloads/workspace/client_cross_logic/prj/cLion/cmake-build-debug/CMakeFiles/cLion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cLion.dir/depend

