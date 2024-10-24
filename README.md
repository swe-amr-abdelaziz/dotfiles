# Dotfiles for Linux

## Installing ZSH, Nerdfonts, fzf, Powerlevel10k and Kitty

* **Current dotfiles are for `Arch Linux`. If you need dotfiles for `Ubuntu` or `Debian`, please refer to the `ubuntu-debian` branch**

### Prerequisits

* Copy dotfiles folder content to the `home` directory

* Installing packages

```bash
sudo pacman -Sy $(< packages.txt)
```

### Fonts

```bash
find . -name '*.zip' -exec sh -c 'unzip -d "${1%.*}" "$1"' _ {} \;
sudo mkdir -p /usr/share/fonts/truetype
sudo cp -r Arimo* Noto_Sans_Arabic /usr/share/fonts/truetype
sudo rm -rf /usr/share/fonts/truetype/*.zip
mkdir -p ~/.config/fontconfig
cp fonts-conf/fonts.conf ~/.config/fontconfig
sudo fc-cache -fv
```

### Oh my zsh

```bash
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

### Powerlevel10k theme

```bash
https://aur.archlinux.org/packages/zsh-theme-powerlevel10k-git
```

* Then restart the computer

```bash
p10k configure
```

###  Oh my zsh plugins

```bash
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
```

## i3 config

### Move i3 binaries

```bash
cd $HOME/.config/i3/bin
ls -1 | awk '$0 ~ /^(greenclip|i3exit|main_dirs|pick-color|rofi-)/ {print $0}' | xargs -I {} ln -s $PWD/{} $HOME/.local/bin/{}
ln -s $PWD/picom.conf $HOME/.config/
cd $HOME/.local/bin
sudo chmod +x *
```

## Installing rofi

* **Note:** rofi plugins are installed in `/usr/lib64/rofi`

### rofi-file-browser-extended

```bash
git clone https://github.com/marvinkreis/rofi-file-browser-extended.git
cd rofi-file-browser-extended
cmake .
# edit src/filebrowser.c line 380 to:
    ._get_icon          = (cairo_surface_t * (*)(const Mode *, unsigned int,  unsigned int)) file_browser_get_icon,
make
sudo make install
sudo chmod +x /usr/lib64/rofi/*
```

* Optional: `https://github.com/axrdiv/i3-rofi-scratchpad`

## Extras

### Stretchly

```bash
https://aur.archlinux.org/packages/stretchly-bin
```

## Installing NNN

```bash
sudo apt install libreadline-dev
cd $HOME/Downloads
git clone https://github.com/jarun/nnn.git
cd nnn
make O_NERD=1 # OR: `make O_EMOJI=1` for nnn with emoji version
mv nnn $HOME/.local/bin
cd ..
rm -rf nnn
```

### Install NNN plugins

```bash
sh -c "$(curl -Ls https://raw.githubusercontent.com/jarun/nnn/master/plugins/getplugs)"
```

- Create the file `~/.local/bin/preview_cmd.sh` with the following content, then give it the execution permission

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

## Installing Node Version Manager (nvm)

```bash
# Go to https://github.com/nvm-sh/nvm
```

## Adding GTK theme and icons with lxappearance

```bash
https://aur.archlinux.org/packages/tokyonight-gtk-theme-git
```
