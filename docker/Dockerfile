ARG ROS_DISTRO=noetic

FROM osrf/ros:$ROS_DISTRO-desktop-full

SHELL ["/bin/bash", "-c"]
ENV DEBIAN_FRONTEND=noninteractive

# Deps
# RUN apt-get update \
#   && apt-get install -y \
#     python3-catkin-tools \
#     # python3-osrf-pycommon \
#     libzmq3-dev \
#     libboost-dev \
#     ros-${ROS_DISTRO}-behaviortree-cpp-v3 \
#     ros-${ROS_DISTRO}-realsense2-camera \
#     ros-${ROS_DISTRO}-realsense2-description\
#     ros-${ROS_DISTRO}-joy/
#     ros-${ROS_DISTRO}-tf2-sensor-msgs

COPY src /catkin_ws/src

WORKDIR /catkin_ws

RUN source /opt/ros/${ROS_DISTRO}/setup.bash \
  && apt-get update \
  && apt-get install -y python3-catkin-tools \
  && rosdep install -i --from-path src --rosdistro ${ROS_DISTRO} -y \
  && catkin config --cmake-args -DCMAKE_BUILD_TYPE=Release \
  && catkin build \
  && echo 'source /opt/ros/${ROS_DISTRO}/setup.bash' >> /root/.bashrc \
  && echo 'source /catkin_ws/devel/setup.bash' >> /root/.bashrc \
  && echo 'source /catkin_ws/devel/setup.bash' >> /ros_entrypoint.sh \
  && sed -i '/exec "$@"/d' /ros_entrypoint.sh \
  && echo 'exec "$@"' >> /ros_entrypoint.sh \
  && rm -rf /var/lib/apt/lists/*

ENTRYPOINT [ "/ros_entrypoint.sh" ]

ENV DEBIAN_FRONTEND=dialog
