#!/usr/bin/python
import os


def count_dir(path, count=0):
    for filename in os.listdir(path):
        new_path = os.path.join(path, filename)
        if os.path.isdir(new_path):
            count += count_dir(new_path)
        elif os.path.isfile(new_path):
            count += count_file(new_path)
    return count


def count_file(filepath):
    count = 0
    with open(filepath, 'r') as f:
        for _ in f:
            count += 1
    print("[{:>4} lines] {}".format(count, filepath))
    return count


print(f"\nTotal lines: {count_dir('src')}\n")
os.system("pause")