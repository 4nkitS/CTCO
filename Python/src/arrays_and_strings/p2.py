# Check Permutation

from typing import Dict


def get_key_frequency_map(word: str):
    map_char_frequency_word: Dict[str, int] = {}
    for char in word:
        map_char_frequency_word[char] = map_char_frequency_word.get(char, 0) + 1
    return map_char_frequency_word


def maps_match(map1, map2):
    if len(map1) != len(map2):
        return False
    for key in map1:
        if map1[key] != map2.get(key):
            return False
    return True


def both_are_permutations(word1: str, word2: str) -> bool:
    map_char_frequency_word1 = get_key_frequency_map(word1)
    map_char_frequency_word2 = get_key_frequency_map(word2)
    return maps_match(map_char_frequency_word1, map_char_frequency_word2)


def P2():
    for pair in list_inputs:
        x = '' if both_are_permutations(pair[0], pair[1]) else ' not'
        print('"' + pair[0] + '" and "' + pair[1] + '" are' + x + ' permutations.')


list_inputs = [['ankit', 'tikna'], ['apricot', 'tapioca'], ['plainsboro', 'boroplains']]
