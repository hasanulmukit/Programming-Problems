#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;
    if (root->ch != '#') huffmanCodes[root->ch] = code;
    
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to build Huffman Tree
Node* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    
    for (auto& pair : freqMap)
        pq.push(new Node(pair.first, pair.second));
    
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        
        Node* newNode = new Node('#', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    
    return pq.top();
}

// Main function
int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    unordered_map<char, int> freqMap;
    for (char ch : input) freqMap[ch]++;

    Node* root = buildHuffmanTree(freqMap);
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    cout << "\nHuffman Codes:\n";
    for (auto& pair : huffmanCodes)
        cout << pair.first << ": " << pair.second << endl;

    return 0;
}
