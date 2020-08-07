Main usage will be shown in [Use as a part of other projects](#Use-as-a-part-of-other-projects).

# Revise this proj. as you like
## Procedure

1. Fork this proj. to your space.
2. Clone from your space.


```
$ git clone [URL of your space]
$ colcon build --symlink-install
```

# Use as a part of other projects
Add this proj. to other projects as a submodule.
Not clone all packages, just clone core packages.

core packages
* key_event_msgs
* key_event_nodes

## Procedure

```bash
$ cd [Directory into where you want to put this proj.]
$ git submodule add [URL of this proj.]
$ git commit -m "Added module"
$ cd key_event
$ git config core.sparsecheckout true
$ echo "key_event_msgs" >> ../.git/modules/key_event/info/sparse-checkout
$ echo "key_event_nodes" >> ../.git/modules/key_event/info/sparse-checkout
$ git read-tree -mu HEAD
```

### Submodule operations: Download

```
$ git submodule init
$ git submodule update
```

#### Submodule operations: Update

```
$ git submodule fetch
$ git submodule merge origin/master
```

