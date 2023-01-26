#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
"""
import sys

from utils import check_line_format, count_line, print_metrics


def main():
    """Entry point."""
    file_size = 0
    try:
        for index, input in enumerate(sys.stdin, start=1):
            line = check_line_format(input.split())

            if line:
                count_line(line)
                file_size += int(line.file_size)

                if index % 10 == 0:
                    print_metrics(file_size)
            else:
                continue
    except KeyboardInterrupt:
        print_metrics(file_size)


if __name__ == "__main__":
    main()
