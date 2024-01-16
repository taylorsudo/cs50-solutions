def main():
    # Ask how many cents the customer is owed
    cents = round(get_cents("Change owed: ") * 100)

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(coins)


def get_cents(prompt):
    while True:
        try:
            cents = float(input(prompt))
            if cents > 0:
                return cents
        except ValueError:
            print("Not an integer")


def calculate_quarters(cents):
    quarters = int(cents / 25)
    return quarters


def calculate_dimes(cents):
    dimes = int(cents / 10)
    return dimes


def calculate_nickels(cents):
    nickels = int(cents / 5)
    return nickels


def calculate_pennies(cents):
    pennies = int(cents / 1)
    return pennies


if __name__ == "__main__":
    main()
