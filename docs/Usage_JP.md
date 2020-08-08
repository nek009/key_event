# Usage
`colcon build`を行ったディレクトリにて実行．

## targetノードによる実行
パラメータを設定するためのYAMLファイルの雛型は以下にあるので，必要に応じてコピー・編集・使用のこと．

* [key_event/key_event_nodes/yaml/key_hit_event_node.yaml](../key_event_nodes/yaml/key_hit_event_node.yaml)


```
$ . install/setup.bash
$ ros2 run tests key_hit_event_target --ros-args --params-file [YAMLファイル]
```

key_hit_event_targetを起動したterminalでキー入力するとpublishされる．
キー入力されていない時には`\0`がpublishされる．


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

terminal-1でキー入力するとpublishされる．
キー入力されていない時には`\0`がpublishされる．

## 確認
新しくterminalを開き，`colcon build`を行ったディレクトリにて実行．

```
$ . install/setup.bash
$ ros2 topic echo /key_hit_event
```

publishされているキー入力を表示し続ける．

## 共有ライブラリとして使用

* include file
    * #include "key_event_nodes/key_hit_event_node.hpp"
* クラス名
    * key_event::KeyHitEventNode

詳しい組み込み方は[`tests`](../tests)プロジェクトを参照のこと．