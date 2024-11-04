#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define USB_PATH "/sys/bus/usb/devices/"

void list_usb_devices() {
    DIR *dir;
    struct dirent *entry;

    // Open the USB devices directory
    dir = opendir(USB_PATH);
    if (dir == NULL) {
        perror("Failed to open USB directory");
        return;
    }

    printf("Connected USB devices:\n");

    // Loop through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_LNK && strstr(entry->d_name, ":")) { // USB devices have ":" in their names
            char device_path[256];
            snprintf(device_path, sizeof(device_path), "%s%s/product", USB_PATH, entry->d_name);
            
            FILE *file = fopen(device_path, "r");
            if (file) {
                char product_name[128];
                
                // Read and display the product name
                if (fgets(product_name, sizeof(product_name), file) != NULL) {
                    printf("Device: %s\n", product_name);
                }
                fclose(file);
            }
        }
    }

    closedir(dir);
}

int main() {
    list_usb_devices();
    return 0;
}
