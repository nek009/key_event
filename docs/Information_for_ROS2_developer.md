# package name: key_event_nodes
## key_event::KeyHitEventNode
### topic name: key_hit_event
---
#### service contents
Work as publisher.

Publish the inputed key periodically(interval_ms.) Publish `\0` for no input.

##### message
[key_event/key_event_msgs/msg/KeyEvent.msg](../key_event_msgs/msg/KeyEvent.msg)

* char key
    * inputted key
    * `\0` for no key input

### parameters
---
[key_event/key_event_nodes/yaml/key_hit_event_node.yaml](../key_event_nodes/yaml/key_hit_event_node.yaml)

* int interval_ms
    * interval time for publishing
    * unit: millisecond
    * default value: 100(ms)
