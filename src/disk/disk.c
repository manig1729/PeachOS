#include "io/io.h"
#include "memory/memory.h"
#include "disk.h"
#include "config.h"
#include "status.h"

struct disk disk;

// low level function - not there in header file
int disk_read_sector(int lba, int total, void* buf) {
    outb(0x1f6, (lba >> 24) | 0xE0);
    outb(0x1f2, total);
    outb(0x1f3, (unsigned char) (lba & 0xff));
    outb(0x1f4, (unsigned char)(lba >> 8));
    outb(0x1f5, (unsigned char)(lba >> 16));
    outb(0x1f7, 0x20);

    unsigned short* ptr = (unsigned short*) buf;
    for (int b = 0; b < total; b++) {
        // wait for buffer to be ready
        char c = insb(0x1f7);
        while (!(c & 0x08)) {
            c = insb(0x1f7);
        }

        // Copy from hard disk to memory
        for (int i = 0; i < 256; i++) {
            *ptr = insw(0x1f0);
            ptr++;
        }
    }

    return 0;
}

void disk_search_and_init() {
    // only abstraction
    memset(&disk, 0, sizeof(disk));
    disk.type = PEACHOS_DISK_TYPE_REAL;
    disk.sector_size = PEACHOS_SECTOR_SIZE;
    disk.id = 0;
    disk.filesystem = fs_resolve(&disk);

}

struct disk* disk_get (int index) {
    // abstraction
    if (index != 0) 
        return 0;
    
    return &disk;
}

int disk_read_block (struct disk* idisk, unsigned int lba, int total, void* buf) {
    if (idisk != &disk) {
        return -EIO;
    }
    return disk_read_sector(lba, total, buf);
}