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
include CMakeFiles/temTest.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/temTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/temTest.dir/flags.make

CMakeFiles/temTest.dir/week04/Test.cpp.o: CMakeFiles/temTest.dir/flags.make
CMakeFiles/temTest.dir/week04/Test.cpp.o: ../week04/Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/temTest.dir/week04/Test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/temTest.dir/week04/Test.cpp.o -c /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/week04/Test.cpp

CMakeFiles/temTest.dir/week04/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/temTest.dir/week04/Test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/week04/Test.cpp > CMakeFiles/temTest.dir/week04/Test.cpp.i

CMakeFiles/temTest.dir/week04/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/temTest.dir/week04/Test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/week04/Test.cpp -o CMakeFiles/temTest.dir/week04/Test.cpp.s

# Object files for target temTest
temTest_OBJECTS = \
"CMakeFiles/temTest.dir/week04/Test.cpp.o"

# External object files for target temTest
temTest_EXTERNAL_OBJECTS =

temTest: CMakeFiles/temTest.dir/week04/Test.cpp.o
temTest: CMakeFiles/temTest.dir/build.make
temTest: CMakeFiles/temTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable temTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/temTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/temTest.dir/build: temTest
.PHONY : CMakeFiles/temTest.dir/build

CMakeFiles/temTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/temTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/temTest.dir/clean

CMakeFiles/temTest.dir/depend:
	cd /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles/temTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/temTest.dir/depend

