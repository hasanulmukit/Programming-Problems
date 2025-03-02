import java.util.Scanner;

class TreeNode {
    int value;
    TreeNode left, right;

    TreeNode(int value) {
        this.value = value;
        left = right = null;
    }
}

public class TreeTraversals {
    // Preorder Traversal
    public static void preorder(TreeNode root) {
        if (root != null) {
            System.out.print(root.value + " ");
            preorder(root.left);
            preorder(root.right);
        }
    }

    // Inorder Traversal
    public static void inorder(TreeNode root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.value + " ");
            inorder(root.right);
        }
    }

    // Postorder Traversal
    public static void postorder(TreeNode root) {
        if (root != null) {
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.value + " ");
        }
    }

    // Build a sample tree for demonstration
    public static TreeNode buildTree(Scanner scanner) {
        System.out.print("Enter value (-1 for no node): ");
        int value = scanner.nextInt();

        if (value == -1) return null;

        TreeNode node = new TreeNode(value);
        System.out.println("Enter left child of " + value + ":");
        node.left = buildTree(scanner);

        System.out.println("Enter right child of " + value + ":");
        node.right = buildTree(scanner);

        return node;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Build the binary tree:");
        TreeNode root = buildTree(scanner);

        System.out.println("\nPreorder Traversal:");
        preorder(root);

        System.out.println("\nInorder Traversal:");
        inorder(root);

        System.out.println("\nPostorder Traversal:");
        postorder(root);

        scanner.close();
    }
}
