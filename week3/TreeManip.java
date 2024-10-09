package week3;

import java.util.*; 
class Node {
    int key;
    Node firstChild, nextSibling;
}

class Tree {
    static Node makeRoot(int key) {
        Node root = new Node();
        root.key = key;
        root.firstChild = null;
        root.nextSibling = null;
        return root;
    }

    static Node findNode(Node root, int u) {//return the node with key u, if it does not exist, return null
        Node temp = root;
        while (temp != null) {
            if (temp.key == u) {
                return temp;
            }
            temp = temp.nextSibling;
        }
        return null;
    }

    static void insert(Node root, int u, int v){//create a new node u and insert it as the last child of v, if v does not exist or u already exists, do nothing
        Node node = new Node();
        node.key = u;
        node.firstChild = null;
        node.nextSibling = null;
        if (v == 0) {
            return;
        }
        Node parent = findNode(root, v);
        if (parent == null) {
            return;
        }
        if (parent.firstChild == null) {
            parent.firstChild = node;
        } else {
            Node temp = parent.firstChild;
            while (temp.nextSibling != null) {
                temp = temp.nextSibling;
            }
            temp.nextSibling = node;
        }
    }

    static void preOrder(Node root) {
        if (root != null) {
            System.out.print(root.key + " ");
            preOrder(root.firstChild);
            preOrder(root.nextSibling);
        }
    }

    static void postOrder(Node root) {
        if (root != null) {
            postOrder(root.firstChild);
            System.out.print(root.key + " ");
            postOrder(root.nextSibling);
        }
    }

    static void inOrder(Node root) {
        if (root != null) {
            inOrder(root.firstChild);
            System.out.print(root.key + " ");
            inOrder(root.nextSibling);
        }
    }
}

public class TreeManip {
    public static void main(String[] args) {
        Node root = null;
        String cmd;
        Scanner sc = new Scanner(System.in);
        while (true) {
            cmd = sc.nextLine();
            if (cmd.equals("*")) {
                break;
            }
            String[] cmdArr = cmd.split(" ");
            if (cmdArr[0].equals("MakeRoot")) {
                int key = Integer.parseInt(cmdArr[1]);
                root = Tree.makeRoot(key);
            }
            if (cmdArr[0].equals("Insert")) {
                int u = Integer.parseInt(cmdArr[1]);
                int v = Integer.parseInt(cmdArr[2]);
                Tree.insert(root, u, v);
            }   
            if (cmdArr[0].equals("PreOrder")) {
                Tree.preOrder(root);
                System.out.println();
            }
            if (cmdArr[0].equals("PostOrder")) {
                Tree.postOrder(root);
                System.out.println();
            }
            if (cmdArr[0].equals("InOrder")) {
                Tree.inOrder(root);
                System.out.println();
            }
        }
        sc.close();
    }
}