def move_disk(src, dest, s, d):
    if not src:
        disk = dest.pop()
        src.append(disk)
        print(f"Move disk {disk} from {d} to {s}")
    elif not dest:
        disk = src.pop()
        dest.append(disk)
        print(f"Move disk {disk} from {s} to {d}")
    elif src[-1] > dest[-1]:
        disk = dest.pop()
        src.append(disk)
        print(f"Move disk {disk} from {d} to {s}")
    else:
        disk = src.pop()
        dest.append(disk)
        print(f"Move disk {disk} from {s} to {d}")


def hanoi(n, src, aux, dest):
    moves = (1 << n) - 1
    s, a, d = "S", "A", "D"

    if n % 2 == 0:
        a, d = d, a

    for i in range(n, 0, -1):
        src.append(i)

    for i in range(1, moves + 1):
        if i % 3 == 1:
            move_disk(src, dest, s, d)
        elif i % 3 == 2:
            move_disk(src, aux, s, a)
        elif i % 3 == 0:
            move_disk(aux, dest, a, d)


if __name__ == "__main__":
    n = int(input("Enter the number of disks: "))
    src, aux, dest = [], [], []
    hanoi(n, src, aux, dest)
