# Usage
Works under the directory where executed `colcon build`.

## Execution by target node
The template of YAML file to set up parameters is as follows. Use it by copying, revising and as a option for ros2 run.

* [key_event/key_event_nodes/yaml/key_hit_event_node.yaml](../key_event_nodes/yaml/key_hit_event_node.yaml)

```
$ . install/setup.bash
$ ros2 run tests key_hit_event_target --ros-args --params file [YAML file]
```

By inputing keys on the terminal where key_hit_event_target works, we can confirm the keys are published.
Under no input key status, `\0` will be kept publishing periodically.

## Execution as components.
Starts up two terminals, executes following commands on each terminal.

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

By inputing keys on the terminal-1, we can confirm the keys are published.
Under no input key status, `\0` will be kept publishing periodically.

## Confirmation
Open new terminal, change directory to execute `colcon build`.

```
$ . install/setup.bash
$ ros2 topic echo /key_hit_event
```

The published keys are displayed.

## Use as shared library

* include file
    * #include "key_event_nodes/key_hit_event_node.hpp"
* クラス名
    * key_event::KeyHitEventNode

See [`tests`](../tests) project to know a detailed way to use it.