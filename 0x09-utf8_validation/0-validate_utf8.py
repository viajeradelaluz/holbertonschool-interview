#!/usr/bin/python3
"""
Module that determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding.

    :param data: list of integers
    :return: True if data is a valid UTF-8 encoding, else return False
    """

    bits = 0

    for n in data:
        byte = n & 255

        if bits:
            if byte >> 6 != 2:
                return False
            bits -= 1
            continue
        
        while (1 << abs(7 - bits)) & byte:
            bits += 1
        
        if bits == 1 or bits > 4:
            return False
        
        bits = max(bits - 1, 0)

    return bits == 0
