def evaluate_postfix(expression):
    stack = []
    for ch in expression:
        if ch.isdigit():
            stack.append(int(ch))
        else:
            val2 = stack.pop()
            val1 = stack.pop()
            if ch == '+':
                stack.append(val1 + val2)
            elif ch == '-':
                stack.append(val1 - val2)
            elif ch == '*':
                stack.append(val1 * val2)
            elif ch == '/':
                stack.append(val1 // val2)
            elif ch == '^':
                stack.append(val1 ** val2)
    return stack.pop()

if __name__ == "__main__":
    expression = input("Enter postfix expression: ")
    result = evaluate_postfix(expression)
    print(f"Result: {result}")
