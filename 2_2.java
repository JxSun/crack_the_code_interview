public class Node {
	int value;
	Node next;

	Node(int v) {
		value = v;
	}

	/**
     * My original approach: Time = O(n + (n-k)), Space = O(1)
     */
	public static Node findLastKthNode1(Node head, int k) {
		if (k <= 0) {
			System.err.println("k can't be 0 or negative");
			return null;
		}		

		// Find list's length
		int listLength = 0;
		Node curr;
		for (curr = head; curr != null; curr = curr.next, listLength++);
		if (k > listLength) {
			System.err.println("k is larger than the list's length");
			return null;
		}
	
		// Start counting backward
		curr = head;
		for (int diff = listLength - k; diff > 0; curr = curr.next, diff--);
		return curr;
	}

	/**
     * Book's approach: Time = O(n), Space = O(1)
     */
	public static Node findLastKthNode2(Node head, int k) {
		if (k <= 0) {
			System.err.println("k can't be 0 or negative");
			return null;
		}		

		// node1 moves k steps first
		Node node1, node2;
		for (node1 = head; node1 != null && k > 0; node1 = node1.next, k--);
		if (node1 == null) {
			System.err.println("k is larger than the list's length");
			return null;
		}
		
		// Both node1 and node2 move until node1 meets the list's end
		for (node2 = head; node1 != null; node1 = node1.next, node2 = node2.next);
		return node2;
	}

	/**
     * Recursive approach: Time = O(2 * n), Space = O(n)
	 */
	private static class NodeResultChecker {
		int checker;
		Node node;
		NodeResultChecker(Node n, int c) {
			node = n;
			checker = c;
		}
	}

	public static Node findLastKthNode3(Node head, int k) {
		NodeResultChecker result = findLastKthNode3Internal(head, k);
		return result.node;
	}

	private static NodeResultChecker findLastKthNode3Internal(Node head, int k) {
		if (head == null) return new NodeResultChecker(null , 0);
		
		NodeResultChecker result = findLastKthNode3Internal(head.next, k);
		if (result.checker + 1 == k) { // +1: to skip the last 0th node
			if (result.node == null)
				result.node = head;		
			return result;
		}
		result.checker++;
		return result;
	}

	public static Node createTestList() {
		Node head = null, node = null;
		for (int i = 1; i <= 10; i++) {
			if (i == 1) {
				node = new Node(i);
				head = node;
			} else {
				node.next = new Node(i);
				node = node.next;
			}
		}
		return head;
	}

	public static void main(String[] args) {
		Node head = createTestList();
		Node n = findLastKthNode3(head, 0);
		System.out.println((n == null) ? "NULL" : n.value);
		n = findLastKthNode3(head, 1);
		System.out.println((n == null) ? "NULL" : n.value);
		n = findLastKthNode3(head, 5);
		System.out.println((n == null) ? "NULL" : n.value);
		n = findLastKthNode3(head, 9);
		System.out.println((n == null) ? "NULL" : n.value);
		n = findLastKthNode3(head, 100);
		System.out.println((n == null) ? "NULL" : n.value);
	}
}
