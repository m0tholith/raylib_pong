# raylib_pong
A simple implementation of pong using raylib
## Dependencies
- raylib
- GNU Make
## Usage
If you're on Linux, run the following commands:
```bash
git clone https://github.com/m0tholith/raylib_pong
cd raylib_pong/
make
```
### NixOS users
For NixOS users, a shell is supplied with the repo, and all you have to do in
the repo directory is running `nix develop -c $SHELL`, or alternatively, if you
have `direnv` set up, run `direnv allow`.
