# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/alehandro/Programming/clion-2019.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alehandro/Programming/clion-2019.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug

# Include any dependencies generated for this target.
include gtests/googlemock/CMakeFiles/gmock_main.dir/depend.make

# Include the progress variables for this target.
include gtests/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include gtests/googlemock/CMakeFiles/gmock_main.dir/flags.make

gtests/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: gtests/googlemock/CMakeFiles/gmock_main.dir/flags.make
gtests/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: ../gtests/googlemock/src/gmock_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gtests/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug/gtests/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/gtests/googlemock/src/gmock_main.cc

gtests/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug/gtests/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/gtests/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

gtests/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug/gtests/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/gtests/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_maind.a: gtests/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
lib/libgmock_maind.a: gtests/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_maind.a: gtests/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libgmock_maind.a"
	cd /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug/gtests/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug/gtests/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gtests/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_maind.a

.PHONY : gtests/googlemock/CMakeFiles/gmock_main.dir/build

gtests/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug/gtests/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : gtests/googlemock/CMakeFiles/gmock_main.dir/clean

gtests/googlemock/CMakeFiles/gmock_main.dir/depend:
	cd /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/gtests/googlemock /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug/gtests/googlemock /home/alehandro/CLionProjects/cpp_18210-18211_tasks/LaboratoryWorks/Lab_TritSet/cmake-build-debug/gtests/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gtests/googlemock/CMakeFiles/gmock_main.dir/depend

