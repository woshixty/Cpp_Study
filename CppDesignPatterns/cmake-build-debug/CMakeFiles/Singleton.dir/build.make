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
include CMakeFiles/singleton.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/singleton.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/singleton.dir/flags.make

CMakeFiles/singleton.dir/singleton/Singleton.cpp.o: CMakeFiles/singleton.dir/flags.make
CMakeFiles/singleton.dir/singleton/Singleton.cpp.o: ../singleton/Singleton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/singleton.dir/singleton/Singleton.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/singleton.dir/singleton/Singleton.cpp.o -c /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/singleton/Singleton.cpp

CMakeFiles/singleton.dir/singleton/Singleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/singleton.dir/singleton/Singleton.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/singleton/Singleton.cpp > CMakeFiles/singleton.dir/singleton/Singleton.cpp.i

CMakeFiles/singleton.dir/singleton/Singleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/singleton.dir/singleton/Singleton.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/singleton/Singleton.cpp -o CMakeFiles/singleton.dir/singleton/Singleton.cpp.s

# Object files for target singleton
singleton_OBJECTS = \
"CMakeFiles/singleton.dir/singleton/Singleton.cpp.o"

# External object files for target singleton
singleton_EXTERNAL_OBJECTS =

singleton: CMakeFiles/singleton.dir/singleton/Singleton.cpp.o
singleton: CMakeFiles/singleton.dir/build.make
singleton: CMakeFiles/singleton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable singleton"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/singleton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/singleton.dir/build: singleton
.PHONY : CMakeFiles/singleton.dir/build

CMakeFiles/singleton.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/singleton.dir/cmake_clean.cmake
.PHONY : CMakeFiles/singleton.dir/clean

CMakeFiles/singleton.dir/depend:
	cd /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug /Users/xietingyu/Desktop/Cpp_Study/CppDesignPatterns/cmake-build-debug/CMakeFiles/singleton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/singleton.dir/depend

