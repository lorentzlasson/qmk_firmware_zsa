# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a fork of QMK firmware specifically configured for ZSA keyboards (Voyager, Moonlander, Ergodox EZ, Planck EZ). The repository includes a personal keymap for the Voyager keyboard under `keyboards/zsa/voyager/keymaps/lorentz/`.

## Development Environment

The repository uses Nix flakes for development environment setup. The flake provides:
- `qmk` CLI tool
- `gnumake` for the build system

To enter the development shell:
```bash
nix develop
```

## Building Firmware

### Build for specific keyboard and keymap
```bash
make zsa/voyager:lorentz
```

### Build and flash
```bash
make zsa/voyager:lorentz:flash
```

### Clean build artifacts
```bash
make clean
```

### Deep clean (also removes generated binaries)
```bash
make distclean
```

## Keymap Structure

Keymaps are located at `keyboards/{manufacturer}/{keyboard}/keymaps/{keymap_name}/`:
- `keymap.c` - Main keymap definition with layer layouts
- `config.h` - Keymap-specific configuration (timing, features)
- `rules.mk` - Feature enablement (combos, caps word, etc.)

### Current Keymap (lorentz)

Located at `keyboards/zsa/voyager/keymaps/lorentz/`:
- Uses 6 layers: QWERTY, SYM, SYS, F, GAME, GAME_SYM
- Enabled features: combos, caps word, Oryx integration
- Custom tap-hold configurations with 150ms tapping term
- Combo definitions for bootloader, alt, tmux, and GUI keys

## Architecture

### Build System
- Top-level `Makefile` parses targets in format `keyboard:keymap:target`
- Recursively includes keyboard-specific `rules.mk` files
- Build definitions in `builddefs/*.mk`
- Output directory: `.build/`

### ZSA Keyboards
All located under `keyboards/zsa/`:
- `common/` - Shared ZSA keyboard code
- `voyager/` - ZSA Voyager specific implementation
- `moonlander/` - ZSA Moonlander
- `ergodox_ez/` - Ergodox EZ
- `planck_ez/` - Planck EZ

### Keymap Definitions
- Layers defined in `keymaps[][MATRIX_ROWS][MATRIX_COLS]` array
- Use `LAYOUT()` macro matching keyboard's physical layout
- Custom keycodes via `enum` and `#define` macros
- Mod-tap keys: `MT(mod, kc)` - tap for keycode, hold for modifier
- Layer-tap keys: `LT(layer, kc)` - tap for keycode, hold for layer

### Feature Configuration
Enable features in keymap's `rules.mk`:
- `COMBO_ENABLE = yes` - Key combinations
- `CAPS_WORD_ENABLE = yes` - Smart caps lock
- `ORYX_ENABLE = yes` - ZSA Oryx integration

Configure behavior in keymap's `config.h`:
- `TAPPING_TERM` - Milliseconds to distinguish tap vs hold
- `PERMISSIVE_HOLD` - Hold action triggers even if another key pressed
- `BOTH_SHIFTS_TURNS_ON_CAPS_WORD` - Enable caps word gesture
