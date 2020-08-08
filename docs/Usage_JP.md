# Usage
`colcon build`を行ったディレクトリにて実行．

## targetノードによる実行
パラメータを設定するためのYAMLファイルの雛型は以下にあるので，必要に応じてコピー・編集・使用のこと．

* [key_event/key_event_nodes/yaml/key_hit_event_node.yaml](../key_event_nodes/yaml/key_hit_event_node.yaml)


```
$ . install/setup.bash
$ ros2 run tests key_hit_event_target --ros-args --params-file [YAMLファイル]
```

## componentsによる実行
terminalを二つ起動，それぞれで以下を実行．

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


## 確認
新しくterminalを開き，`colcon build`を行ったディレクトリにて実行．

```
$ . install/setup.bash
$ ros2 topic echo /key_hit_event
```

key_hit_event_targetを起動したterminalでキー入力するとpublishされていることが確認できる．
