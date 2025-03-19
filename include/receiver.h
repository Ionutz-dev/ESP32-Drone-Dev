// FlySky FS-i6 + FS-iA6B receiver signal processing

#ifndef RECEIVER_H
#define RECEIVER_H

struct Commands {
    int throttle;
    float pitch;
    float roll;
    float yaw;
};

void initReceiver();
Commands readReceiver();

#endif
