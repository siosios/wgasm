# Documentation

The documentation takes the form of this **Steam Community Guide**:

https://steamcommunity.com/sharedfiles/filedetails/?id=3259278773

# Quick-Quick Start :

### 1. Download this repo
```shell
git clone https://github.com/Mecha-Weasel/wgasm
```
Don't have `git` ?
```shell
sudo apt-get update && sudo apt-get install git -y
```

### 2. Run the preparation script

```shell
cd wgasm
chmod +x prepare-debian.sh
sudo ./prepare-debian.sh --nike
```

### 3. Installation of WGASM

```shell
chmod +x install-wgasm.sh
sudo su -c "./install-wgasm.sh --nike" game-servers
```

# Conclusion

WGASM is now installed and you can start using it.
