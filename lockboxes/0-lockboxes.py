#!/usr/bin/python3
"""
Modul can see if all boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    See if all boxes can be opened

    Args:
        boxes (list of list of int): list of boxes and their keys.

    Returns:
        boolean: Return true if all boxe can be opened, else false.
    """
    opened = {0}
    keys_to_check = [0]

    while keys_to_check:
        current_box = keys_to_check.pop()

        for key in boxes[current_box]:
            if key < len(boxes) and key not in opened:
                opened.add(key)
                keys_to_check.append(key)

    return len(opened) == len(boxes)
