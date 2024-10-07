package week3;

import java.util.*; 
class Node {
    int key;
    Node left, right;

    public Node(int item) {
        key = item;
        left = right = null;
    }
}

class Tree {
    static Node insert(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }

        if (key < root.key) {
            root.left = insert(root.left, key);
        } else if (key > root.key) {
            root.right = insert(root.right, key);
        }

        return root;
    }

    static void preOrder(Node root) {
        if (root != null) {
            System.out.print(root.key + " ");
            preOrder(root.left);
            preOrder(root.right);
        }
    }
}

public class BST {
    public static void main(String[] args) {
        Node root = null;
        String cmd;
        Scanner sc = new Scanner(System.in);
        while (true) {
            cmd = sc.nextLine();
            if (cmd.equals("#")) {
                break;
            }
            String[] cmdArr = cmd.split(" ");
            if (cmdArr[0].equals("insert")) {
                int key = Integer.parseInt(cmdArr[1]);
                root = Tree.insert(root, key);
            }
        }
        sc.close();
        Tree.preOrder(root);
    }
}