def main():
    height = get_int("Height: ")

    for row in range(1, height + 1):
        print(" " * (height - row) + "#" * row)


def get_int(prompt):
    while True:
        try:
            height = int(input(prompt))
            if height > 0 and height < 9:
                return height
        except ValueError:
            print("Not an integer")


if __name__ == "__main__":
    main()
