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
        n_byte = format(n, "#010b")[-8:]

        if bits != 0:
            bits -= 1
            if not n_byte.startswith("10"):
                return False

        if n_byte.startswith("1"):
            bits = len(n_byte.split("0")[0])

    return True
