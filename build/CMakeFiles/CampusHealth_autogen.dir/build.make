# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System/build

# Utility rule file for CampusHealth_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/CampusHealth_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CampusHealth_autogen.dir/progress.make

CMakeFiles/CampusHealth_autogen: CampusHealth_autogen/timestamp

CampusHealth_autogen/timestamp: /Users/wu/Qt/6.9.0/macos/libexec/moc
CampusHealth_autogen/timestamp: /Users/wu/Qt/6.9.0/macos/libexec/uic
CampusHealth_autogen/timestamp: CMakeFiles/CampusHealth_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target CampusHealth"
	/opt/homebrew/bin/cmake -E cmake_autogen /Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System/build/CMakeFiles/CampusHealth_autogen.dir/AutogenInfo.json Debug
	/opt/homebrew/bin/cmake -E touch /Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System/build/CampusHealth_autogen/timestamp

CMakeFiles/CampusHealth_autogen.dir/codegen:
.PHONY : CMakeFiles/CampusHealth_autogen.dir/codegen

CampusHealth_autogen: CMakeFiles/CampusHealth_autogen
CampusHealth_autogen: CampusHealth_autogen/timestamp
CampusHealth_autogen: CMakeFiles/CampusHealth_autogen.dir/build.make
.PHONY : CampusHealth_autogen

# Rule to build all files generated by this target.
CMakeFiles/CampusHealth_autogen.dir/build: CampusHealth_autogen
.PHONY : CMakeFiles/CampusHealth_autogen.dir/build

CMakeFiles/CampusHealth_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CampusHealth_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CampusHealth_autogen.dir/clean

CMakeFiles/CampusHealth_autogen.dir/depend:
	cd /Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System /Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System /Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System/build /Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System/build /Users/wu/Documents/VScode/QtProjects/Campus-Health-Managing-System/build/CMakeFiles/CampusHealth_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CampusHealth_autogen.dir/depend

