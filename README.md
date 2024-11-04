# USB Device Detection Script

This is a simple C script that identifies and displays USB devices connected to a Linux-based system. It reads from the `/sys/bus/usb/devices/` directory to list the names of connected USB devices.

## How It Works

The script:
1. Opens the `/sys/bus/usb/devices/` directory, where USB device information is stored.
2. Searches for entries containing `:` in their names, as these typically correspond to USB devices.
3. Reads each device's `product` file to retrieve the device name.
4. Prints each USB device’s name to the console.

## Prerequisites

- **Operating System:** Linux-based (the script relies on the `/sys` file system, which is standard in Linux for hardware information).
- **C Compiler:** `gcc` or any other C compiler.

## Usage

1. **Clone or Download** the repository.

2. **Compile the Script:**

    ```bash
    gcc usb_devices.c -o usb_devices
    ```

3. **Run the Script:**

    ```bash
    ./usb_devices
    ```

4. **Output:**

    The script will display a list of USB devices currently connected to your system.

    ```
    Connected USB devices:
    Device: USB Keyboard
    Device: USB Mouse
    Device: External USB Drive
    ```

## Code Explanation

### `list_usb_devices()`

The `list_usb_devices()` function opens the `/sys/bus/usb/devices/` directory and iterates through each entry:
- It identifies entries with `:` in the name, which generally represent USB devices.
- For each entry, it attempts to read the `product` file to retrieve the device's name.

### `main()`

The `main()` function simply calls `list_usb_devices()` to execute the USB detection logic.

## Notes

- This script is designed for **Linux systems**; it will not work on Windows or macOS without significant changes.
- The script reads directly from system files; it may require **root permissions** to access certain USB device information depending on your system’s configuration.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

---

Enjoy identifying your connected USB devices!
