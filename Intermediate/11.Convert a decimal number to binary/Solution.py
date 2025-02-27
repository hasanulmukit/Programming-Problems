def decimal_to_binary(n):
    if n == 0:
        return "0"

    binary = ""
    while n > 0:
        binary = str(n % 2) + binary
        n //= 2

    return binary

if __name__ == "__main__":
    num = int(input("Enter a decimal number: "))
    print("Binary representation:", decimal_to_binary(num))
