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

