# URLify
from typing import Dict


def URLify(word: str, length: int) -> str:
    count_spaces = 0
    for i in range(length):
        if word[i] == ' ':
            count_spaces += 1
    assert(length + 2 * count_spaces == len(word))
    for i in range(length):
        if word[length - 1 - i] != ' ':
            word[length + 2 * count_spaces - 1 - i] = word[length - 1 - i]
        else:
            count_spaces -= 1
            word[length + 2 * count_spaces - 1 - i] = '%'
            word[length + 2 * count_spaces - 1 - i + 1] = '2'
            word[length + 2 * count_spaces - 1 - i + 2] = '0'
    return word


def P3():
    for test in list_inputs:
        print('"' + test["string"] + '" of length ' + str(test["length"]) + ' URLify to ' + URLify(test["string"], test["length"]) + '.')


list_inputs = [{"string": 'Mr John Smith    ', "length": 13}, {"string": 'a b  ', "length": 3}]
