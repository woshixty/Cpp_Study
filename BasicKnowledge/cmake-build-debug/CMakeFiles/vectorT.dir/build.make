# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/vectorT.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/vectorT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vectorT.dir/flags.make

CMakeFiles/vectorT.dir/vectorT/main.cpp.o: CMakeFiles/vectorT.dir/flags.make
CMakeFiles/vectorT.dir/vectorT/main.cpp.o: ../vectorT/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vectorT.dir/vectorT/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vectorT.dir/vectorT/main.cpp.o -c /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge/vectorT/main.cpp

CMakeFiles/vectorT.dir/vectorT/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vectorT.dir/vectorT/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge/vectorT/main.cpp > CMakeFiles/vectorT.dir/vectorT/main.cpp.i

CMakeFiles/vectorT.dir/vectorT/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vectorT.dir/vectorT/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge/vectorT/main.cpp -o CMakeFiles/vectorT.dir/vectorT/main.cpp.s

# Object files for target vectorT
vectorT_OBJECTS = \
"CMakeFiles/vectorT.dir/vectorT/main.cpp.o"

# External object files for target vectorT
vectorT_EXTERNAL_OBJECTS =

vectorT: CMakeFiles/vectorT.dir/vectorT/main.cpp.o
vectorT: CMakeFiles/vectorT.dir/build.make
vectorT: CMakeFiles/vectorT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vectorT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vectorT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vectorT.dir/build: vectorT
.PHONY : CMakeFiles/vectorT.dir/build

CMakeFiles/vectorT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vectorT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vectorT.dir/clean

CMakeFiles/vectorT.dir/depend:
	cd /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge/cmake-build-debug /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge/cmake-build-debug /Users/xietingyu/Desktop/Cpp_Study/BasicKnowledge/cmake-build-debug/CMakeFiles/vectorT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vectorT.dir/depend
