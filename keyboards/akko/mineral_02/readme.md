# mineral_02_us VIA

* Keyboard Maintainer: [yangzheng20003](https://github.com/yangzheng20003)
* Hardware Supported: mineral_02_us VIA
* Hardware Availability: mineral_02_us VIA

Make example for this keyboard (after setting up your build environment):

    make akko/mineral_02_us/:default
        
Flashing example for this keyboard:

    make akko/mineral_02_us/:default

To reset the board into bootloader mode, do one of the following:

* Hold the Reset switch mounted on the bottom side of the PCB while connecting the USB cable
* Hold the Escape key while connecting the USB cable (also erases persistent settings)
* Fn+R_Shift+Esc will reset the board to bootloader mode if you have flashed the default QMK keymap

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

## Flashing on macOS (Apple Silicon)

QMK Toolbox (v0.3.3) bundles an x86_64-only `wb32-dfu-updater_cli` binary. On Apple Silicon Macs, this binary fails silently — it detects the device but does not actually write firmware (output shows only `Reset device completed!` with no `Download` progress).

### Workaround: Build a native `wb32-dfu-updater_cli`

```bash
# 1. Install dependencies
brew install cmake libusb

# 2. Build native ARM64 binary
cd /tmp
git clone https://github.com/WestberryTech/wb32-dfu-updater.git
cd wb32-dfu-updater
mkdir build && cd build
cmake .. && make

# 3. The binary is at:
#    wb32-dfu-updater/bin/Darwin_64_Debug/wb32-dfu-updater_cli
```

### Flash the firmware

1. Switch the keyboard to **wired mode** (system switch under Caps Lock → middle position).
2. Enter bootloader: press **Fn + R_Shift + Esc**.
3. Flash (use `-t` flag for toolbox mode, which handles read-protection automatically):

```bash
/path/to/wb32-dfu-updater_cli -t -D /path/to/firmware.bin
```

Expected successful output:

```
Found DFU
Opening DFU capable USB device ...
Device ID 342d:dfa0
The device bootloader version: 0.4
Start Download ...
Download block start address: 0x08000000
Download block size: 73300 Bytes
Writing ...
OK
Download completed!
```

### Notes

* If your firmware is in `.hex` format, convert it to `.bin` first:

```bash
arm-none-eabi-objcopy -I ihex -O binary firmware.hex firmware.bin
```

* The `-t` (toolbox mode) flag is **required** — without it the download may be skipped silently.
* The keyboard exits bootloader mode after a few seconds of inactivity, so run the flash command promptly after entering DFU mode.

