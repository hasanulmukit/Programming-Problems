MAX = 100
stack = []
top = -1

def push():
    global top
    if top == MAX - 1:
        print("Stack overflow!")
        return
    val = int(input("Enter value to push: "))
    stack.append(val)
    top += 1
    print(f"{val} pushed onto stack.")

def pop():
    global top
    if top == -1:
        print("Stack underflow!")
        return
    val = stack.pop()
    top -= 1
    print(f"{val} popped from stack.")

def display():
    if not stack:
        print("Stack is empty.")
        return
    print("Stack elements:")
    for i in range(len(stack) - 1, -1, -1):
        print(stack[i])

while True:
    print("\n1. Push\n2. Pop\n3. Display\n4. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        push()
    elif choice == 2:
        pop()
    elif choice == 3:
        display()
    elif choice == 4:
        break
    else:
        print("Invalid choice!")
