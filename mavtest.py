#!/usr/bin/env python

import sys
import mavlink

class fifo(object):
    def __init__(self):
        self.buf = []
    def write(self, data):
        self.buf += data
        return len(data)
    def read(self):
        return self.buf.pop(0)

f = fifo()

mav = mavlink.MAVLink(f)
m = mav.param_set_send(7, 1, "WP_RADIUS", 101)
m = mav.param_set_encode(7, 1, "WP_RADIUS", 101)
m2 = mav.decode(m.msgbuf())
