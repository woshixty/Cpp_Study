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
CMAKE_SOURCE_DIR = /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cppDesignPatterns.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/cppDesignPatterns.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cppDesignPatterns.dir/flags.make

CMakeFiles/cppDesignPatterns.dir/main.cpp.o: CMakeFiles/cppDesignPatterns.dir/flags.make
CMakeFiles/cppDesignPatterns.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cppDesignPatterns.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cppDesignPatterns.dir/main.cpp.o -c /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/main.cpp

CMakeFiles/cppDesignPatterns.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppDesignPatterns.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/main.cpp > CMakeFiles/cppDesignPatterns.dir/main.cpp.i

CMakeFiles/cppDesignPatterns.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppDesignPatterns.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/main.cpp -o CMakeFiles/cppDesignPatterns.dir/main.cpp.s

# Object files for target cppDesignPatterns
cppDesignPatterns_OBJECTS = \
"CMakeFiles/cppDesignPatterns.dir/main.cpp.o"

# External object files for target cppDesignPatterns
cppDesignPatterns_EXTERNAL_OBJECTS =

cppDesignPatterns: CMakeFiles/cppDesignPatterns.dir/main.cpp.o
cppDesignPatterns: CMakeFiles/cppDesignPatterns.dir/build.make
cppDesignPatterns: CMakeFiles/cppDesignPatterns.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cppDesignPatterns"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppDesignPatterns.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cppDesignPatterns.dir/build: cppDesignPatterns
.PHONY : CMakeFiles/cppDesignPatterns.dir/build

CMakeFiles/cppDesignPatterns.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cppDesignPatterns.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cppDesignPatterns.dir/clean

CMakeFiles/cppDesignPatterns.dir/depend:
	cd /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles/cppDesignPatterns.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cppDesignPatterns.dir/depend

