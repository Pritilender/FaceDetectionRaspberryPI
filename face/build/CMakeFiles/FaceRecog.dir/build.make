# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/face

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/face/build

# Include any dependencies generated for this target.
include CMakeFiles/FaceRecog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FaceRecog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FaceRecog.dir/flags.make

CMakeFiles/FaceRecog.dir/faceRec.cpp.o: CMakeFiles/FaceRecog.dir/flags.make
CMakeFiles/FaceRecog.dir/faceRec.cpp.o: ../faceRec.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/face/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FaceRecog.dir/faceRec.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FaceRecog.dir/faceRec.cpp.o -c /home/pi/face/faceRec.cpp

CMakeFiles/FaceRecog.dir/faceRec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FaceRecog.dir/faceRec.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/face/faceRec.cpp > CMakeFiles/FaceRecog.dir/faceRec.cpp.i

CMakeFiles/FaceRecog.dir/faceRec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FaceRecog.dir/faceRec.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/face/faceRec.cpp -o CMakeFiles/FaceRecog.dir/faceRec.cpp.s

CMakeFiles/FaceRecog.dir/faceRec.cpp.o.requires:
.PHONY : CMakeFiles/FaceRecog.dir/faceRec.cpp.o.requires

CMakeFiles/FaceRecog.dir/faceRec.cpp.o.provides: CMakeFiles/FaceRecog.dir/faceRec.cpp.o.requires
	$(MAKE) -f CMakeFiles/FaceRecog.dir/build.make CMakeFiles/FaceRecog.dir/faceRec.cpp.o.provides.build
.PHONY : CMakeFiles/FaceRecog.dir/faceRec.cpp.o.provides

CMakeFiles/FaceRecog.dir/faceRec.cpp.o.provides.build: CMakeFiles/FaceRecog.dir/faceRec.cpp.o

# Object files for target FaceRecog
FaceRecog_OBJECTS = \
"CMakeFiles/FaceRecog.dir/faceRec.cpp.o"

# External object files for target FaceRecog
FaceRecog_EXTERNAL_OBJECTS =

FaceRecog: CMakeFiles/FaceRecog.dir/faceRec.cpp.o
FaceRecog: CMakeFiles/FaceRecog.dir/build.make
FaceRecog: /home/pi/opencv/build/lib/libopencv_xphoto.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_xobjdetect.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_ximgproc.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_xfeatures2d.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_tracking.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_text.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_surface_matching.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_structured_light.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_stereo.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_saliency.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_rgbd.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_reg.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_plot.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_optflow.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_line_descriptor.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_fuzzy.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_face.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_dpm.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_dnn.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_datasets.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_ccalib.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_bioinspired.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_bgsegm.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_aruco.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_videostab.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_videoio.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_video.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_superres.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_stitching.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_shape.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_photo.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_objdetect.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_ml.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_imgproc.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_imgcodecs.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_highgui.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_flann.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_features2d.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_core.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_calib3d.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_text.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_face.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_ximgproc.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_xfeatures2d.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_shape.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_video.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_objdetect.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_calib3d.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_features2d.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_ml.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_highgui.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_videoio.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_imgcodecs.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_imgproc.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_flann.so.3.1.0
FaceRecog: /home/pi/opencv/build/lib/libopencv_core.so.3.1.0
FaceRecog: CMakeFiles/FaceRecog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable FaceRecog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FaceRecog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FaceRecog.dir/build: FaceRecog
.PHONY : CMakeFiles/FaceRecog.dir/build

CMakeFiles/FaceRecog.dir/requires: CMakeFiles/FaceRecog.dir/faceRec.cpp.o.requires
.PHONY : CMakeFiles/FaceRecog.dir/requires

CMakeFiles/FaceRecog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FaceRecog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FaceRecog.dir/clean

CMakeFiles/FaceRecog.dir/depend:
	cd /home/pi/face/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/face /home/pi/face /home/pi/face/build /home/pi/face/build /home/pi/face/build/CMakeFiles/FaceRecog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FaceRecog.dir/depend

