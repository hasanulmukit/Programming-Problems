class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_tree():
    # Read integer input. Use -1 as sentinel for no node.
    data = int(input("Enter node value (-1 for no node): "))
    if data == -1:
        return None
    
    root = Node(data)
    print(f"Enter left child of {data}:")
    root.left = build_tree()
    print(f"Enter right child of {data}:")
    root.right = build_tree()
    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)

def preorder(root):
    if root:
        print(root.data, end=" ")
        preorder(root.left)
        preorder(root.right)

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.data, end=" ")

if __name__ == "__main__":
    print("Build the binary tree:")
    root = build_tree()

    print("\nInorder Traversal:")
    inorder(root)
    print("\nPreorder Traversal:")
    preorder(root)
    print("\nPostorder Traversal:")
    postorder(root)
    print()
