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
`colcon build`を行ったディレクトリにて実行．

```
$ . install/setup.bash
$ ros2 run tests key_hit_event_target
```

## 確認
新しくterminalを開き，`colcon build`を行ったディレクトリにて実行．

```
$ . install/setup.bash
$ ros2 topic echo /key_hit_event
```

key_hit_event_targetを起動したterminalでキー入力するとpublishされていることが確認できる．

[more detailed...](Usage_JP.md)


# [Information for ROS2 developer](Information_for_ROS2_developer_JP.md)

# Release
* メインブランチ
    * master
