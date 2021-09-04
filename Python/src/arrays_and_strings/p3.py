# URLify
from typing import Dict


# Not in place substitution?
def URLify1(word: str, length: int) -> str:
    list_words = word.strip().split(' ')
    ret = ''
    for word in list_words:
        if ret != '':
            ret += '%20'
        ret += word
    return ret


# SLOW
def URLify2(word: str, length: int) -> str:
    count_preceding_spaces = 0
    for i in range(length):
        if word[i] == ' ':
            count_preceding_spaces += 1
    assert(length + 2 * count_preceding_spaces == len(word))

    word = list(word)
    for i in range(length):
        if count_preceding_spaces == 0:
            break
        if word[length - 1 - i] != ' ':
            word[length - 1 + 2 * count_preceding_spaces - i] = word[length - 1 - i]
        else:
            word[length - 1 + 2 * count_preceding_spaces - i - 2] = '%'
            word[length - 1 + 2 * count_preceding_spaces - i - 1] = '2'
            word[length - 1 + 2 * count_preceding_spaces - i] = '0'
            count_preceding_spaces -= 1
    return ''.join(word)


def URLify3(word: str, length: int) -> str:
    count_preceding_spaces = 0
    for i in range(length):
        if word[i] == ' ':
            count_preceding_spaces += 1
    assert(length + 2 * count_preceding_spaces == len(word))
    for i in range(length):
        if word[length - 1 - i] != ' ':
            word = word[:length - 1 + 2 * count_preceding_spaces - i] + word[length - 1 - i] + word[length - 1 + 2 * count_preceding_spaces - i + 1:]
        else:
            count_preceding_spaces -= 1
            word = word[:length - 1 + 2 * count_preceding_spaces - i] + '%20' + word[length - 1 + 2 * count_preceding_spaces - i + 3:]
            if count_preceding_spaces == 0:
                break
    return word


def P3():
    for test in list_inputs:
        print('"' + test["string"] + '" of length ' + str(test["length"]) + ' URLify to ' + URLify3(test["string"], test["length"]))


list_inputs = [{"string": 'Mr John Smith    ', "length": 13}, {"string": 'a b  ', "length": 3}]
