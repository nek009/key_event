[for Japanese:日本語](docs/README_JP.md)

# Description
ROS2 node. It publishes key input periodically, or publishes '\0' for no key input.

# Installation
Premise: Installed [ROS2](https://index.ros.org/doc/ros2/) system.

```
$ git clone [URL of this project]
$ colcon build --symlink-install
```

[more detailed...](docs/Installation.md)

# Useage
Works under the directory where executed `colcon build'.

## Execution by target node

```
$ . install/setup.bash
$ ros2 run tests key_hit_event_target
```

## Execution with components.
Starts up two terminals, executes following command on each terminal.

terminal-1
```
$ . install/setup.bash
$ ros2 run rclcpp_components component_container
```

terminal-2
```
$ . install/setup.bash
$ ros2 component load /ComponentManager key_event_nodes key_event::KeyHitEventNode
```

After that, publishing key inputs on terminal-1.

## confirmation

```
$ . install/setup.bash
$ ros2 topic echo /key_hit_event
```

# Information for ROS developer
## msg messages
### topic名:key_hit_event

* char key
    * inputted key
    * `\0` for no key input

## parameters

* int interval_ms
    * interval time for publishing
    * unit: millisecond
    * default value: 100(ms)

# Release
* main branch
    * master
