# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/z/Dropbox/projects/hypetrain/celeste/libTAS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/z/Dropbox/projects/hypetrain/celeste/libTAS/build64

# Utility rule file for tas_autogen.

# Include the progress variables for this target.
include CMakeFiles/tas_autogen.dir/progress.make

CMakeFiles/tas_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/z/Dropbox/projects/hypetrain/celeste/libTAS/build64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target tas"
	/usr/local/bin/cmake -E cmake_autogen /mnt/z/Dropbox/projects/hypetrain/celeste/libTAS/build64/CMakeFiles/tas_autogen.dir/AutogenInfo.cmake ""

tas_autogen: CMakeFiles/tas_autogen
tas_autogen: CMakeFiles/tas_autogen.dir/build.make

.PHONY : tas_autogen

# Rule to build all files generated by this target.
CMakeFiles/tas_autogen.dir/build: tas_autogen

.PHONY : CMakeFiles/tas_autogen.dir/build

CMakeFiles/tas_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tas_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tas_autogen.dir/clean

CMakeFiles/tas_autogen.dir/depend:
	cd /mnt/z/Dropbox/projects/hypetrain/celeste/libTAS/build64 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/z/Dropbox/projects/hypetrain/celeste/libTAS /mnt/z/Dropbox/projects/hypetrain/celeste/libTAS /mnt/z/Dropbox/projects/hypetrain/celeste/libTAS/build64 /mnt/z/Dropbox/projects/hypetrain/celeste/libTAS/build64 /mnt/z/Dropbox/projects/hypetrain/celeste/libTAS/build64/CMakeFiles/tas_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tas_autogen.dir/depend

