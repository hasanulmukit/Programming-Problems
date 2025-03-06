class Node {
    int data;
    Node left, right;

    public Node(int value) {
        data = value;
        left = right = null;
    }
}

public class Main {
    static boolean isBSTUtil(Node root, int min, int max) {
        if (root == null)
            return true;

        if (root.data <= min || root.data >= max)
            return false;

        return isBSTUtil(root.left, min, root.data) && isBSTUtil(root.right, root.data, max);
    }

    static boolean isBST(Node root) {
        return isBSTUtil(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(5);
        root.right = new Node(20);
        root.left.left = new Node(3);
        root.left.right = new Node(7);

        if (isBST(root))
            System.out.println("The tree is a valid BST.");
        else
            System.out.println("The tree is not a valid BST.");
    }
}
