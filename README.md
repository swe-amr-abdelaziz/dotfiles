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
sudo apt install htop neofetch vim
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

