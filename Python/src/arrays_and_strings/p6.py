# String Compression

def StringCompression(word: str):
    ret = ''
    if len(word) > 0:
        prev_char = word[0]
        count_prev_char = 0
        for char in word:
            if prev_char == char:
                count_prev_char += 1
            else:
                ret += prev_char + str(count_prev_char)
                prev_char = char
                count_prev_char = 1
        ret += prev_char + str(count_prev_char)
    return ret


def P6():
    for test in tests:
        print('"' + test + '" compresses to "' + StringCompression(test) + '"')


tests = ['aabcccccaaa', '']
