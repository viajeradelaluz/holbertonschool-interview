#!/usr/bin/python3
"""
Module that contains the function minOperations
"""


def minOperations(n):
    """Calculates the fewest number of operations needed
    to result in exactly n H characters in the file.

    :param n: number of operations
    :return: number of operations needed, 0 otherwise
    """
    if n < 2:
        return 0

    num_ops, temporal = 0, 0
    current_H = 1

    while current_H < n:

        # if the current value of H is a multiple of n, increase it
        # by performing the "Paste" operation
        if n % current_H == 0:
            temporal = current_H
            current_H *= 2
            num_ops += 1

        # if not, "Copy All" from the temporal variable
        else:
            current_H += temporal

        # And "Paste"
        num_ops += 1

    return num_ops
