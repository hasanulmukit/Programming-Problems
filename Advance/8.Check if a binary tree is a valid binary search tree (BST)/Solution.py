class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def is_bst_util(root, min_val, max_val):
    if root is None:
        return True

    if root.data <= min_val or root.data >= max_val:
        return False

    return (is_bst_util(root.left, min_val, root.data) and
            is_bst_util(root.right, root.data, max_val))

def is_bst(root):
    return is_bst_util(root, float('-inf'), float('inf'))

if __name__ == "__main__":
    root = Node(10)
    root.left = Node(5)
    root.right = Node(20)
    root.left.left = Node(3)
    root.left.right = Node(7)

    if is_bst(root):
        print("The tree is a valid BST.")
    else:
        print("The tree is not a valid BST.")
