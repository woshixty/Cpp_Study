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
include CMakeFiles/testBuilder.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/testBuilder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testBuilder.dir/flags.make

CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.o: CMakeFiles/testBuilder.dir/flags.make
CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.o: ../week04/TestBuilder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.o -c /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/week04/TestBuilder.cpp

CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/week04/TestBuilder.cpp > CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.i

CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/week04/TestBuilder.cpp -o CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.s

# Object files for target testBuilder
testBuilder_OBJECTS = \
"CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.o"

# External object files for target testBuilder
testBuilder_EXTERNAL_OBJECTS =

testBuilder: CMakeFiles/testBuilder.dir/week04/TestBuilder.cpp.o
testBuilder: CMakeFiles/testBuilder.dir/build.make
testBuilder: CMakeFiles/testBuilder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testBuilder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testBuilder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testBuilder.dir/build: testBuilder
.PHONY : CMakeFiles/testBuilder.dir/build

CMakeFiles/testBuilder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testBuilder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testBuilder.dir/clean

CMakeFiles/testBuilder.dir/depend:
	cd /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles/testBuilder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testBuilder.dir/depend
