# package名: key_event_nodes
## key_event::KeyHitEventNode
### topic名: key_hit_event
---
#### サービス内容
publisher側.
定期的(interval_ms)に入力されたキーをpublishする．入力がない時には`\0`文字をpublishする．

##### message
[key_event/key_event_msgs/msg/KeyEvent.msg](../key_event_msgs/msg/KeyEvent.msg)

* char key
    * 入力されたキー
    * 入力されていない場合`\0`

### parameters
---
[key_event/key_event_nodes/yaml/key_hit_event_node.yaml](../key_event_nodes/yaml/key_hit_event_node.yaml)

* int interval_ms
    * publishする間隔
    * 単位: ミリ秒
    * デフォルト値: 100(ms)
