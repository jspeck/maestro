# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/ros/fuerte/stacks/maestro/hubomsg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/ros/fuerte/stacks/maestro/hubomsg/build

# Utility rule file for ROSBUILD_genmanifest_roseus_hubomsg.

# Include the progress variables for this target.
include CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg.dir/progress.make

CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg: /home/cgtester/.ros/roseus/hubomsg/manifest.l

/home/cgtester/.ros/roseus/hubomsg/manifest.l: ../manifest.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/ros/fuerte/stacks/maestro/hubomsg/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating /home/cgtester/.ros/roseus/hubomsg/manifest.l"
	/opt/ros/fuerte/stacks/roseus/scripts/genmanifest_eus hubomsg

ROSBUILD_genmanifest_roseus_hubomsg: CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg
ROSBUILD_genmanifest_roseus_hubomsg: /home/cgtester/.ros/roseus/hubomsg/manifest.l
ROSBUILD_genmanifest_roseus_hubomsg: CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg.dir/build.make
.PHONY : ROSBUILD_genmanifest_roseus_hubomsg

# Rule to build all files generated by this target.
CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg.dir/build: ROSBUILD_genmanifest_roseus_hubomsg
.PHONY : CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg.dir/build

CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg.dir/clean

CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg.dir/depend:
	cd /opt/ros/fuerte/stacks/maestro/hubomsg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/ros/fuerte/stacks/maestro/hubomsg /opt/ros/fuerte/stacks/maestro/hubomsg /opt/ros/fuerte/stacks/maestro/hubomsg/build /opt/ros/fuerte/stacks/maestro/hubomsg/build /opt/ros/fuerte/stacks/maestro/hubomsg/build/CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ROSBUILD_genmanifest_roseus_hubomsg.dir/depend
