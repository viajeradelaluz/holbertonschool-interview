#!/usr/bin/env python3
"""
Utils for log parsing.
"""

LINES_BY_STATUS_CODE = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0,
}


class LineFormat:
    """Represents the line format."""

    def __init__(self, *args):
        self.status_code = args[-2]
        self.file_size = args[-1]


def check_line_format(line):
    """Checks if line is in the correct format."""
    if len(line) < 2:
        return None

    line_ = LineFormat(*line)
    return line_


def count_line(status_code):
    """Counts lines by status code."""
    if status_code.isdigit() and status_code in LINES_BY_STATUS_CODE:
        LINES_BY_STATUS_CODE[status_code] += 1


def print_metrics(file_size):
    """Prints metrics."""
    print("File size: {}".format(file_size))
    for status_code, total_lines in sorted(LINES_BY_STATUS_CODE.items()):
        if total_lines > 0:
            print("{}: {}".format(status_code, total_lines))
