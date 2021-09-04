# One Away


def is_one_away(word1: str, word2: str):
    if abs(len(word1)-len(word2)) > 1:
        return False
    for i in range(len(word1)):
        if len(word2) >= i + 1:
            if word1[i] != word2[i]:
                if len(word1) >= i + 2 and len(word2) >= i + 2 and word1[i+1:] == word2[i+1:]:# Check REPLACE
                    return True
                elif len(word1) >= i + 2 and len(word2) >= i + 1 and word1[i+1:] == word2[i:]:# Check REMOVE
                    return True
                elif len(word2) >= i + 2 and word1[i:] == word2[i+1:]:# Check INSERT
                    return True
                else:
                    return False
        elif len(word2) == i and word1[:-1] == word2:
            return True

    return True


def P5():
    for test in tests:
        x = '' if is_one_away(test[0], test[1]) else 'not '
        print(test[0] + ' and ' + test[1] + ' are ' + x + 'one away')


tests = [['pale', 'ple'], ['pales', 'pale'], ['pale', 'bale'], ['pale', 'bake']]
