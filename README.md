# termNote ![](https://travis-ci.org/Terodom/termNote.svg?branch=master)

## About

termNote is going to be a full fledged terminal notes application with funcionality for adding and removing Notes, implenting times for it to be due and notfiy the User and make it customizable with a Config file.

* * *

## Prerequisites

You will need to have atleast these things:

-   `cmake 3.6`
-   `gcc 7+`
-   `argp`

If you need to build `noted`, you need to have `libnotify` (with headers).
If you would like to run unit tests, install or download `catch2`.

* * *

## Installation

### Arch

Either install it directly from the AUR or use an AUR helper like trizen
```bash
trizen -S termNote-git
```

### Nix

```bash
nix-shell -p 'import (builtins.fetchGit {url="https://github.com/Terodom/termNote"; ref="master";} {})'
```

or

```bash
git clone https://github.com/Terodom/termNote
cd termNote 
nix-build
```

#### Building distribution-independent executables (nix bundles)
```bash
nix-build -A bundles.termNote -o termNote
nix-build -A bundles.noted -o noted
```

#### Building AppImages 

:warning: **This is currently broken and it takes a long time to build as it requires everything to be built with musl. Build it only if you are ready to create a fix**

```bash
nix-build -A AppImages.termNote
nix-build -A AppImages.noted
```

### Source

```bash
git clone https://github.com/Terodom/termNote.git
cd termNote
cmake .
make
```
This will install it to /usr/local/bin/

#### Tests
Run `./test.sh` in any POSIX-copmliant shell to run tests. This is done automatically when built with Nix.

* * *

## Usage
### `termNote` (The main utility)
`termNote` is used to manipulate (`--add -a`, `--delete -d`, `--list -l`, `--show -s`, `--complete -c`) notes.
Entries are kept in `$XDG_DATA_HOME/termNote/notes` (or `$HOME/.termNote/notes` if you don't use XDG). Configuration is (going to) be kept in `$XDG_CONFIG_HOME/termNote/config`. Default option is `--list`.
### `noted` (The note daemon)
`noted` is a notification daemon that uses `libnotify` to send you messages about due dates. It tries to guess what date and time you've meant (see #8 #15 for details). It forks by default (meaning it's safe to use in startup scripts), but you can make it stay in foreground by using `-f`. `-v` is mostly used for debugging.

* * *

## Checklist

- [x]   List Notes
- [x]   Add Notes
- [x]   Remove Notes
- [x]   Add Functionality of Due Dates
- [ ]   Make Config File
