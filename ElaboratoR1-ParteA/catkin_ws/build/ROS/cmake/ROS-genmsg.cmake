# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ROS: 1 messages, 1 services")

set(MSG_I_FLAGS "-IROS:/home/fabio/catkin_ws/src/ROS/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Iturtlesim:/opt/ros/melodic/share/turtlesim/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ROS_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv" NAME_WE)
add_custom_target(_ROS_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ROS" "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv" ""
)

get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/msg/Num.msg" NAME_WE)
add_custom_target(_ROS_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ROS" "/home/fabio/catkin_ws/src/ROS/msg/Num.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ROS
  "/home/fabio/catkin_ws/src/ROS/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ROS
)

### Generating Services
_generate_srv_cpp(ROS
  "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ROS
)

### Generating Module File
_generate_module_cpp(ROS
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ROS
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ROS_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ROS_generate_messages ROS_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(ROS_generate_messages_cpp _ROS_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/msg/Num.msg" NAME_WE)
add_dependencies(ROS_generate_messages_cpp _ROS_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ROS_gencpp)
add_dependencies(ROS_gencpp ROS_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ROS_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(ROS
  "/home/fabio/catkin_ws/src/ROS/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ROS
)

### Generating Services
_generate_srv_eus(ROS
  "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ROS
)

### Generating Module File
_generate_module_eus(ROS
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ROS
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(ROS_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(ROS_generate_messages ROS_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(ROS_generate_messages_eus _ROS_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/msg/Num.msg" NAME_WE)
add_dependencies(ROS_generate_messages_eus _ROS_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ROS_geneus)
add_dependencies(ROS_geneus ROS_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ROS_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(ROS
  "/home/fabio/catkin_ws/src/ROS/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ROS
)

### Generating Services
_generate_srv_lisp(ROS
  "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ROS
)

### Generating Module File
_generate_module_lisp(ROS
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ROS
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(ROS_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(ROS_generate_messages ROS_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(ROS_generate_messages_lisp _ROS_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/msg/Num.msg" NAME_WE)
add_dependencies(ROS_generate_messages_lisp _ROS_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ROS_genlisp)
add_dependencies(ROS_genlisp ROS_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ROS_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(ROS
  "/home/fabio/catkin_ws/src/ROS/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ROS
)

### Generating Services
_generate_srv_nodejs(ROS
  "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ROS
)

### Generating Module File
_generate_module_nodejs(ROS
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ROS
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(ROS_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(ROS_generate_messages ROS_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(ROS_generate_messages_nodejs _ROS_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/msg/Num.msg" NAME_WE)
add_dependencies(ROS_generate_messages_nodejs _ROS_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ROS_gennodejs)
add_dependencies(ROS_gennodejs ROS_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ROS_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ROS
  "/home/fabio/catkin_ws/src/ROS/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ROS
)

### Generating Services
_generate_srv_py(ROS
  "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ROS
)

### Generating Module File
_generate_module_py(ROS
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ROS
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ROS_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ROS_generate_messages ROS_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(ROS_generate_messages_py _ROS_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fabio/catkin_ws/src/ROS/msg/Num.msg" NAME_WE)
add_dependencies(ROS_generate_messages_py _ROS_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ROS_genpy)
add_dependencies(ROS_genpy ROS_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ROS_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ROS)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ROS
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(ROS_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(ROS_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET turtlesim_generate_messages_cpp)
  add_dependencies(ROS_generate_messages_cpp turtlesim_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ROS)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/ROS
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(ROS_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(ROS_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET turtlesim_generate_messages_eus)
  add_dependencies(ROS_generate_messages_eus turtlesim_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ROS)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ROS
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(ROS_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(ROS_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET turtlesim_generate_messages_lisp)
  add_dependencies(ROS_generate_messages_lisp turtlesim_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ROS)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/ROS
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(ROS_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(ROS_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET turtlesim_generate_messages_nodejs)
  add_dependencies(ROS_generate_messages_nodejs turtlesim_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ROS)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ROS\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ROS
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(ROS_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(ROS_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET turtlesim_generate_messages_py)
  add_dependencies(ROS_generate_messages_py turtlesim_generate_messages_py)
endif()
