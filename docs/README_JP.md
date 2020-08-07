# Description
ROS2 node．キー入力を定期的(intermal_ms)に拾い上げpublishする．文字入力がない場合は'\0'文字(ヌル文字)をpublishする．
詳しくは本プロジェクトのWiki参照のこと．

# Installation
[ROS2](https://index.ros.org/doc/ros2/)システムが動いていること．


```
$ git clone [本プロジェクトのURL]
$ colcon build --symlink-install
```

[more detailed...](Installation_JP.md)

# Usage
`colcon build`を行ったディレクトリにて作業．

## targetによる実行

```
$ . install/setup.bash
$ ros2 run tests key_hit_event_target
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

targetを起動したterminalもしくはterminal-1でキー入力に対するpublishが行われる．

## 確認

```
$ . install/setup.bash
$ ros2 topic echo /key_hit_event
```

# Information for ROS developer
## msg messages
### topic名:key_hit_event

* char key
    * 入力されたキー
    * 入力されていない場合`\0`

## parameters

* int interval_ms
    * publishする間隔
    * 単位: ミリ秒
    * デフォルト値: 100(ms)

# Release
* メインブランチ
    * master
