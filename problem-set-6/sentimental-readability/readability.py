def main():
    # Prompt user for string of text
    text = input("Text: ")

    # Get number of letters
    letters = float(count_letters(text))

    # Get number of words
    words = float(count_words(text))

    # Get number of sentences
    sentences = float(count_sentences(text))

    # L = average number of letters per 100 words
    L = float(letters / words * 100)

    # S = average number of sentences per 100 words
    S = float(sentences / words * 100)

    # Compute Coleman-Liau index
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")

    elif index >= 16:
        print("Grade 16+")

    else:
        print("Grade " + str(index))


def count_letters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count


def count_words(text):
    count = 1
    for char in text:
        if char.isspace():
            count += 1
    return count


def count_sentences(text):
    count = 0
    for char in text:
        if char in [".", "!", "?"]:
            count += 1
    return count


main()
