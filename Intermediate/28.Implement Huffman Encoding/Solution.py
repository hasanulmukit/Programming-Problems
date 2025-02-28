import heapq

# Huffman Tree Node
class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

# Function to generate Huffman Codes
def generate_codes(root, code, huffman_codes):
    if root is None:
        return
    
    if root.char != "#":
        huffman_codes[root.char] = code
    
    generate_codes(root.left, code + "0", huffman_codes)
    generate_codes(root.right, code + "1", huffman_codes)

# Function to build Huffman Tree
def build_huffman_tree(freq_map):
    heap = [Node(char, freq) for char, freq in freq_map.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        merged = Node("#", left.freq + right.freq)
        merged.left = left
        merged.right = right
        heapq.heappush(heap, merged)

    return heap[0]

# Main function
if __name__ == "__main__":
    text = input("Enter the string: ")
    freq_map = {}

    for char in text:
        freq_map[char] = freq_map.get(char, 0) + 1

    root = build_huffman_tree(freq_map)
    huffman_codes = {}
    generate_codes(root, "", huffman_codes)

    print("\nHuffman Codes:")
    for char, code in huffman_codes.items():
        print(f"{char}: {code}")
