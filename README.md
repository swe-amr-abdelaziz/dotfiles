# Dotfiles for Linux

## Installing ZSH, Nerdfonts, fzf, Powerlevel10k and Kitty

### Prerequisits

* Copy dotfiles folder content to the `home` directory

### Nerdfonts

```bash
./scripts/fonts_installation_script
```

* Open a new terminal and change the font to `MesloLGS Nerd Font Regular`

### ZSH

```bash
sudo apt install zsh curl git xclip ripgrep bat fd-find
```

* Go to lsd releases page [here](https://github.com/lsd-rs/lsd/releases)
* Download the package with the name: `lsd_x.x.x_amd64.deb`
* Run:

```bash
sudo apt install ./lsd_x.x.x_amd64.deb && rm ./lsd_x.x.x_amd64.deb
```

### Oh my zsh

```bash
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

### Powerlevel10k theme

```bash
git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
```

* Then restart the computer

```bash
p10k configure
```

###  Oh my zsh plugins

```bash
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting && \
git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
```

###  fzf

```bash
git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf && \
~/.fzf/install
```

### Aliases

```bash
sudo ln -s /usr/bin/fdfind /usr/bin/fd && \
sudo ln -s /usr/bin/batcat /usr/bin/bat
```

### After ZSH

```bash
sudo apt install htop neofetch vim tmux
```

### Kitty

```bash
curl -L https://sw.kovidgoyal.net/kitty/installer.sh | sh /dev/stdin && \
sudo ln -s $HOME/.local/kitty.app/bin/kitty /usr/bin/kitty
```

## Installing i3

### Install dependencies:

```bash
sudo apt install libxcb1-dev libxcb-keysyms1-dev libpango1.0-dev \
                 libxcb-util0-dev libxcb-icccm4-dev libyajl-dev \
                 libstartup-notification0-dev libxcb-randr0-dev \
                 libev-dev libxcb-cursor-dev libxcb-xinerama0-dev \
                 libxcb-xkb-dev libxkbcommon-dev libxkbcommon-x11-dev \
                 autoconf libxcb-xrm0 libxcb-xrm-dev automake \
                 libxcb-shape0-dev pkg-config meson
```

```bash
sudo apt install dex git suckless-tools xss-lock
```

### Install i3

```bash
https://i3wm.org/downloads/
```

```bash
tar xvf ...... && \
cd i3...... && \
mkdir build && \
cd build && \
meson .. && \
ninja && \
sudo ninja install && \
cd .. && \
rm -rf i3......
```

### Install i3blocks

```bash
git clone https://github.com/vivien/i3blocks && \
cd i3blocks && \
./autogen.sh && \
./configure && \
make && \
sudo make install && \
cd .. && \
rm -rf i3blocks
```

###  Add i3 to .xsession

```bash
sudo vim /usr/share/xsessions/i3.desktop
```

```bash
[Desktop Entry]
Name=i3
Comment=improved dynamic tiling window manager
Exec=i3
TryExec=i3
Type=Application
X-LightDM-DesktopName=i3
DesktopNames=i3
Keywords=tiling;wm;windowmanager;window;manager;
```

### Add GTK themes and cursor

```bash
sudo apt install lxappearance
```

## i3 config

### Install dependencies:

```bash
sudo apt install gpick rofi flameshot
```

### Install picom

```bash
# Go to https://github.com/yshui/picom and download the latest release
sudo apt install libconfig-dev libdbus-1-dev libegl-dev libev-dev libgl-dev libepoxy-dev libpcre2-dev libpixman-1-dev libx11-xcb-dev libxcb1-dev libxcb-composite0-dev libxcb-damage0-dev libxcb-glx0-dev libxcb-image0-dev libxcb-present-dev libxcb-randr0-dev libxcb-render0-dev libxcb-render-util0-dev libxcb-shape0-dev libxcb-util-dev libxcb-xfixes0-dev meson ninja-build uthash-dev libxcb-dpms0-dev
cd picom-xx.x && \
meson setup --buildtype=release build && \
ninja -C build && \
sudo mv build/src/picom /usr/bin && \
cd .. && \
rm -rf picom-xx.x
```

### Greenclip

```bash
mkdir -p $HOME/.local/bin && \
cd $HOME/.local/bin && \
wget https://github.com/erebe/greenclip/releases/download/v4.2/greenclip && \
sudo chmod +x greenclip
```

### Move i3 binaries

```bash
cd $HOME/.config/i3/bin && \
ls -1 | awk '$0 ~ /^(i3exit|main_dirs|pick-color|rofi-)/ {print $0}' | xargs -I {} ln -s $PWD/{} $HOME/.local/bin/{} && \
ln -s $PWD/picom.conf $HOME/.config/ && \
cd $HOME/.local/bin
```

### Install dependencies

```bash
sudo apt install build-essential autoconf pkg-config feh
```

### Install volumeicon

```bash
sudo apt install libasound2-dev libglib2.0-dev libgtk-3-dev perl intltool && \
git clone https://github.com/Maato/volumeicon.git && \
cd volumeicon && \
./autogen.sh && \
./configure && \
make && \
sudo make install && \
cd .. && \
rm -rf volumeicon
```

## Installing rofi

### rofi-calc

```bash
sudo apt install rofi-dev qalc libtool libtool-bin && \
git clone https://github.com/svenstaro/rofi-calc.git && \
cd rofi-calc/ && \
mkdir m4 && \
autoreconf -i && \
mkdir build && \
cd build/ && \
../configure && \
make && \
sudo make install
```

* Locate the rofi-calc binary in `/usr/lib64/rofi` or `/usr/lib/x86_64-linux-gnu/rofi` directories

### rofi-file-browser-extended

```bash
sudo apt install cmake && \
git clone https://github.com/marvinkreis/rofi-file-browser-extended.git && \
cd rofi-file-browser-extended && \
cmake . && \
make && \
sudo make install && \
sudo chmod 755 /usr/lib/x86_64-linux-gnu/rofi/filebrowser.so
```

### rofi-emoji

```bash
git clone https://github.com/Mange/rofi-emoji.git && \
cd rofi-emoji && \
autoreconf -i && \
mkdir build && \
cd build/ && \
../configure && \
make && \
sudo make install
```

### noto-emoji

```bash
# https://github.com/googlefonts/noto-emoji
mkdir -p $HOME/.fonts && \
cd $HOME/Downloads && \
wget https://github.com/googlefonts/noto-emoji/raw/main/fonts/NotoColorEmoji.ttf && \
mv NotoColorEmoji.ttf $HOME/.fonts && \
fc-cache -fv
```

* Optional: `https://github.com/axrdiv/i3-rofi-scratchpad`

## Extras

### Snap Store

```bash
sudo mv /etc/apt/preferences.d/nosnap.pref ~/Documents/nosnap.backup && \
sudo apt update && \
sudo apt install snapd
```

## Installing NNN

```bash
sudo apt install libreadline-dev && \
cd $HOME/Downloads && \
git clone https://github.com/jarun/nnn.git && \
cd nnn && \
make O_NERD=1 && \
mv nnn $HOME/.local/bin && \
cd .. && \
rm -rf nnn
```

### Install NNN plugins

```bash
sh -c "$(curl -Ls https://raw.githubusercontent.com/jarun/nnn/master/plugins/getplugs)"
```

- Create the file `~/.local/bin/preview_cmd.sh`

```bash
#!/usr/bin/env sh
# #############################################################################
# File: preview_cmd.sh
# Description: Minimal example to preview files and directories
#              No external dependencies
#              Can be easily extended
#              Automatically exits when the NNN_FIFO closes
#              Prints a `tree` if directory or `head` if it's a file
#
# Shell: POSIX compliant
# Author: Todd Yamakawa
#
# ToDo:
#   1. Add support for more types of files
#         e.g. binary files, we shouldn't try to `head` those
# #############################################################################

# Check FIFO
NNN_FIFO=${NNN_FIFO:-$1}
if [ ! -r "$NNN_FIFO" ]; then
    echo "Unable to open \$NNN_FIFO='$NNN_FIFO'" | less
    exit 2
fi

# Read selection from $NNN_FIFO
while read -r selection; do
    clear
    lines=$(($(tput lines)-1))
    cols=$(tput cols)

    # Print directory tree
    if [ -d "$selection" ]; then
        cd "$selection" || continue
        tree | head -n $lines | cut -c 1-"$cols"
        continue
    fi

    # Print file head
    if [ -f "$selection" ]; then
        head -n $lines "$selection" | cut -c 1-"$cols"
        continue
    fi

    # Something went wrong
    echo "Unknown type: '$selection'"
done < "$NNN_FIFO"
```

### Preview dependencies

```bash
sudo apt install djvulibre-bin ffmpeg ffmpegthumbnailer poppler-utils
```

## LazyGit

### Install Delta

* Go to delta releases page [here](https://github.com/dandavison/delta/releases/)
* Download the package with the name: `git-delta_x.x.x_amd64.deb`
* Run:

```bash
sudo apt install ./git-delta_x.x.x_amd64.deb && rm ./git-delta_x.x.x_amd64.deb
```

### Install LazyGit

```bash
LAZYGIT_VERSION=$(curl -s "https://api.github.com/repos/jesseduffield/lazygit/releases/latest" | grep -Po '"tag_name": "v\K[^"]*')
curl -Lo lazygit.tar.gz "https://github.com/jesseduffield/lazygit/releases/latest/download/lazygit_${LAZYGIT_VERSION}_Linux_x86_64.tar.gz"
tar xf lazygit.tar.gz lazygit
sudo install lazygit /usr/local/bin
```

