# Palindrome Permutation

from .p2 import get_key_frequency_map


def is_permutation_of_palindrome(word: str):
    map_char_to_frequency = get_key_frequency_map(word.casefold())
    # a palindrome can have at max only one char with with odd number frequency
    count_char_with_odd_frequeny = 0
    for char in map_char_to_frequency:
        if map_char_to_frequency[char] % 2 != 0:
            if count_char_with_odd_frequeny > 1:
                return False
            else:
                count_char_with_odd_frequeny += 1
    return True


def P4():
    for test in tests:
        x = '' if is_permutation_of_palindrome(test) else 'not '
        print(test + ' is ' + x + 'a permutation of a palindrome')


tests = ['Tact Coa', 'Dalda']