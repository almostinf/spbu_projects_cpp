# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\My Projects C++\spbu projects cpp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\My Projects C++\spbu projects cpp\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/spbu_projects_cpp.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/spbu_projects_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spbu_projects_cpp.dir/flags.make

CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix_calc.cpp.obj: CMakeFiles/spbu_projects_cpp.dir/flags.make
CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix_calc.cpp.obj: ../classwork/Matrix_Calc/matrix_calc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\My Projects C++\spbu projects cpp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix_calc.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\spbu_projects_cpp.dir\classwork\Matrix_Calc\matrix_calc.cpp.obj -c "C:\My Projects C++\spbu projects cpp\classwork\Matrix_Calc\matrix_calc.cpp"

CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix_calc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix_calc.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\My Projects C++\spbu projects cpp\classwork\Matrix_Calc\matrix_calc.cpp" > CMakeFiles\spbu_projects_cpp.dir\classwork\Matrix_Calc\matrix_calc.cpp.i

CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix_calc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix_calc.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\My Projects C++\spbu projects cpp\classwork\Matrix_Calc\matrix_calc.cpp" -o CMakeFiles\spbu_projects_cpp.dir\classwork\Matrix_Calc\matrix_calc.cpp.s

CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix.cpp.obj: CMakeFiles/spbu_projects_cpp.dir/flags.make
CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix.cpp.obj: ../classwork/Matrix_Calc/matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\My Projects C++\spbu projects cpp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\spbu_projects_cpp.dir\classwork\Matrix_Calc\matrix.cpp.obj -c "C:\My Projects C++\spbu projects cpp\classwork\Matrix_Calc\matrix.cpp"

CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\My Projects C++\spbu projects cpp\classwork\Matrix_Calc\matrix.cpp" > CMakeFiles\spbu_projects_cpp.dir\classwork\Matrix_Calc\matrix.cpp.i

CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\My Projects C++\spbu projects cpp\classwork\Matrix_Calc\matrix.cpp" -o CMakeFiles\spbu_projects_cpp.dir\classwork\Matrix_Calc\matrix.cpp.s

# Object files for target spbu_projects_cpp
spbu_projects_cpp_OBJECTS = \
"CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix_calc.cpp.obj" \
"CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix.cpp.obj"

# External object files for target spbu_projects_cpp
spbu_projects_cpp_EXTERNAL_OBJECTS =

spbu_projects_cpp.exe: CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix_calc.cpp.obj
spbu_projects_cpp.exe: CMakeFiles/spbu_projects_cpp.dir/classwork/Matrix_Calc/matrix.cpp.obj
spbu_projects_cpp.exe: CMakeFiles/spbu_projects_cpp.dir/build.make
spbu_projects_cpp.exe: CMakeFiles/spbu_projects_cpp.dir/linklibs.rsp
spbu_projects_cpp.exe: CMakeFiles/spbu_projects_cpp.dir/objects1.rsp
spbu_projects_cpp.exe: CMakeFiles/spbu_projects_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\My Projects C++\spbu projects cpp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable spbu_projects_cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\spbu_projects_cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spbu_projects_cpp.dir/build: spbu_projects_cpp.exe
.PHONY : CMakeFiles/spbu_projects_cpp.dir/build

CMakeFiles/spbu_projects_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\spbu_projects_cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/spbu_projects_cpp.dir/clean

CMakeFiles/spbu_projects_cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\My Projects C++\spbu projects cpp" "C:\My Projects C++\spbu projects cpp" "C:\My Projects C++\spbu projects cpp\cmake-build-debug" "C:\My Projects C++\spbu projects cpp\cmake-build-debug" "C:\My Projects C++\spbu projects cpp\cmake-build-debug\CMakeFiles\spbu_projects_cpp.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/spbu_projects_cpp.dir/depend

