最終的には[他のプロジェクトの一部として使いたい場合](#他のプロジェクトの一部として使いたい場合)が主となると思われる．
全体像は[研究室内の独自ルールのページ](https://qiita.com/NeK/items/2c4a8a7086c85d6461c0)を参照のこと．

# 自分の好みのままにいじってみたい場合
[qiita:自分の好みのままにいじってみたい場合](https://qiita.com/NeK/items/2c4a8a7086c85d6461c0#%E6%89%8B%E9%A0%86%E8%87%AA%E5%88%86%E3%81%AE%E5%A5%BD%E3%81%BF%E3%81%AE%E3%81%BE%E3%81%BE%E3%81%AB%E3%81%84%E3%81%98%E3%81%A3%E3%81%A6%E3%81%BF%E3%81%9F%E3%81%84%E5%A0%B4%E5%90%88)

## 手順:

1. プロジェクトを自分のプロジェクトにForkする．
- 自分のプロジェクトからcloneする．

```
$ git clone [forkしたプロジェクトのurl]
$ colcon build --symlink-install
```

有用な変更したらfork元にマージリクエストして還元する．

# 他のプロジェクトの一部として使いたい場合
[qiita:自分のプロジェクトの一部として使いたい](https://qiita.com/NeK/items/2c4a8a7086c85d6461c0#%E8%87%AA%E5%88%86%E3%81%AE%E3%83%97%E3%83%AD%E3%82%B8%E3%82%A7%E3%82%AF%E3%83%88%E3%81%AE%E4%B8%80%E9%83%A8%E3%81%A8%E3%81%97%E3%81%A6%E4%BD%BF%E3%81%84%E3%81%9F%E3%81%84)

他のプロジェクトにはsubmoduleとして追加し使用する．
clone時に全部DLするのではなく，必要なもののみをDLする．
参考:[Git 特定のフォルダのみcloneする submodule編](https://qiita.com/icoxfog417/items/89e55947e9e8f2c16077)

重要なパッケージ一覧
* key_event_msgs
* key_event_nodes

## 手順

```bash
$ cd [本プロジェクトを置きたいディレクトリ]
$ git submodule add [本プロジェクトのURL]
$ git commit -m "Added module"
$ cd key_event
$ git config core.sparsecheckout true
$ echo "key_event_msgs" >> ../.git/modules/key_event/info/sparse-checkout
$ echo "key_event_nodes" >> ../.git/modules/key_event/info/sparse-checkout
$ git read-tree -mu HEAD
```

lsなどで都度確認すると，git read-treeで必要なディレクトリ以外確かに見えなくなっている．

### submoduleの操作:ダウンロード

```
$ git submodule init
$ git submodule update
```

### submoduleの操作:アップデート
アップデートを取り込んで更新．

```
$ git submodule fetch
$ git submodule merge origin/master
```

