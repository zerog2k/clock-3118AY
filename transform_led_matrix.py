#!/usr/bin/env python3
help_text =""" 
    use to transform uint64_t 8x8 matrix produced by 
    https://xantorohara.github.io/led-matrix-editor
    which produce uint64_t row scan, LSB to MSB, top to bottom
    into uint8_t array, column scan, L to R
"""

import argparse

parser = argparse.ArgumentParser(description=help_text)
parser.add_argument("uint64_t", type=lambda x: int(x,16), help="hex value")
parser.add_argument("--single", "-s", help="single line output", action="store_true")
args = parser.parse_args()


def transform_matrix(input):
    out = []
    col = 0
    #
    while (col < 8):
        colbyte = 0
        row = 0
        while (row < 8):
            mask = 1 << ( col + (row*8))
            if input & mask:
                colbyte = colbyte | 1 << (7 - row)
            row += 1
        out.append(colbyte)
        col += 1
    return out

def print_array(input):
    for b in input:
        if args.single:
            print("{:#010b}, ".format(b), end="")
        else:
            print("{:#010b},".format(b))
    if args.single:
        print()


myinput = args.uint64_t
mytransformed = transform_matrix(myinput)
print_array(mytransformed)


