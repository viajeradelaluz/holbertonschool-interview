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
        self.ip = args[0]
        self.sep = args[1]
        self.date = args[2]
        self.time = args[3]
        self.http_method = args[4]
        self.endpoint = args[5]
        self.http_version = args[6]
        self.status_code = args[7]
        self.file_size = args[8]


def check_line_format(line):
    """Checks if line is in the correct format."""
    constrains = [
        "len(line) == 9",
        "line_.ip.count('.') == 3",
        "line_.sep == '-'",
        "line_.date.startswith('[') and line_.date.count('-') == 2",
        "line_.time.count(':') == 2 and line_.time.endswith(']')",
        "line_.http_method == '\"GET'",
        "line_.endpoint.startswith('/')",
        "line_.http_version.startswith('HTTP/')",
    ]
    line_ = LineFormat(*line)

    format = []
    for statement in constrains:
        format.append(eval(statement))

    return line_ if all(format) else None


def count_line(line):
    """Counts lines by status code."""
    if line.status_code in LINES_BY_STATUS_CODE:
        LINES_BY_STATUS_CODE[line.status_code] += 1


def print_metrics(file_size):
    """Prints metrics."""
    print("File size: {}".format(file_size))
    for status_code, total_lines in sorted(LINES_BY_STATUS_CODE.items()):
        if total_lines:
            print("{}: {}".format(status_code, total_lines))
