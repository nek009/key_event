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

# Usage
Works under the directory where executed `colcon build'.

```
$ . install/setup.bash
$ ros2 run tests key_hit_event_target
```

## Confirmation
Open new terminal, change directory to execute `colcon build`.

```
$ . install/setup.bash
$ ros2 topic echo /key_hit_event
```

By inputing keys on the terminal where key_hit_event_target works, we can confirm the keys are published.
Under no input key status, `\0` will be kept publishing periodically.

[more detailed...](docs/Usage.md)


# Information for ROS developer
## msg messages
### topic name:key_hit_event

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
