#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics.
"""
import sys

check_line_format = __import__("utils").check_line_format
count_line = __import__("utils").count_line
print_metrics = __import__("utils").print_metrics


def main():
    """Entry point."""
    file_size = 0
    try:
        for index, input in enumerate(sys.stdin, start=1):
            line = check_line_format(input.split())
            if line is None:
                continue

            count_line(line)
            file_size += int(line.file_size)

            if index % 10 == 0:
                print_metrics(file_size)

    finally:
        print_metrics(file_size)


if __name__ == "__main__":
    main()
