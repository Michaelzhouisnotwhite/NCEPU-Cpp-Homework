# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files (x64)\MicrosoftVC++tools\IDE\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x64)\MicrosoftVC++tools\IDE\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\User_Michael's\C project\Clion C++\Homework\hw01"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\User_Michael's\C project\Clion C++\Homework\hw01\build"

# Include any dependencies generated for this target.
include CMakeFiles/test02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test02.dir/flags.make

CMakeFiles/test02.dir/test02.cpp.obj: CMakeFiles/test02.dir/flags.make
CMakeFiles/test02.dir/test02.cpp.obj: ../test02.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\User_Michael's\C project\Clion C++\Homework\hw01\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test02.dir/test02.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test02.dir\test02.cpp.obj -c "E:\User_Michael's\C project\Clion C++\Homework\hw01\test02.cpp"

CMakeFiles/test02.dir/test02.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test02.dir/test02.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\User_Michael's\C project\Clion C++\Homework\hw01\test02.cpp" > CMakeFiles\test02.dir\test02.cpp.i

CMakeFiles/test02.dir/test02.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test02.dir/test02.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\User_Michael's\C project\Clion C++\Homework\hw01\test02.cpp" -o CMakeFiles\test02.dir\test02.cpp.s

# Object files for target test02
test02_OBJECTS = \
"CMakeFiles/test02.dir/test02.cpp.obj"

# External object files for target test02
test02_EXTERNAL_OBJECTS =

test02.exe: CMakeFiles/test02.dir/test02.cpp.obj
test02.exe: CMakeFiles/test02.dir/build.make
test02.exe: CMakeFiles/test02.dir/linklibs.rsp
test02.exe: CMakeFiles/test02.dir/objects1.rsp
test02.exe: CMakeFiles/test02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\User_Michael's\C project\Clion C++\Homework\hw01\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test02.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test02.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test02.dir/build: test02.exe

.PHONY : CMakeFiles/test02.dir/build

CMakeFiles/test02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test02.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test02.dir/clean

CMakeFiles/test02.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\User_Michael's\C project\Clion C++\Homework\hw01" "E:\User_Michael's\C project\Clion C++\Homework\hw01" "E:\User_Michael's\C project\Clion C++\Homework\hw01\build" "E:\User_Michael's\C project\Clion C++\Homework\hw01\build" "E:\User_Michael's\C project\Clion C++\Homework\hw01\build\CMakeFiles\test02.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test02.dir/depend

