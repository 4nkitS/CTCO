# Is Unique

from typing import List


def all_chars_unique_in_word(self, word: str) -> bool:
    list_of_chars_in_str: List = []
    for char in word:
        if char in list_of_chars_in_str:
            return False
        list_of_chars_in_str.append(char)
    return True


def P1(self):
    for word in list_inputs:
        print('"' + word + '" has all unique chars' if self.all_chars_unique_in_word(word)
              else '"' + word + '"' + " doesn't have all unique chars")


list_inputs = ['hello', 'world', 'this', 'is', 'plainsboro', 'new jersey']
